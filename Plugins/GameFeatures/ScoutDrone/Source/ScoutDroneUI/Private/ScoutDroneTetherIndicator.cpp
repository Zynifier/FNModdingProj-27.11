// Copyright Epic Games, Inc. All Rights Reserved.

#include "ScoutDroneTetherIndicator.h"

UScoutDroneTetherIndicator::UScoutDroneTetherIndicator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

AFortScoutDrone* UScoutDroneTetherIndicator::GetControlledDrone() const
{
	return nullptr;
}
