// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "FortInteractInterface.h"
#include "FortAthenaBTService_Interact.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaBTService_Interact : public UBTService
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(DisplayName="Interact Execution Status Key"))
	FBlackboardKeySelector InteractExecutionStatusKeySelector;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(DisplayName="Interact Context Info Key"))
	FBlackboardKeySelector InteractContextInfoKeySelector;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FBlackboardKeySelector InteractObjectKeySelector;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FBlackboardKeySelector ExecutionStatusKeySelector;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FBlackboardKeySelector MovementStateKeySelector;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<EInteractionBeingAttempted> InteractionBeingAttempted;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bRequireDistanceCheck;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bRequireBlockedCheck;

};

