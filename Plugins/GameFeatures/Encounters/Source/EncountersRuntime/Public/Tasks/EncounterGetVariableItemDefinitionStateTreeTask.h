// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "EncounterGetVariableItemDefinitionStateTreeTask.generated.h"

class AActor;
class UFortWorldItemDefinition;

USTRUCT(meta=(Category="Encounter", DisplayName="Get Variable [Item Definition]"))
struct FEncounterGetVariableItemDefinitionStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FEncounterGetVariableItemDefinitionStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag VariableIdentifier;

	UPROPERTY(EditAnywhere, Category="Output")
	TSoftObjectPtr<UFortWorldItemDefinition> Value;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

