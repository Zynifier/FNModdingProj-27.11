// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortQuestItemComponent.generated.h"

class UFortQuestDefinitionComponent;

UCLASS(Abstract, MinimalAPI)
class UFortQuestItemComponent : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortQuestDefinitionComponent> QuestDefinitionComponent;

};

