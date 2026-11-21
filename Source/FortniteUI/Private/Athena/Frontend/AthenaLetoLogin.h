// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaLetoLogin.generated.h"

class UFortUIStateWidget_Login;
class UPanelWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaLetoLogin : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_Login;

	UPROPERTY(EditDefaultsOnly, Category="AthenaLetoLogin")
	TSubclassOf<UFortUIStateWidget_Login> LoginWidgetClass;

};

