// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_Ghost.h"

void UFortControllerComponent_Ghost::EndGhostMode()
{
}

void UFortControllerComponent_Ghost::HandleAbilityEnded(const FAbilityEndedData& AbilityData)
{
}

bool UFortControllerComponent_Ghost::IsInGhostMode() const
{
	return false;
}

void UFortControllerComponent_Ghost::OnGhostModeChanged(AFortPlayerControllerGameplay* PlayerController, bool bEnteredGhostMode)
{
}

void UFortControllerComponent_Ghost::OnPawnDBNOStateChange(AFortPawn* Pawn, bool bNewDBNOState)
{
}

void UFortControllerComponent_Ghost::OnPlayerPossession(APawn* PossessPawn)
{
}

void UFortControllerComponent_Ghost::ReviveAndBecomeGhosted()
{
}

void UFortControllerComponent_Ghost::SetBecomeGhostOnDBNO(bool bEnable)
{
}

void UFortControllerComponent_Ghost::StartGhostMode()
{
}
