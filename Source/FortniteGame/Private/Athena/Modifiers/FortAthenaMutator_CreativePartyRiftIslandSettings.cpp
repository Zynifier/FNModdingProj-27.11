// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_CreativePartyRiftIslandSettings.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_CreativePartyRiftIslandSettings::MutatorSettingsChanged(const FPropertyOverrideData& OverrideData)
{
}

void AFortAthenaMutator_CreativePartyRiftIslandSettings::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_CreativePartyRiftIslandSettings, bAllowGuestPartyRiftsUserSetting);
}
