// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UObject/NoExportTypes.h"
#include "Athena/FortActivatablePanelWithItemPreview.h"
#include "ItemReceived/FortItemReceivedTypes.h"
#include "McpSharedTypes.h"
#include "UIManager/FortHUDShutdownTimerInterface.h"
#include "FortItemReceivedWidgetBase.generated.h"

class UFortGiftBoxItem;
class UFortGiftInfo;
class UFortItem;
class UFortMultiSizeItemCard;
class UHorizontalBox;
class UItemCardWidgetBase;
class UScrollBox;

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortGiftInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortGiftInfo")
	FGiftBoxInfo GiftBoxInfo;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortItemReceivedWidgetBase : public UFortActivatablePanelWithItemPreview
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClosingGiftbox();

	UFUNCTION(BlueprintCallable)
	void SetGiftBoxItem(UFortGiftBoxItem* GiftBoxItem);

protected:
	UFUNCTION(BlueprintCallable)
	UFortItem* GetTemporaryInstance(const FFortReceivedItemLootInfo& ItemReference);

	UFUNCTION(BlueprintImplementableEvent)
	void OnGiftBoxItemSet(bool bFromSelf);

	UFUNCTION()
	void OnGiftBoxItemSetInternal(bool bFromSelf);

	UFUNCTION(BlueprintCallable)
	void SetAlignmentOnSlot(UScrollBox* Widget, int32 Index);

	UFUNCTION(BlueprintCallable)
	void SetAlignmentOnSlots(UScrollBox* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowGiftBox();

	UPROPERTY(BlueprintReadOnly, Category="FortItemReceivedWidgetBase")
	TArray<FFortReceivedItemLootInfo> ItemDefs;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemReceivedWidgetBase")
	TObjectPtr<UFortGiftBoxItem> GiftBoxItem;

	UPROPERTY(BlueprintReadOnly, Category="FortItemReceivedWidgetBase")
	FString FromUsername;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemReceivedWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HeaderContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemReceivedWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> GiftScrollBox;

	UPROPERTY(EditAnywhere, Category="FortItemReceivedWidgetBase")
	TSubclassOf<UItemCardWidgetBase> ItemCardClass;

};

UCLASS(Abstract)
class UFortItemReceivedPrePrompt : public UFortItemReceivedWidgetBase, public IFortHUDShutdownTimerInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPrePromptClosed);

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnPrePromptClosed OnPrePromptClosed;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UItemCardWidgetBase : public UButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLootInfoSet();

	UFUNCTION(BlueprintCallable)
	void SetLootInfo(UFortGiftInfo* LootInfo);

	UPROPERTY(BlueprintReadWrite, Category="ItemCardWidgetBase")
	TObjectPtr<UFortGiftInfo> LootInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> FortMultiSizeItemCard_Widget;

};

