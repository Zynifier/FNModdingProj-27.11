// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "FortCreativeOptionVariableBase.h"
#include "Player/FortPlayerController.h"
#include "Player/FortPlayerVehicleManager.h"
#include "Vehicles/VehicleSeats.h"
#include "FortPlayerControllerGameplay.generated.h"

class AActor;
class AController;
class AFortAthenaVehicle;
class AFortMinigame;
class AFortPlayerControllerGameplay;
class AFortPlayerState;
class AFortPoiManager;
class UCameraModifier;
class UCreativeQuickbarComponent;
class UDataAsset;
class UFortAbilitySet;
class UFortAmbientAudioController;
class UFortControllerComponent_PhotoMode;
class UFortControllerComponent_SpawnedVehicle;
class UFortControllerComponent_Swinging;
class UFortCreativeOption;
class UFortCreativeOptionsBundle;
class UFortWorldItemDefinition;
class UInputComponent;
class UObject;
enum class EPlayerControllerFollow : uint8;
enum class EVehicleSeats : uint8;

UENUM()
enum class EPlayerControllerFollow : uint8
{
	NextTeammate = 0,
	PreviousTeammate = 1,
	NextPlayer = 2,
	PreviousPlayer = 3,
	SpecialActor = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBalloonMovementChanged, bool, bUsingBalloonMovement);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeFlyChanged, bool, bFlying);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreativeFlyingSpeedChanged, int32, FlyingSpeedLevel, bool, bPlayFX);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeGhostChanged, bool, bIsGhosting);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeHeatmapToggled, bool, bIsHeatmapToggled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeInvulnerableChanged, bool, bIsInvulnerable);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeModeEnabledChanged, bool, bIsEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativePhotoModeActivated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativePreviewScreenshotAccepted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativePreviewScreenshotActiveChanged, bool, bActive);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativePreviewScreenshotCancelled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativePreviewScreenshotReset);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativeQuickbarComponentLoaded);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeQuickbarEnabledChanged, bool, bIsEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeQuickmenuEnabledChanged, bool, bIsEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeSwapPhoneAndHarvestHoldChanged, bool, bIsSwapped);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeUIMetricsDisplayChanged, int32, UIMetricsDisplayIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDBNOCarryPlayerChanged, bool, bCarryingPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGhostModeChanged, AFortPlayerControllerGameplay*, PlayerController, bool, bEnteredGhostMode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHUDElementVisibilityRefreshed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowCreativeGlobalOptions);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWorldInventoryChanged, bool, bIsAllowedToFly);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVehicleFuelAdded, float, NewFuelPercent);

USTRUCT()
struct FGhostModeRepData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bInGhostMode;

	UPROPERTY()
	TObjectPtr<UFortWorldItemDefinition> GhostModeItemDef;

	UPROPERTY(NotReplicated)
	int32 PreviousFocusedSlot;

	UPROPERTY(NotReplicated)
	float TimeExitedGhostMode;

};

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerGameplay : public AFortPlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ActivateCreativePreviewScreenshot(bool bActivate);

	UFUNCTION(BlueprintPure, Category="Team")
	virtual bool CanFollowAPlayer(const bool bOnlyCheckTeammates) const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool CanPlayerCreateInCurrentExperience() const;

	UFUNCTION(Client, Reliable)
	void ClientApplyItemAbilitySet(UFortAbilitySet* AbilitySet, FGuid Guid);

	UFUNCTION(Client, Reliable)
	void ClientCreativeSetUIMetricsDisplayIndex(int32 Index);

	UFUNCTION(Client, Reliable)
	void ClientCreativeStopFly();

	UFUNCTION(Client, Reliable)
	void ClientRemoveItemAbilitySet(UFortAbilitySet* AbilitySet, FGuid Guid);

	UFUNCTION(BlueprintCallable, Category="Controller|Flying")
	void CreativeToggleFly(const bool bEnableOnly = false);

	UFUNCTION(BlueprintCallable, Category="Vehicle Tricks")
	void DisableTrickCredit(float Duration = 0.100000f);

	UFUNCTION(Exec)
	void DisplayNPCNumbers(bool bDisplay);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Controller|Ghost Mode")
	void EndGhostMode();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ExitSpawnedVehicle();

	UFUNCTION(BlueprintCallable, Category="Team")
	virtual bool FollowPlayer(const EPlayerControllerFollow Follow);

	UFUNCTION()
	UFortAmbientAudioController* GetAmbientAudioController() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	AFortMinigame* GetMinigame() const;

	UFUNCTION(BlueprintPure)
	FString GetSettingsFilteredPlayerName(const AFortPlayerState* OtherPlayerState) const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	virtual FString GetSpectatingPlayerName();

	UFUNCTION(BlueprintCallable, Category="Vehicle Tricks")
	FVehicleTrickInfo GetVehicleTrickInfo();

	UFUNCTION()
	void HandlePoiTagContainerTableFinishedReplicating(AFortPoiManager* PoiManager);

	UFUNCTION(BlueprintPure, Category="Controller|Flying")
	virtual bool HasCreativeFlyingInputComponent() const;

	UFUNCTION()
	void InitializeAmbientAudioController();

	UFUNCTION(BlueprintPure, Category="Controller|Flying")
	bool IsAllowedToFly() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsCreativeIslandExporterEnabled() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsCreativeModeEnabled() const;

	UFUNCTION(BlueprintPure, Category="Controller|Creative|Moderator")
	bool IsCreativeModeratorModeActive() const;

	UFUNCTION(BlueprintPure, Category="Controller|Creative|Moderator")
	bool IsCreativeModeratorModeAllowed() const;

	UFUNCTION(BlueprintPure, Category="Controller|Creative|Moderator")
	bool IsCreativeModeratorModeEnabled() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsCreativePhoneAndHarvestHoldSwapped() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativePhotoModeAvailable() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativePreviewScreenshotAvailable() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsCreativeQuickbarActive() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsCreativeQuickbarEnabled() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsCreativeQuickmenuEnabled() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsCreativeThermometerNewUIEnabled() const;

	UFUNCTION(BlueprintPure, Category="Controller|Ghost Mode")
	bool IsInGhostMode() const;

	UFUNCTION(BlueprintPure)
	bool IsUsingHideOtherPlayerNames() const;

	UFUNCTION()
	void OnRep_CreativeQuickbarComponent();

	UFUNCTION()
	void OnRep_IsCreativeQuickbarEnabled(bool bPrevIsEnabled);

	UFUNCTION()
	void OnRep_PoiTagContainerTableID(int16 PreviousPoiTagContainerTableID);

	UFUNCTION()
	void OnRep_UIMetricsDisplayIndex();

	UFUNCTION()
	void OnVerifyAllowedToBeInvulnerable();

	UFUNCTION()
	void OnVerifyAllowedToFly();

	UFUNCTION()
	void OnVerifyAllowModeratorMode();

	UFUNCTION(BlueprintCallable, Category="Creative")
	void PopCreativeReadyCheckInputMode();

	UFUNCTION(BlueprintCallable, Category="Creative")
	void PushCreativeReadyCheckInputMode();

	UFUNCTION(BlueprintCallable, Category="Vehicle Tricks")
	void ResetTrick(AActor* VehicleActor);

	UFUNCTION(Server, Reliable)
	void Server_CreativeModeratorModeSetActive(bool bActive);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAwardVehicleTrickPoints(int32 InPoints, int32 InAirTimeX1000, int32 NumberOfTricks, float AirDistance, float AirHeight);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeSetFlightSpeedIndex(int32 Index);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeSetFlightSprint(bool bSprint);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeSetGhost(bool bWantsToGhost);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeStartFlyDown();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeStartFlyUp();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeStartInvulnerable();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeStopFly();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeStopFlyDown();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeStopFlyUp();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeStopGhost();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreativeStopInvulnerable();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerCreativeToggleFly(const bool bEnableOnly = false);

	UFUNCTION(Server, Reliable)
	void ServerDespawnModeratorBot();

	UFUNCTION(Server, Reliable)
	void ServerSpawnModeratorBot();

	UFUNCTION(BlueprintCallable, Category="Streaming")
	void SetCanStreamBuildingFoundationsIn(bool bCanStream);

	UFUNCTION(BlueprintCallable, Category="Controller|Creative|Moderator")
	void SetCreativeModeratorModeActive(bool bActive);

	UFUNCTION(BlueprintCallable)
	void SetCreativePhotoModeActivateState(bool bIsActive);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	AFortAthenaVehicle* SpawnVehicleAndEnter(TSubclassOf<AFortAthenaVehicle> VehicleClass, const bool bHidePawn = true, const bool bSetPawnAsVehicleOwner = true, const EVehicleSeats SeatToEnter = EVehicleSeats::Driver, const bool bIgnoreDBNOCheck = false, const bool bCheckForNonBlockingSpawnPosition = true, const bool bForceToWaterSurfaceOnSpawn = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Controller|Ghost Mode")
	void StartGhostMode(UFortWorldItemDefinition* ItemProvidingGhostMode);

	UFUNCTION(BlueprintPure, Category="Controller|Flying")
	bool Validation_IsFlyingPossible() const;

	UPROPERTY(EditDefaultsOnly, Category="Controller|Creative|Moderator")
	TSubclassOf<UFortControllerComponent_PhotoMode> CreativeModeratorPhotoModeComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="Controller|Creative|Moderator")
	TObjectPtr<UDataAsset> CreativeModeratorDynamicScene;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAmbientAudioController> FortAmbientAudioController;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PoiTagContainerTableID)
	int16 PoiTagContainerTableID;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FVehicleFuelAdded OnAddFuel;

	UPROPERTY(Transient)
	FTimerHandle VerifyAllowedToFlyTimerHandle;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeGhostChanged OnCreativeGhostEnabledDelegate;

	UPROPERTY(Transient)
	FTimerHandle VerifyAllowModeratorModeTimerHandle;

	UPROPERTY(Transient)
	FTimerHandle VerifyAllowedToBeInvulnerableTimerHandle;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeInvulnerableChanged OnCreativeInvulnerableEnabledDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeHeatmapToggled OnCreativeHeatmapToggledDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeSwapPhoneAndHarvestHoldChanged OnCreativeSwapPhoneAndHarvestHoldChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeFlyingSpeedChanged OnCreativeFlyingSpeedChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeUIMetricsDisplayChanged OnCreativeUIMetricsDisplayChanged;

	UPROPERTY(BlueprintAssignable)
	FOnShowCreativeGlobalOptions OnShowCreativeGlobalOptions;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickbarEnabledChanged OnCreativeQuickbarEnabledChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickbarComponentLoaded OnCreativeQuickbarComponentLoaded;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickmenuEnabledChanged OnCreativeQuickmenuEnabledChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeModeEnabledChanged OnCreativeModeEnabledChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativePreviewScreenshotActiveChanged OnCreativePreviewScreenshotActiveChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativePreviewScreenshotReset OnCreativePreviewScreenshotReset;

	UPROPERTY(BlueprintAssignable)
	FOnCreativePreviewScreenshotAccepted OnCreativePreviewScreenshotAccepted;

	UPROPERTY(BlueprintAssignable)
	FOnCreativePreviewScreenshotReset OnCreativePreviewScreenshotCancelled;

	UPROPERTY(BlueprintAssignable)
	FOnBalloonMovementChanged OnBalloonMovementChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativePhotoModeActivated OnCreativePhotoModeActivated;

	UPROPERTY(BlueprintAssignable)
	FOnCreativePhotoModeActivated OnCreativePhotoModeDeactivated;

	UPROPERTY(ReplicatedUsing=OnRep_UIMetricsDisplayIndex)
	int32 UIMetricsDisplayIndex;

	UPROPERTY()
	int32 FlightSpeedWhenEnteredSprint;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsFlightSprinting)
	bool bIsFlightSprinting;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsCreativeModeEnabled)
	uint8 bIsCreativeModeEnabled : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsCreativeQuickbarEnabled)
	uint8 bIsCreativeQuickbarEnabled : 1;

	UPROPERTY(Transient)
	uint8 bIsCreativeQuickmenuEnabled : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bCreativeMCPProfileIsMatchamkingEnabled : 1;

	UPROPERTY(Transient)
	uint8 bIsCreativeThermometer2Enabled : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsCreativeThermometerNewUIEnabled : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsCreativeIslandExporterEnabled : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsCreativeModeratorModeEnabled : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsCreativeModeratorModeActive)
	uint8 bIsCreativeModeratorModeActive : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerControllerGameplay")
	TArray<TSubclassOf<UCameraModifier>> DefaultCameraModifierClasses;

protected:
	UFUNCTION(Client, Reliable)
	void ClientCreativePhoneCreated();

	UFUNCTION()
	virtual void OnEnterAircraft(AController* EnteringController);

	UFUNCTION()
	virtual void OnExitAircraft(AController* ExitingController);

	UFUNCTION()
	void OnWantedFlightSpeedChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue);

	UFUNCTION()
	void OnWantedToSwapPhoneAndHarvestHoldChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue);

	UFUNCTION()
	void OnWantedUIMetricsDisplayChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue);

	UFUNCTION()
	void OnWantsToBeInvulnerableChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue);

	UFUNCTION()
	void OnWantsToGhostModeChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue);

	UPROPERTY(EditDefaultsOnly, Category="Creative")
	FPrimaryAssetId CreativeMoveToolPrimaryAsset;

	UPROPERTY(EditDefaultsOnly, Category="Creative")
	TSoftClassPtr<UCreativeQuickbarComponent> CreativeQuickbarClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Creative")
	TSubclassOf<UObject> CreativeCameraPreviewScreenshotClass;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CreativeQuickbarComponent, Export, Category="FortPlayerControllerGameplay", meta=(EditInline="true"))
	TObjectPtr<UCreativeQuickbarComponent> CreativeQuickbarComponent;

	UPROPERTY(EditAnywhere, Category="Vehicle Tricks")
	FVehicleTrickInfo VehicleTrickInfo;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_GhostModeRepData)
	FGhostModeRepData GhostModeRepData;

	UPROPERTY(BlueprintAssignable)
	FOnGhostModeChanged OnGhostModeChanged;

	UPROPERTY(BlueprintAssignable)
	FOnDBNOCarryPlayerChanged OnDBNOCarryPlayerChanged;

	UPROPERTY(BlueprintAssignable)
	FOnWorldInventoryChanged OnWorldInventoryChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeFlyChanged OnCreativeFlyChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHUDElementVisibilityRefreshed OnHUDElementVisibilityRefreshedDelegate;

	UPROPERTY(Transient, Replicated)
	uint16 ServerNumNPCs;

	UPROPERTY(Transient, Replicated)
	uint16 ServerMaxNumNPCs;

	UPROPERTY(Transient)
	FTimerHandle AmbientControllerInitializeTimer;

	UPROPERTY(Transient, Replicated)
	bool bDisplayNPCNumbers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerGameplay")
	FScalableFloat FlightSprintMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative")
	TSoftObjectPtr<UFortCreativeOptionsBundle> CreativeOptions;

	UPROPERTY(EditAnywhere, Category="Creative")
	FCreativeOptionVariableBase WantsToGhostMode;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> SocialNotificationInputComponent;

	UPROPERTY(EditAnywhere, Category="Creative")
	FCreativeOptionVariableBase WantsToBeInvulnerable;

	UPROPERTY(EditAnywhere, Category="Creative")
	FCreativeOptionVariableBase WantedFlightSpeed;

	UPROPERTY(EditAnywhere, Category="Creative")
	FCreativeOptionVariableBase WantsToSwapPhoneAndHarvestHold;

	UPROPERTY(EditAnywhere, Category="Creative")
	FCreativeOptionVariableBase WantedUIMetricsDisplay;

	UPROPERTY(Transient)
	TMap<FGuid, FFortAbilitySetHandle> AppliedInGameModifierAbilitySetHandles;

private:
	UFUNCTION()
	void CheckGhostModeItemRemoved(UFortWorldItemDefinition* GhostModeItemDef);

	UFUNCTION()
	void CheckGhostModeItemReplicated();

	UFUNCTION(BlueprintPure)
	int32 GetFlyingModifierIndex();

	UFUNCTION()
	void OnRep_FlyingModifierIndex();

	UFUNCTION()
	void OnRep_GhostModeRepData();

	UFUNCTION()
	void OnRep_IsCreativeModeEnabled();

	UFUNCTION()
	void OnRep_IsCreativeModeratorModeActive();

	UFUNCTION()
	void OnRep_IsFlightSprinting();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRPCSetDisplayNPCNumbers(bool bEnable);

	UPROPERTY(Transient)
	bool bHasSetInitialPoiTags;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeModeFlyingInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeModeInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeGlobalOptionsInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeModePreviewScreenshotInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeModeInGameReadyCheckInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeModeratorModeInputComponent;

	UPROPERTY(EditInstanceOnly, Category="FortPlayerControllerGameplay")
	TArray<float> FlyingModifiers;

	UPROPERTY(EditInstanceOnly, Category="FortPlayerControllerGameplay")
	TArray<float> AdditionalModeratorFlyingModifiers;

	UPROPERTY(ReplicatedUsing=OnRep_FlyingModifierIndex)
	int32 FlyingModifierIndex;

	UPROPERTY()
	TObjectPtr<UFortCreativeOptionsBundle> CreativeOptionsInternal;

	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<FGuid, TObjectPtr<UInputComponent>> AbilityActivatedByInputInputComponentMap;

	UPROPERTY()
	TMap<FGameplayTag, FGameplayAbilitySpecHandle> AbilityActivatedByInputSpecHandleMap;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_SpawnedVehicle> SpawnedVehicleComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Swinging> SwingingComponent;

};

UCLASS(HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerGameplay_Custom : public AFortPlayerControllerGameplay
{
	GENERATED_BODY()

};

