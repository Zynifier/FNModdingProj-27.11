// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortPathFollowingComponent.h"
#include "AthenaPathFollowingComponent.generated.h"

class AAthenaAIController;

UENUM(BlueprintType)
enum class EAthenaPathFollowingFocus : uint8
{
	// Default focus direction. While moving, the character will align towards its current path point

	TowardsNextPathPoint = 0,
	// Face the current velocity, with some smoothing applied. Useful for characters without animation or ability support to turn smoothly (Deimos).
// However it can make the facing lag, cause more sliding and prevent animation from reaching the desired focus directly.

	AlignWithSmoothedVelocity = 1,
};

UCLASS(MinimalAPI)
class UAthenaPathFollowingComponent : public UFortPathFollowingComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="AthenaPathFollowingComponent")
	EAthenaPathFollowingFocus FocusDirectionMethod;

private:
	UPROPERTY(Transient)
	TObjectPtr<AAthenaAIController> AthenaAIController;

};

