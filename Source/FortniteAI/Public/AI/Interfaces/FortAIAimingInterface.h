// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAIAimingInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortAIAimingInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortAIAimingInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="LearningAgents")
	void GetAimingRotation(FRotator& OutRotation);

};

