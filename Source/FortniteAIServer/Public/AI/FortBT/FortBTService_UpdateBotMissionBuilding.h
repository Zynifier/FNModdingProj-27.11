// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "FortBTService_UpdateBotMissionBuilding.generated.h"

UCLASS(HideCategories=("Service"))
class UFortBTService_UpdateBotMissionBuilding : public UBTService
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector InterestLocationKey;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector BuildOrderKey;

};

