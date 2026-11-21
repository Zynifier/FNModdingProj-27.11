// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldConditionBase.h"
#include "WorldConditionTypes.h"
#include "FortWorldConditionPlayerHasConvertedNPC.generated.h"

UENUM(BlueprintType)
enum class EFortWorldConditionPlayerHasConvertedNPCCondition : uint8
{
	HasReachedConvertedNPCLimit = 0,
	HasAnotherConvertedNPC = 1,
};

USTRUCT(meta=(DisplayName="(Fortnite) Return if the referenced player has a converted NPC"))
struct FFortWorldConditionPlayerHasConvertedNPC : public FWorldConditionCommonActorBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortWorldConditionPlayerHasConvertedNPC", meta=(BaseClass="/Script/Engine.Actor"))
	FWorldConditionContextDataRef ActorRef;

	UPROPERTY(EditAnywhere, Category="FortWorldConditionPlayerHasConvertedNPC")
	EFortWorldConditionPlayerHasConvertedNPCCondition ConditionToCheck;

};

