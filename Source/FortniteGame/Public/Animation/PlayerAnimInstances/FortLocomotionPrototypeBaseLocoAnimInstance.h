// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Math/MathFwd.h"
#include "SequenceEvaluatorLibrary.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/PlayerAnimInstances/FortLocomotionPrototypeLinkedAnimInstance.h"
#include "FortLocomotionPrototypeBaseLocoAnimInstance.generated.h"

USTRUCT()
struct FORTNITEGAME_API FFortLocomotionStateMachineInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortLocomotionStateMachineInfo")
	FName StateMachineName;

	UPROPERTY(EditDefaultsOnly, Category="FortLocomotionStateMachineInfo")
	FName IdleState;

	UPROPERTY(EditDefaultsOnly, Category="FortLocomotionStateMachineInfo")
	FName TurnState;

	UPROPERTY(EditDefaultsOnly, Category="FortLocomotionStateMachineInfo")
	FName MovementState;

	UPROPERTY(EditDefaultsOnly, Category="FortLocomotionStateMachineInfo")
	FName StartState;

	UPROPERTY(EditDefaultsOnly, Category="FortLocomotionStateMachineInfo")
	FName PivotState;

	UPROPERTY(EditDefaultsOnly, Category="FortLocomotionStateMachineInfo")
	FName StopState;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortLocomotionStateMachineInput
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bEnterTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bEnterMovement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bEnterStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bEnterPivot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bEnterStop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bExitTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bExitMovement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bExitStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bExitPivot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineInput")
	bool bExitStop;

};

UCLASS(HideCategories=("AnimInstance"))
class FORTNITEGAME_API UFortLocomotionPrototypeBaseLocoAnimInstance : public UFortLocomotionPrototypeLinkedAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Locomotion", meta=(BlueprintThreadSafe))
	void UpdatePivotState(FSequenceEvaluatorReference SequencePlayer);

	UFUNCTION(BlueprintCallable, Category="Locomotion", meta=(BlueprintThreadSafe))
	void UpdateStartState(FSequenceEvaluatorReference SequencePlayer);

	UFUNCTION(BlueprintCallable, Category="Locomotion", meta=(BlueprintThreadSafe))
	void UpdateStopState(FSequenceEvaluatorReference SequencePlayer);

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FCachedAnimStateArray TurnInitiatingStates;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FCachedAnimStateArray TurnTransitionStates;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	FFortLocomotionStateMachineInfo LocomotionStateMachineInfo;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionPrototypeBaseLocoAnimInstance")
	FFortLocomotionStateMachineInput LocomotionStateMachineInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionPrototypeBaseLocoAnimInstance")
	float OrientationWarpingYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bUseEightDirectionLocomotion;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	bool bUseLoopTurnOnSpot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bPlayFeetShuffle;

private:
	UPROPERTY(Transient)
	EFortCardinalDirection PreviousFrameLocomotionCardinalDirection;

	UPROPERTY(Transient)
	FVector PivotInitialVelocity;

	UPROPERTY(Transient)
	FVector PreviousFrameAcceleration;

	UPROPERTY(Transient)
	FVector PreviousFrameVelocity;

	UPROPERTY(Transient)
	EFortCardinalDirection PivotTargetCardinalDirection;

	UPROPERTY(Transient)
	float PivotInitialAngle;

	UPROPERTY(Transient)
	bool bPivotDirectionChanged;

	UPROPERTY(Transient)
	bool bIsPivotStop;

};

