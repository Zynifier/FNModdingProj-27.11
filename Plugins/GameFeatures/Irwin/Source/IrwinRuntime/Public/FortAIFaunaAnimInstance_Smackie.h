// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance.h"
#include "FortAIFaunaAnimInstance_Smackie.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Smackie : public UFortAIFaunaAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Smackie|Properties")
	bool bIsIdleShuffleTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Smackie|Properties")
	float IdleShuffleBodyBend;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Smackie|Properties")
	float IdleShufflePlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Smackie|Properties")
	bool bIdleShuffleTurnDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Smackie|State Rules")
	bool bCanTransitionIdleToHop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Smackie|State Rules")
	bool bCanTransitionHopToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Smackie|State Rules")
	bool bCanTransitionFallToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Smackie|State Rules")
	bool bCanTransitionFallToHop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Smackie|Magic Numbers")
	float SpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Smackie|Magic Numbers|Idle Shuffle")
	float IdleShuffleBodyBendMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Smackie|Magic Numbers|Idle Shuffle")
	float IdleShuffleTurnThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Smackie|Magic Numbers|Idle Shuffle")
	float IdleShuffleTurnDirectionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Smackie|Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Smackie|Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Smackie|Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Smackie|Magic Numbers|Idle Shuffle|Map Range")
	float IdleShufflePlayRateOutRangeB;

};

