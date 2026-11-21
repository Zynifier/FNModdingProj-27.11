// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestItemComponents/FortQuestItemComponent.h"
#include "FortQuestItemComponent_MapMarkers.generated.h"

class UFortQuestItem;

UCLASS()
class UFortQuestItemComponent_MapMarkers : public UFortQuestItemComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleObjectiveReset(const UFortQuestItem* QuestItem, const FName ObjectiveBackendName);

};

