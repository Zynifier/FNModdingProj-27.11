// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "Quests/QuestManagerEventDispatcherTypes.h"
#include "FortControllerComponent_QuestManagerDataReplicator.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_QuestManagerDataReplicator : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Replicated)
	FQuestEventRecordArray QuestRecordDataArray;

	UPROPERTY(Transient, Replicated)
	FObjectiveEventRecordArray ObjectiveRecordDataArray;

};

