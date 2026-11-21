// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "Movement/FortMovementMode_BaseExtLogic.h"
#include "FortMovementMode_ExtLogicGrinding.generated.h"

class AActor;
class ABuildingActor;
class AFortAthenaVehicle;
class AFortGrindRail;
class AFortPawn;
class AFortPlayerPawn;
class AHUD;
class UCanvas;
class USkeletalMeshComponent;
enum class EGrindRailBoosterMode : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnBegunGrindingDelegate_ExtLogic, bool, bWasAlreadyGrinding, bool, bWasJumpingFromRail, bool, bEnteredFromInteraction, FVector, PreviousPlayerLocation);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBoosterModeChanged_ExtLogic, EGrindRailBoosterMode, PreviousBoosterMode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndedGrindingDelegate_ExtLogic);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrindRailChanged_ExtLogic, AFortGrindRail*, OldRail, AFortGrindRail*, NewRail);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitObstacle_ExtLogic);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSprintingStateChanged_ExtLogic, bool, bNewIsSprinting);

USTRUCT()
struct FFortMovementMode_GrindingCreationData : public FFortMovementMode_BaseExtCreationData
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortMovementMode_GrindingRuntimeData : public FFortMovementMode_BaseExtRuntimeData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortMovementMode_ExtLogicGrinding : public UFortMovementMode_BaseExtLogic, public IFortHolsterWeaponSourceInterface, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetCurrentSpeedAlongSpline() const;

	UFUNCTION(BlueprintPure)
	float GetLeanForward() const;

	UFUNCTION(BlueprintPure)
	float GetLeanRight() const;

	UFUNCTION(BlueprintCallable)
	void TriggerEndGrinding();

protected:
	UFUNCTION(BlueprintCallable)
	void AddGameplayCue(const FGameplayTag& GameplayCueTag);

	UFUNCTION(BlueprintCallable)
	void AddMoveIgnoreActor(ABuildingActor* BuildingActor);

	UFUNCTION(BlueprintCallable)
	bool AttemptDestroyVehicleWhileGrinding(AFortAthenaVehicle* Vehicle);

	UFUNCTION(BlueprintCallable)
	void BeginGrinding(AFortGrindRail* GrindRail, const float OptionalStartDistance = -1.000000f, const bool bFromInteraction = false);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanBeginGrinding();

	UFUNCTION()
	void DrawDebugHUD(AHUD* HUD, UCanvas* Canvas) const;

	UFUNCTION(BlueprintCallable)
	void EndGrinding(const bool bSetEndMovementMode = true);

	UFUNCTION(BlueprintPure)
	EGrindRailBoosterMode GetBoosterMode() const;

	UFUNCTION(BlueprintPure)
	void GetCameraOrientedLeanValues(const float RawLeanForward, const float RawLeanRight, float& OrientedLeanForward, float& OrientedLeanRight) const;

	UFUNCTION(BlueprintPure)
	FVector GetCurrentDirection() const;

	UFUNCTION(BlueprintPure)
	AFortGrindRail* GetGrindBaseActor() const;

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
	float GetValueAtLevelWithContext(const FScalableFloat& Input, float Level) const;

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
	bool IsSprinting() const;

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

	UFUNCTION()
	void OnIgnoredBuildingEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void OnJumpInput(bool bPressed);

	UFUNCTION()
	void OnOwnerDBNO();

	UFUNCTION()
	void OnReloadInput();

	UFUNCTION()
	void OnRep_IsSprinting();

	UFUNCTION()
	void OnWalkingBaseChanged(AFortPawn* Pawn, AActor* NewBase);

	UFUNCTION(BlueprintCallable)
	void PlayJumpOnSound(bool bPlayAudio);

	UFUNCTION(BlueprintCallable)
	void RemoveGameplayCue(const FGameplayTag& GameplayCueTag);

	UFUNCTION(BlueprintCallable)
	void RemoveGrindingGameplayCue(const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable)
	void RemoveMoveIgnoreActors();

	UFUNCTION(BlueprintCallable)
	void SetCurrentDirection(const FVector& NewDirection);

	UFUNCTION(BlueprintCallable)
	void SetGrindBaseActor(AFortGrindRail* NewBaseActor);

	UFUNCTION(BlueprintCallable)
	void SetGrindDistanceOnSpline(const float NewDistanceOnSpline);

	UFUNCTION(BlueprintCallable)
	void SetIsSprinting(const bool bNewIsSprinting);

	UFUNCTION(BlueprintCallable)
	void SetMovementStatus(const FVector& NewStatus);

	UFUNCTION(BlueprintPure)
	void SphereTraceForJump(const FVector& Start, const FVector& End, float Radius, bool bDrawDebug, const FLinearColor& TraceColor, TArray<FHitResult>& OutHits) const;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementMode_ExtLogicGrinding")
	bool bUseNativeSpeedCalculation;

	UPROPERTY(BlueprintAssignable)
	FOnGrindRailChanged_ExtLogic GrindRailChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnBegunGrindingDelegate_ExtLogic BegunGrindingDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnHitObstacle_ExtLogic HitObstacleWhenGrindingDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnBoosterModeChanged_ExtLogic BoosterModeChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnSprintingStateChanged_ExtLogic SprintingStateChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnEndedGrindingDelegate_ExtLogic EndedGrindingDelegate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	float BaseLeanRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animation | Turning")
	bool bShould180Turn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animation | Turning")
	bool bShould180TurnAgain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMovementMode_ExtLogicGrinding", meta=(ClampMin="0", ForceUnits="deg/s", UIMin="0"))
	FScalableFloat BaseMaxLeanAngularSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMovementMode_ExtLogicGrinding", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BaseLeanInterpSpeed;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortGrindRail> ReplicatedGrindingRail;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	TWeakObjectPtr<AFortGrindRail> PreviousGrindingRail;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	TWeakObjectPtr<AFortGrindRail> GrindingRail;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	TWeakObjectPtr<AFortGrindRail> NextGrindingRail;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	bool bIsGrinding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	bool bIsGrindJumping;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortMovementMode_ExtLogicGrinding")
	bool bIsSprinting;

	UPROPERTY(Transient)
	bool bWeaponHolstered;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	bool bJumpInputReady;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortMovementMode_ExtLogicGrinding")
	float GrindStartDistance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	float CurrentDistanceAlongSpline;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	FVector NativeLastRailLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_ExtLogicGrinding")
	float NativeMaxSpeed;

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

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FScalableFloat ServerPositionTolerance;

};

