// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Items/FortProfileItemDefinition.h"
#include "FortCosmeticLockerItemDefinition.generated.h"

USTRUCT(BlueprintType)
struct FFortCosmeticLockerSlotInformation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCosmeticLockerSlotInformation")
	EAthenaCustomizationCategory CustomizationCategory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCosmeticLockerSlotInformation", meta=(ClampMin="1"))
	int32 NumSlotsOfCategory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCosmeticLockerSlotInformation")
	bool bCanBeBlank;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCosmeticLockerSlotInformation")
	bool bMustBeUniqueInArray;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCosmeticLockerSlotInformation")
	bool bHasDynamicSlotCount;

};

UCLASS(NotBlueprintable)
class UFortCosmeticLockerItemDefinition : public UFortProfileItemDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticLockerItemDefinition")
	TArray<FFortCosmeticLockerSlotInformation> LockerSlots;

};

