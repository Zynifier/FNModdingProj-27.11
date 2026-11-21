// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortSocialPanel.generated.h"

class UFortSocialPanelView_UserLists;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortSocialPanel : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ClosePanel();

	UFUNCTION(BlueprintPure)
	bool IsAnySlideOutMenuOpen() const;

	UFUNCTION()
	void OnClosePanelInternal(bool& PassThrough);

private:
	UFUNCTION(BlueprintCallable)
	void HandleSocialPanelClose();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialPanelView_UserLists> PanelView_UserLists;

	UPROPERTY(EditAnywhere, Category="FortSocialPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CloseInputAction;

};

