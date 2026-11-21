// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/FortAimAssist2D.h"
#include "FortTouchAimAssist.generated.h"

class AActor;

USTRUCT()
struct FFortTouchAimAssist
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FFortAimAssist2D_InputParams InputParams;

	UPROPERTY()
	FFortAimAssist2D_OwnerInfo OwnerInfo;

	UPROPERTY()
	TArray<FFortAimAssist2D_Target> TargetCache0;

	UPROPERTY()
	TArray<FFortAimAssist2D_Target> TargetCache1;

	UPROPERTY()
	TObjectPtr<AActor> AutoFireTargetActor;

};

