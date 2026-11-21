// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCollectionBookProgressionRewardsModalWidget.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonNumericTextBlock;
class UCommonTextBlock;
class UFortCollectionBookProgressionRewardDetailInspectWidget;
class UFortItem;
class UVerticalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookProgressionRewardsModalWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Collection Book Progression Rewards")
	void InspectItemBP(UFortItem* Item);

	UFUNCTION(BlueprintNativeEvent)
	void OnLevelProgressionSet(int32 CurrentLevel, float NextLvlPct, int32 MaxAchievedLevel);

	UFUNCTION()
	void OnSelectedButtonChanged(UCommonButtonLegacy* SelectedButton, int32 ButtonIndex);

	UPROPERTY(EditAnywhere, Category="Collection Book")
	TSoftClassPtr<UFortCollectionBookProgressionRewardDetailInspectWidget> RewardWidgetClass;

	UPROPERTY(EditAnywhere, Category="Collection Book")
	FMargin RewardWidgetPadding;

	UPROPERTY(EditAnywhere, Category="Collection Book", meta=(ClampMin="1", UIMin="1"))
	int32 NumRewardsToShow;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> RewardBoxWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> MajorRewardBoxWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> XPTextWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> LevelTextWidget;

private:
	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup;

};

