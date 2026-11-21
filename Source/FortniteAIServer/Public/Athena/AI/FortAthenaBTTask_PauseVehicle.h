// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_PauseVehicle.generated.h"

UCLASS()
class FORTNITEAISERVER_API UFortAthenaBTTask_PauseVehicle : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	bool bPausePathFollow;

};

