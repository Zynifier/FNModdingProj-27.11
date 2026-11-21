// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticCustomizationInfo.h"
#include "CosmeticLoadoutSlot.generated.h"

class UCosmeticLoadoutSlotTemplate;
class UObject;

USTRUCT(BlueprintType)
struct FCosmeticLoadoutSlot
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticLoadoutSlot", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<UCosmeticLoadoutSlotTemplate> SlotTemplate;

	UPROPERTY()
	TObjectPtr<UObject> EquippedItemDefinitionObject;

	UPROPERTY()
	TArray<FCosmeticCustomizationInfo> CustomizationInfo;

};

