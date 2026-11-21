// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPoolableWidgetInterface.h"
#include "CommonUserWidget.h"
#include "Layout/Margin.h"
#include "Types/SlateEnums.h"
#include "CommonButtonLegacy.h"
#include "FortItemQuantityPair.h"
#include "FortTypes.h"
#include "FortUITypes.h"
#include "FortRewardInfoWidget_Legacy.generated.h"

class UCommonButtonGroupLegacy;
class UFortItem;
class UFortRewardInfoButton_Legacy;
class UPanelWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortRewardInfoButton_Legacy : public UCommonButtonLegacy, public ICommonPoolableWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Reward Info Button")
	UFortItem* GetItemInstance() const;

	UFUNCTION(BlueprintCallable, Category="Reward Info Button")
	void SetItemInstanceQuantityPair(const FFortItemInstanceQuantityPair& ItemQuantityPair);

	UFUNCTION(BlueprintCallable, Category="Reward Info Button")
	void SetShowDescription(bool bInShowDescription);

protected:
	UFUNCTION(BlueprintPure, Category="Reward Info Button")
	int32 GetQuantity() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Reward Info Button")
	void HandleDifferentItemOrQuantitySetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Reward Info Button")
	void SetShowDescriptionBP(bool bInShowDescription);

	UPROPERTY(BlueprintReadOnly, Export, Category="Reward Info Button", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UPanelWidget> ItemCardPanel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Reward Info Button")
	EFortItemCardSize ItemCardSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Reward Info Button")
	bool bDisplayAsRewardCard;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortItem> ItemInstance;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortRewardInfoWidget_Legacy : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Reward Info")
	bool ContainsReward(const FString& TemplateIdToCheck);

	UFUNCTION(BlueprintCallable, Category="Reward Info")
	void SetButtonGroup(UCommonButtonGroupLegacy* InButtonGroup);

	UFUNCTION(BlueprintCallable, Category="Reward Info")
	void SetReward(const FFortItemQuantityPair& RewardIn);

	UFUNCTION(BlueprintCallable, Category="Reward Info")
	void SetRewards(const FFortRewardInfo& RewardsIn);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortRewardInfoWidget_Legacy", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UPanelWidget> RewardListWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget_Legacy")
	FMargin RewardWidgetPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget_Legacy")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget_Legacy")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget_Legacy")
	bool bShowDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget_Legacy")
	bool bAllowItemInteraction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget_Legacy")
	int32 MaxNumRewardsShown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget_Legacy")
	TSubclassOf<UFortRewardInfoButton_Legacy> OrWidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget_Legacy")
	TSubclassOf<UFortRewardInfoButton_Legacy> RewardInfoButtonType;

private:
	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup;

};

