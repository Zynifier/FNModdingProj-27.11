// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/HitResult.h"
#include "Engine/TimerHandle.h"
#include "GameplayCueInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "Athena/FortAthenaVehicleInputState.h"
#include "Athena/FortVehicleConfigs.h"
#include "Athena/FortVehicleRuntimeModifiers.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Athena/Vehicle/FortRechargingActionTimer.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "Curie/FortCurieInterface.h"
#include "Environment/WaterSurfaceInfo.h"
#include "FortAutoFireTargetInterface.h"
#include "FortCombatTypes.h"
#include "FortDamageSourceInterface.h"
#include "FortDamageableActorInterface.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "FortInteractInterface.h"
#include "FortReplicationGraphInterface.h"
#include "FortSoundIndicatorInterface.h"
#include "FortVehicleInterface.h"
#include "FortVehicleTypes.h"
#include "Pawns/FortPhysicsPawn.h"
#include "Vehicles/Components/FortVehicleSeatComponent.h"
#include "FortAthenaVehicle.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortAthenaVehicle;
class AFortPawn;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortWaterBodyActor;
class IVehicleSeatInputHookProvider;
class UAnimInstance;
class UAthenaItemWrapDefinition;
class UBuildingEditModeMetadata;
class UFXSystemAsset;
class UFortAbilitySet;
class UFortAbilitySystemComponent;
class UFortAthenaImpulseResponseSet;
class UFortAthenaTrackableAIObjectComponent;
class UFortCameraMode;
class UFortCameraMode_AthenaVehicle;
class UFortDamageSet;
class UFortHealthBarIndicator;
class UFortHealthSet;
class UFortPhysicsVehicleConfigs;
class UFortSkyTubePhysicsComponent;
class UFortSoundIndicatorComponent;
class UFortSoundLibraryComponent;
class UFortVehicleAnimSet;
class UFortVehicleFuelComponent;
class UFortVehicleInteractionOverrideComponent;
class UFortVehicleModCollectedData;
class UFortVehicleMovementSet;
class UFortVehicleNavModifierComponent;
class UFortVehiclePhysicsCollisionDamageComponent;
class UFortVehiclePontoonsComponent;
class UFortVehicleSeatComponent;
class UFortVehicleSeatWeaponComponent;
class UFortVehicleTrickSet;
class UGameplayEffect;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UNiagaraComponent;
class UNiagaraSystem;
class UObject;
class UPrimitiveComponent;
class USkeletalMeshComponentBudgeted;
class USlateBrushAsset;
class USoundAttenuation;
class USoundBase;
class USoundEffectSourcePresetChain;
class USplineComponent;
class UWeaponHitNotifyAudioBank;
enum class ETireStates : uint8;
enum class EVehicleSeats : uint8;

UENUM()
namespace EDebugVehicleFlags
{
	enum Type
	{
		Status = 0,
		Input = 1,
		Controls = 2,
		Shocks = 3,
		Exits = 4,
		Water = 5,
		Wheels = 6,
		Friction = 7,
		AirControl = 8,
		CenterOfMass = 9,
		Gravity = 10,
		Forces = 11,
		Damage = 12,
		Collisions = 13,
		OrientationCorrection = 14,
		BoundarySpline = 15,
		Sleeping = 16,
		Misc = 17,
		LeanBreak = 18,
	};
}

UENUM(BlueprintType)
namespace EVehicleInitialOverlapBehavior
{
	enum Type
	{
		None = 0,
		DontCollideUntilNotOverlapping = 1,
		DestroyWhenVehicleOccupied = 2,
		DestroyIfBackingInto = 3,
	};
}

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentGearChanged, int32, GearIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHandleOutOfHealth, AFortAthenaVehicle*, DeadVehicle, const FGameplayTagContainer&, InTags, AController*, EventInstigator, AActor*, DamageCauser);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRimScrapingChanged, bool, bIsRimScraping, int32, TireIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScrapingSidesOrTopChanged, bool, bIsScraping);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSurfaceTypeVehicleIsOnChanged, TEnumAsByte<EPhysicalSurface>, SurfaceTypeVehicleIsOn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTirePopped, const int32, TireIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTireRepaired, const int32, TireIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVehicleEnteredWaterBody, AFortAthenaVehicle*, Vehicle, AFortWaterBodyActor*, WaterBody);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVehicleExitedWaterBody, AFortAthenaVehicle*, Vehicle, AFortWaterBodyActor*, WaterBody);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVehicleModApplied, const AFortAthenaVehicle*, Vehicle, const FGameplayTag&, ModTag);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVehicleSquadChanged, uint8, OldID, uint8, NewID);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleBoost);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleCosmeticsFinished);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleCosmeticsStarted);

USTRUCT(BlueprintType)
struct FVehicleDamageablePart
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleDamageablePart")
	int32 ConfigIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleDamageablePart")
	int32 BoneIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleDamageablePart")
	int32 ShapeIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleDamageablePart")
	float Health;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleDamageablePart")
	bool bConsideredCriticalHit;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FVehicleDamageablePartHealthChanged, const FVehicleDamageablePartConfig&, PartConfig, const FVehicleDamageablePart&, Part, const bool, bNewlyDisabled, const bool, bNewlyEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleDrift);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVehicleDriverChanged, const AFortPlayerControllerAthena*, NewController, AFortAthenaVehicle*, Vehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVehicleExplode, const AController*, LastDamageInstigator, AFortAthenaVehicle*, Vehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleGainedFuel);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FVehicleHornEvent, const AFortPlayerControllerAthena*, Controller, AFortAthenaVehicle*, Vehicle, const bool, bIsHeld);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleLowFuel);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleOutOfFuel);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVehiclePlayerExit, const AFortPlayerControllerAthena*, Controller, AFortAthenaVehicle*, Vehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleReachedChargeThreshold);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVehicleSetDisabled, bool, bIsDisabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVehicleSpringCompression);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVehicleStartCriticalHealth, const AController*, LastDamageInstigator);

USTRUCT()
struct FIgnoredPawn
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> Pawn;

	UPROPERTY(Transient)
	float Time;


	FORTNITEGAME_API bool operator==(const FIgnoredPawn& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FIgnoredPawn& Value);
};

USTRUCT()
struct FPredictedDestroyedBuilding
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> Building;

	UPROPERTY(Transient)
	float Time;

};

USTRUCT()
struct FPredictionReplicationProxy_AP
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ClientFrameNumber;

	UPROPERTY()
	int32 ServerFrameNumber;

	UPROPERTY()
	TArray<uint8> Data;

};

USTRUCT()
struct FPredictionReplicationProxy_SP
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ServerFrameNumber;

	UPROPERTY()
	TArray<uint8> Data;

};

USTRUCT()
struct FRecentlyHitBuildingActorsData
{
	GENERATED_BODY()

};

USTRUCT()
struct FSMVehicleGear
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Gear", meta=(DisplayName="TopSpeed"))
	FScalableFloat TopSpeedHotfixable;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Gear", meta=(DisplayName="MinSpeed"))
	FScalableFloat MinSpeedHotfixable;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Gear", meta=(DisplayName="PushForce"))
	FScalableFloat PushForceHotfixable;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Gear", meta=(DisplayName="RampTime"))
	FScalableFloat RampTimeHotfixable;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Gear", meta=(DisplayName="SteeringAngleMultiplier"))
	FScalableFloat SteeringAngleMultiplierHotfixable;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Gear", meta=(DisplayName="AutoBrake"))
	FScalableFloat AutoBrakeHotfixable;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Gear", meta=(DisplayName="IgnoreGravity"))
	FScalableFloat IgnoredGravityHotfixable;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FSpringGroundTriangle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpringGroundTriangle")
	FName Socket0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpringGroundTriangle")
	FName Socket1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpringGroundTriangle")
	FName Socket2;

};

USTRUCT()
struct FVehicleImpactBucket
{
	GENERATED_BODY()

};

USTRUCT()
struct FVehicleTargetOrientation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector UpVector;

	UPROPERTY()
	FVector ForwardVector;

	UPROPERTY()
	FVector Location;

};

USTRUCT(BlueprintType)
struct FVehicleToggleablePart
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleToggleablePart")
	int32 ShapeIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleToggleablePart")
	bool bEnabled;

};

UCLASS(PerObjectConfig, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaVehicle : public AFortPhysicsPawn, public IFortInteractInterface, public IFortDamageableActorInterface, public IFortAbilitySystemInterface, public IGameplayCueInterface, public IGameplayTagAssetInterface, public IFortMarkableActorInterface, public IFortVehicleInterface, public IFortAutoFireTargetInterface, public IFortCurieInterface, public IFortSoundIndicatorInterface, public IFortDamageSourceInterface, public IFortReplicationGraphInterface, public IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API bool AddObjectToIgnoreForShocks(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API virtual void AddReasonWhyCantContainPlayers(const FText& TextToAdd);

	UFUNCTION(BlueprintPure, Category="InteractInterface")
	FORTNITEGAME_API virtual bool AllowInteractionBetweenFortVolume() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use IsTouchingGround in VehicleInterface."))
	FORTNITEGAME_API virtual bool AnyWheelsOnGround() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool BlocksBuilding() const;

	UFUNCTION(BlueprintNativeEvent, Category="Interaction", meta=(DisplayName="CanInteract"))
	FORTNITEGAME_API bool BP_CanInteract(AController* InController);

	UFUNCTION(BlueprintNativeEvent, Category="Interaction", meta=(DisplayName="IsSeatEnabled"))
	FORTNITEGAME_API bool BP_IsSeatEnabled(const int32 SeatIdx) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Boost Finished"))
	FORTNITEGAME_API void BP_OnBoostFinished();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Boost Started"))
	FORTNITEGAME_API void BP_OnBoostStarted();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnEmptyFuel"))
	FORTNITEGAME_API void BP_OnEmptyFuel();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnGainedFuel"))
	FORTNITEGAME_API void BP_OnGainedFuel(float NewPercent);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnLowFuel"))
	FORTNITEGAME_API void BP_OnLowFuel();

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle", meta=(DisplayName="On Spring Compression"))
	FORTNITEGAME_API void BP_OnSpringCompression();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Vehicle Cosmetics Finished"))
	FORTNITEGAME_API void BP_OnVehicleCosmeticsFinished();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Vehicle Cosmetics Started"))
	FORTNITEGAME_API void BP_OnVehicleCosmeticsStarted();

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API bool CanAntigravityOnIncline() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool CanContainPlayers() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool CanCorrectOrientation(AFortPawn* FP) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API bool CanDriveOnIncline() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool CanForcePawnToSeat(AFortPlayerPawn* PawnToSeat, const int32 SeatIndex) const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool CanShootFromSeat(const int32 SeatIndex) const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool CanTeleport() const;

	UFUNCTION(Client, Reliable)
	FORTNITEGAME_API void ClientBroadcastAbilityImpactAtLocation(UObject* WorldContextObject, USoundBase* InSound, UObject* InInstigator, const FVector& Velocity, const float Radius, const FName Tag, const bool bSubtractLocalNoise);

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool ClientIsDriver() const;

	UFUNCTION(Client, Reliable)
	FORTNITEGAME_API void ClientTeleportVehicleToLoc(const FVector& TeleportLocation);

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool ContainsPlayers() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API virtual void DemagnetizeFromSkyTube();

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void DestroyVehicle();

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void DisableTrickCredit(float Duration = 0.100000f);

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void EjectAllPlayers();

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool EjectPlayerPawn(const AFortPlayerPawn* InPlayerPawn);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Vehicle", meta=(HidePin="Target"))
	FORTNITEGAME_API static void EnableVehicleStencil(AActor* PotentialVehicle, const bool bEnable, bool bHighlighted = false, int32 StencilValueOverride = -1);

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual int32 FindSeatIndex(const AFortPlayerPawn* PlayerPawn) const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API bool ForceEnterSeat(AFortPlayerPawn* Pawn, const EVehicleSeats Seat, const bool bIgnoreDBNOCheck = false);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API virtual void ForceSeatPawns(TArray<AFortPlayerPawn*> PawnsToSeat);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API virtual bool ForceSeatSinglePawn(AFortPlayerPawn* PawnToSeat, int32 SeatIndex = -1);

	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleGameplayCue_Damage on VehicleInterface."))
	FORTNITEGAME_API virtual void GameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual float GetAccelerationAlpha() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual TArray<AFortPlayerPawn*> GetAllNonDriverPassengers() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual float GetBrakingDelta() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual FVector GetCrouchingFiringOffsetForSeat(const int32 SeatIdx) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual float GetCurrentBrakeForce(float ForwardSpeedKmh) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetCurrentForwardVelocity() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetCurrentFOV() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual int32 GetCurrentGear() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API const FVehicleRuntimeModifiers& GetCurrentRuntimeProperties();

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual float GetDesiredForwardSpeedKmh() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetDesiredForwardVelocity() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetDesiredForwardVelocityDelta() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual FString GetDisplayName() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual AFortPlayerPawn* GetDriver() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetExplosionDelay() const;

	UFUNCTION(BlueprintPure, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual float GetHealth() const;

	UFUNCTION(BlueprintPure, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual FVector GetIndicatorRelativeOffset() const;

	UFUNCTION(BlueprintPure, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetMaxZeroHealthTime() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API int32 GetMinigameClassID() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API uint8 GetMinigameTeamID() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetNormalizedAudioRPM() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual AFortPlayerPawn* GetPawnAtSeat(const int32 SeatIdx) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API float GetPontoonRadius(const int32 PontoonIndex) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API FVector GetPreviousLinearAcceleration() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API FVector GetPreviousLinearVelocity() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual float GetSeatSwitchCooldown(const int32 SeatIndex) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetSelfDestructCleanupDelay() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetSelfDestructDelay() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool GetShootingCone(const int32 SeatIdx, FTransform& OutConeTM, FAthenaVehicleShootingCone& OutCone) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API int32 GetSignificanceLOD() const;

	UFUNCTION(BlueprintPure, Category="Sound Library", meta=(CPP_Default_InComponentTag="()"))
	FORTNITEGAME_API UFortSoundLibraryComponent* GetSoundLibraryComponent(FGameplayTag InComponentTag) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API float GetSpringLengthRatio(int32 SpringIdx) const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual FVector GetStandingFiringOffsetForSeat(const int32 SeatIdx) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API float GetSteeringAngle() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual float GetTotalSpeedKmh() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual FVector GetVehicleVelocity() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API float GetWaterLevel() const;

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void GunOverheat(UFortVehicleSeatWeaponComponent* WeaponComponent);

	UFUNCTION()
	FORTNITEGAME_API void HandleFuelChanged(float NewFuelPercent, float OldFuelPercent);

	UFUNCTION()
	FORTNITEGAME_API void HandleLowFuel();

	UFUNCTION()
	FORTNITEGAME_API virtual void HandleOutOfFuel();

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API bool HasConstraints() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool HasDriver() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool HasEverContainedPlayers() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool HasExploded() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual bool HasTraction() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsAirControlling() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool IsAsleep() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsBraking() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API bool IsCameraControlledRotation() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsCorrectingOrientation() const;

	UFUNCTION(BlueprintPure, Category="Vehicle|Destruction")
	FORTNITEGAME_API virtual bool IsCriticalHealth() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsDriverMinigameTeamRestricted(const AFortPlayerPawn* PlayerPawn) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API bool IsDriverSplitScreen() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsEnforcingMinigameClassRestriction() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsEnforcingTeamRestriction() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsHonking() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool IsInAir() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsInReverseGear() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleIsInSkyTube in VehicleInterface."))
	FORTNITEGAME_API virtual bool IsInSkyTube() const;

	UFUNCTION(BlueprintPure, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool IsInWater() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual bool IsInWaterBody() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API bool IsJumping() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsMagnetizedForSkyTubes() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsOnFire() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual bool IsOverlappingWaterBody() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsPendingDeath() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsScrapingSidesOrTop() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsSlowEnoughToInteract() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool IsSprinting() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsSquadRestricted(const AFortPlayerPawnAthena* InteractingPawn) const;

	UFUNCTION()
	FORTNITEGAME_API virtual float ModifyIncomingDamage(float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void MulticastVehicleInputStateUnreliable(FFortAthenaVehicleInputStateUnreliable InputState, AFortPlayerPawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnAbilityImpactAtLocation(UObject* WorldContextObject, USoundBase* InSound, UObject* InInstigator, const FVector& Velocity, const float Radius, const FName Tag, const bool bSubtractLocalNoise);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnCollisionHitDamageEffects(float DamageTaken);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnCollisionHitEffects(const FVector& HitLocation, const FVector& HitNormalImpulse, const FVector& HitFrictionImpulse, const FVector& HitNormal, AActor* HitActor, EPhysicalSurface HitSurfaceType);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnDamaged(float Damage, const FGameplayTagContainer& DamageTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnDamagePlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnDeathPlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void OnDisabledChanged(bool bDisabled);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnEnteredWaterBody(AFortWaterBodyActor* WaterBody);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	FORTNITEGAME_API void OnEnteredWaterVolume(const FVector& WaterSurfacePoint);

	UFUNCTION()
	FORTNITEGAME_API void OnEnterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnExitedWaterBody(AFortWaterBodyActor* WaterBody);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	FORTNITEGAME_API void OnExitedWaterVolume(const FVector& WaterSurfacePoint);

	UFUNCTION()
	FORTNITEGAME_API void OnExitOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnFireStart();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnFireStop();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnFuelTouchedFire(AActor* SourceActor);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnGearShiftDown();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnGearShiftUp();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnHealed(float Heal, const FGameplayTagContainer& HealTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* HealCauser);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnHitBuildingActor(const FHitResult& HitResult, const float ModifiedDamageToApply);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnHoldExitStarted(AFortPawn* ExitingPawn, const float ExitDuration);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnHoldExitStopped(AFortPawn* ExitingPawn);

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	FORTNITEGAME_API void OnHonk();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnImpactDamageApplied(const float Damage, const FVector ImpactNormal);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnPawnEnterVehicle(AFortPlayerPawn* PlayerPawn, const int32 SeatIdx);

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void OnPawnExitVehicle(AFortPlayerPawn* PlayerPawn, FName ExitSocketName);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_NetPrediction_AP();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_NetPrediction_SP();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_OverrideWrap();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnSetSeatCollision(const int32 SeatIndex, bool bOccupied);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Vehicle")
	FORTNITEGAME_API void OnSignificanceLODChanged(int32 NewLOD);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnSleepStateChanged(const bool bAwake);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnStartFire(uint8 FireModeNum);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnStartTick();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnStopTick();

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void OnWaterTooDeep();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void OverrideCurrentWrap(const UAthenaItemWrapDefinition* LoadedWrap);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Vehicle")
	FORTNITEGAME_API void OverridePontoonRadiusOnServer(int32 PontoonIndex, float NewRadius);

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void PawnHitByVehicle(AFortPawn* Pawn, const FVector& ImpactPoint, const FVector& ImpactNormal, const FVector LaunchVector);

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool PlayerIsTryingToReverse() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool RearLateralFrictionHasReachedMax() const;

	UFUNCTION()
	FORTNITEGAME_API void RefreshVehicleClientSettings();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void RemoveIgnoredPawnForDamage(const AFortPawn* IgnoredPawn);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API bool RemoveObjectToIgnoreForShocks(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API virtual bool RemoveReasonWhyCantContainPlayers(const FText& TextToRemove);

	UFUNCTION(Client, Reliable)
	FORTNITEGAME_API void RequestReliablePhysicsUpdate();

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void ResetTrick();

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool SeatIsTurret(const int32 SeatIndex) const;

	UFUNCTION()
	FORTNITEGAME_API virtual bool ServerOnAttemptInteract(const FInteractionType& InteractType);

	UFUNCTION(Server, Unreliable)
	FORTNITEGAME_API void ServerReceiveInputCmd(int32 ClientFrameNumber, const TArray<uint8>& Data);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void ServerSetDestructionInfo(const float InSelfDestructTime, const float InMaxTimeZeroHealth, const float InMaxTimeSelfDestructCleanup, const float InMaxTimeExplosion);

	UFUNCTION(Server, Reliable, Category="Vehicle")
	FORTNITEGAME_API void ServerSetIgnoreAllFallingDamage(bool InIgnoreAllFallingDamage);

	UFUNCTION(Server, Reliable, Category="Vehicle")
	FORTNITEGAME_API void ServerSetIgnoreNextFallingDamage(bool InIgnoreNextFallingDamage);

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerStartFire(uint8 FireModeNum);

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerUsingRiftPortal(AActor* RiftPortal);

	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void SetActorBase(AActor* InActorBase, const int32 SeatIndex = 0);

	UFUNCTION(BlueprintCallable, Category="InteractInterface")
	FORTNITEGAME_API virtual void SetAllowInteractionBetweenFortVolumes(bool bInteractBetweenVolumes);

	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void SetCurrentFocusedSocketLocation(const int32 SeatIndex);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void SetEnforceMinigameClassRestriction(const bool bNewEnforceClassRestriction);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void SetEnforceTeamRestriction(const bool bNewEnforceTeamRestriction);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void SetForceInfiniteFuel(const bool bNewForceInfiniteFuel);

	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void SetHealthPercent(float Percent);

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void SetIgnoreAllFallingDamage(bool InIgnoreAllFallingDamage);

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void SetIgnoreNextFallingDamage(bool bInIgnoreNextFallingDamage);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetImpulseResponseMultiplier(const float Multiplier);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetImpulseResponseZBias(const float ZBias);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void SetMinigameClassID(const int32 NewClassID);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void SetMinigameTeamID(const uint8 NewTeamID);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void SetNormalizedAudioRPM(const float NewValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void SetOnFire(const bool bNewValue);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void SetPropDestructionParams(TArray<TSubclassOf<ABuildingActor>> InBuildingPropClassesVehicleCanDestroy, TArray<TSubclassOf<ABuildingActor>> InBuildingPropClassesVehicleCannotDestroyWhenBoosting, TArray<UBuildingEditModeMetadata*> InWallsVehicleCanDestroy, TArray<UBuildingEditModeMetadata*> InWallsVehicleCannotDestroyWhenBoosting);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetShouldSleepAtSpawn(const bool bNewValue);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API virtual void SetSpringEnabled(const int32 SpringIndex, const bool bEnabled);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetStaticPhysics(const bool bStatic);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void SetSupportCosmeticWrap(const bool bNewSupportCosmeticWrap);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API void SetUnoccupiedAutoDestroy(float UnoccupiedTime);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API virtual void SetUseGravity(const bool bInUseGravity);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Vehicle", meta=(HidePin="Target"))
	FORTNITEGAME_API static bool SetVehicleStencilHighlighted(AActor* PotentialVehicle, bool bHighlighted, int32 StencilValueOverride = -1);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void SetWaterDestructionDelay(const float NewWaterDestructionDelay);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	FORTNITEGAME_API void UpdateClientWithVehicleTestInput(FVector LinearVelocity, FVector AngularVelocity);

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool VehicleIsInSkyTube() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void WakeUp();

	UFUNCTION()
	FORTNITEGAME_API void WakeUpOnGroundDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void WeaponFired(UFortVehicleSeatWeaponComponent* WeaponComponent, float Overheat);

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API virtual bool WheelsOnGround() const;

	UPROPERTY(ReplicatedUsing=OnRep_NetPrediction_AP)
	FPredictionReplicationProxy_AP NetPredictionProxy_AP;

	UPROPERTY(ReplicatedUsing=OnRep_NetPrediction_SP)
	FPredictionReplicationProxy_SP NetPredictionProxy_SP;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnScrapingSidesOrTopChanged OnScrapingSidesOrTopChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnCurrentGearChanged OnCurrentGearChangedDelegate;

	UPROPERTY(ReplicatedUsing=OnRep_OverrideWrap)
	TSoftObjectPtr<UAthenaItemWrapDefinition> SoftOverrideItemWrap;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaItemWrapDefinition> OverrideItemWrap;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSpringCompression OnSpringCompressionDelegate;

	UPROPERTY(Transient)
	TSet<TObjectPtr<AFortPlayerPawnAthena>> PlayersBasedOnVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaVehicle")
	FWaterSurfaceInfo WaterSurfaceDataCache;

	UPROPERTY(EditAnywhere, Transient, Category="FortAthenaVehicle")
	TEnumAsByte<EVehicleInitialOverlapBehavior::Type> InitialOverlapBehavior;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	uint8 bDisableUpdateForcedDebugInput : 1;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	uint8 bDisableUpdateAutoRun : 1;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	uint8 bDisableUpdateHonk : 1;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	uint8 bDisableUpdateIgnoredBuildingActors : 1;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	uint8 bDisableUpdateIngoredPawnsForDamage : 1;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	uint8 bDisableUpdateSafeTeleport : 1;

	UPROPERTY(Transient)
	uint8 bUseForceHeading : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaVehicle")
	uint8 bDestroyOnLastExit : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaVehicle")
	uint8 bShowDamageNumbers : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaVehicle")
	uint8 bShowDamageNumbersAtImpactLocation : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaVehicle")
	uint8 bPlayDamageAudio : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaVehicle")
	uint8 bShowVehicleHealthBarOnPlayerHUD : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaVehicle")
	uint8 bDestroyBuildingSMActorOnForceExit : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintSetter=SetIgnoreAllFallingDamage, Transient, Category="Vehicle|Fall Damage")
	uint8 bIgnoreAllFallingDamage : 1;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Vehicle|Fall Damage")
	uint8 bIgnoreNextFallingDamage : 1;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Vehicle|Fall Damage")
	uint8 bShouldClearFallDamageImmunityForPawnsOnExit : 1;

	UPROPERTY(VisibleAnywhere, Transient, Category="Vehicle")
	uint8 bIsBraking : 1;

	UPROPERTY(Transient)
	uint8 bPlayedDying : 1;

	UPROPERTY(Transient)
	uint8 bForceDeath : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bPlayInstantDeathEffects : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bHasDriver : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bHasPassengers : 1;

	UPROPERTY()
	uint8 bCanSleepWhileNotTouchingAnything : 1;

	UPROPERTY()
	uint8 bIsTouchingAnything : 1;

	UPROPERTY()
	uint8 bIsInWater : 1;

	UPROPERTY()
	uint8 bIsInWaterBody : 1;

	UPROPERTY()
	uint8 bIsOverlappingWaterBody : 1;

	UPROPERTY()
	uint8 bIsFullyInWaterBody : 1;

	UPROPERTY()
	uint8 bCanDriveOnIncline : 1;

	UPROPERTY()
	uint8 bCanCoastOnIncline : 1;

	UPROPERTY()
	uint8 bWheelsOnGround : 1;

	UPROPERTY()
	uint8 bAnyWheelsOnGround : 1;

	UPROPERTY()
	uint8 bIsTouchingDrivableGround : 1;

	UPROPERTY()
	uint8 bIsTouchingGroundWithoutWheels : 1;

	UPROPERTY()
	uint8 bPossiblyTouchingTop : 1;

	UPROPERTY()
	uint8 bUseGravity : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Tricks")
	uint8 bTricksEnabled : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FX")
	float WaterEffectsVehicleMaxSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FX")
	TObjectPtr<UNiagaraSystem> WaterEffectsAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FX", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> WaterEffectsComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameplayTags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(Transient)
	TSet<FIgnoredPawn> PawnsToIgnoreForDamge;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPawn>> PawnsToIgnoreForCollision;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPawn>> IgnoredPawnsPendingTeleport;

	UPROPERTY(Transient)
	float LastPropImpactImpulseTime;

	UPROPERTY(Transient)
	TArray<FPredictedDestroyedBuilding> PredictedDestroyedBuildings;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UBuildingEditModeMetadata>> WallsVehicleCanDestroy;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UBuildingEditModeMetadata>> WallsVehicleCannotDestroyWhenBoosting;

	UPROPERTY(Transient)
	TArray<TSubclassOf<ABuildingActor>> BuildingPropClassesVehicleCanDestroy;

	UPROPERTY(Transient)
	TArray<TSubclassOf<ABuildingActor>> BuildingPropClassesVehicleCannotDestroyWhenBoosting;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IVehicleSeatInputHookProvider>> SeatInputProviders;

	UPROPERTY(Replicated)
	FFortAthenaVehicleInputState EmptyDriverInputState;

	UPROPERTY()
	FVector AverageSpringNormal;

	UPROPERTY(Transient)
	float TopSpeedCurrentMultiplier;

	UPROPERTY(Transient)
	float PushForceCurrentMultiplier;

	UPROPERTY(Transient)
	FVector2D LastStickInput;

	UPROPERTY()
	float SteeringAngle;

	UPROPERTY(Transient)
	float FrontLateralFrictionRuntimeMultiplier;

	UPROPERTY(Transient)
	float RearLateralFrictionRuntimeMultiplier;

	UPROPERTY()
	FVector LocalRearFrictionPt;

	UPROPERTY()
	FVector LocalFrontFrictionPt;

	UPROPERTY()
	float FrontMassRatio;

	UPROPERTY()
	float RearMassRatio;

	UPROPERTY()
	float TotalBrakingDelta;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageSettings")
	TEnumAsByte<EPhysicalSurface> PrimarySurfaceType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageSettings")
	TEnumAsByte<EFortBaseWeaponDamage::Type> WeaponResponseType;

	UPROPERTY(Config)
	uint8 VTDMode;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaVehicle")
	int32 ForcedMaterialVariantIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fuel")
	FFortRechargingActionTimer FuelCharge;

	UPROPERTY(BlueprintAssignable, Category="Fuel")
	FVehicleReachedChargeThreshold OnRechargeableFuelAboveThreshold;

	UPROPERTY(BlueprintAssignable, Category="Fuel")
	FVehicleReachedChargeThreshold OnRechargeableFuelBelowThreshold;

	UPROPERTY(BlueprintAssignable, Category="Fuel")
	FVehicleReachedChargeThreshold OnOutOfRechargeableFuel;

	UPROPERTY(BlueprintAssignable, Category="Fuel")
	FVehicleReachedChargeThreshold OnNotOutOfRechargeableFuel;

	UPROPERTY(BlueprintAssignable)
	FOnMountedWeaponFired OnMountedWeaponFiredEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="FortAthenaVehicle")
	float SeatSwitchCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle", meta=(Categories="Vehicle"))
	FGameplayTagContainer VehicleTags;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TArray<FVehicleSpringInfo> Springs;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FSpringGroundTriangle GroundTriangle;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TArray<FSMVehicleGear> Gears;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TArray<FSMVehicleGear> SprintGears;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TArray<FSMVehicleGear> ReverseGears;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float ForwardDrivingAntiGravityScaler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Camera")
	float CameraSpaceForwardDistanceOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraAssistStrength;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraAssistRampUp;

	UPROPERTY(EditAnywhere, Category="Camera | Auto Center")
	bool bAllowAutoCamera;

	UPROPERTY(EditAnywhere, Category="Camera | Auto Center", meta=(EditCondition="bAllowAutoCamera"))
	float TimeToAutoCamera;

	UPROPERTY(EditAnywhere, Category="Camera | Auto Center", meta=(EditCondition="bAllowAutoCamera"))
	float MinSpeedForAutoCamera;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraAssistBaseHeight;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraAssistUpHillScaler;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraAssistSteerScaler;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraAssistForwardScale;

	UPROPERTY(EditAnywhere, Category="Camera")
	float AngleDegreesThresholdFromCurrentCameraToTarget;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Camera")
	float CameraFOVOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaVehicle")
	TSubclassOf<UFortCameraMode> TetheredCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaVehicle")
	TSubclassOf<UGameplayEffect> PlayerCollisionGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortAthenaVehicle", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> OverlapComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortAthenaVehicle", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> WaterOverlapComponent;

	UPROPERTY(EditAnywhere, Category="Damage")
	float VehicleMinHorSpeedToDamage;

	UPROPERTY(EditAnywhere, Category="Damage")
	float VehicleMaxHorSpeedToDamage;

	UPROPERTY(EditAnywhere, Category="Damage")
	float VehicleMinHorSpeedDamage;

	UPROPERTY(EditAnywhere, Category="Damage")
	float VehicleMaxHorSpeedDamage;

	UPROPERTY(EditAnywhere, Category="AI")
	float TargetingZOffset;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float BrakeAboveTopSpeedDelta;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float TimeToIdleBrake;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float DragCoefficient;

	UPROPERTY()
	float PrimaryCameraPitchConstraint;

	UPROPERTY()
	float PrimaryCameraYawConstraint;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float CachedSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	FName MainBodyCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	FVector TestInitialLinearVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	FVector TestInitialAngularVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle")
	FHitResult LookAheadHit;

	UPROPERTY(EditDefaultsOnly, Category="Tricks")
	TObjectPtr<UFortVehicleTrickSet> TrickSet;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName PushForceSocket;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName FrontWheelsSocket;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName RearWheelSockets;

	UPROPERTY(EditDefaultsOnly, Category="HitNotifies")
	TObjectPtr<UWeaponHitNotifyAudioBank> DefaultHitNotifyAudioBank;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Sound Library", meta=(EditInline="true"))
	TObjectPtr<UFortSoundLibraryComponent> SoundLibraryComponent;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FOnHandleOutOfHealth OnHandleOutOfHealthDelegate;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FVehicleHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="Collision")
	FVehicleDamageablePartHealthChanged OnDamageablePartHealthChanged;

	UPROPERTY(EditDefaultsOnly, Category="Collision")
	FName BulletCollisionComponentTag;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	TSubclassOf<UGameplayEffect> GEDamagePassengersOnDeath;

	UPROPERTY(BlueprintAssignable, Category="Squad")
	FOnVehicleSquadChanged OnVehicleSquadChanged;

	UPROPERTY(BlueprintAssignable, Category="SurfaceType")
	FOnSurfaceTypeVehicleIsOnChanged OnSurfaceTypeVehicleIsOnChangedDelegate;

	UPROPERTY(EditAnywhere, Transient, Category="FortAthenaVehicle")
	float LifespanAfterDeath;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Damage")
	float LastDamagedTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle")
	TArray<FSeatTransitionMontage> SeatTransitions;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleEnteredWaterBody OnVehicleEnteredWaterBody;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleExitedWaterBody OnVehicleExitedWaterBody;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FGameplayTag AlwaysDamageVehiclesWithTag;

	UPROPERTY(BlueprintAssignable)
	FOnVehicleModApplied OnModAppliedOnClientDelegate;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleBoost OnBoostStartedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleBoost OnBoostFinishedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleDrift OnDriftStartedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleDrift OnDriftFinishedDelegate;

	UPROPERTY(BlueprintAssignable)
	FVehicleOutOfFuel OnOutOfFuelDelegate;

	UPROPERTY(BlueprintAssignable)
	FVehicleGainedFuel OnGainedFuelDelegate;

	UPROPERTY(BlueprintAssignable)
	FVehicleLowFuel OnLowFuelDelegate;

	UPROPERTY(BlueprintAssignable, Category="Vehicle|Destruction")
	FVehicleStartCriticalHealth OnStartCriticalHealth;

	UPROPERTY(BlueprintAssignable, Category="Vehicle|Destruction")
	FVehicleExplode OnExplode;

	UPROPERTY(BlueprintAssignable)
	FVehicleSetDisabled OnDisabledChangedDelegate;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Vehicle|Fall Damage", meta=(DisplayAfter="bShouldClearFallDamageImmunityForPawnsOnExit", EditCondition="bShouldClearFallDamageImmunityForPawnsOnExit"))
	FGameplayTagQuery ExceptionsForClearFallDamageImmunityOnExitTagQuery;

	UPROPERTY(ReplicatedUsing=OnRep_ActiveGameplayEffectGrantedTagsToForceRemove)
	FGameplayTagContainer ActiveGameplayEffectGrantedTagsToForceRemove;

	UPROPERTY(BlueprintAssignable, Category="Vehicle|Cosmetics")
	FVehicleCosmeticsStarted VehicleCosmeticsStartedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Vehicle|Cosmetics")
	FVehicleCosmeticsFinished VehicleCosmeticsFinishedDelegate;

	FORTNITEGAME_API virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	FORTNITEGAME_API virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual UMaterialInstanceDynamic* ApplyMaterialAndUseWrapIfPossible(UMaterialInterface* MaterialToUse, int32 SlotIndex, bool bAlwaysCreateMID = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API virtual void BreakDamageablePart(const FName& ShapeName);

	UFUNCTION(NetMulticast, Reliable)
	FORTNITEGAME_API void BroadcastResetWaterIdleTimeEmpty();

	UFUNCTION(Client, Reliable)
	FORTNITEGAME_API void ClientRefreshVehicleClientSettings();

	UFUNCTION(Client, Reliable)
	FORTNITEGAME_API void DebugDrawImpactBucket(FVector Location, FVector ImpactVector, FColor Color);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void DestroyAllDamageableParts();

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual bool EjectSeat(const int32 SeatIndex);

	UFUNCTION()
	FORTNITEGAME_API virtual void GamepadUseOrExitPressedFromSeat(const int32 FromSeatIndex);

	UFUNCTION()
	FORTNITEGAME_API virtual void GamepadUseOrExitReleasedFromSeat(const int32 FromSeatIndex);

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool GetTireState(int32 TireIndex) const;

	UFUNCTION(BlueprintPure, Category="Fuel")
	FORTNITEGAME_API bool IsOutOfRechargeableFuel() const;

	UFUNCTION(BlueprintPure, Category="Fuel")
	FORTNITEGAME_API bool IsRechargeableFuelBelowThreshold() const;

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void K2_ApplyCosmeticWrap(const UAthenaItemWrapDefinition* LoadedWrap);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnEnteredRoad();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnEnterLandscape();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnExitLandscape();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnExitRoad();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnHandleImpulsed(const FVector& ImpulsePoint, const FVector& ImpulseValue, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* ImpulseCauser);

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	FORTNITEGAME_API void OnIsSprintingChanged();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnModAppliedOnClient(const FGameplayTag& ModTag);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void OnPoppedTire(const int32 TireIndex, const bool bFakeTire);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnPrimitiveComponentSleep(UPrimitiveComponent* WakingComponent, FName BoneName);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnPrimitiveComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_DamageableParts(const TArray<FVehicleDamageablePart>& PrevDamageableParts);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_IgnoredBuildingActors();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_SurfaceTypeVehicleOn(EPhysicalSurface PreviousSurfaceOn);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ToggleableParts(const TArray<FVehicleToggleablePart>& PrevToggleableParts);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_VehicleAttributes();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void OnRepairedTire(const int32 TireIndex, const bool bFakeTire);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnRimScrapeDamage(int32 TireIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle|FX")
	FORTNITEGAME_API void OnSetVehicleFx(const FGameplayTag FxTag, const UFXSystemAsset* FxSystem);

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle|FX")
	FORTNITEGAME_API void OnSetVehicleFxMaterial(const FGameplayTag FxTag, const UMaterialInterface* FxMaterial);

	UFUNCTION(BlueprintImplementableEvent, Category="SurfaceType")
	FORTNITEGAME_API void OnSurfaceTypeVehicleIsOnChanged(EPhysicalSurface SurfaceTypeVehicleIsOn);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void RepairAllDamageableParts(const float NewHealthPercent = 1.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API virtual void RepairDamageablePart(const FName& ShapeName, const float NewHealthPercent = 1.000000f);

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerSetMoveStickAcceleratesVehicles(const bool bNewValue);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	FORTNITEGAME_API virtual void SetDyingPhysics();

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use VehicleInterface."))
	FORTNITEGAME_API virtual void SetShootingCone(const int32 SeatIdx, FAthenaVehicleShootingCone InCone);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetShouldDealDamage(const bool bNewValue);

	UFUNCTION()
	FORTNITEGAME_API virtual void UseOrExitPressedFromSeat(const int32 FromSeatIndex);

	UFUNCTION()
	FORTNITEGAME_API virtual void UseOrExitReleasedFromSeat(const int32 FromSeatIndex);

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnSleepStateChanged OnSleepStateChangedDelegate;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> BoundsXYSplineComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> SkeletalMesh;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaVehicle")
	uint8 bAllowInteractBetweenFortVolumes : 1;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	uint8 bCanPassengerPawnsTakeDamage : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bServerIsInUndergroundVolume : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaVehicle")
	uint8 bEnableCurieMaterial : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bEnforceTeamRestrictionForMiniGame : 1;

	UPROPERTY(EditDefaultsOnly, Transient, Replicated, Category="FortAthenaVehicle")
	uint8 bEnforceMinigameClassRestriction : 1;

	UPROPERTY(EditDefaultsOnly, Transient, Replicated, Category="FortAthenaVehicle")
	int32 MinigameClassID;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnEnteredVehicleAtSeat;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnEnteredVehicleSeat;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnExitedVehicleSeat;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnExitedVehicleFromSeat;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleSeatEvent OnPawnFinishEnteringVehicle;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FVehicleHornEvent OnVehicleHornEvent;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleOwnerChanged OnVehicleOwnerChanged;

	UPROPERTY(Transient)
	uint8 bWaitingForSleep : 1;

	UPROPERTY()
	uint8 bAttemptAsyncOrientationCorrection : 1;

	UPROPERTY()
	uint8 bIsAsyncCorrectingOrientation : 1;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle Navigation")
	uint8 bAlwaysCreateNavComponent : 1;

	UPROPERTY(Transient)
	float FireDamageTickTimer;

	UPROPERTY(Transient)
	float CurrentFOV;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FGameplayTagContainer FireEnvDamageTags;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FGameplayTagContainer PawnIgnoreBumpTags;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TObjectPtr<USlateBrushAsset> DriverReticleBrush;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_SurfaceTypeVehicleOn, Category="Surface Type")
	TEnumAsByte<EPhysicalSurface> SurfaceTypeVehicleOn;

	UPROPERTY(Transient)
	float WaterLevel;

	UPROPERTY(Transient)
	int32 WaterOverlapCount;

	UPROPERTY(Transient, Replicated)
	FVehicleRuntimeModifiers RuntimeModifiedProperties;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingActor>> LocallyIgnoredBuildingActors;

	UPROPERTY(Transient)
	FVector PreviousBuildingQueryPosition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Damage")
	float ImpulseResponseMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Damage")
	float ImpulseResponseZBias;

	UPROPERTY(Transient)
	FTimerHandle WaterSubmergedTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category="Emote Audio")
	TObjectPtr<USoundEffectSourcePresetChain> EmoteAudioSourcePresetChain;

	UPROPERTY(EditDefaultsOnly, Category="Emote Audio")
	TObjectPtr<USoundAttenuation> EmoteAudioAttenuation;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySet")
	TObjectPtr<UFortAbilitySet> StartupAbilitySet;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Export, Category="Vehicle", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UFortVehicleSeatComponent> VehicleSeatComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleInteractionOverrideComponent> VehicleInteractionOverrideComponent;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Export, Category="Vehicle", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UFortSkyTubePhysicsComponent> SkyTubePhysicsComponent;

	UPROPERTY(EditDefaultsOnly, Transient, Export, Category="FortAthenaVehicle", meta=(EditInline="true"))
	TObjectPtr<UFortVehiclePontoonsComponent> PontoonsComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaTrackableAIObjectComponent> TrackableAIObjectComponent;

	UPROPERTY()
	TArray<FAthenaCarPlayerSlot> PlayerSlots_DEPRECATED;

	UPROPERTY()
	TArray<FAthenaCarPlayerSlot> PlayerSlotsBackup;

	UPROPERTY(Transient)
	TArray<FAthenaCarPlayerSlotUnreplicated> PlayerSlotsUnreplicated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TObjectPtr<UFortVehicleMovementSet> VehicleMovementSet;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_VehicleAttributes)
	FReplicatedAthenaVehicleAttributes VehicleAttributes;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehiclePhysicsCollisionDamageComponent> CachedVehiclePhysicsCollisionDamageComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleFuelComponent> CachedFuelComponent;

	UPROPERTY(Transient)
	TArray<FText> ReasonsWhyCantContainPlayers;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IgnoredBuildingActors)
	TArray<TObjectPtr<ABuildingActor>> IgnoredBuildingActors;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DamageableParts)
	TArray<FVehicleDamageablePart> DamageableParts;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ToggleableParts)
	TArray<FVehicleToggleablePart> ToggledParts;

	UPROPERTY(EditAnywhere, Category="UI")
	TArray<FVehicleSpecificUIDetails> CustomUI;

	UPROPERTY(Transient)
	FTireInfo BaseTireInfo;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle|Config Class")
	TSubclassOf<UFortPhysicsVehicleConfigs> VehicleConfigsClass;

	UPROPERTY(Transient)
	bool bBoosting;

	UPROPERTY(Transient)
	float BoostEndTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Sound Indicator", meta=(EditInline="true"))
	TObjectPtr<UFortSoundIndicatorComponent> SoundIndicatorComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Fuel", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NativeComp_LowFuelSputter;

	UPROPERTY(EditAnywhere, Category="FortAthenaVehicle")
	TObjectPtr<UNiagaraSystem> NativeSys_LowFuelSputter;

	UPROPERTY(Transient)
	bool bOnRoad;

	UPROPERTY(Transient)
	bool bOnLandscape;

	UPROPERTY(Transient)
	bool bOnDirt;

	UPROPERTY(Transient)
	bool bOnGrass;

	UPROPERTY(Transient)
	bool bOnIce;

	UPROPERTY(Transient)
	bool bOnSnow;

	UPROPERTY(Transient)
	bool bOnMud;

	UPROPERTY(Transient)
	bool bOnVehicle;

	UPROPERTY(Transient)
	TArray<ETireSurfaces> TireSurfaces;

	UPROPERTY(BlueprintAssignable)
	FOnTirePopped OnTirePoppedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnTireRepaired OnTireRepairedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnRimScrapingChanged OnRimScrapingChangedDelegate;

private:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Vehicle")
	FORTNITEGAME_API void BreakSpawnedSleepLock();

	UFUNCTION()
	FORTNITEGAME_API void ManageSpeedDamageMutlipliers();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_AbilitySystemComponent();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ActiveGameplayEffectGrantedTagsToForceRemove();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_CorrectTargetOrientation();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_Exploded();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ForceKinematicOnClientCount();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_HealthSet();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_OnFire();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_PendingDeath();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_SpawnedSleepLockActive();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_Tires(const TArray<ETireStates>& PrevTireStates);

	UFUNCTION()
	FORTNITEGAME_API void ReleaseVehicleControlledExternalyInternal();

	UFUNCTION()
	FORTNITEGAME_API void ResetHasContact();

	UPROPERTY(Transient)
	TWeakObjectPtr<AController> LastDamageInstigator;

	UPROPERTY(Transient)
	TWeakObjectPtr<AController> LastOutOfHealthInstigator;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> LastOutOfHealthDamageCauser;

	UPROPERTY(VisibleAnywhere, Category="Vehicle")
	int32 CustomDepthStencilValue;

	UPROPERTY(VisibleAnywhere, Category="Vehicle")
	int32 CustomDepthStencilValueForHighlightedVehicle;

	UPROPERTY(Transient, Replicated)
	uint8 SquadID;

	UPROPERTY(Transient, Replicated)
	uint8 TeamID;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	uint8 bUseCustomDepthStencilValue : 1;

	UPROPERTY(Transient)
	uint8 bStencilEnabled : 1;

	UPROPERTY(Transient)
	uint8 bCachedSquadRestrictionEnabled : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bEnforceTeamRestriction : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bMoveStickAcceleratesVehicles : 1;

	UPROPERTY(Transient)
	uint8 bAllowInteractBetweenFortVolumes_Runtime : 1;

	UPROPERTY(Transient, Replicated)
	FGameplayTagContainer AppliedVehicleModTags;

	UPROPERTY(Transient)
	TObjectPtr<UFortVehicleModCollectedData> CollectedVehicleModData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CorrectTargetOrientation)
	FVehicleTargetOrientation CorrectTargetOrientation;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode_AthenaVehicle> CameraModeClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAnimInstance> DrivingAnimClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAnimInstance> DriverAnimLayerOverlayClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAnimInstance> PassengerAnimLayerOverlayClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<UFortVehicleAnimSet> AnimSet;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AbilitySystemComponent, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_HealthSet, Export, meta=(EditInline="true"))
	TObjectPtr<UFortHealthSet> HealthSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaImpulseResponseSet> ImpulseResponseSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortDamageSet> DamageSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortHealthBarIndicator> HealthBarIndicator;

	UPROPERTY()
	FVehicleCosmeticInfo VehicleCosmeticInfo;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Vehicle Navigation", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortVehicleNavModifierComponent> NavModifierComponent;

	UPROPERTY(Transient, Replicated)
	bool bShouldSleepAtSpawn;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_SpawnedSleepLockActive, Category="Vehicle", meta=(AllowPrivateAccess="true", ExposeOnSpawn="true"))
	bool bSpawnedSleepLockActive;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ForceKinematicOnClientCount)
	uint32 ForceKinematicOnClientCount;

	UPROPERTY(Transient)
	TObjectPtr<AActor> ImpactInstigator;

	UPROPERTY(Transient)
	float NormalizedRPM;

	UPROPERTY(Transient)
	TArray<FActiveVehicleUI> ActiveCustomUI;

	UPROPERTY(Transient)
	TArray<FVehicleSpecificUIDetails> MobileCustomUI;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> CurrentOverlapComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortPhysicsVehicleConfigs> FortPhysicsVehicleConfigs;

	UPROPERTY(Transient)
	bool bShouldDealDamage;

	UPROPERTY(Transient)
	int32 DebugDestroyLogCount;

	UPROPERTY(Transient)
	float ServerCriticalHealth;

	UPROPERTY(Transient)
	float HealthZeroTime;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Exploded)
	uint8 bExploded : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PendingDeath)
	uint8 bPendingDeath : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_OnFire)
	uint8 bOnFire : 1;

	UPROPERTY(Transient)
	float LastPopTireTime;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Tires)
	TArray<ETireStates> TireStates;

	UPROPERTY(Transient)
	float RimScrapeDamageTimer;

};

