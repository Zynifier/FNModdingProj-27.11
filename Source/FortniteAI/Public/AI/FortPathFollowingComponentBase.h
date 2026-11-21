// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "FortPathFollowingComponentBase.generated.h"

class AAIController;

UCLASS(Config=Game, MinimalAPI, BlueprintType)
class UFortPathFollowingComponentBase : public UCrowdFollowingComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<AAIController> AIController;

};

