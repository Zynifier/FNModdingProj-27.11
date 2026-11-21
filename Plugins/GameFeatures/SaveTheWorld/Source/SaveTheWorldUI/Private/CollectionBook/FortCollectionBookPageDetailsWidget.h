// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCollectionBookPageDetailsWidget.generated.h"

class UCommonActivatablePanelLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortAccountItem;
class UFortCollectionBookPage;
class UFortCollectionBookPageCompletionRewardWidget;
class UFortCollectionBookRewardModalWidget;
class UFortMaterialProgressBar;
enum class EFortCollectionBookState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookPageDetailsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	void OnDetailsPageChanged(const UFortCollectionBookPage* InNewDetailsPage);

	UFUNCTION(BlueprintNativeEvent)
	void OnPageProgressionUpdated(int32 TotalFilledSlots, int32 TotalSlots, EFortCollectionBookState State);

	UFUNCTION()
	void OnSlotItemComplete(const UFortAccountItem* SlottedItem, FName SlotId);

	UFUNCTION()
	void OnUnslotItemComplete(const UFortAccountItem* SlottedItem, const UFortAccountItem* OldItem, FName SlotId);

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PageCompletionText;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMaterialProgressBar> ProgressBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookPageCompletionRewardWidget> PageRewardWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> RewardDetailsButton;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionBookPage> DetailsPage;

	UPROPERTY(EditAnywhere, Category="Reward Modal")
	TSoftClassPtr<UFortCollectionBookRewardModalWidget> RewardDetailsModalWidgetClass;

	UPROPERTY(EditAnywhere, Category="Reward Modal")
	FText ModalTitle;

private:
	UFUNCTION()
	void HandleRewardDetailsModalWidgetDeactivated(UCommonActivatablePanelLegacy* DeactivatedPanel);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCollectionBookRewardModalWidget> RewardDetailsModalWidget;

};

