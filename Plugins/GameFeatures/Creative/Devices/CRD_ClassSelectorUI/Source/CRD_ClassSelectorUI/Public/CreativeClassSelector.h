// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "CheckDismissableActivatableWidget.h"
#include "ClassSelectorTypes.h"
#include "UIManager/AthenaHUDPrimaryContentInterface.h"
#include "CreativeClassSelector.generated.h"

class AFortMinigame;
class UClassSelectorLoadoutContainer;
class UClassSelectorTabButtons;
class UClassSelectorTeamInfoWidget;
class UClassSelectorTeamTiles;
class UCommonButtonBase;
class UCommonListView;
class UCommonTextBlock;
class UCreativeClassItemInfo;
class UCreativeClassSelectorButton;
class UPanelWidget;
class UScrollBox;
class UWidget;
class UWidgetSwitcher;
enum class EFortMinigameState : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativeClassSelector : public UCommonActivatableWidget, public ICheckDismissableActivatableWidget, public IAthenaHUDPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UWidget* GetFirstLoadoutItem() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnClassSelectionChanged(const FText& NewClassName, const FText& NewClassDescription);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadoutCommitted(const FText& NewClassName, const FText& NewTeamName, const bool bNewLoadout);

protected:
	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnClassSelectorUIPopulated(const bool bHasValidData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTimerCountdown(const int32 RemainingTime);

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UClassSelectorTabButtons> TabButtons_TeamSelection;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Classes;

	UPROPERTY()
	TArray<TObjectPtr<UCreativeClassItemInfo>> ClassItemInfos;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> LoadoutScrollBox;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UClassSelectorLoadoutContainer> LoadoutContainer_Inventory;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UClassSelectorLoadoutContainer> LoadoutContainer_Resources;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SelectLoadout;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_RandomClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_Descriptions;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> ClassAndTeamDescriptionContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> ItemDescriptionContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> InventoryPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> ResourcesPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ItemRarity;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ItemName;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ItemDescription;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> TeamDescriptionContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UClassSelectorTeamInfoWidget> TeamInfoWidget_FullView;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UClassSelectorTeamInfoWidget> TeamInfoWidget_TeamsOnly;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> DisplaySwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> ClassAndTeamSelectionContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> OnlyTeamSelectionContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> InvalidDataContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UClassSelectorTeamTiles> TeamTiles;

	UPROPERTY(EditAnywhere, Category="CreativeClassSelector")
	TSubclassOf<UCreativeClassSelectorButton> TeamSelectionTabClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeClassSelector")
	bool bIsModalVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeClassSelector")
	bool bEnableModalTimeLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeClassSelector")
	int32 ModalTimeLimitInSeconds;

	UPROPERTY(BlueprintReadWrite, Category="CreativeClassSelector")
	EClassSelectorDisplayMode DisplayMode;

	UPROPERTY(BlueprintReadWrite, Category="CreativeClassSelector")
	bool bDeferRespawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeClassSelector", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ReturnToClassSelectionInputAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeClassSelector")
	float LoadoutScrollPadding;

	UPROPERTY(Transient)
	TObjectPtr<UCreativeClassItemInfo> SelectedClassItemInfo;

};

