// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortCreditsScreen.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreditsScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void NativeConstruct();

private:
	UFUNCTION()
	void HandleBackActionInput(bool& bBPassThrough);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(EditDefaultsOnly, Category="FortCreditsScreen")
	FDataTableRowHandle BackAction;

};

