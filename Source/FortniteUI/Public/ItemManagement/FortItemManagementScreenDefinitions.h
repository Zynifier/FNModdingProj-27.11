// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortTabListWidgetBase.h"
#include "FortItemManagementScreenDefinitions.generated.h"

enum class EFortFrontendInventoryFilter : uint8;

UENUM(BlueprintType)
enum class EFortItemManagementMode : uint8
{
	Details = 0,
	Comparison = 1,
	Mulch = 2,
};

USTRUCT()
struct FFortItemManagementInventoryFilterTabLabelInfo : public FFortTabButtonLabelInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortItemManagementInventoryFilterTabLabelInfo")
	FName FilterTabNameId;

};

USTRUCT()
struct FQuickbarEquipSlotIndicesConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="Item Management|Equip Slot")
	TArray<int32> EquipSlotIndices;

};

UCLASS()
class UFortFrontendInventoryFilterFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item Type Filter", meta=(DisplayName="Get Text For Item Type Filter"))
	static FText ToText(EFortFrontendInventoryFilter FrontendInventoryFilter);

};

