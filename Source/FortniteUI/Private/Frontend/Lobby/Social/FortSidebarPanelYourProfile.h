// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialProfilePanel.h"
#include "FortSidebarPanelYourProfile.generated.h"

class UFortSettingsListView;
class UFortSocialProfileSettingRegistry;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarPanelYourProfile : public UFortSocialProfilePanel
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortSocialProfileSettingRegistry> Registry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSettingsListView> ListView_Settings;

};

