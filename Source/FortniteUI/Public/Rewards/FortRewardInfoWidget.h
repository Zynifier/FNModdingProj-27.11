// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CommonPoolableWidgetInterface.h"
#include "CommonUserWidget.h"
#include "Layout/Margin.h"
#include "Types/SlateEnums.h"
#include "FortItemQuantityPair.h"
#include "FortTypes.h"
#include "FortUITypes.h"
#include "FortRewardInfoWidget.generated.h"

class UCommonButtonGroupBase;
class UFortItem;
class UFortRewardInfoButton;
class UPanelWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortRewardInfoButton : public UCommonButtonBase, public ICommonPoolableWidgetInterface
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
class UFortRewardInfoWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Reward Info")
	bool ContainsReward(const FString& TemplateIdToCheck);

	UFUNCTION(BlueprintCallable, Category="Reward Info")
	void SetButtonGroup(UCommonButtonGroupBase* InButtonGroup);

	UFUNCTION(BlueprintCallable, Category="Reward Info")
	void SetReward(const FFortItemQuantityPair& RewardIn);

	UFUNCTION(BlueprintCallable, Category="Reward Info")
	void SetRewards(const FFortRewardInfo& RewardsIn);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortRewardInfoWidget", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UPanelWidget> RewardListWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget")
	FMargin RewardWidgetPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget")
	bool bShowDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget")
	bool bAllowItemInteraction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget")
	int32 MaxNumRewardsShown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget")
	TSubclassOf<UFortRewardInfoButton> OrWidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfoWidget")
	TSubclassOf<UFortRewardInfoButton> RewardInfoButtonType;

private:
	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup;

};

