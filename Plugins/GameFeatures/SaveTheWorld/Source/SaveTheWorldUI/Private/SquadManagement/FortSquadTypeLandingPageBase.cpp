// Copyright Epic Games, Inc. All Rights Reserved.

#include "SquadManagement/FortSquadTypeLandingPageBase.h"

FName UFortSquadSelectorButton::GetIdOfSquadToManageBP() const
{
	return FName();
}

void UFortSquadSelectorButton::SetIdOfSquadToManageBP(const FName& SquadId)
{
}

bool UFortSquadSelectorButton::TryGetStaticSquadDataBP(FHomebaseSquad& OutSquadData) const
{
	return false;
}

void UFortSquadTypeLandingPageBase::HandleBackInputAction(bool& bPassThrough)
{
}

void UFortSquadTypeLandingPageBase::HandlePendingNavigationOp()
{
}

bool UFortSquadTypeLandingPageBase::IsScreenWIFE() const
{
	return false;
}
