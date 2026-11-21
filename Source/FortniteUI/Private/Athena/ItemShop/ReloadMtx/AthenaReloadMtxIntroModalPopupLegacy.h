// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaReloadMtxIntroModalPopupLegacy.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaReloadMtxIntroModalPopupLegacy : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayOutro();

private:
	UFUNCTION(BlueprintCallable)
	void Dismiss();

	UFUNCTION()
	void HandleConfirmButtonClicked();

	UFUNCTION(BlueprintCallable)
	void HandleTapToClose();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

};

