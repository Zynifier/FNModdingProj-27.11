// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "GameplayInteractionContext.h"
#include "FortAthenaBTTask_UseSmartObject.generated.h"

UCLASS()
class UFortAthenaBTTask_UseSmartObject : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SmartObjectsStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SmartObjectDestinationRotationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortAthenaBTTask_UseSmartObject", meta=(AllowPrivateAccess="true"))
	bool bHandleAbortWithSoftDisable;

	UPROPERTY(Transient)
	FGameplayInteractionContext GameplayInteractionContext;

};

