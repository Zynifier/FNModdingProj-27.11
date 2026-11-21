// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_LeaveVehicle.generated.h"

UCLASS()
class UFortAthenaBTTask_LeaveVehicle : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	bool bWaitVehicleStop;

};

