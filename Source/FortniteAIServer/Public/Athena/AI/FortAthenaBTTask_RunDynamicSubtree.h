// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_RunBehaviorDynamic.h"
#include "FortAthenaBTTask_RunDynamicSubtree.generated.h"

UCLASS()
class UFortAthenaBTTask_RunDynamicSubtree : public UBTTask_RunBehaviorDynamic
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bCallParentOnInstanceCreated : 1;

	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bUpdateBlackboardAsset : 1;

};

