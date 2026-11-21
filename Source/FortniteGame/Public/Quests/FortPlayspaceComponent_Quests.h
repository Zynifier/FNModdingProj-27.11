// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "Quests/IFortQuestInstanceManagerInterface.h"
#include "Quests/Processors/ISpatialEventConsumerInterface.h"
#include "Quests/QuestTypes.h"
#include "FortPlayspaceComponent_Quests.generated.h"

class UFortQuestItemDefinition;

UCLASS(BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("QuestComponents"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UFortPlayspaceComponent_Quests : public UFortPlayspaceComponent, public IFortQuestInstanceManagerInterface, public ISpatialEventConsumerInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortPlayspaceComponent_Quests")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> QuestsToGrantOnStart;

private:
	UPROPERTY(Transient, Replicated)
	FFortGrantedQuestDataArray GrantedQuestDataArray;

	UPROPERTY(Transient, Replicated)
	FUpdatedQuestObjectiveDataArray UpdatedQuestObjectivesArray;

};

