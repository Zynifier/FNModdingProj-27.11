// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaReplayBrowserScreenBase.generated.h"

class UAthenaReplayBrowserRowProxyInstance;
class UAthenaViewStreamingReplayModalBase;
class UCommonButtonBase;
class UCommonListView;
class UFortReplayBrowserRenameDialog;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaReplayBrowserScreenBase : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActionStateChanged(bool bHasAction);

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaReplayBrowserScreenBase")
	TSubclassOf<UAthenaViewStreamingReplayModalBase> ViewStreamingReplayModalClass;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle RefreshActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ViewStreamingReplayActionRowHandle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Replay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortReplayBrowserRenameDialog> RenameDialog;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_OpenReplayFolder;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PlayReplay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_DeleteReplay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_RenameReplay;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaReplayBrowserRowProxyInstance>> RowProxies;

};

