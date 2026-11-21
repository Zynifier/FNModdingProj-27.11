// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortInitializationInterface.h"

void IFortInitializationInterface::MatchStarted()
{
}

bool IFortInitializationInterface::NeedsWorldReady() const
{
	return false;
}

void IFortInitializationInterface::WorldReady()
{
}
