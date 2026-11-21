// Copyright Epic Games, Inc. All Rights Reserved.

#include "Settings/FortSetting.h"

FText UFortSetting::GetDescriptionRichText() const
{
	return FText();
}

FString UFortSetting::GetDevName() const
{
	return FString();
}

FText UFortSetting::GetDisplayName() const
{
	return FText();
}

ESlateVisibility UFortSetting::GetDisplayNameVisibility()
{
	return ESlateVisibility();
}

FText UFortSetting::GetDynamicDetails() const
{
	return FText();
}

FText UFortSetting::GetWarningRichText() const
{
	return FText();
}
