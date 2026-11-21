// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/FortPlayerPawnAthena.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "FortVehicleInterface.h"
#include "FortCharacterVehicle.generated.h"

class AActor;
class AController;
class AFortPawn;
class AFortPlayerController;
class AFortPlayerPawn;
class APawn;
class APlayerState;
class UAbilitySystemComponent;
class UAnimInstance;
class UAthenaItemWrapDefinition;
class UFortAbilitySet;
class UFortAbilitySystemComponent;
class UFortCameraMode;
class UFortMontageItemDefinitionBase;
class UFortOstrichAnimInstance;
class UFortOstrichSet;
class UFortSkeletalAudioComponent;
class UFortVehicleSeatComponent;
class UFortVehicleSeatWeaponComponent;
class USkeletalMeshComponent;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AI", "AI", "Movement", "AI", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class AFortCharacterVehicle : public AFortPlayerPawnAthena, public IFortVehicleInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="InteractInterface")
	virtual bool AllowInteractionBetweenFortVolume() const;

	UFUNCTION(BlueprintNativeEvent, Category="Interaction", meta=(DisplayName="CanInteract"))
	bool BP_CanInteract(AController* InController);

	UFUNCTION(BlueprintImplementableEvent)
	FText FormatActionLabelText(const FName& ActionName, const FText& InActionLabel);

	UFUNCTION(BlueprintPure, Category="Gameplay")
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UFUNCTION(BlueprintPure, Category="Mesh")
	USkeletalMeshComponent* GetEmoteMesh() const;

	UFUNCTION(BlueprintPure, Category="Gameplay")
	bool GetHasGunner() const;

	UFUNCTION(BlueprintPure, Category="Gameplay")
	bool GetIsChargedJumpActive() const;

	UFUNCTION(BlueprintPure, Category="Mesh")
	USkeletalMeshComponent* GetMechMesh() const;

	UFUNCTION(BlueprintPure)
	virtual USkeletalMeshComponent* GetSkeletalMeshComponent() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPawnEnterVehicle(AFortPlayerPawn* PlayerPawn, const int32 SeatIdx);

	UFUNCTION(BlueprintNativeEvent)
	void OnPawnExitVehicle(AFortPlayerPawn* PlayerPawn, FName ExitSocketName);

	UFUNCTION()
	void OnRep_OverrideWrap();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnShutdown();

	UFUNCTION(BlueprintCallable, Category="InteractInterface")
	virtual void SetAllowInteractionBetweenFortVolumes(bool bInteractBetweenVolumes);

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCharacterVehicle")
	bool bDestroyBuildingSMActorOnForceExit;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCharacterVehicle")
	bool bDestroyOnLastExit;

	UPROPERTY(Config)
	uint8 VTDMode;

	UPROPERTY(ReplicatedUsing=OnRep_OverrideWrap)
	TSoftObjectPtr<UAthenaItemWrapDefinition> SoftOverrideItemWrap;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaItemWrapDefinition> OverrideItemWrap;

	UPROPERTY()
	FVehicleCosmeticInfo VehicleCosmeticInfo;

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool DoesDamageCauserPreventDamageFromBeingNulled(AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent)
	void GunOverheat(UFortVehicleSeatWeaponComponent* WeaponComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void K2_ApplyCosmeticWrap(const UAthenaItemWrapDefinition* LoadedWrap);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHoldExitStarted(AFortPawn* ExitingPawn, const float ExitDuration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHoldExitStopped(AFortPawn* ExitingPawn);

	UFUNCTION()
	void OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);

	UFUNCTION()
	void OnRep_OverrideAbilitySystemComponent();

	UFUNCTION(BlueprintCallable, Category="Character Vehicle")
	virtual void StopEmoting();

	UFUNCTION(BlueprintImplementableEvent)
	void WeaponFired(UFortVehicleSeatWeaponComponent* WeaponComponent, float Overheat);

	UPROPERTY(Transient)
	bool bForcedToAlwaysSpawn;

	UPROPERTY()
	bool bAllowInteractBetweenFortVolumes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Mesh", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> EmoteMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TArray<TObjectPtr<UFortMontageItemDefinitionBase>> SpecialVehicleEmotes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float SpawnPropOnEmoteScalar;

	UPROPERTY(EditDefaultsOnly, Export, Category="Emote", meta=(EditInline="true"))
	TObjectPtr<UFortSkeletalAudioComponent> EmoteFoleyAudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="FortCharacterVehicle")
	float SeatSwitchCooldown;

	UPROPERTY(BlueprintAssignable)
	FOnMountedWeaponFired OnMountedWeaponFiredEvent;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Export, Category="Vehicle", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UFortVehicleSeatComponent> VehicleSeatComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_OverrideAbilitySystemComponent, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> OverrideAbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category="CharacterVehicle")
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAnimInstance> DriverAnimClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAnimInstance> PassengerAnimClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAnimInstance> DriverAnimLayerOverlayClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAnimInstance> PassengerAnimLayerOverlayClass;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortOstrichSet> OstrichSet;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle", meta=(Categories="Vehicle"))
	FGameplayTagContainer VehicleTags;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySet")
	TObjectPtr<UFortAbilitySet> StartupAbilitySet;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FVehicleHealthChanged OnHealthChanged;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode> CameraModeClass;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode> PassengerCameraModeClass;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float MinBoostDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float MaxBoostDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float FullyChargedJumpTime;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float MinHoldDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float DriverExitLaunchScale;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float PassengerExitLaunchScale;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float ExtraInteractTraceRange;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float MinDistForInteract;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float DashMovementLockDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SeatTransitionDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float ClearMoveIgnoreActorsDelay;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float HealthIndicatorVerticalOffset;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SplashDamageMinPercent;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SplashDamageFalloffRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCharacterVehicle")
	FGameplayTagContainer BlockEntry;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCharacterVehicle")
	FGameplayTagContainer IgnoreDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCharacterVehicle")
	FGameplayTagContainer IgnoreRiderDamageFalloff;

	UPROPERTY(Transient)
	float JumpPressTime;

	UPROPERTY(Transient)
	bool bDidChargeJump;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> LastController;

	UPROPERTY(Transient)
	TObjectPtr<UFortOstrichAnimInstance> OstrichAnimInstance;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnEnteredVehicleAtSeat;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnEnteredVehicleSeat;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnExitedVehicleSeat;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnExitedVehicleFromSeat;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleOwnerChanged OnVehicleOwnerChanged;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnSleepStateChanged OnSleepStateChangedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(Transient)
	FName SpecialActorID;

	UPROPERTY(EditDefaultsOnly, Category="SpecialActor")
	FScalableFloat ReregisterSpecialActorIconDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortCharacterVehicle")
	bool bEnableCurieMaterial;

};

