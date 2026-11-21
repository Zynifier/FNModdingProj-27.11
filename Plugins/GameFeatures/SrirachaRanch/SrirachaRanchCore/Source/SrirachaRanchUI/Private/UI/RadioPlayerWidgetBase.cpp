// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/RadioPlayerWidgetBase.h"

float URadioPlayerWidgetBase::GetRadioStatusOnScreenTime()
{
	return float();
}

bool URadioPlayerWidgetBase::HaveToChangeSongInfo(const FFortMediaInBandMetadata& MediaMetadata)
{
	return false;
}

bool URadioPlayerWidgetBase::IsMetadataEmpty(const FFortMediaInBandMetadata& MediaMetadata)
{
	return false;
}

void URadioPlayerWidgetBase::NativeEnteredVehicle()
{
}

void URadioPlayerWidgetBase::NativeExitedVehicle()
{
}

void URadioPlayerWidgetBase::OnControllerGainedNewFortPawn(AFortPawn* FortPawn)
{
}
