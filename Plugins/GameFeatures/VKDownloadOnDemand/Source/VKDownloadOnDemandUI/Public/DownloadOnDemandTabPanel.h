// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortCreativeContentBrowserTabPanelBase.h"
#include "DownloadOnDemandTabPanel.generated.h"

class UCommonButtonLegacy;
class UCommonTileView;
class UCommonVisibilitySwitcher;
class UDownloadOnDemandAddProjectModal;
class UDownloadOnDemandMessageModal;
class UDownloadOnDemandProject;
class UDownloadOnDemandProjectDetailsSidePanel;
class UDownloadOnDemandProjectManagementTab;
class UHorizontalBox;
class UOverlay;

UCLASS()
class UDownloadOnDemandTabPanel : public UFortCreativeContentBrowserTabPanelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="DownloadOnDemandTabPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle AddProjectWithLinkCodeInputRowHandle;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandTabPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle AddSelectedProjectInputRowHandle;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandTabPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ManageSelectedProjectInputRowHandle;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandTabPanel")
	TSubclassOf<UDownloadOnDemandProjectDetailsSidePanel> DownloadOnDemandProjectDetailsSidePanelClass;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandTabPanel")
	TSubclassOf<UDownloadOnDemandAddProjectModal> DownloadOnDemandAddProjectModalClass;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandTabPanel")
	TSubclassOf<UDownloadOnDemandMessageModal> DownloadOnDemandMessageModalClass;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandTabPanel")
	FString AddProjectsWithMnemonicEntitlementName;

	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandProject> SelectedProject;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_AddProjectParent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> CommonTileView_ProjectTiles;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_DownloadOnDemandPanels;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AddProject;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_EntitlementCheckMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_EntitlementCheckFailed;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDownloadOnDemandProjectManagementTab> ProjectManagementTab;

};

