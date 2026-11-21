// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialProfanityData.generated.h"

USTRUCT(BlueprintType)
struct FProfanityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FString CountryCode;

	UPROPERTY(EditAnywhere, Category="Properties")
	FString ProfanityList;

	UPROPERTY(EditAnywhere, Category="Properties")
	FString WhiteList;

	UPROPERTY(EditAnywhere, Category="Properties")
	bool bAutoAdd;

};

