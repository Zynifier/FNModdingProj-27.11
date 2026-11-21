// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTabListWidgetBase.h"
#include "FortAthenaItemManagementInventoryFilterTabLabelInfo.generated.h"

USTRUCT()
struct FFortAthenaItemManagementInventoryFilterTabLabelInfo : public FFortTabButtonLabelInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortAthenaItemManagementInventoryFilterTabLabelInfo")
	FName FilterTabNameId;

	UPROPERTY(EditAnywhere, Category="FortAthenaItemManagementInventoryFilterTabLabelInfo")
	bool bAllowEmptySlotItem;

	UPROPERTY(EditAnywhere, Category="FortAthenaItemManagementInventoryFilterTabLabelInfo")
	FText EmptyFilterDisplay;

	UPROPERTY(EditAnywhere, Category="FortAthenaItemManagementInventoryFilterTabLabelInfo")
	FText EmptyArchivedFilterDisplay;

};

