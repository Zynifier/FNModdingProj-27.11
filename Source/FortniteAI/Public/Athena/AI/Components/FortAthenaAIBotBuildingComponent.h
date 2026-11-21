// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortAthenaAIBotBuildingComponent.generated.h"

USTRUCT()
struct FFortAthenaAIBotBuildingQueue
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, ClassGroup=("AI"), meta=(BlueprintSpawnableComponent))
class UFortAthenaAIBotBuildingComponent : public UActorComponent
{
	GENERATED_BODY()

};

