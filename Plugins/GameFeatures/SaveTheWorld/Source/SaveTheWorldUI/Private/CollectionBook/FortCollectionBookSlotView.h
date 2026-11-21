// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCollectionBookSlotView.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UFortCollectionBookSection;
class UFortCollectionBookSlotButton;
class UHorizontalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookSlotView : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnSelectedSlotButtonChanged(UCommonButtonLegacy* SelectedButton, int32 ButtonIdx);

	UFUNCTION()
	virtual void OnSlotButtonClicked(UCommonButtonLegacy* ClickedButton, int32 ButtonIdx);

	UFUNCTION()
	virtual void OnSlotButtonHovered(UCommonButtonLegacy* HoveredButton, int32 ButtonIdx);

	UPROPERTY(EditAnywhere, Category="CollectionBook")
	TSoftClassPtr<UFortCollectionBookSlotButton> CollectionBookButtonClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> CollectionBookButtonBox;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> CollectionBookSlotButtonGroup;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCollectionBookSlotButton>> CollectionBookSlotButtons;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionBookSection> AssociatedSection;

private:
	UPROPERTY()
	int32 PreviousSelectedButtonIdx;

	UPROPERTY()
	int32 CurrentSelectedButtonIdx;

};

