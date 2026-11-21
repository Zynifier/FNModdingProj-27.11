// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIEncounterTargetInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortAIEncounterTargetInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortAIEncounterTargetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="FortAIObjectiveInterface")
	float GetObjectiveCompletionPercentage();

	UFUNCTION(BlueprintImplementableEvent, Category="FortAIObjectiveInterface")
	bool IsFloatingTarget();

};

