// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "FortAthenaBTTask_VehicleTurnTo.generated.h"

UCLASS(Config=Game)
class FORTNITEAISERVER_API UFortAthenaBTTask_VehicleTurnTo : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Node", meta=(ClampMin="0.0"))
	float Precision;

};

