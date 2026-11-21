// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortControllerEffectUIParameters.generated.h"

USTRUCT(BlueprintType)
struct FEffectUIParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="EffectUIParameters")
	TMap<FString, FString> ParameterKeyValuePairs;

};

