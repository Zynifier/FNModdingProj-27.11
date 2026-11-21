// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "Quests/QuestDefinitionComponents/FortUrgentQuestTypes.h"
#include "FortQuestDefinitionComponent_UrgentQuest.generated.h"

UCLASS(MinimalAPI, BlueprintType, meta=(DevelopmentStatus="Experimental", DisplayName="Urgent Quest"))
class UFortQuestDefinitionComponent_UrgentQuest : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_UrgentQuest")
	FUrgentQuestSettings UrgentQuestSettings;

};

