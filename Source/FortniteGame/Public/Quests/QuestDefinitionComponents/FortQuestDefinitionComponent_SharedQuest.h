// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "Quests/QuestTypes.h"
#include "FortQuestDefinitionComponent_SharedQuest.generated.h"

UENUM(BlueprintType)
enum class ESharedQuestScopePolicy : uint8
{
	/** Only (friendly) Party members can participate. */
	Party = 0,
	/** All Squad members can participate. Party members who are not squad mates, cannot participate. */
	Squad = 1,
};

UCLASS(MinimalAPI, BlueprintType, meta=(DevelopmentStatus="Experimental", DisplayName="Shared Quest"))
class UFortQuestDefinitionComponent_SharedQuest : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_SharedQuest")
	ESharedQuestScopePolicy ScopePolicy;

	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_SharedQuest")
	FQuestInstanceParticipantConfiguration ParticipantConfiguration;

};

