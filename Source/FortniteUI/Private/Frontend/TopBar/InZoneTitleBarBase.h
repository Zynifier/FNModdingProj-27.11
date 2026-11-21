// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "InZoneTitleBarBase.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInZoneTitleBarBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MainMenu;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

};

