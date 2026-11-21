// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_Warmup.generated.h"

class UFortAthenaAIBotWarmupDigestedSkillSet;

UCLASS()
class UFortAthenaAIBotEvaluator_Warmup : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WarmupPlayEmoteExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WarmupLootAndShootExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WarmupIdleExecutionStatusKeyName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotWarmupDigestedSkillSet> CacheWarmupDigestedSkillSet;

};

