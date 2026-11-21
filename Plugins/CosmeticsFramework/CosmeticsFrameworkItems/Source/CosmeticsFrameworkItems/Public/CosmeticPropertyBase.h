// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CosmeticPropertyBase.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticPropertyBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticPropertyBase")
	FGameplayTag PropertyTag;

};

