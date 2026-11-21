// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortPathFollowingComponentBase.h"
#include "FortPathFollowingComponent.generated.h"

class AFortAIController;

UENUM()
namespace EPathObstacleAction
{
	enum Type
	{
		Melee = 0,
		Ignore = 1,
		AbortMoveAsFailed = 2,
		FinishMoveAsSucceeded = 3,
	};
}

UENUM()
enum class EPathUndermineEvent : uint8
{
	Predicted = 0,
	Started = 1,
	Finished = 2,
};

UCLASS(MinimalAPI, BlueprintType)
class UFortPathFollowingComponent : public UFortPathFollowingComponentBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortAIController> MyAI;

protected:
	UPROPERTY(Config)
	float MovementBlockFrustrationCooldownSpeed;

};

