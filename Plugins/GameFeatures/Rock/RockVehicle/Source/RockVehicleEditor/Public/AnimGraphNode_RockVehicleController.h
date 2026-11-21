// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "AnimNode_RockVehicleController.h"
#include "AnimGraphNode_RockVehicleController.generated.h"

UCLASS()
class UAnimGraphNode_RockVehilceController : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Settings")
	FAnimNode_RockVehicleController Node;

};

