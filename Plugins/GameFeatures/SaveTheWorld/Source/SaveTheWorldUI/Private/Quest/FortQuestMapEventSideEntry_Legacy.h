// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/TimerHandle.h"
#include "Layout/Margin.h"
#include "FortQuestMapEventSideEntry_Legacy.generated.h"

class UCommonListView;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestObjectiveInfo;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapEventSideEntry_Legacy : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Rewards;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> List_SideTasks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SideQuestTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Arrow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_QuestComplete;

	UPROPERTY(EditAnywhere, Category="Quest Map Event Side Entry")
	FMargin RewardPadding;

	UPROPERTY()
	TObjectPtr<UFortQuestItemDefinition> CurrentQuestItemDef;

	UPROPERTY()
	TObjectPtr<UFortQuestItem> CurrentQuestItem;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UCommonWidgetSwitcherLegacy>> RewardSwitchers;

	UPROPERTY()
	FTimerHandle RewardAnimationTimer;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> SideQuestObjectives;

};

