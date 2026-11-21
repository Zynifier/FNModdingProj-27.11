// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_TagQuery.h"
#include "FortAthenaAIBotEvaluator_TagQueryToBBKey.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Nav"))
class UFortAthenaAIBotEvaluator_TagQueryToBBKey : public UFortAthenaAIBotEvaluator_TagQuery
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LinkedBBKeyName;

};

