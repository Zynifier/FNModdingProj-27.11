// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Settings/Widgets/SettingsScreen.h"
#include "CheatSettingsScreen.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UCheatSettingsScreen : public USettingsScreen
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleBackActionInput(bool& PassThrough);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(EditDefaultsOnly, Category="CheatSettingsScreen")
	FDataTableRowHandle BackAction;

};

