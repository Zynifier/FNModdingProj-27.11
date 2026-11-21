// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortComponent_Energy.h"

UFortComponent_Energy::UFortComponent_Energy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortComponent_Energy::AddEnergy(float& OutAmountOfEnergyAdded, float AmountOfEnergyToAdd, UObject* OptionalEnergySource, bool bBroadcastEnergyPercentChanged)
{
	return false;
}

void UFortComponent_Energy::ApplyRegenDataOverride(const FGameplayTag& RegenOverrideIdentifier, const float NewRechargeAmountPerSecond, const float NewRechargeDelayInSeconds, const float NewRechargePercentageLimit)
{
}

float UFortComponent_Energy::GetCurrentEnergyPercentage() const
{
	return float();
}

void UFortComponent_Energy::HandleAbilitySystemComponentInitialized(UFortAbilitySystemComponent* AbilitySystemComponent, AFortPlayerPawn* PlayerPawn)
{
}

void UFortComponent_Energy::HandleAbilitySystemComponentInvalidated()
{
}

bool UFortComponent_Energy::HasSufficientEnergy(float EnergyAmountToTest) const
{
	return false;
}

void UFortComponent_Energy::OnMutatorUpdated()
{
}

void UFortComponent_Energy::OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
}

void UFortComponent_Energy::RegisterMutatorUpdatedDelegate(APawn* AffectedPawn)
{
}

bool UFortComponent_Energy::RemoveRegenDataOverride(const FGameplayTag& RegenOverrideIdentifier)
{
	return false;
}

bool UFortComponent_Energy::SetAllEnergyUsageFree(bool bShouldEnergyUsageBeFree)
{
	return false;
}

bool UFortComponent_Energy::StartAddingEnergy(float EnergyToAddPerSecond, const FGameplayTag& EnergySourceIdentifier, UObject* OptionalEnergySource)
{
	return false;
}

bool UFortComponent_Energy::StartUsingEnergy(float EnergyToUseToStart, float EnergyToUsePerSecond, const FGameplayTag& EnergyUseIdentifier, UObject* OptionalEnergyUser)
{
	return false;
}

bool UFortComponent_Energy::StopAddingEnergy(const FGameplayTag& EnergyUseIdentifier, UObject* OptionalEnergySource)
{
	return false;
}

bool UFortComponent_Energy::StopUsingEnergy(const FGameplayTag& EnergyUseIdentifier, UObject* OptionalEnergyUser)
{
	return false;
}

bool UFortComponent_Energy::UseEnergy(float& OutAmountOfEnergyUsed, float AmountOfEnergyToUse, bool bUseEnergyEvenOnFailure, UObject* OptionalEnergyUser, bool bBroadcastEnergyPercentChanged)
{
	return false;
}
