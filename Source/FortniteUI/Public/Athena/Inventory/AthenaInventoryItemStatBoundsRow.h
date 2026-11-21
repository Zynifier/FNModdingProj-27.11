// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "AthenaInventoryItemStatBoundsRow.generated.h"

USTRUCT(BlueprintType)
struct FStatBound
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="StatBound", meta=(ClampMax="500.0", ClampMin="0.0", UIMax="500.0", UIMin="0.0"))
	float Minimum;

	UPROPERTY(EditAnywhere, Category="StatBound", meta=(ClampMax="500.0", ClampMin="0.0", UIMax="500.0", UIMin="0.0"))
	float Maximum;

};

USTRUCT(BlueprintType)
struct FAthenaInventoryItemStatBoundsRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaInventoryItemStatBoundsRow")
	FGameplayTagContainer ItemTags;

	UPROPERTY(EditAnywhere, Category="AthenaInventoryItemStatBoundsRow")
	FStatBound Damage;

	UPROPERTY(EditAnywhere, Category="AthenaInventoryItemStatBoundsRow")
	FStatBound FireRate;

	UPROPERTY(EditAnywhere, Category="AthenaInventoryItemStatBoundsRow")
	FStatBound MagazineSize;

	UPROPERTY(EditAnywhere, Category="AthenaInventoryItemStatBoundsRow")
	FStatBound ReloadTime;

};

