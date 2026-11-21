// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "FortQuestPropPropagator.generated.h"

class UBlueprint;
class UFortQuestItemDefinition;
class UObject;

UCLASS()
class UFortQuestPropPropagator : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void MakePropActors(UClass* InQuestPropParentClass, UFortQuestItemDefinition* QuestItemDef);

	UFUNCTION(BlueprintImplementableEvent)
	void SetPropActorData(UBlueprint* BlueprintObject, UObject* BlueprintObjectCDO, int32 ObjectiveIndex);

};

