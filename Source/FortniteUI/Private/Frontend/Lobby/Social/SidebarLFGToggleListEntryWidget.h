// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListEntry.h"
#include "SidebarLFGToggleListEntryWidget.generated.h"

UCLASS(meta=(DisableNativeTick))
class USidebarLFGToggleListEntryWidget : public USocialListInteractableEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLfgSettingChanged(const bool bIsLfgEnabled);

};

