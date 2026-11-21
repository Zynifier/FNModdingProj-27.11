// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEventScreenListView.h"

UEventScreenListView::UEventScreenListView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const UFortEventScreenData* UEventScreenListView::GetEventScreenData() const
{
	return nullptr;
}

void UEventScreenListView::SetNativeTickAllowed(const bool bAllowed)
{
}
