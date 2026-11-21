// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortUITypes.h"
#include "FortCollectionBookSlotWidget.generated.h"

class UFortAccountItem;
class UFortItem;
class UFortMultiSizeItemCard;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookSlotWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortCollectionBookSlottedItemUpdatedDelegate);

public:
	UFUNCTION(BlueprintPure)
	int32 GetNumItemsToSlot() const;

	UFUNCTION(BlueprintPure)
	const FName& GetSlotRowName() const;

	UFUNCTION(BlueprintPure)
	UFortItem* GetSlottedItemRepresentation() const;

	UFUNCTION(BlueprintPure)
	bool HasItemsToSlot() const;

	UFUNCTION(BlueprintPure)
	bool IsItemSlotted() const;

protected:
	UFUNCTION()
	void HandleResearchItemComplete(const UFortAccountItem* ResearchedItem, const FString& SlotId);

	UFUNCTION()
	void HandleSlottedItemOperationComplete(const UFortAccountItem* NewItem, FName TemplateId);

	UFUNCTION()
	void HandleUnslotItemComplete(const UFortAccountItem* UnslottedItem, const UFortAccountItem* OldItem, FName SlotId);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemCardUpdated();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book")
	EFortItemCardSize ItemCardSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book")
	bool bIsRewardCard;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemCardWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UWidget> UnslottedOverlayWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UWidget> ReadyToSlotOverlayWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UWidget> UnslottedButReadyOverlayWidget;

	UPROPERTY(Transient)
	FName SlotRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="User Context Text")
	FText ItemAvailableToSlotText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="User Context Text")
	FText NoItemsAvailableToSlotText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="User Context Text")
	FText HigherQualityItemsAvailableToSlotAndUpgradeAvailableText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="User Context Text")
	FText HigherQualityItemsAvailableToSlotAndEvolveAvailableText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="User Context Text")
	FText HigherQualityItemsAvailableToSlotText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="User Context Text")
	FText ItemInSlotFullyUpgradedText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="User Context Text")
	FText ItemInSlotCanBeUpgradedText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="User Context Text")
	FText ItemInSlotCanBeEvolvedText;

private:
	UFUNCTION()
	void OnItemDestroyed();

	UPROPERTY(Transient)
	TObjectPtr<UFortItem> SlottedItemRepresentation;

};

