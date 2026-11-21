// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_SkillsetBase.generated.h"

class UFortAthenaAIBotSkillSet;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAI_API UFortAthenaAISpawnerDataComponent_SkillsetBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetSkill();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> GetSkillSets();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool ShouldUseMatchMMRToOverrideSkillLevel();

};

