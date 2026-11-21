// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIManager/FortUIStateWidget_NUI.h"

void UFortUIStateWidget_NUI::DynamicHandleLoadingScreenVisibilityChanged(bool IsVisible)
{
}

bool UFortUIStateWidget_NUI::IsContentOnStack() const
{
	return false;
}

void UFortUIStateWidget_NUI::PopAllContentWidgets()
{
}

UWidget* UFortUIStateWidget_NUI::PopContentWidget()
{
	return nullptr;
}

UWidget* UFortUIStateWidget_NUI::PopContentWidgetInternal_Implementation(FContentPushState State)
{
	return nullptr;
}

void UFortUIStateWidget_NUI::PushContentWidget(UWidget* Widget)
{
}

void UFortUIStateWidget_NUI::PushContentWidgetAdvanced(UWidget* Widget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget)
{
}

void UFortUIStateWidget_NUI::PushContentWidgetInternal_Implementation(UWidget* Widget, FContentPushState State)
{
}

void UFortUIStateWidget_NUI::RequestOpenSocialPanel()
{
}

void UFortUIStateWidget_NUI::SetFrontEndVisibility(bool bHideHeader, bool bHideFooter, bool bHideChatWidget)
{
}

void UFortUIStateWidget_NUI::SetSocialButtonEnabled(bool bEnabled)
{
}
