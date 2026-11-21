// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_Augments.generated.h"

UCLASS()
class UFortAthenaBTTask_Augments : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Augments", meta=(AllowPrivateAccess="true"))
	float MinSelectionTime;

	UPROPERTY(EditAnywhere, Category="Augments", meta=(AllowPrivateAccess="true"))
	float MaxSelectionTime;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AugmentStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AugmentItemKeyName;

};

