// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "Quests/IFortQuestInstanceManagerInterface.h"
#include "Quests/QuestTypes.h"
#include "ControllerComponent_Quests.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UControllerComponent_Quests : public UControllerComponent, public IFortQuestInstanceManagerInterface
{
	GENERATED_BODY()

public:
	UControllerComponent_Quests(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Transient, Replicated)
	FFortGrantedQuestDataArray GrantedQuestDataArray;

	UPROPERTY(Transient, Replicated)
	FUpdatedQuestObjectiveDataArray UpdatedQuestObjectivesArray;

};

