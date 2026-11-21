// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventPhase.h"
#include "Net/UnrealNetwork.h"

void ASpecialEventPhase::DebugActivatePhase()
{
}

FGameplayTag ASpecialEventPhase::GetPhaseTag() const
{
	return FGameplayTag();
}

void ASpecialEventPhase::OnPhaseFinished()
{
}

void ASpecialEventPhase::OnRep_PhaseState()
{
}

void ASpecialEventPhase::SetHUDElementVisibility(const FGameplayTagContainer& HUDElementTags, bool bHideElements)
{
}

void ASpecialEventPhase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASpecialEventPhase, PhaseState);
}
