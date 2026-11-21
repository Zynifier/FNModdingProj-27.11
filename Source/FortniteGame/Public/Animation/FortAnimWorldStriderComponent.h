// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Components/ActorComponent.h"
#include "Engine/SpringInterpolator.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimTypes.h"
#include "FortAnimWorldStriderComponent.generated.h"

class UAnimSequence;
class UAnimSequenceBase;

USTRUCT(BlueprintType)
struct FFortAnimInput_TurnCorrection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TurnCorrectionSettings")
	FFortCachedFloatCurve RotationCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TurnCorrectionSettings")
	float MaxYawCorrectionOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TurnCorrectionSettings")
	float CharacterMeshYawOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TurnCorrectionSettings")
	float CurveMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TurnCorrectionSettings")
	bool bEnableDebug;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnCorrection")
	float YawCorrectionOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnCorrection")
	float CharacterInitialWorldYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnCorrection")
	float CharacterWorldYawLastFrame;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnCorrection")
	float AccumulatedAnimationYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnCorrection")
	float TotalYawFromCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnCorrection")
	float RotationCurveYawLastFrame;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnCorrection")
	bool bIsTurnFinished;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortAnimWorldStriderComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CalculateSpeedWarpingValues(const float InRateWarpAlpha, const float InOverallSpeedRate);

	UFUNCTION(BlueprintCallable)
	void ChooseStartAnimationFromSettings();

	UFUNCTION(BlueprintPure)
	float GetWalkPlayRateValue() const;

	UFUNCTION(BlueprintPure)
	float GetWalkSpeedWarpingValue() const;

	UFUNCTION(BlueprintCallable)
	void InitializeStartTransition(UAnimSequenceBase* InStartAnimation);

	UFUNCTION(BlueprintCallable)
	float UpdateStartTransition(const float DeltaTime, UAnimSequenceBase* InStartAnimation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FFortDistanceCurve DistanceCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Pivot Turn")
	FFortAnimInput_TurnCorrection PivotTurnCorrection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Pivot Turn")
	FFortCachedFloatCurve PlayRateSpeedWarpAlphaCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Pivot Turn")
	float PlayRateSpeedWarpAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Pivot Turn")
	FCachedAnimStateData PivotStateData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Pivot Turn")
	TObjectPtr<UAnimSequence> PivotAnimationLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Pivot Turn")
	TObjectPtr<UAnimSequence> PivotAnimationRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Pivot Turn")
	float PivotEarlyOutAngleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Start Turn")
	FFortAnimInput_TurnCorrection StartTurnCorrection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Start Turn")
	FCachedAnimStateData StartStateData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Start Turn")
	FFortDirectionalAnimRef DirectionalStartAnims;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Start Turn")
	float StartEarlyOutThresold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Start Turn")
	uint8 bIgnoreStartTransitionSettings : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Movement")
	FCachedAnimStateData MovementStateData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Locomotion")
	float LocomotionDeadZoneAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings|Locomotion")
	float OverallSpeedRateMaxValue;

	UPROPERTY(BlueprintGetter=GetWalkSpeedWarpingValue, Transient, Category="Transients|Warping Values")
	float WalkPlayRateValue;

	UPROPERTY(BlueprintGetter=GetWalkSpeedWarpingValue, Transient, Category="Transients|Warping Values")
	float WalkSpeedWarpingValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Locomotion")
	float Speed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Gameplay")
	uint8 bIsOnGround : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Gameplay")
	uint8 bIsMoving2D : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Gameplay")
	uint8 bWasMoving2DLastFrame : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Pivot Transition")
	FVector PivotLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Pivot Transition")
	FVector PivotInitialFacingDir2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Pivot Transition")
	TObjectPtr<UAnimSequence> PivotAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Pivot Transition")
	float PivotAnimPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bPivotTransitionTriggered : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bPivotEarlyOut : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	uint8 bStartTransitionTriggered : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	uint8 bStartEarlyOut : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float StartAnimDistanceFromMarker;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float ActualDistanceFromMarker;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float StartAnimTimeElapsed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float StartTurnDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float StartInitialAccelYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float StartAnimPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	FVector StartAnimLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	EFortCardinalDirection StartCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	TObjectPtr<UAnimSequenceBase> StartAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float LocalVelocityYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float LocalAccelerationYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	FFloatRK4SpringInterpolator LocalVelocityYawAngleInterpolator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Start Transition")
	float LocalVelocityYawAngleInterpolated;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Pivot Transition")
	FRotator ActorRotationLastTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transients|Pivot Transition")
	FRotator ActorRotation;

};

