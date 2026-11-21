// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaCustomizationScreenBase.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, Config=Game)
class UAthenaCustomizationScreenBase : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ActionBarToolTipSeen();

	UFUNCTION(BlueprintCallable)
	void QuickSaveToolTipSeen();

	UFUNCTION(BlueprintCallable)
	bool ShouldShowActionBarTooltip();

	UFUNCTION(BlueprintPure)
	bool ShouldShowQuickSaveTooltip() const;

	UFUNCTION(BlueprintPure)
	bool ShouldShowTemporaryItemsTooltip() const;

	UFUNCTION(BlueprintCallable)
	void TemporaryItemsToolTipSeen();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackToGame;

};

