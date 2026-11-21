// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_BehaviorBase.generated.h"

class UBehaviorTree;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_BehaviorBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UBehaviorTree* GetBehaviorTree();

};

