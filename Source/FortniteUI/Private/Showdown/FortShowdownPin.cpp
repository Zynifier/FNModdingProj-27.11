// Copyright Epic Games, Inc. All Rights Reserved.

#include "Showdown/FortShowdownPin.h"

int32 UFortShowdownPin::GetAlternativeScoreToDisplay() const
{
	return int32();
}

int32 UFortShowdownPin::GetScoreToDisplay(bool bUseBestPin)
{
	return int32();
}

bool UFortShowdownPin::ShouldUseAlternativeScore() const
{
	return false;
}
