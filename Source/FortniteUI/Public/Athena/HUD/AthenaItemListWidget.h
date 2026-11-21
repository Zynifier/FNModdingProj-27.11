// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortHUDElementWidget.h"
#include "FortInventoryFilterEnum.h"
#include "ItemTiles/FortItemFiltering.h"
#include "AthenaItemListWidget.generated.h"

class UFortItemListView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaItemListWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInventoryUpdated();

private:
	UFUNCTION()
	void HandleInventoryUpdated();

	UPROPERTY(EditAnywhere, Category="AthenaItemListWidget")
	FFortItemFilterDefinition ItemFilter;

	UPROPERTY(EditAnywhere, Category="AthenaItemListWidget")
	FGameplayTagContainer ItemFilterTags;

	UPROPERTY(EditAnywhere, Category="AthenaItemListWidget")
	EInventoryContentSortType ItemSortType;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemListWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortItemListView> ItemListView;

};

