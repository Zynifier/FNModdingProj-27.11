// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "FortQuestDefinitionComponent_StagedObjectives.generated.h"

USTRUCT()
struct FObjectiveExtensionStagedObjectives : public FObjectiveExtensionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveExtensionStagedObjectives")
	int32 Stage;

};

UCLASS(MinimalAPI, BlueprintType, meta=(DisplayName="Staged Objectives Component"))
class UFortQuestDefinitionComponent_StagedObjectives : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_StagedObjectives")
	bool bDisplayStageCompletionCount;

};

