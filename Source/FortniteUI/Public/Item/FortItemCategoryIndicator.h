// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "FortTypes.h"
#include "Item/FortIconWithLabel.h"
#include "FortItemCategoryIndicator.generated.h"

class UFortItem;
enum class EFortItemCategoryOrdinal : uint8;

UCLASS(BlueprintType)
class UFortItemCategoryIndicator : public UFortIconWithLabel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Category Indicator")
	void ClearLabelColorOverride();

	UFUNCTION(BlueprintCallable, Category="Item Category Indicator")
	void SetItemToRepresent(const UFortItem* ItemToRepresent);

	UFUNCTION(BlueprintCallable, Category="Item Category Indicator")
	void SetLabelColorOverride(const FLinearColor InLabelColorOverride);

	UFUNCTION(BlueprintCallable, Category="Item Category Indicator")
	void SetOrdinalOfCategoryToRepresent(const EFortItemCategoryOrdinal ItemCategoryOrdinal);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Category Indicator", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Category Indicator", meta=(ExposeOnSpawn))
	EFortItemCategoryOrdinal OrdinalOfCategoryToRepresent;

};

