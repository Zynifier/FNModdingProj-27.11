// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAttributeInitializationKey.generated.h"

USTRUCT(BlueprintType)
struct FFortAttributeInitializationKey
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	FName AttributeInitCategory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	FName AttributeInitSubCategory;

};

