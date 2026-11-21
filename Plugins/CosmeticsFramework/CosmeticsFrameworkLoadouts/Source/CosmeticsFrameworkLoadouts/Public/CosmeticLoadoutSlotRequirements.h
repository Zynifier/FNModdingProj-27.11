// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "CosmeticLoadoutSlotRequirements.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticLoadoutSlotRequirements
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticLoadoutSlotRequirements")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticLoadoutSlotRequirements")
	FGameplayTagContainer DeniedTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticLoadoutSlotRequirements")
	TArray<FPrimaryAssetType> AllowedItemTypes;

};

