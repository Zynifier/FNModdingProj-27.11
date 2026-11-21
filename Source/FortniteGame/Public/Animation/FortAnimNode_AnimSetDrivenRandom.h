// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimNodes/AnimNode_RandomPlayer.h"
#include "GameplayTagContainer.h"
#include "FortAnimNode_AnimSetDrivenRandom.generated.h"

class UFortAnimSet;

USTRUCT()
struct FFortAnimNode_AnimSetDrivenRandom : public FAnimNode_RandomPlayer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNode_AnimSetDrivenRandom")
	FGameplayTag RandomSlotName;

	UPROPERTY(EditAnywhere, Category="FortAnimNode_AnimSetDrivenRandom")
	TObjectPtr<UFortAnimSet> AnimSet;

};

