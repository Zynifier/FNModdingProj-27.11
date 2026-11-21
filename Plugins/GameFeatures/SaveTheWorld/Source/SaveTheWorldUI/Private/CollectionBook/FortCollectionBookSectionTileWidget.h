// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Layout/Margin.h"
#include "Types/SlateEnums.h"
#include "CommonButtonLegacy.h"
#include "FortCollectionBookSectionTileWidget.generated.h"

class UCommonTextBlock;
class UFortAccountItem;
class UFortCollectionBookGenericRewardWidget;
class UFortCollectionBookSection;
class UFortCollectionBookSlotWidget;
class UHorizontalBox;
enum class EFortCollectionBookState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCollectionBookSectionTileWidget : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnItemSlotted(const UFortAccountItem* ItemSlotted, FName SlotId);

	UFUNCTION()
	virtual void OnItemUnslotted(const UFortAccountItem* ItemUnslotted, const UFortAccountItem* OldSlottedItem, FName SlotId);

	UFUNCTION(BlueprintNativeEvent)
	void OnSectionSlotUpdate(int32 NumFilledSlots, int32 NumSlots, EFortCollectionBookState SectionState);

	UPROPERTY(EditAnywhere, Category="Collection Book")
	TSoftClassPtr<UFortCollectionBookSlotWidget> SlotWidgetClass;

	UPROPERTY(EditAnywhere, Category="Collection Book")
	FMargin SlotWidgetPadding;

	UPROPERTY(EditAnywhere, Category="Collection Book")
	TEnumAsByte<EHorizontalAlignment> SlotWidgetHorizontalAlignment;

	UPROPERTY(EditAnywhere, Category="Collection Book")
	TEnumAsByte<EVerticalAlignment> SlotWidgetVerticalAlignment;

	UPROPERTY(EditAnywhere, Category="Collection Book", meta=(ClampMin="1", UIMin="1"))
	int32 MaxNumSlotsSupported;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> SlotBoxWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> SectionNameWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookGenericRewardWidget> SectionRewardWidget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Collection Book")
	TObjectPtr<UFortCollectionBookSection> AssociatedSection;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCollectionBookSlotWidget>> SlotWidgets;

};

