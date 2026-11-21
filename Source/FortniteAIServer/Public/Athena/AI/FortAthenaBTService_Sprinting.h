// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FortAthenaBTService_Sprinting.generated.h"

UCLASS(HideCategories=("Service"))
class UFortAthenaBTService_Sprinting : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SprintExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TacticalSprintExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TacticalSprintOverridenName;

};

