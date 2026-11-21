// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortVehicleTypes.h"
#include "FortVehicleInterface.generated.h"

class AActor;
class ACustomItemWrapModifier;
class AFortPawn;
class AFortPlayerController;
class AFortPlayerControllerZone;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortPlayerStateZone;
class IFortVehicleInterface;
class UAbilitySystemComponent;
class UAthenaItemWrapDefinition;
class UAthenaVehicleCosmeticItemDefinition;
class UAudioComponent;
class UFXSystemAsset;
class UFortGameplayAbility;
class UFortVehicleConfigs;
class UFortVehicleFuelComponent;
class UFortVehiclePontoonsComponent;
class UFortVehicleSeatComponent;
class UFortVehicleSeatWeaponComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USceneComponent;
class USkeletalMeshComponent;

UENUM()
enum class EVehicleFuelState : uint8
{
	Uninitialized = 0,
	UsingVehicleFuel = 1,
	NotUsingVehicleFuel = 2,
};

UENUM()
enum class EVehicleMovementMode : uint8
{
	OnGround = 0,
	InAir = 1,
	WipeOut = 2,
	MaxCount = 3,
};

UENUM()
enum class EVehicleSessionEndReason : uint8
{
	Invalid = 0,
	NoPassengers = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMountedWeaponFired, UFortVehicleSeatWeaponComponent*, SeatWeaponComponent, int32, SeatIndex, int32, ShotsRemaining);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSleepStateChanged, const bool, bIsAwake);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVehicleOwnerChanged, const TScriptInterface<IFortVehicleInterface>&, Vehicle, const AActor*, NewOwner, const AActor*, PrevOwner);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleHealthChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FVehicleSeatEvent, const TScriptInterface<IFortVehicleInterface>&, Vehicle, AFortPawn*, PlayerPawn, int32, SeatIndex);

USTRUCT()
struct FFortAthenaVehicleSessionTelemetryInfo
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FVehicleCosmeticInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> MostRecentCosmeticSourcePawn;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaVehicleCosmeticItemDefinition> ActiveCosmeticItem;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> PawnAssociatedWithWrap;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaItemWrapDefinition> ActiveCosmeticWrap;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USceneComponent>> SpawnedCosmeticComponents;

	UPROPERTY(Transient)
	TObjectPtr<ACustomItemWrapModifier> ItemWrapModifier;

};

USTRUCT()
struct FVehicleGamepadLiftInputs
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float MoveUpPressTime;

	UPROPERTY(Transient)
	float MoveDownPressTime;

};

USTRUCT(BlueprintType)
struct FVehicleWheelFXSocketInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	FName SocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	FVector Offset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	float Scale;

};

UINTERFACE(MinimalAPI, BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UFortVehicleInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortVehicleInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void AddVehicleActionNamesAndLabels(AFortPlayerPawn* FortPlayerPawn, UPARAM(ref) TArray<FName>& SeatActionNames, UPARAM(ref) TArray<FText>& SeatActionLabels);

	UFUNCTION(BlueprintCallable, Category="Vehicle|Damage")
	virtual bool AllowsDamageFromOtherVehicle() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Mod|Tire")
	virtual void ApplyTireMod(const FGameplayTag& NewTireModTag, const AFortPlayerController* EventInstigator = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Vehicle|Mod")
	virtual void ApplyVehicleMod(const FGameplayTag& ModTag, const AFortPlayerController* EventInstigator = nullptr);

	UFUNCTION(BlueprintCallable, Category="Vehicle|Tire")
	virtual bool AreAnyTiresPopped() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool BlocksBuilding() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DisplayName="Get All Passengers"))
	virtual TArray<AFortPlayerPawn*> BP_GetAllPassengers() const;

	UFUNCTION(BlueprintCallable)
	virtual void CallGunOverheat(UFortVehicleSeatWeaponComponent* WeaponComponent);

	UFUNCTION(BlueprintCallable)
	virtual void CallWeaponFired(UFortVehicleSeatWeaponComponent* WeaponComponent, float Overheat);

	UFUNCTION(BlueprintCallable, Category="Vehicle|Mod")
	virtual bool CanApplyMod(const FGameplayTag& InTag) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool CanContainPlayers() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool CanShootFromSeat(const int32 SeatIndex) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool CanTeleport() const;

	UFUNCTION()
	virtual void ChangeSeat();

	UFUNCTION()
	virtual void ChangeSeatFromIndex(const int32 FromSeatIndex);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool ClientIsDriver() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool ContainsPlayers() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void DestroyVehicle();

	UFUNCTION(BlueprintCallable)
	virtual void DisableTrickCredit(float Duration = 0.100000f);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool DoAltimeterTrace(FHitResult& HitResult, const FName TraceFromSocketName = NAME_None) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Damage")
	virtual bool DoesVehicleDamageFriendlyVehicles() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Damage")
	virtual bool DoesVehicleDamageOtherVehicles() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Damage")
	virtual bool DoesVehicleDamageOwnVehicle() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void EjectAllPlayers();

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool EjectPlayerPawn(const AFortPlayerPawn* InPlayerPawn);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool EjectSeat(const int32 SeatIndex);

	UFUNCTION()
	virtual void ExitActivatedFromSeat(const int32 FromSeatIndex);

	UFUNCTION()
	virtual void ExitPressedFromSeat(const int32 FromSeatIndex);

	UFUNCTION()
	virtual void ExitReleasedFromSeat(const int32 FromSeatIndex);

	UFUNCTION(BlueprintCallable)
	virtual int32 FindSeatIndex(const AFortPlayerPawn* PlayerPawn) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Vehicle")
	virtual void ForceDestroyVehicle(const bool bInPlayInstantDeathEffects = true);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool GasPedalIsDown() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Cosmetics")
	virtual void GatherAndAssignAssembledMeshParts();

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual TArray<AFortPlayerPawn*> GetAllNonDriverPassengers() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(ActorClass="/Script/Engine.Actor", DeterminesOutputType="ActorClass"))
	virtual AActor* GetChildActorByClass(TSubclassOf<AActor> ActorClass) const;

	UFUNCTION(BlueprintCallable)
	virtual FVector GetCrouchingFiringOffsetForSeat(const int32 SeatIndex) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual FString GetDisplayName() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual AFortPlayerPawn* GetDriver() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual FTransform GetExitSocketTransform(const int32 SeatIndex, const int32 SocketIndex) const;

	UFUNCTION(BlueprintCallable, Category="Spawn")
	virtual bool GetForcedToAlwaysSpawn() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual float GetForwardSpeedKmh() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual float GetForwardSpeedPercent() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Fuel")
	virtual float GetFuel() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Fuel")
	virtual float GetFuelCapacity() const;

	UFUNCTION(BlueprintCallable)
	virtual FGameplayTagContainer GetGameplayTags() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetHUDTopSpeed() const;

	UFUNCTION(BlueprintCallable)
	virtual FVector GetIndicatorRelativeOffset() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Tire")
	virtual int32 GetNumTires() const;

	UFUNCTION(BlueprintCallable)
	virtual FVector GetOwnerLocation() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual AFortPlayerPawn* GetPawnAtSeat(const int32 SeatIndex) const;

	UFUNCTION(BlueprintCallable)
	virtual FString GetPlayerFacingName() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual float GetPreviousForwardSpeedKmh() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual float GetSeatSwitchCooldown(const int32 SeatIndex) const;

	UFUNCTION(BlueprintCallable, Category="VehicleWeapon")
	virtual UFortVehicleSeatWeaponComponent* GetSeatWeaponComponent(const int32 SeatIndex) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool GetShootingCone(const int32 SeatIndex, FTransform& OutConeTM, FAthenaVehicleShootingCone& OutCone) const;

	UFUNCTION(BlueprintCallable)
	virtual USkeletalMeshComponent* GetSkeletalMeshComponent() const;

	UFUNCTION(BlueprintCallable)
	virtual FVector GetStandingFiringOffsetForSeat(const int32 SeatIndex) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual float GetThrottle() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual UAbilitySystemComponent* GetVehicleAbilitySystemComponent() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DisplayName="GetVehicleActor"))
	virtual AActor* GetVehicleActorPtr();

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DisplayName="GetActor"))
	virtual AActor* GetVehicleActorPtrConst() const;

	UFUNCTION(BlueprintCallable)
	virtual FName GetVehicleChangeSeatActionName(AFortPlayerPawn* FortPlayerPawn) const;

	UFUNCTION(BlueprintCallable)
	virtual const UFortVehicleConfigs* GetVehicleConfigs() const;

	UFUNCTION(BlueprintCallable)
	virtual AFortPlayerControllerZone* GetVehicleController(AFortPlayerPawn* PlayerPawn = nullptr) const;

	UFUNCTION(BlueprintCallable)
	virtual FName GetVehicleExitActionName(AFortPlayerPawn* FortPlayerPawn) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual FVector GetVehicleForwardVector() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Fuel")
	virtual UFortVehicleFuelComponent* GetVehicleFuelComponent() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Fuel")
	virtual float GetVehicleFuelPercent() const;

	UFUNCTION(BlueprintCallable)
	virtual AFortPlayerStateZone* GetVehiclePlayerState(const AFortPlayerPawn* PlayerPawn = nullptr) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Water")
	virtual UFortVehiclePontoonsComponent* GetVehiclePontoonsComponent() const;

	UFUNCTION(BlueprintCallable)
	virtual TSubclassOf<UFortGameplayAbility> GetVehiclePrimaryFireAbility() const;

	UFUNCTION(BlueprintCallable)
	virtual FName GetVehiclePrimaryFireActionName() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual FVector GetVehicleRightVector() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual FRotator GetVehicleRotation() const;

	UFUNCTION(BlueprintCallable)
	virtual FText GetVehicleSeatChoiceDisplayText(const int32 SeatIndex) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DisplayName="GetVehicleSeatComponent"))
	virtual UFortVehicleSeatComponent* GetVehicleSeatComponentPtr();

	UFUNCTION(BlueprintCallable)
	virtual FName GetVehicleSecondaryFireActionName() const;

	UFUNCTION(BlueprintCallable)
	virtual const FGameplayTagContainer& GetVehicleTags() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual FVector GetVehicleVelocity() const;

	UFUNCTION(BlueprintCallable)
	virtual float GetWaterDepth() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|FX")
	virtual void GetWheelFXSockets(TArray<FVehicleWheelFXSocketInfo>& OutSockets) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool HasDriver() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool HasEverContainedPlayers() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Fuel")
	virtual const bool HasInfiniteFuel() const;

	UFUNCTION(BlueprintCallable)
	virtual bool HasPermissionToAlterBuildings() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool HasSeatCollision(const int32 SeatIndex);

	UFUNCTION(BlueprintCallable, Category="Vehicle|Mod|Tire")
	virtual bool HasTireMod() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Mod")
	virtual bool HasVehicleModApplied(const FGameplayTag& ModTag) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void ImpulseVehicle(const FVector& LinearVelocity, const FVector& AngularVelocity, const bool bRotateLinearVelocity = false, const bool bRotateAngularVelocity = true, const bool bAddToCurrent = false, const FName BoneName = NAME_None);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsAsleep() const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsBoosting() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsDestructible() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsDisabled() const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsDriverMinigameClassRestricted(const AFortPlayerPawn* PlayerPawn) const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsIdling() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsInoperable() const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsInWater() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsOffroad() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsOnDirt() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsOnGrass() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsOnIce() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsOnMud() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsOnRoad() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsOnSnow() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool IsPawnInSeatRequiringTargetingForShooting(const AFortPlayerPawn* PawnToCheck);

	UFUNCTION(BlueprintCallable)
	virtual bool IsTeamRestricted(const AFortPlayerPawnAthena* InteractingPawn) const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsTouchingGround() const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsVehicleAcceleratingWithSpeedThreshold(const float MinSpeed, const float MaxSpeed) const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Fuel")
	virtual bool IsVehicleFuelEmpty() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Fuel")
	virtual bool IsVehicleFuelLow() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void MakeInoperable();

	UFUNCTION(BlueprintCallable)
	virtual void OverrideCurrentWrap(const UAthenaItemWrapDefinition* LoadedWrap);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool PlayerIsTryingToMoveForward() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle|Mod|Tire")
	virtual void RemoveAppliedTireMod();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Vehicle|Mod")
	virtual void RemoveVehicleMod(const FGameplayTag& ModTag);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void ResetTrick();

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool SeatIsTurret(const int32 SeatIndex) const;

	UFUNCTION(BlueprintCallable)
	virtual void SetActorBase(AActor* InActorBase, const int32 SeatIndex = 0);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Vehicle")
	virtual void SetAttachedWheelDataMaterialInstance(const int32 TireIndex, UMaterialInstanceDynamic* NewValue);

	UFUNCTION(BlueprintCallable)
	virtual void SetCurrentFocusedSocketLocation(const int32 SeatIndex);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void SetDestroyOnLastExit(bool bSetTo);

	UFUNCTION(BlueprintCallable, Category="Spawn")
	virtual void SetForcedToAlwaysSpawn(const bool bSetTo);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Vehicle|Fuel")
	virtual void SetFuel(const float NewFuel);

	UFUNCTION(BlueprintCallable)
	virtual void SetHealthPercent(float Percent);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void SetIgnoreAllFallingDamage(bool InIgnoreAllFallingDamage);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void SetIgnoreNextFallingDamage(bool bInIgnoreNextFallingDamage);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void SetShootingCone(const int32 SeatIndex, FAthenaVehicleShootingCone InCone);

	UFUNCTION(BlueprintCallable, Category="Vehicle|FX")
	virtual void SetVehicleFx(const FGameplayTag FxTag, const UFXSystemAsset* FxSystem);

	UFUNCTION(BlueprintCallable, Category="Vehicle|FX")
	virtual void SetVehicleFxMaterial(const FGameplayTag FxTag, const UMaterialInterface* FxMaterial);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool ShowVehicleHealthBarOnPlayerHUD() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Vehicle")
	virtual void TryConstructWithModServer(const FGameplayTagContainer& ForceMods);

	UFUNCTION(BlueprintCallable, Category="Vehicle|Fuel")
	virtual bool UsesVehicleFuelSystem() const;

	UFUNCTION(BlueprintCallable)
	virtual void VehicleGameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool VehicleIsInAir() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual bool VehicleIsInSkyTube() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual void WakeUp();

protected:
	UFUNCTION(BlueprintCallable)
	virtual UMaterialInstanceDynamic* ApplyMaterialAndUseWrapIfPossible(UMaterialInterface* MaterialToUse, int32 SlotIndex, bool bAlwaysCreateMID = true);

	UFUNCTION(BlueprintCallable)
	virtual void NotifyAudioComponentVehicleTriggered(UAudioComponent* AudioComponent, int32 Priority = 1);

};

