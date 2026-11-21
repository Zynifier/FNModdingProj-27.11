// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_AIBotSkillset.h"
#include "FortAthenaAISpawnerDataComponent_PlayerBotSkillset.generated.h"

class UFortAthenaAIBotWarmupSkillSet;

UCLASS(MinimalAPI)
class UFortAthenaAISpawnerDataComponent_PlayerBotSkillset : public UFortAthenaAISpawnerDataComponent_AIBotSkillset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="PlayerBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotWarmupSkillSet> WarmUpSkillSet;

};

