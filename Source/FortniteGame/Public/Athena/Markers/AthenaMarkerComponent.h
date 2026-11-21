// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "Components/ActorComponent.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "AthenaMarkerComponent.generated.h"

class AActor;
class AFortPlayerMarkerBase;
class AFortPlayerStateAthena;
class UFortWorldMarker;
class UObject;
class UUserWidget;
enum class ECancelMarkerReason : int32;
enum class EFortWorldMarkerType : uint8;

UENUM()
enum class ECancelMarkerReason : int32
{
	Ping = 0,
	MapOrDeath = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddMapMarkerOnServer, const FFortWorldMarkerData&, WorldMarkerData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClientMapMarkersChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveMapMarkerOnServer, FMarkerID, MarkerID);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeleportToMarkerTimeChanged, float, TimeLeftBeforeTeleport);

USTRUCT()
struct FFortFrontEndMarkerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl PlayerID;

	UPROPERTY()
	FVector CurrentLocation;

};

UCLASS(MinimalAPI, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent))
class UAthenaMarkerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Marker Component")
	void CancelAllMarkers();

	UFUNCTION(Client, Reliable)
	void EnableCommandWheel(bool bInEnableCommandWheel);

	UFUNCTION(BlueprintPure, Category="Marker Component")
	UFortWorldMarker* FindMarkerByID(FMarkerID MarkerID) const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Marker Component")
	UFortWorldMarker* FindMarkerByMarkedActor(AActor* MarkedActor);

	UFUNCTION(BlueprintCallable, Category="Marker Component")
	FLinearColor GetMarkerColor(FMarkerID MarkerID);

	UFUNCTION(BlueprintCallable, Category="Marker Component")
	FVector GetMarkerCurrentPosition(FMarkerID MarkerID);

	UFUNCTION(BlueprintCallable, Category="Marker Component")
	TArray<FMarkerID> GetMarkerIDsByType(EFortWorldMarkerType MarkerType);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Marker Component")
	FMarkerID MarkActorOnClient(AActor* ActorToBeMarked, const bool bIncludeSquad = true, const bool bUseHoveredMarkerDetail = true);

	UFUNCTION(BlueprintCallable, Category="Marker Component")
	FMarkerID MarkActorOnServer(AActor* ActorToBeMarked, const bool bIncludeSquad = true, const bool bUseHoveredMarkerDetail = true);

	UFUNCTION(Client, Reliable)
	void OnPingCommandDeclined(FMarkerID MarkerID, bool bPlayUnableToPerformAction);

	UFUNCTION()
	void OnTimelineScrubbed();

	UFUNCTION(Client, Unreliable)
	void PlayMarkerConfirmationSound(int32 InPlayerId, FMarkerID InMarkerID);

	UFUNCTION(BlueprintCallable, Category="Marker Component")
	void SetMarkerActorClass(TSubclassOf<AFortPlayerMarkerBase> InMarkerActorClass);

	UFUNCTION(BlueprintCallable, Category="Marker Component")
	void SetMarkerWidgetClass(TSubclassOf<UUserWidget> InMarkerClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Marker Component")
	void UnmarkActorOnClient(FMarkerID MarkerID);

private:
	UFUNCTION()
	void HandleServerSquadChange(AFortPlayerStateAthena* InPlayerstate, const uint8 PreviousSquadId);

	UFUNCTION()
	void OnRep_MarkerStream();

	UFUNCTION(Server, Reliable)
	void ServerAddMapMarker(FFortClientMarkerRequest MarkerRequest);

	UFUNCTION(Server, Reliable)
	void ServerRemoveMapMarker(FMarkerID MarkerID, ECancelMarkerReason CancelReason);

	UFUNCTION(Server, Reliable)
	void ServerSetMapMarkerConfirmation(const FMarkerID& MarkerID, const int32 InPlayerId, const FLinearColor InPinColor, const bool bWasConfirmed);

	UPROPERTY(BlueprintAssignable, Category="Marker Events", meta=(AllowPrivateAccess="true"))
	FOnAddMapMarkerOnServer OnAddMapMarkerOnServerEvent;

	UPROPERTY(BlueprintAssignable, Category="Marker Events", meta=(AllowPrivateAccess="true"))
	FOnRemoveMapMarkerOnServer OnRemoveMapMarkerOnServerEvent;

	UPROPERTY(BlueprintAssignable, Category="Marker Events", meta=(AllowPrivateAccess="true"))
	FOnClientMapMarkersChanged OnClientMapMarkersChangedEvent;

	UPROPERTY(EditAnywhere, Category="Visuals", meta=(AllowedClasses="/Script/FortniteGame.FortActorIndicatorInterface"))
	TSubclassOf<UUserWidget> MarkerWidgetClass;

	UPROPERTY(EditAnywhere, Category="Visuals")
	TSubclassOf<AFortPlayerMarkerBase> MarkerActorClass;

	UPROPERTY(ReplicatedUsing=OnRep_MarkerStream)
	FFortWorldMarkerContainer MarkerStream;

	UPROPERTY(Transient)
	TMap<FMarkerID, FTimerHandle> LocalMarkersDeletedBeforeReplication;

	UPROPERTY(Transient)
	int32 LocalPlaceableMarkersPerRate;

	UPROPERTY(Transient)
	int32 RemotePlayableMarkerSoundsPerRate;

	UPROPERTY(Transient)
	int32 LocalMarkerConfirmationsPerRate;

	UPROPERTY(Transient)
	int32 LocalPlayableMarkerConfirmationSoundsPerRate;

	UPROPERTY(Transient)
	TMap<int32, int32> RemotePlayableMarkerSoundsPerPlayerIDMap;

	UPROPERTY()
	TObjectPtr<UFortWorldMarker> PendingCancelMarker;

	UPROPERTY()
	TObjectPtr<UFortWorldMarker> LastHoveredMarker;

	UPROPERTY()
	TObjectPtr<UFortWorldMarker> PendingConfirmMarker;

	UPROPERTY()
	TObjectPtr<UFortWorldMarker> LastPingMarker;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerMarkerBase>> MarkerActorPool;

	UPROPERTY(Transient)
	FUserWidgetPool MarkerWidgetPool;

	UPROPERTY(Transient)
	bool bIsAimingDownSights;

};

UCLASS()
class UAthenaMarkerComponentLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Marker Component", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void ActivateAllMarkerComponents(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Marker Component", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void DeactivateAllMarkerComponents(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Marker Component")
	static void DeactivateMarkersOnActor(AActor* ActorToRemoveMarkersFrom);

};

