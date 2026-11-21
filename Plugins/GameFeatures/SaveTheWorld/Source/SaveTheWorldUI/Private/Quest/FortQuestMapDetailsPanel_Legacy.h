// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Quest/FortQuestMapDetailsPanelBase.h"
#include "FortQuestMapDetailsPanel_Legacy.generated.h"

class UCommonActivatablePanelLegacy;
class UCommonBorder;
class UCommonBorderStyle;
class UCommonListView;
class UCommonTextBlock;
class UFortJournalQuestDetails;
class UFortQuestItem;
class UFortQuestObjectiveInfo;
class UFortRewardInfoWidget_Legacy;
class UImage;
class UScrollBox;
class UWidgetSwitcher;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortQuestMapDetailsPanel_Legacy : public UFortQuestMapDetailsPanelBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Details Panel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PlayButtonTriggeringAction;

private:
	UPROPERTY(EditAnywhere, Category="Details Panel")
	TArray<TSubclassOf<UCommonActivatablePanelLegacy>> PriorityActivatablePanelClassList;

	UPROPERTY(EditAnywhere, Category="Details Panel")
	TSubclassOf<UCommonBorderStyle> CurrentQuestBorder;

	UPROPERTY(EditAnywhere, Category="Details Panel")
	TSubclassOf<UCommonBorderStyle> CompletedQuestBorder;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortJournalQuestDetails> Panel_JournalDetails;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NotOwnedHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_InactiveQuestName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_QuestIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> List_Tasks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_Body;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRewardInfoWidget_Legacy> Widget_FutureQuestRewardInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Quest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_NoQuest;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> VisibleObjectives;

	UPROPERTY()
	TObjectPtr<UFortQuestItem> CurrentQuestItem;

};

