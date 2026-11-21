// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_WeaponSettings.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_WeaponSettings::AddDataSourceForClassSlot(UFortItemDefinition* ItemDefinition, const uint8 ClassSlot, UObject* DataSource)
{
}

void AFortAthenaMutator_WeaponSettings::AddDataSourceForTeam(UFortItemDefinition* ItemDefinition, const uint8 TeamIndex, UObject* DataSource)
{
}

void AFortAthenaMutator_WeaponSettings::RemoveDataSource(UObject* DataSource)
{
}

void AFortAthenaMutator_WeaponSettings::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_WeaponSettings, WeaponSettings);
}

void UFortWeaponSettingsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortWeaponSettingsComponent, bPickAxe);
	DOREPLIFETIME(UFortWeaponSettingsComponent, ItemDefinition);
	DOREPLIFETIME(UFortWeaponSettingsComponent, TeamIndex);
	DOREPLIFETIME(UFortWeaponSettingsComponent, ClassSlot);
	DOREPLIFETIME(UFortWeaponSettingsComponent, RangeMultiplier);
	DOREPLIFETIME(UFortWeaponSettingsComponent, ConeAngleMultiplier);
	DOREPLIFETIME(UFortWeaponSettingsComponent, Enabled);
	DOREPLIFETIME(UFortWeaponSettingsComponent, OverriddenPropertyNames);
}
