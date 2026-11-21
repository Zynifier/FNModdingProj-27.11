// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "SpecialEventGameplayLibrary.generated.h"

class AController;
class AFortAthenaMutator_SpecialEvent;
class AFortPawn;
class AFortPlayerControllerAthena;
class AFortPlayerStateAthena;
class ASpecialEventScript;
class UActorComponent;
class UAthenaLoadingScreenItemDefinition;
class UFortAsyncAction_GameplayCinematicComponentReady;
class UFortControllerComponent_GameplayCinematic;
class UFortControllerComponent_SpecialEvent;
class UObject;
class USceneComponent;
enum class EDeathCauseReason : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayCineCompReady, UFortControllerComponent_GameplayCinematic*, FoundComponent);

UCLASS()
class UFortAsyncAction_GameplayCinematicComponentReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_GameplayCinematicComponentReady* FindGameplayCinematicComponentAsync(AController* Conroller);

	UPROPERTY(BlueprintAssignable)
	FOnGameplayCineCompReady OnReady;

};

UCLASS()
class USpecialEventGameplayLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
	static void AddSpecialEventKillFeedEntry(const UObject* WorldContextObject, const AFortPlayerStateAthena* VictimPlayerState, const AFortPlayerStateAthena* KillerPlayerState, const FText NonPlayerVictimName, const FText NonPlayerKillerName, const FGameplayTag& DeathCauseTag, const EDeathCauseReason DeathCauseReason, const float Distance);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	static void AddSpecialEventRecentElimination(const FVector& Location, const AFortPlayerStateAthena* PlayerState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static bool AttachPawnToComponent(AFortPawn* Pawn, USceneComponent* Component, const FName SocketName = NAME_None, const EAttachmentRule LocationRule = EAttachmentRule::SnapToTarget, const EAttachmentRule RotationRule = EAttachmentRule::SnapToTarget, const EAttachmentRule ScaleRule = EAttachmentRule::KeepWorld, const bool bWeldSimulatedBodies = true);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	static void CreateSpecialEventPlayerEliminationWorldMarker(const AFortPlayerControllerAthena* LocalController, const AFortPlayerStateAthena* VictimPlayerState, const FVector& DeathLocation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static bool DetachPawn(AFortPawn* Pawn, const EDetachmentRule LocationRule, const EDetachmentRule RotationRule, const EDetachmentRule ScaleRule);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static bool DetachPawnFromComponent(AFortPawn* Pawn, const USceneComponent* Component, const EDetachmentRule LocationRule = EDetachmentRule::KeepWorld, const EDetachmentRule RotationRule = EDetachmentRule::KeepWorld, const EDetachmentRule ScaleRule = EDetachmentRule::KeepWorld);

	UFUNCTION(BlueprintCallable)
	static UFortControllerComponent_GameplayCinematic* FindGameplayCinematicComponent(AController* Controller);

	UFUNCTION(BlueprintCallable)
	static UFortControllerComponent_SpecialEvent* FindSpecialEventComponent(AController* Controller);

	UFUNCTION(BlueprintCallable)
	static void ForceDestroyComponents(const TArray<UActorComponent*>& Components, const bool bPromoteChildren = false, const FString& LogContext = TEXT(""));

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
	static void ForceUpdateGrass(UObject* WorldContextObject, const FVector Location);

	UFUNCTION(BlueprintPure, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
	static bool GetHasInfiniteSafeZonePhase(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
	static FFortAthenaLoadout GetLocalPlayerLoadout(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static AFortAthenaMutator_SpecialEvent* GetSpecialEventMutator(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	static FString GetSpecialEventPlayerDisplayName(const AFortPlayerControllerAthena* LocalController, const AFortPlayerStateAthena* PlayerState);

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static ASpecialEventScript* GetSpecialEventScript(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static void HideSkydivingShadowProxy(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static void SetLODOnLandscapProxies(UObject* WorldContextObject, bool bForced, int32 InLODValue);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
	static void SetNextLoadingScreen(UObject* WorldContextObject, const UAthenaLoadingScreenItemDefinition* LoadingScreenDefinition, const bool bCanShowLoadingBar);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static void StreamOutAllBuildingFoundations(const UObject* WorldContextObject);

};

