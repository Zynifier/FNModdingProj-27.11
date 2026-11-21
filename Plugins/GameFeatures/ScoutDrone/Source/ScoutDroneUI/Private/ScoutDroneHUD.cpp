// Copyright Epic Games, Inc. All Rights Reserved.

#include "ScoutDroneHUD.h"

UScoutDroneHUD::UScoutDroneHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

AFortScoutDrone* UScoutDroneHUD::GetControlledDrone() const
{
	return nullptr;
}

float UScoutDroneHUD::GetTargetConfirmationTime()
{
	return float();
}
