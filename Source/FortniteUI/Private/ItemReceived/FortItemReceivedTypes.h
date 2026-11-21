// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "Items/FortGiftBoxItemDefinition.h"
#include "FortItemReceivedTypes.generated.h"

class UFortGiftBoxItem;
class UFortItem;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FFortReceivedItemLootInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortReceivedItemLootInfo")
	FFortItemHeaderInformation HeaderInformation;

	UPROPERTY(BlueprintReadOnly, Category="FortReceivedItemLootInfo")
	TObjectPtr<UFortItem> SourceItemInstance;

	UPROPERTY(BlueprintReadOnly, Category="FortReceivedItemLootInfo")
	TObjectPtr<UFortItem> GeneratedItemInstance;

	UPROPERTY(BlueprintReadOnly, Category="FortReceivedItemLootInfo")
	TObjectPtr<UFortItemDefinition> ItemDef;

	UPROPERTY(BlueprintReadOnly, Category="FortReceivedItemLootInfo")
	FString TemplateId;

	UPROPERTY(BlueprintReadOnly, Category="FortReceivedItemLootInfo")
	int32 Quantity;

};

UCLASS(BlueprintType)
class UFortPresentationItemLootInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortReceivedItemLootInfo ItemReceivedInfo;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UItemReceivedHeaderBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UItemReceivedHeaderBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void InitFromGiftBoxItem_BP();

	UFUNCTION(BlueprintImplementableEvent)
	void SetBlueprintGiftBoxItem(UFortGiftBoxItem* GiftBox, const FString& FromUser, const TArray<FFortReceivedItemLootInfo>& ItemDefs, bool bSelfGift);

protected:
	UPROPERTY(BlueprintReadWrite, Category="ItemReceivedHeaderBase")
	TObjectPtr<UFortGiftBoxItem> GiftBoxItem;

	UPROPERTY(BlueprintReadWrite, Category="ItemReceivedHeaderBase")
	FString FromUserName;

};

