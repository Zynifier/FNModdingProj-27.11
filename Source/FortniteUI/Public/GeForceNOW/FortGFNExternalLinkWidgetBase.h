// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortGFNExternalLinkWidgetBase.generated.h"

class UCommonButtonBase;
class UCommonVisibilitySwitcher;

UCLASS(meta=(DisableNativeTick))
class UFortGFNExternalLinkWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortGFNExternalLinkWidgetBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_LinkType;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortGFNExternalLinkWidgetBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortGFNExternalLinkWidgetBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

};

