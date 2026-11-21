// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "FortAIFaunaAnimInstance.h"
#include "FortAIFaunaAnimInstance_Burt.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Burt : public UFortAIFaunaAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	float MovingPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	float LocomotionPoseAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	bool bEnableHeadTiltUpAdditive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	bool bTurnAngleIsNegative;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Properties")
	FName DisableLocomotionAdditiveCurveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Properties")
	FName InterruptibleCurveName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	bool bIsIdleShuffleTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	float IdleShuffleBodyBend;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	float IdleShufflePlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	bool bIdleShuffleTurnDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Properties")
	bool bIsMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionIdleToApex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionIdleToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionMovingToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionLandToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionLandToJumpStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionJumpStartToApex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionApexToFall;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionFallToLand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionIdleTurnToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionLocomotionTurnToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionLocomotionTurnToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionIdleTurnToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionFallToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Transition Conditions")
	bool bCanTransitionFallToIdle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float MovingPlayRate_SpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float MovingPlayRate_SlowSpeedDivisor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float MovingPlayRate_FastSpeedDivisor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float MovingPlayRate_MinClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float MovingPlayRate_MaxClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float MovingPlayRate_InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float LocomotionPoseAdditiveAlpha_InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float EnableHeadTiltUpAdditive_PawnUniqueIDMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float EnableHeadTiltUpAdditive_ModOperand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float InterruptibleCurveValue_LargeThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float InterruptibleCurveValue_TurnAngleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float Speed_MovingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float Speed_IdleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float TurnAngle_LargeThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float Speed_RidingMovingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers")
	float Speed_RidingIdleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers|Idle Shuffle")
	float IdleShuffleBodyBendMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers|Idle Shuffle")
	float IdleShuffleTurnThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers|Idle Shuffle")
	float IdleShuffleTurnDirectionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burt Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateOutRangeB;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Burt Magic Numbers|Riding")
	float MinSpeedSlowRidingMovePlayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Burt Magic Numbers|Riding")
	float SpeedSlowDivisorRidingMovePlayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Burt Magic Numbers|Riding")
	FMapRangeClamped_Ranges RidingMovePlayRate_Ranges;

};

