// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_ConstructObjectFromClass.h"
#include "K2Node_OverrideAISpawnerComponent.generated.h"

class UFortAthenaAISpawnerDataComponent;

UCLASS(MinimalAPI)
class UK2Node_OverrideAISpawnerComponent : public UK2Node_ConstructObjectFromClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="K2Node_OverrideAISpawnerComponent")
	uint8 bInstancedComponentAllowed : 1;

	UPROPERTY(EditAnywhere, Instanced, Category="K2Node_OverrideAISpawnerComponent", meta=(EditCondition="bInstancedComponentAllowed"))
	TObjectPtr<UFortAthenaAISpawnerDataComponent> InstancedComponent;

};

