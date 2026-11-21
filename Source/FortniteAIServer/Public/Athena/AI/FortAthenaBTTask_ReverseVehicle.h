// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_ReverseVehicle.generated.h"

UCLASS()
class FORTNITEAISERVER_API UFortAthenaBTTask_ReverseVehicle : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Reverse", meta=(AllowPrivateAccess="true"))
	bool bReverseVehicle;

};

