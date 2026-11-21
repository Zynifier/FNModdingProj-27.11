// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "AsyncTaskQueue.h"
#include "Athena/FortVehicleTeleportPortal.h"
#include "Building/BuildingGameplayActor.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "Creative/FortCreativeTypes.h"
#include "FortAthenaCreativePortal.generated.h"

class AActor;
class AFortAthenaVehicle;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
class AFortVolume;
class UCapsuleComponent;
class UPrimitiveComponent;
class UTexture2DDynamic;
class UUserWidget;
enum class EMMSPrivacy : uint8;

USTRUCT()
struct FLocalPortalState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bPortalOpen;

	UPROPERTY()
	FText PortalStatus;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaCreativePortal : public ABuildingGameplayActor, public IVehicleTeleportPortal
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	bool BlueprintDisplayMobileInteractPrompt() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	bool BlueprintUseMobileHighlight() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ClientSaveDisplayChanged(bool bSaving);

	UFUNCTION(BlueprintImplementableEvent)
	void CuratedPortalChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void DisplayNameChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void ErrorStateChanged();

	UFUNCTION(BlueprintPure, Category="Portal")
	const FText& GetCachedEditIslandDataIslandName() const;

	UFUNCTION(BlueprintCallable)
	FVector GetHUDPointerOrigin();

	UFUNCTION(BlueprintPure)
	TArray<FCreativeIslandDescriptionTag> GetIslandDescriptionTags() const;

	UFUNCTION(BlueprintPure)
	AFortVolume* GetLinkedVolume() const;

	UFUNCTION(BlueprintCallable)
	AFortPlayerStateAthena* GetPlayerState();

	UFUNCTION()
	uint8 GetPopulation() const;

	UFUNCTION(BlueprintPure)
	bool IsPortalInteractable() const;

	UFUNCTION(BlueprintImplementableEvent)
	void NotifyTeleportedPlayerPawn(AFortPlayerPawn* PlayerPawn, bool bTeleportedToIslandStart);

	UFUNCTION(BlueprintNativeEvent)
	void NotifyTeleportedVehicle(AActor* VehicleActor);

	UFUNCTION()
	void OnRep_ErrorState();

	UFUNCTION()
	void OnRep_IslandInfo();

	UFUNCTION()
	void OnRep_IsUsingUGC();

	UFUNCTION()
	void OnRep_MaxAvailablePopulationChanged();

	UFUNCTION()
	void OnRep_OwningPlayer();

	UFUNCTION()
	void OnRep_PlayersReady();

	UFUNCTION()
	void OnRep_PopulationChanged();

	UFUNCTION()
	void OnRep_PortalOpen();

	UFUNCTION()
	void OnRep_PublishedPortal();

	UFUNCTION()
	void OnRep_VolumeStatus();

	UFUNCTION(BlueprintImplementableEvent)
	void OverlappingOnBeginPlay(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent)
	void OwningPlayerChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void PopulationChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void PortalOpenChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void ServerOnInteractWithIslandPortal(const AFortPlayerPawn* InteractingPawn);

	UFUNCTION(BlueprintCallable)
	void SetHUDPointerOrigin(FVector NewPointerOrigin);

	UFUNCTION(BlueprintCallable)
	void TeleportPlayer(AFortPlayerPawn* PlayerPawn, const FRotator& TeleportRotation);

	UFUNCTION(BlueprintCallable)
	void TeleportPlayerToLinkedVolume(AFortPlayerPawn* PlayerPawn, bool bUseSpawnTags = false);

	UFUNCTION(BlueprintCallable)
	void TeleportVehicle(AFortAthenaVehicle* Vehicle);

	UFUNCTION()
	void UpdateIslandDisplayName();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="FortAthenaCreativePortal")
	int32 PortalIndex;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="FortAthenaCreativePortal")
	TObjectPtr<AActor> DestinationActor;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Portal")
	FString OverrideImageURL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction", meta=(EditCondition="bAllowInteract"))
	uint8 bForceUpdateInteraction : 1;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnOverlapBegin(AActor* OtherActor);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnOverlapEnd(AActor* OtherActor);

	UFUNCTION()
	void CheckMinigameOnTeleportComplete(AFortPlayerPawn* PlayerPawn, bool bTeleportedToIslandStart);

	UFUNCTION()
	void ClientSaveStateChanged(bool bSaving);

	UFUNCTION()
	void FinishedReadingCloudFiles(const FAsyncTaskResult& Result);

	UFUNCTION(BlueprintPure)
	FText GetCreatorName() const;

	UFUNCTION(BlueprintPure)
	TArray<FString> GetDescriptionTags() const;

	UFUNCTION(BlueprintPure)
	FString GetImageURL() const;

	UFUNCTION(BlueprintPure)
	FString GetIslandID() const;

	UFUNCTION(BlueprintPure)
	bool GetIsPublishedPortal() const;

	UFUNCTION(BlueprintPure)
	FString GetMnemonic() const;

	UFUNCTION(BlueprintPure)
	EMMSPrivacy GetPrivacy() const;

	UFUNCTION(BlueprintPure)
	FText GetTagline() const;

	UFUNCTION(BlueprintPure)
	int32 GetThumbnailHeight() const;

	UFUNCTION(BlueprintPure)
	int32 GetThumbnailWidth() const;

	UFUNCTION(BlueprintPure)
	FText GetVolumeDisplayName() const;

	UFUNCTION(BlueprintPure)
	bool IsPortalOpen() const;

	UFUNCTION(BlueprintCallable)
	void LogIslandTeleportation();

	UFUNCTION()
	void OnClientLoadedStateChanged();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReceivedNewIslandInfo();

	UFUNCTION(BlueprintImplementableEvent)
	void OnThumbnailTextureReady();

	UFUNCTION()
	void OnUGCPaletteChanged(const TArray<FString>& UpdatedLinkCodes);

	UFUNCTION()
	void OnUnloadPlotComplete();

	UFUNCTION()
	void OnUserGeneratedContentRestrictionsChanged(bool bRestrictionEnabled);

	UFUNCTION()
	void OnVolumeManagerUserGeneratedContentRestrictionsChanged(AFortVolume* Volume, bool bRestrictionEnabled);

	UFUNCTION(BlueprintCallable)
	void SetInteractionDisplayWidget(UUserWidget* DisplayWidget);

	UFUNCTION(BlueprintCallable)
	void SetInteractionInteractComponent(UPrimitiveComponent* PrimitiveComponent);

	UFUNCTION(BlueprintCallable)
	void SetOverlapComponent(UCapsuleComponent* InOverlapComponent);

	UFUNCTION(BlueprintPure)
	bool ShouldPausePortalUpdates_Client() const;

	UFUNCTION()
	void StartedPlotLoadForUser(const FAsyncTaskResult& Result);

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaCreativePortal")
	FVector MarkerDetailsPointerOrigin;

	UPROPERTY(Config)
	float MaxInstantTeleportDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaCreativePortal")
	FText LoadingText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaCreativePortal")
	FText UnloadingText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaCreativePortal")
	FText SavingText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaCreativePortal")
	FText TeleportingPlayersText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaCreativePortal")
	FText TeleportingVehiclesText;

	UPROPERTY(EditInstanceOnly, Category="FortAthenaCreativePortal")
	TObjectPtr<AFortVolume> LinkedVolume;

	UPROPERTY(Transient)
	FText SanitizedTitle;

	UPROPERTY(Transient)
	FText SanitizedTagline;

	UPROPERTY(Transient)
	FText SanitizedCreatorName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaCreativePortal", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> InteractComponent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaCreativePortal", meta=(EditInline="true"))
	TObjectPtr<UCapsuleComponent> OverlapComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Portal")
	FScalableFloat TeleportExitDistance;

	UPROPERTY()
	uint8 bTeleportLocationIsIslandStart : 1;

	UPROPERTY(BlueprintReadOnly, Config, Category="Portal")
	bool bDisallowPortalInteract;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaCreativePortal")
	bool bLocalClientLacksPermission;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaCreativePortal")
	TObjectPtr<UTexture2DDynamic> ThumbnailTexture;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortAthenaCreativePortal")
	TWeakObjectPtr<UCapsuleComponent> InteractIconPlacementCapsule;

private:
	UFUNCTION(BlueprintCallable)
	void AttemptCancelMatchmakingToEdit(AFortPlayerController* PlayerToMatchmake);

	UFUNCTION()
	void Client_OnIsValkyrieEditPortalChanged();

	UFUNCTION(BlueprintPure)
	bool IsInErrorStateForRole() const;

	UFUNCTION(BlueprintPure)
	bool IsPortalOpenForRole() const;

	UFUNCTION(BlueprintPure)
	bool IsRunningMatchmakingFlowToEdit(AFortPlayerController* PlayerToMatchmake) const;

	UFUNCTION()
	void OnRep_CachedEditIslandData();

	UFUNCTION()
	void TeleportPlayerForPlotLoadComplete(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable)
	void UpdateThumbnail();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Replicated, Category="FortAthenaCreativePortal", meta=(AllowPrivateAccess="true"))
	bool bReturnToCreativeHub;

	UPROPERTY(BlueprintGetter=IsInErrorStateForRole, Transient, ReplicatedUsing=OnRep_ErrorState, Category="Portal", meta=(AllowPrivateAccess="true"))
	bool bInErrorState;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Portal", meta=(AllowPrivateAccess="true"))
	bool bUserInitiatedLoad;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CachedEditIslandData)
	FCreativeIslandData CachedEditIslandData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IslandInfo)
	FCreativeLoadedLinkData IslandInfo;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_VolumeStatus)
	FText VolumeStatus;

	UPROPERTY(Transient, Replicated)
	FString EditOverridePlaylist;

	UPROPERTY(Transient, Replicated)
	bool bIsPlotLoadTimeOut;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_PopulationChanged, Category="FortAthenaCreativePortal", meta=(AllowPrivateAccess="true"))
	uint8 CurrentPopulation;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_MaxAvailablePopulationChanged, Category="FortAthenaCreativePortal", meta=(AllowPrivateAccess="true"))
	uint8 MaxAvailablePopulation;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_OwningPlayer, Category="Portal", meta=(AllowPrivateAccess="true"))
	FUniqueNetIdRepl OwningPlayer;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayersReady)
	TArray<FUniqueNetIdRepl> PlayersReady;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PublishedPortal)
	bool bIsPublishedPortal;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsUsingUGC)
	bool bIsUsingUGC;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Portal", meta=(AllowPrivateAccess="true"))
	FVector TeleportLocation;

	UPROPERTY(BlueprintGetter=IsPortalOpenForRole, Transient, ReplicatedUsing=OnRep_PortalOpen, Category="Portal", meta=(AllowPrivateAccess="true"))
	bool bPortalOpen;

	UPROPERTY(Transient)
	FLocalPortalState PortalStateForLocalPlayer;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> CachedOwningPlayerState;

};

