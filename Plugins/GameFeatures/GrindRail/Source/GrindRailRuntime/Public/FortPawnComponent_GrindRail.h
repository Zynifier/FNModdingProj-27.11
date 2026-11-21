// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Analytics/FortMatchStatProviderInterface.h"
#include "Components/FortPawnComponent.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortGrindRail.h"
#include "FortPawnComponent_GrindRail.generated.h"

class AActor;
class ABuildingActor;
class ACharacter;
class AFortAthenaVehicle;
class AFortGrindRail;
class AFortPawn;
class AFortPlayerPawn;
class AHUD;
class UCanvas;
class UFortGrindRailLayerAnimInstance;
class UFortMovementMode_ExtLogicGrinding;
class USkeletalMeshComponent;
enum class EGrindRailBoosterMode : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnBegunGrindingDelegate, bool, bWasAlreadyGrinding, bool, bWasJumpingFromRail, bool, bEnteredFromInteraction, FVector, PreviousPlayerLocation);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBoosterModeChanged, EGrindRailBoosterMode, PreviousBoosterMode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndedGrindingDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrindRailChanged, AFortGrindRail*, OldRail, AFortGrindRail*, NewRail);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitObstacle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSprintingStateChanged, bool, bNewIsSprinting);

USTRUCT()
struct FGrindRailStatus
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortGrindRail> GrindingRail;

	UPROPERTY()
	float CurrentSpeedAlongSpline;

	UPROPERTY()
	float CurrentDistanceAlongSpline;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortPawnComponent_GrindRail : public UFortPawnComponent, public IFortMatchStatProviderInterface, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BeginGrinding(AFortGrindRail* GrindRail, const float OptionalStartDistance = -1.000000f, const bool bFromInteraction = false);

	UFUNCTION(BlueprintImplementableEvent)
	void CalculateVelocity(const float DeltaTime, const bool bReplayingMovement, FVector& OutVelocity);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanBeginGrinding();

	UFUNCTION(BlueprintCallable)
	void EndGrinding(const bool bSetEndMovementMode = true);

	UFUNCTION(BlueprintPure)
	void GetCameraOrientedLeanValues(const float RawLeanForward, const float RawLeanRight, float& OrientedLeanForward, float& OrientedLeanRight) const;

	UFUNCTION(BlueprintPure)
	AActor* GetGrindBaseActor() const;

	UFUNCTION(BlueprintPure)
	float GetGrindDistanceOnSpline() const;

	UFUNCTION(BlueprintPure)
	bool GetGrindRequestJump() const;

	UFUNCTION(BlueprintPure)
	float GetHorizontalSplineAngleDeltaDegrees() const;

	UFUNCTION(BlueprintPure)
	float GetLeanForwardSpeedNormalized() const;

	UFUNCTION(BlueprintPure)
	FVector GetMovementStatus() const;

	UFUNCTION(BlueprintPure)
	float GetSpeedHardCap() const;

	UFUNCTION(BlueprintPure)
	bool GetWantsToGrind() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleGrindFinishedAfterJumping();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleGrindingBegun();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleGrindingEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleGrindingEndedFromReplication();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleHitWhenGrinding(const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleJumpOffEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleRailJump();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleSprintInput(bool bPressed);

	UFUNCTION(BlueprintPure)
	bool IsGrinding() const;

	UFUNCTION(BlueprintPure)
	bool IsUsingFirstPersonCamera() const;

	UFUNCTION(BlueprintPure)
	bool IsUsingToggleSprint() const;

	UFUNCTION(BlueprintPure)
	bool IsWeaponActive() const;

	UFUNCTION(BlueprintPure)
	bool IsWeaponADS() const;

	UFUNCTION(BlueprintPure)
	bool NativeIsShooting() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBaseMeshReady(AFortPlayerPawn* Pawn, USkeletalMeshComponent* MeshComponent);

	UFUNCTION(BlueprintCallable)
	void SetGrindBaseActor(AActor* NewBaseActor);

	UFUNCTION(BlueprintCallable)
	void SetGrindDistanceOnSpline(const float NewDistanceOnSpline);

	UFUNCTION(BlueprintCallable)
	void SetIsSprinting(const bool bNewIsSprinting);

	UFUNCTION(BlueprintCallable)
	void SetMovementStatus(const FVector& NewStatus);

	UPROPERTY(EditDefaultsOnly, Category="FortPawnComponent_GrindRail")
	bool bUseNativeSpeedCalculation;

	UPROPERTY(BlueprintAssignable)
	FOnGrindRailChanged GrindRailChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnBegunGrindingDelegate BegunGrindingDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnHitObstacle HitObstacleWhenGrindingDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnBoosterModeChanged BoosterModeChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnSprintingStateChanged SprintingStateChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnEndedGrindingDelegate EndedGrindingDelegate;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Leaning")
	float LeanForward;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Leaning")
	float LeanRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	float BaseLeanRight;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortPawnComponent_GrindRail")
	float CurrentSpeedAlongSpline;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPawnComponent_GrindRail")
	FVector CurrentDirection;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_CurrentBoosterMode, Category="FortPawnComponent_GrindRail")
	EGrindRailBoosterMode CurrentBoosterMode;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animation | Turning")
	bool bShould180Turn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animation | Turning")
	bool bShould180TurnAgain;

protected:
	UFUNCTION(BlueprintCallable)
	bool AddMoveIgnoreActor(ABuildingActor* BuildingActor);

	UFUNCTION(BlueprintCallable)
	void AddTemporaryMoveIgnoreActor(ABuildingActor* BuildingActor, float IgnoreDuration);

	UFUNCTION(BlueprintCallable)
	bool AttemptDestroyVehicleWhileGrinding(AFortAthenaVehicle* Vehicle);

	UFUNCTION()
	void DrawDebugHUD(AHUD* HUD, UCanvas* Canvas) const;

	UFUNCTION()
	void OnIgnoredBuildingEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void OnJumpInput(bool bPressed);

	UFUNCTION()
	void OnMovementModeChanged(ACharacter* InCharacter, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void OnReloadInput();

	UFUNCTION()
	void OnRep_CurrentBoosterMode(const EGrindRailBoosterMode PreviousBoosterMode);

	UFUNCTION()
	void OnRep_GrindingRail();

	UFUNCTION()
	void OnRep_IsSprinting();

	UFUNCTION()
	void OnWalkingBaseChanged(AFortPawn* Pawn, AActor* NewBase);

	UFUNCTION(BlueprintCallable)
	void RemoveMoveIgnoreActors();

	UFUNCTION(Server, Reliable)
	void ServerBeginGrinding(AFortGrindRail* GrindRail, const float OptionalStartDistance, const bool bFromInteraction);

	UFUNCTION(Server, Reliable)
	void ServerUpdateWeaponHolstered(const bool bNewHolstered, const bool bPlayEquipAnim);

	UPROPERTY(EditDefaultsOnly, Category="FortPawnComponent_GrindRail")
	TSubclassOf<UFortMovementMode_ExtLogicGrinding> GrindingExtLogicClass;

	UPROPERTY(EditDefaultsOnly, Category="FortPawnComponent_GrindRail")
	TSubclassOf<UFortGrindRailLayerAnimInstance> GrindingAnimLayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPawnComponent_GrindRail", meta=(ClampMin="0", ForceUnits="deg/s", UIMin="0"))
	FScalableFloat BaseMaxLeanAngularSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPawnComponent_GrindRail", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BaseLeanInterpSpeed;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_GrindingRail)
	TWeakObjectPtr<AFortGrindRail> ReplicatedGrindingRail;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	TWeakObjectPtr<AFortGrindRail> PreviousGrindingRail;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	TWeakObjectPtr<AFortGrindRail> GrindingRail;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	TWeakObjectPtr<AFortGrindRail> NextGrindingRail;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	bool bIsGrinding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	bool bIsGrindJumping;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_IsSprinting, Category="FortPawnComponent_GrindRail")
	bool bIsSprinting;

	UPROPERTY(Transient, Replicated)
	bool bWeaponHolstered;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	bool bJumpInputReady;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPawnComponent_GrindRail")
	float GrindStartDistance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	float CurrentDistanceAlongSpline;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	FVector NativeLastRailLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawnComponent_GrindRail")
	float NativeMaxSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortPawnComponent_GrindRail")
	FRotator GoalRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animation | Turning")
	bool bIs180Turning;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animation | Turning")
	float HorizontalSplineAngleDeltaDegrees;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Rotation", meta=(ClampMax="90", ClampMin="0.000000", ForceUnits="deg", UIMax="90", UIMin="0.000000"))
	FScalableFloat MaxAllowedInclineSplinePitch;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Rotation", meta=(ClampMax="90", ClampMin="0.000000", ForceUnits="deg", UIMax="90", UIMin="0.000000"))
	FScalableFloat MaxAllowedDeclineSplinePitch;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Rotation", meta=(ClampMax="90", ClampMin="0.000000", ForceUnits="deg", UIMax="90", UIMin="0.000000"))
	FScalableFloat MaxAllowedShootingSplinePitch;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Turning", meta=(ClampMax="180", ClampMin="90", ForceUnits="deg", UIMax="180", UIMin="90"))
	FScalableFloat TurnAngleThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Turning", meta=(ClampMin="0", ForceUnits="sec", UIMin="0"))
	FScalableFloat AnimatedTurnDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Rotation", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BaseGrindRailYawRotationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Rotation", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat InclineGrindRailPitchRotationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Rotation", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat DeclineGrindRailPitchRotationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Animation | Rotation", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat ShootingGrindRailRotationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0", ForceUnits="cm", UIMin="0"))
	FScalableFloat NextGrindRailDetectionOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FGameplayTag CancelGrindingTag;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FScalableFloat GrindInteractionReentryCooldownTime;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FScalableFloat ForceGrindingFromWalking;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FScalableFloat MinTimeBeforeJumpSinceEntry;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FScalableFloat CancelSprintLeanBackThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	FScalableFloat WeaponHolsterCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	FScalableFloat WeaponIsShootingCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Gravity")
	FScalableFloat GravityForceWhenGoingDown;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Gravity")
	FScalableFloat GravityForceWhenGoingUp;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Booster")
	FScalableFloat BoosterSprintingAccelerationOnSlowDownBooster;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Booster")
	FScalableFloat BoosterAccelerationOnSpeedUpBooster;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Booster")
	FScalableFloat BoosterSlowDownBoosterDragMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Booster")
	FScalableFloat BoosterSlowDownBoosterGoalSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Booster")
	FScalableFloat BoosterMaxSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Max Speed")
	FScalableFloat ShootingMaxSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Max Speed")
	FScalableFloat AngleForMaxSpeedIncreaseFromDownwardSlope;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Max Speed")
	FScalableFloat MaxSpeedIncreaseFromDownwardSlope;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Max Speed")
	FScalableFloat MaxDragForSpeedSoftCap;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Max Speed")
	FScalableFloat SpeedHardCap;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Sprint")
	FScalableFloat SprintingAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Sprint")
	FScalableFloat SprintingMaxSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Turn")
	FScalableFloat SpeedThresholdForTurn;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Turn")
	FScalableFloat TimeToTurnAround;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat SpeedForMaxLeanAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat SpeedForMinLeanAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat MaxLeanAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat MinLeanAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat CanAccelerateByLeaningIntoTurns;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat CurvatureForMaxLeanIntoTurnsAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat LeanIntoTurnsMaxAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat IncreasedMaxSpeedFromLeanIntoTurn;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Lean")
	FScalableFloat SidewaysLeanBoostReductionRate;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Base")
	FScalableFloat SpeedForMaxBaseAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Base")
	FScalableFloat SpeedForMinBaseAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Base")
	FScalableFloat MaxBaseAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Base")
	FScalableFloat MinBaseAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Base")
	FScalableFloat BaseGoalSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Base")
	FScalableFloat BaseMaxSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Friction")
	FScalableFloat EnableFriction;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Friction")
	FScalableFloat BaseGoalDecelerationSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Friction")
	FScalableFloat FrictionWhenNotLeaning;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Turn")
	FScalableFloat SpeedMultiplierOnHitRailCap;

	UPROPERTY(EditDefaultsOnly, Category="Speed Calculation | Turn")
	FScalableFloat MinSpeedAfterBouncedOffRailCap;

};

