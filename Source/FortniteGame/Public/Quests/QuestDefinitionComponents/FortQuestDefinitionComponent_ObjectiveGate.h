// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "Quests/QuestItemComponents/FortQuestItemComponent_ObjectiveGate.h"
#include "Quests/QuestItemComponents/ObjectiveGateComponentTypes.h"
#include "FortQuestDefinitionComponent_ObjectiveGate.generated.h"

USTRUCT()
struct FObjectiveExtension_Gate : public FObjectiveExtensionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveExtension_Gate")
	EGateCheckType GateCheckType;

	UPROPERTY(EditAnywhere, Category="ObjectiveExtension_Gate")
	TArray<FObjectiveEntry_Gate> ObjectiveGates;

};

UCLASS(MinimalAPI, meta=(DisplayName="Objective Gate"))
class UFortQuestDefinitionComponent_ObjectiveGate : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

};

