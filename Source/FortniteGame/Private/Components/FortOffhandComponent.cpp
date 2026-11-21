// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortOffhandComponent.h"
#include "Net/UnrealNetwork.h"

UFortOffhandComponent::UFortOffhandComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortOffhandComponent::ClientEquipOffhandWeapon_Implementation(AFortWeapon* Weapon)
{
}

void UFortOffhandComponent::ClientHandleOffhandItemDestroyedDueToDurability_Implementation(FGuid ItemGuid)
{
}

void UFortOffhandComponent::ClientUnequipOffhandWeapon_Implementation()
{
}

AFortWeapon* UFortOffhandComponent::GetCurrentEquippedOffhandWeapon()
{
	return nullptr;
}

void UFortOffhandComponent::OnRep_CurrentEquippedOffhandWeapon(AFortWeapon* OldWeapon)
{
}

void UFortOffhandComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortOffhandComponent, OffhandPrimaryAbilitySpecHandle);
	DOREPLIFETIME(UFortOffhandComponent, OffhandEquippedAbilitySet);
	DOREPLIFETIME(UFortOffhandComponent, CurrentEquippedOffhandWeapon);
}
