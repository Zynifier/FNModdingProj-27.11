// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattlePassLandingPageButton.h"

const FBattlePassLandingPageButtonDisplayDetails& UBattlePassLandingPageButton::GetBattlePassDisplayDetails() const
{
	static FBattlePassLandingPageButtonDisplayDetails Dummy;
	return Dummy;
}
