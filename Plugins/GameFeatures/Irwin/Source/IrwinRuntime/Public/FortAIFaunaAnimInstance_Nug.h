// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance.h"
#include "FortAIFaunaAnimInstance_Nug.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Nug : public UFortAIFaunaAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	bool bIsBeingHeld;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	bool bIsBeingThrown;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	float LowerBodyMaskAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	bool bShouldExitJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	float MovingPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	bool bShouldLean;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	float LeanDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	bool bTurnAngleIsNegative;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Properties")
	FName InterruptibleCurveName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	bool bIsIdleShuffleTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	float IdleShuffleBodyBend;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	float IdleShufflePlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Properties")
	bool bIdleShuffleTurnDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionIdleToIdleTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionIdleToLocomotionTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionIdleToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionIdleToJumpApex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionMovingToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionJumpStartToJumpApex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionJumpApexToJumpLoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionLocomotionTurnToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionLocomotionTurnToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionIdleTurnToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionIdleTurnToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionJumpLoopToJumpLand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Transition Conditions")
	bool bCanTransitionIsBeingHeldToChickenChuck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float ShouldExitJump_SpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float MovingPlayRate_SpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float MovingPlayRate_SlowSpeedDivisor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float MovingPlayRate_FastSpeedDivisor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float MovingPlayRate_InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float MovingPlayRate_MinClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float MovingPlayRate_MaxClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float LeanDirection_SpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float ShouldLean_SpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float InterruptibleCurveValue_LargeThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float Speed_MovingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float Speed_IdleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float IdleTurnTransition_SpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers")
	float LocomotionTurnTransition_SpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers|Idle Shuffle")
	float IdleShuffleBodyBendMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers|Idle Shuffle")
	float IdleShuffleTurnThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers|Idle Shuffle")
	float IdleShuffleTurnDirectionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nug Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateOutRangeB;

};

