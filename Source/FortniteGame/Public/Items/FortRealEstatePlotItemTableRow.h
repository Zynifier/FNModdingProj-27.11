// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/PrimaryAssetId.h"
#include "FortRealEstatePlotItemTableRow.generated.h"

USTRUCT()
struct FFortRealEstatePlotItemTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortRealEstatePlotItemTableRow")
	FPrimaryAssetId RealEstatePlotItemId;

	UPROPERTY(EditDefaultsOnly, Category="FortRealEstatePlotItemTableRow")
	bool bIncluded;

	UPROPERTY(EditDefaultsOnly, Category="FortRealEstatePlotItemTableRow")
	bool bIncludedInVkEditor;

	UPROPERTY(EditDefaultsOnly, Category="FortRealEstatePlotItemTableRow")
	bool bDeprecated;

};

