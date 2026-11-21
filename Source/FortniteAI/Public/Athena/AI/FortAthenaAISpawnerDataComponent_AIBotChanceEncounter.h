// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_ChanceEncounterBase.h"
#include "FortAthenaAISpawnerDataComponent_AIBotChanceEncounter.generated.h"

class UFortPawnComponent_PassiveHealer;

UCLASS()
class UFortAthenaAISpawnerDataComponent_AIBotChanceEncounter : public UFortAthenaAISpawnerDataComponent_ChanceEncounterBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	FScalableFloat PassiveHealerEnable;

	UPROPERTY(EditDefaultsOnly, Category="Passive Healer", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortPawnComponent_PassiveHealer> PassiveHealerComponentClass;

};

