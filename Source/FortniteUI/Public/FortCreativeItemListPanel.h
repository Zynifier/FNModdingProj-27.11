// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "FortCreativeItemData.h"
#include "FortUITypes.h"
#include "Items/FortItemEntry.h"
#include "FortCreativeItemListPanel.generated.h"

class UFortCreativeItemListPanelData;
class UFortItemDefinition;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLoadItemsComplete);

USTRUCT(BlueprintType)
struct FFortCreativeItemListCategoryData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListCategoryData")
	ECreativeItemCategory Category;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListCategoryData")
	EFortItemCardSize CardSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListCategoryData")
	bool bCollapseCardBorderPad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListCategoryData")
	bool bUseLegacyItemDetailsPanel;

};

USTRUCT(BlueprintType)
struct FItemListCategoryArray
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ItemListCategoryArray")
	TArray<FFortItemEntry> ItemList;

	UPROPERTY(BlueprintReadOnly, Category="ItemListCategoryArray")
	FName CategoryID;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortCreativeItemListPanelData : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(WorldContext="Target"))
	static UFortCreativeItemListPanelData* GetCreativeItemListPanelData(UObject* Target, TSubclassOf<UFortCreativeItemListPanelData> PanelDataClass);

	UFUNCTION(BlueprintPure)
	virtual FText GetInteractionText() const;

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="Target", HidePin="Target"))
	virtual void LoadItems(UObject* Target);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeItemListPanelData")
	TArray<TObjectPtr<UFortItemDefinition>> AllItems;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeItemListPanelData")
	TArray<FItemListCategoryArray> CategoryList;

	UPROPERTY(BlueprintAssignable)
	FLoadItemsComplete OnLoadItemsComplete;

};

