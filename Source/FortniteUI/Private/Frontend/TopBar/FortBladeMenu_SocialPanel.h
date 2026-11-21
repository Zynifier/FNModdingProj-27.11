// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/TopBar/FortBladeMenu.h"
#include "FortBladeMenu_SocialPanel.generated.h"

class UFortSocialPanelView_UserLists;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortBladeMenu_SocialPanel : public UFortBladeMenu
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialPanelView_UserLists> SocialPanel_UserLists;

};

