// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAnimInput_SlopeInfo.generated.h"

USTRUCT(BlueprintType)
struct FFortAnimInput_SlopeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAnimInput_SlopeInfo")
	FVector RootSlopeTranslation;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAnimInput_SlopeInfo")
	FVector LeftFootSlopeTranslation;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAnimInput_SlopeInfo")
	FVector RightFootSlopeTranslation;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAnimInput_SlopeInfo")
	FRotator SlopeRotation;

};

