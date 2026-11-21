// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaPlayerHitPointBarBase.h"

UAthenaPlayerHitPointBarBase::UAthenaPlayerHitPointBarBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

float UAthenaPlayerHitPointBarBase::GetCurrentValuePercentage() const
{
	return float();
}

float UAthenaPlayerHitPointBarBase::GetLastValuePercentage() const
{
	return float();
}

bool UAthenaPlayerHitPointBarBase::IsShieldSegmented() const
{
	return false;
}
