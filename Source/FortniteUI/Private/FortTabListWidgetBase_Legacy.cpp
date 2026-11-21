// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTabListWidgetBase_Legacy.h"

bool UFortTabListWidgetBase_Legacy::GetPreregisteredTabInfo(const FName TabNameId, FFortTabListRegistrationInfo& OutTabInfo)
{
	return false;
}

int32 UFortTabListWidgetBase_Legacy::GetVisibleTabCount()
{
	return int32();
}

bool UFortTabListWidgetBase_Legacy::IsFirstTabActive() const
{
	return false;
}

bool UFortTabListWidgetBase_Legacy::IsLastTabActive() const
{
	return false;
}

bool UFortTabListWidgetBase_Legacy::IsTabVisible(FName TabId)
{
	return false;
}

void UFortTabListWidgetBase_Legacy::RegisterAllPreregisteredTabInfos()
{
}

void UFortTabListWidgetBase_Legacy::RegisterDivider(TSubclassOf<UUserWidget> DividerWidgetType)
{
}

bool UFortTabListWidgetBase_Legacy::RegisterFortTab(FName TabNameId, TSubclassOf<UCommonButtonBase> TabButtonType, const FFortTabButtonLabelInfo& LabelInfo, UWidget* ContentWidget)
{
	return false;
}

void UFortTabListWidgetBase_Legacy::SetTabHiddenState(FName TabNameId, bool bHidden)
{
}
