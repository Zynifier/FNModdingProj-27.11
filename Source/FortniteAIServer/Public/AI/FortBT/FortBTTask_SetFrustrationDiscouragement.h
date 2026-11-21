// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortBTTask_SetFrustrationDiscouragement.generated.h"

UCLASS()
class UFortBTTask_SetFrustrationDiscouragement : public UBTTaskNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Discouragement", meta=(ClampMin="0.0", UIMin="0.0"))
	float DiscouragementDuration;

};

