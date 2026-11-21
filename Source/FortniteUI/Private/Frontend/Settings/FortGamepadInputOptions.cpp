// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/Settings/FortGamepadInputOptions.h"

bool UFortGamepadInputOptions::AreAllImportantActionsBound(TArray<FText>& OutUnboundScreenLabels, const bool bRichText)
{
	return false;
}

void UFortGamepadInputOptions::BroadcastModalClosed() const
{
}

FString UFortGamepadInputOptions::GetControllerPlatform() const
{
	return FString();
}

bool UFortGamepadInputOptions::HasCustomGamepadBindingChanges() const
{
	return false;
}

bool UFortGamepadInputOptions::IsCustomGamepadConfig(const FString& ConfigName) const
{
	return false;
}

void UFortGamepadInputOptions::ResetCustomGamepadToDefault()
{
}

void UFortGamepadInputOptions::SetControllerPlatform(const FString& InControllerPlatform)
{
}

void UFortGamepadInputOptions::SetControllerPlatformEnum(const ECommonGamepadType InControllerPlatform)
{
}
