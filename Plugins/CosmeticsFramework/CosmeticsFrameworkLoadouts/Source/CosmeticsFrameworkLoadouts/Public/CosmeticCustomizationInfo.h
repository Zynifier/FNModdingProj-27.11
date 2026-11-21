// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CosmeticCustomizationInfo.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticCustomizationInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticCustomizationInfo")
	FGameplayTag ChannelTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticCustomizationInfo")
	FGameplayTag VariantTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticCustomizationInfo")
	FString AdditionalData;

};

