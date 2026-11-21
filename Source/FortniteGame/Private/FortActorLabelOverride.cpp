// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortActorLabelOverride.h"

bool IFortActorLabelOverrideInterface::CanOverrideLabel() const
{
	return false;
}

FText IFortActorLabelOverrideInterface::GetBaseLabel() const
{
	return FText();
}

FText IFortActorLabelOverrideInterface::GetDisplayLabel() const
{
	return FText();
}

FString IFortActorLabelOverrideInterface::GetLabelOverride() const
{
	return FString();
}

bool IFortActorLabelOverrideInterface::ResetLabelOverride(APlayerController* PlayerController)
{
	return false;
}

bool IFortActorLabelOverrideInterface::SetLabelOverride(APlayerController* PlayerController, const FString& NewLabelOverride)
{
	return false;
}
