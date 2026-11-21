// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortScoutDrone.h"
#include "Net/UnrealNetwork.h"

void AFortScoutDrone::GameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

AFortPawn* AFortScoutDrone::GetControllingPlayerPawn() const
{
	return nullptr;
}

FRotator AFortScoutDrone::GetDeltaRotator() const
{
	return FRotator();
}

void AFortScoutDrone::GetForwardAndRightDotProducts_Native(float& OutForwardDot, float& OutRightDot)
{
}

float AFortScoutDrone::GetHealthPercentage() const
{
	return float();
}

void AFortScoutDrone::OnRep_ControllingPlayerPawn()
{
}

void AFortScoutDrone::SetAffiliationAudio()
{
}

void AFortScoutDrone::SetTeamMatesIndicator(bool bState)
{
}

void AFortScoutDrone::SetupGameplayAudioParameters()
{
}

void AFortScoutDrone::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortScoutDrone, bIsSpeedBoosting);
	DOREPLIFETIME(AFortScoutDrone, ControllingPlayerPawn);
}

UAbilitySystemComponent* AFortScoutDrone::GetAbilitySystemComponent() const
{
	return nullptr;
}

void AFortScoutDrone::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}
