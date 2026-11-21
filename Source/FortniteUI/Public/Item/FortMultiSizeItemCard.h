// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRarityEnum.h"
#include "FortUITypes.h"
#include "Item/FortItemWidget_NUI.h"
#include "Items/FortItemTypeEnum.h"
#include "FortMultiSizeItemCard.generated.h"

enum class EFortItemCardSize : uint8;
enum class EFortItemType : uint8;
enum class EFortRarity : uint8;

UCLASS(BlueprintType)
class FORTNITEUI_API UFortMultiSizeItemCard : public UFortItemWidget_NUI
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item Card")
	EFortItemCardSize GetCardSize() const;

	UFUNCTION(BlueprintCallable, Category="Multi Size Item Card")
	void SetCardSize(const EFortItemCardSize CardSize);

	UFUNCTION(BlueprintCallable, Category="Multi Size Item Card")
	void SetEmptyItemType(const EFortItemType NewEmptyItemType);

	UFUNCTION(BlueprintCallable, Category="Item Card")
	void SetQuantityOverride(const int32 QuantityOverride);

	UFUNCTION(BlueprintCallable, Category="Item Card")
	void SetRarityOverride(const EFortRarity RarityOverride);

	UFUNCTION(BlueprintCallable, Category="Item Card")
	void SetShouldCollapseBorderPadding(const bool Value);

	UFUNCTION(BlueprintCallable, Category="Item Card")
	void SetShouldCollapseItem(const bool Value);

	UFUNCTION(BlueprintCallable, Category="Item Card")
	void SetShouldCollapseQuantity(const bool Value);

	UFUNCTION(BlueprintCallable, Category="Item Card")
	void SetShouldDisplayItemAsReward(const bool Value);

	UFUNCTION(BlueprintCallable, Category="Item Card")
	void SetShouldShowDurabilityRepairMode(const bool Value);

	UFUNCTION(BlueprintCallable, Category="Item Card")
	void SetShouldSuppressItemTypeIcon(const bool Value);

	UFUNCTION(BlueprintPure)
	static bool ShouldUseNewItemCards();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Multi Size Item Card", meta=(DesignerRebuild, DisplayName="Card Size", ExposeOnSpawn))
	EFortItemCardSize BPItemCardSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard", meta=(DesignerRebuild))
	bool ShouldDisplayItemAsReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard")
	int32 QuantityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard")
	EFortRarity RarityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard", meta=(DesignerRebuild))
	EFortItemType EmptyItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard", meta=(DesignerRebuild))
	bool ShouldSuppressItemTypeIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard", meta=(DesignerRebuild))
	bool ShouldSuppressTierMeter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard", meta=(DesignerRebuild))
	bool ShouldCollapseBorderPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard")
	bool ShouldCollapseItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard")
	bool ShouldAutoHideDurability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard")
	bool ShouldCollapseQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMultiSizeItemCard")
	bool ShouldShowDurabilityRepairMode;

};

