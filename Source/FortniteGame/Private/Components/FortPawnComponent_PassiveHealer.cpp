// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortPawnComponent_PassiveHealer.h"
#include "Net/UnrealNetwork.h"

FText UFortPawnComponent_PassiveHealer::GetGreetingPassiveHealingText() const
{
	return FText();
}

void UFortPawnComponent_PassiveHealer::OnHealedPlayerStartedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting)
{
}

void UFortPawnComponent_PassiveHealer::OnHealedPlayerStoppedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting)
{
}

void UFortPawnComponent_PassiveHealer::OnRep_PassiveHealingRunning()
{
}

void UFortPawnComponent_PassiveHealer::Start()
{
}

void UFortPawnComponent_PassiveHealer::Stop()
{
}

void UFortPawnComponent_PassiveHealer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPawnComponent_PassiveHealer, PassiveHealerInteractionCollisionProfile);
	DOREPLIFETIME(UFortPawnComponent_PassiveHealer, PassiveHealerInteractionBoxExtent);
	DOREPLIFETIME(UFortPawnComponent_PassiveHealer, PassiveHealerInteractionBoxOffset);
	DOREPLIFETIME(UFortPawnComponent_PassiveHealer, bPassiveHealingRunning);
	DOREPLIFETIME(UFortPawnComponent_PassiveHealer, SelectedEmotePrimaryAssetId);
	DOREPLIFETIME(UFortPawnComponent_PassiveHealer, SelectedInteractText);
	DOREPLIFETIME(UFortPawnComponent_PassiveHealer, SelectedGreetingText);
}
