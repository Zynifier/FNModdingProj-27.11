// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/TopBar/FortMainMenuButton.h"
#include "FortMainMenuButtonExtension.generated.h"

class UCommonActivatableWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMainMenuButtonExtension : public UFortMainMenuButton
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="CustomSidebarBehavior")
	TSubclassOf<UCommonActivatableWidget> SidebarPanelToActivate;

};

