// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Athena/AI/FortAthenaAIEvaluator.h"
#include "FortAthenaBTService_SetExecutionStatus.generated.h"

UCLASS(HideCategories=("Service"))
class UFortAthenaBTService_SetExecutionStatus : public UBTService_BlackboardBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_SetExecutionStatus")
	EExecutionStatus ExecutionStatus;

};

