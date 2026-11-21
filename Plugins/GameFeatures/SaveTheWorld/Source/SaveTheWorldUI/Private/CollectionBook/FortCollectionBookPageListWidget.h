// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortCollectionBookPageListWidget.generated.h"

class UCommonNumericTextBlock;
class UCommonTextBlock;
class UFortAccountItem;
class UFortCollectionBookCategory;
class UFortCollectionBookPage;
class UObject;
enum class EFortCollectionBookState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCollectionBookPageListWidget : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCategoryDetailsUpdated(int32 AvailableSlots, int32 FilledSlots, int32 TotalSlots);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPageDetailsUpdated(int32 AvailableSlots, int32 FilledSlots, int32 TotalSlots, EFortCollectionBookState State);

	UFUNCTION()
	void OnSlottedItemOperationComplete(const UFortAccountItem* SlottedItem, FName SlotId);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupAsCategory(UFortCollectionBookCategory* Category);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupAsPage(UFortCollectionBookPage* Page);

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PageNameWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> AvailableSlotsWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PageCompletionWidget;

	UPROPERTY(Transient)
	TWeakObjectPtr<UObject> AssociatedPageOrCategory;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Collection Book")
	bool bIsExpanded;

};

