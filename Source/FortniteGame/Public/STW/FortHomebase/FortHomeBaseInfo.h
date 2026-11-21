// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHomeBaseInfo.generated.h"

USTRUCT(BlueprintType)
struct FFortHomeBaseInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortHomeBaseInfo")
	FString BannerIconId;

	UPROPERTY(BlueprintReadOnly, Category="FortHomeBaseInfo")
	FString BannerColorId;

	UPROPERTY(BlueprintReadOnly, Category="FortHomeBaseInfo")
	FText Name;

	UPROPERTY(BlueprintReadOnly, Category="FortHomeBaseInfo")
	bool ValidData;

};

