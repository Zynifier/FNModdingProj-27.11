// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "EncounterGetVariableLWMEncounterStateTreeTask.generated.h"

class AActor;
class UFortAthenaLivingWorldEncounter;

USTRUCT(meta=(Category="Encounter", DisplayName="Get Variable [LWM Encounter]"))
struct FEncounterGetVariableLWMEncounterStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FEncounterGetVariableLWMEncounterStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag VariableIdentifier;

	UPROPERTY(EditAnywhere, Category="Output")
	TSoftObjectPtr<UFortAthenaLivingWorldEncounter> Value;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

