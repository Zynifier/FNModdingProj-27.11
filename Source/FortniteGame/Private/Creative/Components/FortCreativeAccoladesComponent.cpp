// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/FortCreativeAccoladesComponent.h"

bool UFortCreativeAccoladesComponent::CanGrantAccolade() const
{
	return false;
}

FString UFortCreativeAccoladesComponent::GetAccoladeJsonForLinkCode()
{
	return FString();
}

bool UFortCreativeAccoladesComponent::GrantAccolade(AFortPlayerController* PlayerController)
{
	return false;
}

void UFortCreativeAccoladesComponent::OnPlayModeChanged(AFortMinigame* Minigame, const bool bNewIsInPlayMode)
{
}
