// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCollectionBookProgressWidget.generated.h"

class UCommonActivatablePanelLegacy;
class UCommonButtonLegacy;
class UCommonNumericTextBlock;
class UCommonTextBlock;
class UFortAccountItem;
class UFortCollectionBookPage;
class UFortCollectionBookPageDetailsWidget;
class UFortCollectionBookProgressionRewardsModalWidget;
class UFortCollectionBookProgressionRewardsPreviewWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookProgressWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnCollectionBookPageSelected(const UFortCollectionBookPage* SelectedPage);

protected:
	UFUNCTION(BlueprintNativeEvent)
	void OnCollectionBookLevelChanged(int32 NewLevel);

	UFUNCTION(BlueprintNativeEvent)
	void OnCollectionBookLevelProgressionChanged(float NewCompletionPct);

	UFUNCTION(BlueprintNativeEvent)
	void OnCollectionBookPreviewXPChange(float PreviewCompletionPct);

	UFUNCTION()
	void OnInventoryUpdated();

	UFUNCTION()
	void OnSlottedItemOperationComplete(const UFortAccountItem* ItemSlotted, FName SlotId);

	UPROPERTY(Transient)
	int32 CachedXPLevel;

	UPROPERTY(Transient)
	float CachedXPCompletionPct;

	UPROPERTY(EditAnywhere, Category="Collection Book")
	TSoftClassPtr<UFortCollectionBookProgressionRewardsModalWidget> RewardDetailsModalWidgetClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCollectionBookProgressWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookProgressionRewardsPreviewWidget> ProgressionRewardsPreviewWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> XPTextWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> LevelTextWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> DetailsButtonWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookPageDetailsWidget> PageDetailsWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCollectionBookProgressionRewardsModalWidget> DetailsModalWidget;

private:
	UFUNCTION()
	void HandleDetailsModalWidgetDeactivated(UCommonActivatablePanelLegacy* DeactivatedPanel);

};

