// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quest/FortQuestMapDetailsPanelBase.h"
#include "FortQuestMapEventDetailsPanel_Legacy.generated.h"

class UCommonBorder;
class UCommonBorderStyle;
class UCommonListView;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UDataTable;
class UFortQuestItemDefinition;
class UFortQuestMapEventSideEntry_Legacy;
class UFortQuestObjectiveInfo;
class UImage;
class UScrollBox;
class UVerticalBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortQuestMapEventDetailsPanel_Legacy : public UFortQuestMapDetailsPanelBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Details Panel")
	TSubclassOf<UCommonBorderStyle> CurrentQuestBorder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Details Panel")
	TSubclassOf<UCommonBorderStyle> CompletedQuestBorder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Details Panel")
	TSubclassOf<UCommonBorderStyle> FutureQuestBorder;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_QuestContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_CompletedQuestContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Quests;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_NextQuest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> List_Tasks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_QuestIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_SideBar;

	UPROPERTY(EditAnywhere, Category="Details Panel")
	TObjectPtr<UDataTable> EventQuestTable;

	UPROPERTY(EditAnywhere, Category="Details Panel")
	TSubclassOf<UFortQuestMapEventSideEntry_Legacy> SideBarEntryClass;

	UPROPERTY(EditAnywhere, Category="Details Panel")
	TObjectPtr<UFortQuestItemDefinition> UnlockEventQuestDefinition;

	UPROPERTY()
	TObjectPtr<UFortQuestItemDefinition> CurrentQuestDef;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> VisibleObjectives;

};

