// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "Engine/TimerHandle.h"
#include "Layout/Margin.h"
#include "FortQuestMapEventSideEntry.generated.h"

class UCommonAnimatedSwitcher;
class UCommonListView;
class UCommonTextBlock;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestObjectiveInfo;
class UImage;

USTRUCT(BlueprintType)
struct FFortQuestMapEventQuestSideBarData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapEventQuestSideBarData")
	TObjectPtr<UFortQuestItemDefinition> QuestItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapEventQuestSideBarData")
	TArray<FString> EventFlags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapEventQuestSideBarData")
	bool bShowAlways;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapEventQuestSideBarData")
	float CycleTime;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapEventSideEntry : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_Rewards;

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

	UPROPERTY()
	FTimerHandle RewardAnimationTimer;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> SideQuestObjectives;

};

