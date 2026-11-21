// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_Zipline.generated.h"

class AFortPlayerPawn;

UCLASS()
class UFortAthenaBTTask_Zipline : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnZiplineStateChanged(bool bIsZiplining, AFortPlayerPawn* FortPlayerPawn);

private:
	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName UsageExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ZiplineTargetName;

};

