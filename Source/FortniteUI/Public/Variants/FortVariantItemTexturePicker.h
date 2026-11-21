// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variants/FortVariantTileSelector.h"
#include "FortVariantItemTexturePicker.generated.h"

class UAthenaCosmeticItemDefinition;
class UFortCosmeticVariant;
class UFortItemDefinition;

UCLASS(Config=Game)
class UFortVariantItemTexturePicker : public UFortVariantTileSelector
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnToggleAllItemsArchivedMessage(bool bDisplay);

private:
	UPROPERTY()
	TObjectPtr<UAthenaCosmeticItemDefinition> CachedItemDef;

	UPROPERTY()
	TObjectPtr<UFortCosmeticVariant> CachedCosmeticVariant;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> AdditionalPreviewStyles;

};

