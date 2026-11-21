// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotWarmupSkillSet.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIBotWarmupDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float WarmupPlayEmoteBehaviorWeight;

	UPROPERTY(Transient)
	float WarmupLootAndShootBehaviorWeight;

	UPROPERTY(Transient)
	float WarmupIdleBehaviorWeight;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotWarmupSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Warmup", meta=(AllowPrivateAccess="true"))
	FScalableFloat WarmupPlayEmoteBehaviorWeight;

	UPROPERTY(EditDefaultsOnly, Category="Warmup", meta=(AllowPrivateAccess="true"))
	FScalableFloat WarmupLootAndShootBehaviorWeight;

	UPROPERTY(EditDefaultsOnly, Category="Warmup", meta=(AllowPrivateAccess="true"))
	FScalableFloat WarmupIdleBehaviorWeight;

};

