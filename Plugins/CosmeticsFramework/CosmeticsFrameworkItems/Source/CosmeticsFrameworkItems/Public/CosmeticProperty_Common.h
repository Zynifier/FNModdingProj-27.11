// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CosmeticPropertyBase.h"
#include "CosmeticProperty_Common.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticProperty_Vector : public FCosmeticPropertyBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticProperty_Vector")
	FVector Value;

};

