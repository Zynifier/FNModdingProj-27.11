// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestTypes.h"
#include "IQuestInstanceManagerInterfaceBlueprintParameters.generated.h"

class AActor;
class IQuestDefinitionInterface;

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FGrantQuestBlueprintParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="GrantQuestBlueprintParameters")
	TScriptInterface<IQuestDefinitionInterface> QuestDefinition;

	UPROPERTY(BlueprintReadWrite, Category="GrantQuestBlueprintParameters")
	AActor* Instigator;

	UPROPERTY(BlueprintReadWrite, Category="GrantQuestBlueprintParameters")
	bool bInstigatorOwnsQuest;

	UPROPERTY(BlueprintReadWrite, Category="GrantQuestBlueprintParameters")
	EQuestParticipationScope QuestParticipationScope;

};

