// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "SpecialEventTypes.generated.h"

USTRUCT(BlueprintType)
struct FSpecialEventMathEaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventMathEaseData")
	TEnumAsByte<EEasingFunc::Type> EasingFunc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventMathEaseData", meta=(EditCondition="EasingFunc == EEasingFunc::EaseIn || EasingFunc == EEasingFunc::EaseOut || EasingFunc == EEasingFunc::EaseInOut"))
	float BlendExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventMathEaseData", meta=(EditCondition="EasingFunc == EEasingFunc::Step"))
	int32 Steps;

};

