// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Frontend/Lobby/Social/FortSocialSidebarPanelInterface.h"
#include "FortSidebarPanelSettings.generated.h"

class UFortBladeMenu_MainMenu;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortSidebarPanelSettings : public UCommonActivatableWidget, public IFortSocialSidebarPanelInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortBladeMenu_MainMenu> BladeMenu_MainMenu;

};

