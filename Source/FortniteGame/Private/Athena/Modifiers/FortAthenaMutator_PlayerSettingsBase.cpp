// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_PlayerSettingsBase.h"
#include "Net/UnrealNetwork.h"

const FGameplayTagContainer UFortPlayerSettingsComponentBase::GetHUDVisibilityTags_Implementation() const
{
	return FGameplayTagContainer();
}

bool UFortPlayerSettingsComponentBase::IsSettingEnabled(const FName& PropertyName) const
{
	return false;
}

void UFortPlayerSettingsComponentBase::OnRep_AbilitySetOptionData()
{
}

void UFortPlayerSettingsComponentBase::OnRep_bGoldCurrencyResourceWidgetVisible()
{
}

void UFortPlayerSettingsComponentBase::OnRep_bInfiniteAmmo()
{
}

void UFortPlayerSettingsComponentBase::OnRep_bMetalResourceWidgetVisible()
{
}

void UFortPlayerSettingsComponentBase::OnRep_bStoneResourceWidgetVisible()
{
}

void UFortPlayerSettingsComponentBase::OnRep_bWoodResourceWidgetVisible()
{
}

void UFortPlayerSettingsComponentBase::OnRep_CreativeBossHealthDisplayMode()
{
}

void UFortPlayerSettingsComponentBase::OnRep_EnabledSettings()
{
}

void UFortPlayerSettingsComponentBase::OnRep_NameplateDisplayMode()
{
}

void UFortPlayerSettingsComponentBase::OnRep_PlayerHealthIndicatorDisplayMode()
{
}

void UFortPlayerSettingsComponentBase::ResolvePendingRepOverrides()
{
}

void UFortPlayerSettingsComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, BuildingMode);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bAimAssistAllowed);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bIsPlayerTriggeredRespawnAllowed);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, OnlyAllowRespawningIfPlayerStartPadsFound);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bInstantReload);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bInfiniteAmmo);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bInfiniteConsumables);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bInfiniteResources);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bAllowItemDrop);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bAllowItemPickUp);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, MaxItemSlots);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bWoodResourceWidgetVisible);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bStoneResourceWidgetVisible);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bMetalResourceWidgetVisible);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bGoldCurrencyResourceWidgetVisible);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bApplyJumpPenalty);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bGliderRedeploy);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bFlyEnabled);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bAllowFlightSprint);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, FlySpeedPreset);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, FlySpeedModifierIndex);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bAllowFriendlyFire);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bVehiclesDamageObjects);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bVehiclesDamageVehicles);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bEnableVehiclesDamageObjects);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, MaximumResources);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, NameplateDisplayMode);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, bLimitNamePlateMaxDistance);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, NameplateDisplayDistanceMeters);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, NameplateDisplayDistance);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, NameplateFocusAngleDegrees);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, NameplateFocusAngle);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, NameplateFocusTime);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, NameplateFocusMode);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, NameplateLineOfSight);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, PlayerHealthIndicatorDisplayMode);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, CreativeBossHealthDisplayMode);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, AbilitySetOptionData);
	DOREPLIFETIME(UFortPlayerSettingsComponentBase, EnabledSettings);
}
