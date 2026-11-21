// Copyright Epic Games, Inc. All Rights Reserved.

#include "Widgets/NewsTile.h"

UCMSNewsLayoutWidget::UCMSNewsLayoutWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UCMSNewsLayoutWidget::GetOnlyShowUnseenNewsOnStartup()
{
	return false;
}

void UCMSNewsLayoutWidget::SetOnlyShowUnseenNewsOnStartup(bool bOnlyShowUnseenNewsOnStartup)
{
}
