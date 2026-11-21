// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "FortAIPerceptionComponent.generated.h"

UENUM()
namespace ECorePerceptionTypes
{
	enum Type
	{
		Sight = 0,
		Hearing = 1,
		Damage = 2,
		Touch = 3,
		Team = 4,
		// information from teammates 

		Prediction = 5,
		MAX = 6 UMETA(Hidden),
	};
}

UCLASS(MinimalAPI, HideCategories=("Activation", "Collision"), ClassGroup=("AI"), meta=(BlueprintSpawnableComponent))
class UFortAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	float LosingSightRadiusBump;

};

