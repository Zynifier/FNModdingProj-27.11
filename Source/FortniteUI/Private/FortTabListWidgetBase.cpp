// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTabListWidgetBase.h"

bool UFortTabListWidgetBase::GetPreregisteredTabInfo(const FName TabNameId, FFortTabListRegistrationInfo& OutTabInfo)
{
	return false;
}

int32 UFortTabListWidgetBase::GetVisibleTabCount() const
{
	return int32();
}

bool UFortTabListWidgetBase::IsFirstTabActive() const
{
	return false;
}

bool UFortTabListWidgetBase::IsLastTabActive() const
{
	return false;
}

bool UFortTabListWidgetBase::IsTabVisible(const FName TabId) const
{
	return false;
}

void UFortTabListWidgetBase::RegisterAllPreregisteredTabInfos()
{
}

void UFortTabListWidgetBase::RegisterDivider(const TSubclassOf<UUserWidget> DividerWidgetType)
{
}

bool UFortTabListWidgetBase::RegisterFortTab(const FName TabNameId, const TSubclassOf<UCommonButtonBase> TabButtonType, const FFortTabButtonLabelInfo& LabelInfo, UWidget* ContentWidget)
{
	return false;
}

void UFortTabListWidgetBase::SetTabHiddenState(const FName TabNameId, const bool bHidden)
{
}
