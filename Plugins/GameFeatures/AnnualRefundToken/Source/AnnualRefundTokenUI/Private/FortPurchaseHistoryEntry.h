// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "FortHoldableButton.h"
#include "FortPurchaseHistoryEntry.generated.h"

class UCommonTextBlock;
class UFortCosmeticItemCard;
class UFortItem;
enum class EFortPurchaseHistoryRefundType : uint8;

USTRUCT(BlueprintType)
struct FPurchaseHistoryBundleEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PurchaseHistoryBundleEntry")
	FString Id;

};

UCLASS(Abstract, Config=Game)
class UFortPurchaseHistoryEntryBase : public UFortHoldableButton, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateItemList(const TArray<UFortCosmeticItemCard*>& ItemCards);

	UPROPERTY(EditAnywhere, Category="FortPurchaseHistoryEntryBase")
	TSubclassOf<UFortCosmeticItemCard> ItemCardClass;

	UPROPERTY(EditAnywhere, Category="FortPurchaseHistoryEntryBase")
	float CardWidthOverride;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Name;

	UPROPERTY(Config)
	TArray<FString> LootEntryItemTypesToExclude;

	UPROPERTY(Config)
	TArray<FString> LootEntryItemTypesToCombine;

};

UCLASS(Abstract)
class UFortPurchaseHistoryBundleEntry : public UFortPurchaseHistoryEntryBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetExpandButtonText(int32 NumPurchases);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="FortPurchaseHistoryBundleEntry")
	bool bIsExpanded;

};

UCLASS(Abstract)
class UFortPurchaseHistoryEntry : public UFortPurchaseHistoryEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetHistory(bool bHasBeenRefunded, bool bIsCancelPurchaseEligible, bool bIsTokenlessRefund, bool bPlayerHasTokens, bool bNonRefundable, bool IsPartOfABundle, bool IsNextRefundable, int32 IndexInBundle, int32 NumPurchasesInBundle);

	UFUNCTION(BlueprintImplementableEvent)
	void SetPurchaseText(const FText& PurchaseDateText, const FText& RefundDateText, bool bHasBeenRefunded, const EFortPurchaseHistoryRefundType RefundType);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupItemCard(const UFortCosmeticItemCard* ItemCard, const UFortItem* Item);

};

