// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "FortAthenaBTTask_Interact.generated.h"

UCLASS()
class UFortAthenaBTTask_Interact : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Interaction", meta=(AllowPrivateAccess="true"))
	float AttemptInterval;

	UPROPERTY(EditAnywhere, Category="Interaction", meta=(AllowPrivateAccess="true"))
	int32 MaxInteractAttempts;

private:
	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bShouldFocusOnInteraction;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(DisplayName="Interact Execution Status Key"))
	FBlackboardKeySelector InteractExecutionStatusKeySelector;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(DisplayName="Interact Context Info Key"))
	FBlackboardKeySelector InteractContextInfoKeySelector;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FocalPointName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName InteractActorName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JumpExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponTriggerMeleeName;

};

