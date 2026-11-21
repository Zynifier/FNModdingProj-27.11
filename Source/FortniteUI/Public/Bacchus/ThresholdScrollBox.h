// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "ThresholdScrollBox.generated.h"

UCLASS()
class UThresholdScrollBox : public UScrollBox
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Scroll")
	float ScrollThreshold;

};

