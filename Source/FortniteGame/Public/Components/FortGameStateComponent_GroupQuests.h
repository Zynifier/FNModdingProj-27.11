// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortGameStateComponent.h"
#include "Quests/IFortQuestInstanceManagerInterface.h"
#include "Quests/ManagerParticipantSubsetID.h"
#include "Quests/QuestTypes.h"
#include "FortGameStateComponent_GroupQuests.generated.h"

UCLASS(Abstract, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("QuestComponents"))
class UFortGameStateComponent_GroupQuests : public UFortGameStateComponent, public IFortQuestInstanceManagerInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Replicated)
	FFortGrantedQuestDataArray GrantedQuestDataArray;

	UPROPERTY(Transient, Replicated)
	FUpdatedQuestObjectiveDataArray UpdatedQuestObjectivesArray;

	UPROPERTY(Transient)
	TMap<FManagerParticipantSubsetID, FUpdatedQuestObjectiveDataArray> SubsetIDToUpdatedQuestObjectives;

	UPROPERTY(Transient)
	TMap<FManagerParticipantSubsetID, FFortGrantedQuestDataArray> SubsetIDToGrantedQuests;

};

