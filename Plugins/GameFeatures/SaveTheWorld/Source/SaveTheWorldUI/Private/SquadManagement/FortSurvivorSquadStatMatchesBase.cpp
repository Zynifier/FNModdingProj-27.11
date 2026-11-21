// Copyright Epic Games, Inc. All Rights Reserved.

#include "SquadManagement/FortSurvivorSquadStatMatchesBase.h"

FName UFortSurvivorSquadStatMatchesBase::GetIdOfSquadToManageBP() const
{
	return FName();
}

void UFortSurvivorSquadStatMatchesBase::SetIdOfSquadToManageBP(const FName& SquadId)
{
}

void UFortSurvivorSquadStatMatchesBase::SetSummaryView(bool bInSummaryView)
{
}

bool UFortSurvivorSquadStatMatchesBase::TryGetStaticSquadDataBP(FHomebaseSquad& OutSquadData) const
{
	return false;
}
