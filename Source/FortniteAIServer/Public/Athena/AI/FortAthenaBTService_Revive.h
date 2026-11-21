// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FortAthenaBTService_Revive.generated.h"

UCLASS()
class UFortAthenaBTService_Revive : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ReviveTargetKeyName;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ExecutionStatusName;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName MoveToPathMovementStateName;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName InteractionExecutionStatusName;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName InteractionContextInfoName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="RangeAttack", meta=(AllowPrivateAccess="true"))
	bool bDisableLeash;

};

