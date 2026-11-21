// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "CosmeticCustomizationInfo.h"
#include "CosmeticBackendLoadoutSlot.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticBackendLoadoutSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticBackendLoadoutSlot", meta=(AllowedTypes="CosmeticLoadoutSlotTemplate"))
	FPrimaryAssetId SlotTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticBackendLoadoutSlot")
	FPrimaryAssetId EquippedItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CosmeticBackendLoadoutSlot")
	TArray<FCosmeticCustomizationInfo> CustomizationInfo;

};

