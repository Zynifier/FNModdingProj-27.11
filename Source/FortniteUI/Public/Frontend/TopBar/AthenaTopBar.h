// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Feature/FortUIFeature.h"
#include "FortTypes.h"
#include "AthenaTopBar.generated.h"

class UCommonActionWidget;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonLazyImage;
class UCommonTextBlock;
class UDynamicEntryBox;
class UEmergencyNoticeBase;
class UFortConfirmationWindow;
class UFortDataDownloadBar;
class UFortPersistentTabObject;
class UFortTabViewModel;
class UFortTopBarTabButton;
enum class EFortUIFeature : uint8;
enum class ETooltipAlignment : uint8;

UENUM(BlueprintType)
enum class EFortTopBarTabButtonGroup : uint8
{
	Discover = 0,
	Core = 1,
	Game = 2,
	PinnedRight = 3,
};

UENUM(BlueprintType)
enum class ETooltipAlignment : uint8
{
	Up = 0,
	Down = 1,
	Left = 2,
	Right = 3,
};

USTRUCT(BlueprintType)
struct FFortTopBarTabButtonInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	FName TabID;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	FString CalendarEventName;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	FSlateBrush IconBrush;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	EFortUIFeature LinkedUIFeature;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	EFortBangType BangType;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	int32 SortOrder;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	bool bForceImage;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	bool bPrimaryPlayerOnly;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	bool bInteractAnalytic;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortTopBarTabButton> OverrideTabWidget;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	TArray<TSoftClassPtr<UFortPersistentTabObject>> PersistentTabObjects;

	UPROPERTY(Transient)
	bool bIsDynamicTab;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	EFortTopBarTabButtonGroup ButtonGroup;

	UPROPERTY(EditAnywhere, Category="FortTopBarTabButtonInfo")
	TSubclassOf<UFortTabViewModel> ViewModel;

};

UCLASS(Abstract)
class UAthenaTopBar : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	EFortUIFeature BP_GetActiveTab() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ShowDataDownloadTooltip(const FVector2D& DataDownloadTooltipPosition, const ETooltipAlignment& Alignment);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void AddIconToScreen(UCommonLazyImage* Image);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityRequested();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMobileTabLabelChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetSelectedTab(EFortUIFeature SelectedTab);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaTopBar", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MTX;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MobileTabLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_TabButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> InputActionWidget_Next;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> InputActionWidget_Prev;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaTopBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortDataDownloadBar> BacchusLobbyDowloadBar;

	UPROPERTY(EditDefaultsOnly, Category="Data Download")
	FText DataDownloadErrorWindowHeaderMessage;

	UPROPERTY(EditDefaultsOnly, Category="Data Download")
	FText DataDownloadErrorWindowBodyMessage;

	UPROPERTY(EditDefaultsOnly, Category="Data Download")
	FName ConnectionErrorButtonActionInputName;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortConfirmationWindow> DataDownloadErrorWindow;

	UPROPERTY()
	TArray<bool> TabButtonBangIconState;

	UPROPERTY(EditDefaultsOnly, Category="Experiment Hack")
	FText ItemShopShortName;

private:
	UFUNCTION()
	void HandleActiveSeasonDataChanged(const TArray<FString>& ActiveEventFlags);

	UFUNCTION()
	void HandleButtonGroupSelectionChanged(UCommonButtonLegacy* SelectedButton, int32 ButtonIndex);

	UFUNCTION()
	void HandleFeatureNavigateRequest(EFortUIFeature Feature);

	UFUNCTION(BlueprintCallable)
	void HandleMainMenuButtonClicked();

	UFUNCTION(BlueprintCallable)
	void HandleSocialButtonClicked();

	UFUNCTION(BlueprintCallable)
	void HandleTopNavSelectionChanged(EFortUIFeature Feature);

	UPROPERTY(EditAnywhere, Category="AthenaTopBar", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, Category="AthenaTopBar", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

	UPROPERTY(EditAnywhere, Category="AthenaTopBar")
	TArray<FFortTopBarTabButtonInfo> TabsInfo;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_TopTabs;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEmergencyNoticeBase> Notice_Emergency_Base;

	UPROPERTY(EditAnywhere, Category="AthenaTopBar")
	TArray<FName> TabsToUnlockOnDownload;

};

