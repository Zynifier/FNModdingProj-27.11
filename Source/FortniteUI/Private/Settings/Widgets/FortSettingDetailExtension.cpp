// Copyright Epic Games, Inc. All Rights Reserved.

#include "Settings/Widgets/FortSettingDetailExtension.h"

UFortSettingDetailExtension::UFortSettingDetailExtension(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const FText UFortSettingDetailExtension::GetOptionsDisabledText(const TArray<FText>& Reasons) const
{
	return FText();
}

bool UFortSettingDetailExtension::UseSplitDisabledOptionsVisual()
{
	return false;
}
