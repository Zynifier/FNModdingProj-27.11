// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_BehaviorBase.h"
#include "FortAthenaAISpawnerDataComponent_Behavior.generated.h"

class UBehaviorTree;

UCLASS()
class UFortAthenaAISpawnerDataComponent_Behavior : public UFortAthenaAISpawnerDataComponent_BehaviorBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AI", meta=(AllowPrivateAccess="true", DisplayAfter="bRunBehaviorTree", EditCondition="bRunBehaviorTree"))
	TObjectPtr<UBehaviorTree> BehaviorTree;

};

