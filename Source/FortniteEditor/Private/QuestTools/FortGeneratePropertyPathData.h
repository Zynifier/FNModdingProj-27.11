// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGeneratePropertyPathData.generated.h"

USTRUCT()
struct FFortGeneratePropertyPathData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGeneratePropertyPathData")
	TArray<FString> PropertyNames;

	UPROPERTY()
	TMap<FString, int32> NestedPropertiesIndexData;

};

