// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "HUDLayoutToolV2_TutorialPopup.generated.h"

class UCommonVisibilitySwitcher;
class UHUDLayoutToolV2_Button;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_TutorialPopup : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TutorialPopup")
	int32 NumberOfTutorials;

	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_TutorialOverlays;

	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_NextTutorial;

};

