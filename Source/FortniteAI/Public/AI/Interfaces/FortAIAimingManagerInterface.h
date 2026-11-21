// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIAimingManagerInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortAIAimingManagerInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortAIAimingManagerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="LearningAgents")
	void ComputeAimingRotations();

};

