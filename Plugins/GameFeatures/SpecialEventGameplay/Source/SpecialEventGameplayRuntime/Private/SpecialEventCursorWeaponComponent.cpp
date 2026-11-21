// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventCursorWeaponComponent.h"
#include "Net/UnrealNetwork.h"

bool USpecialEventCursorWeaponComponent::GetCurrentHitResult(FHitResult& OutHitResult) const
{
	return false;
}

USpecialEventCursorWeaponComponent* USpecialEventCursorWeaponComponent::GetCurrentSpecialEventCursorWeaponComponent(const AFortPlayerPawn* Pawn)
{
	return nullptr;
}

USpecialEventCursorPawnComponent* USpecialEventCursorWeaponComponent::GetCursorPawnComponent() const
{
	return nullptr;
}

USpecialEventCursorPawnComponent* USpecialEventCursorWeaponComponent::GetSpecialEventCursorPawnComponentForCurrentWeapon(const AFortPlayerPawn* Pawn)
{
	return nullptr;
}

USpecialEventCursorPawnComponent* USpecialEventCursorWeaponComponent::GetSpecialEventCursorPawnComponentForWeapon(const AFortWeapon* Weapon)
{
	return nullptr;
}

void USpecialEventCursorWeaponComponent::OnBeamFired(AFortWeapon* Weapon, bool bUsePersistentBeam, UFXSystemComponent* PSC, const FVector& BeamOrigin, const FVector& HitLocation)
{
}

void USpecialEventCursorWeaponComponent::OnEquip(AFortWeapon* Weapon)
{
}

void USpecialEventCursorWeaponComponent::OnGetAimRotOverride(const AFortWeapon* Weapon, const EFortAbilityTargetingSource TargetingSource, FRotator& OutOverride, bool& bOutExecutionResult)
{
}

void USpecialEventCursorWeaponComponent::OnPlayImpactFX(AFortWeapon* Weapon, const FHitResult& HitResult, UFXSystemComponent* FXSystemComponent)
{
}

void USpecialEventCursorWeaponComponent::OnRep_CursorPawnComponent()
{
}

void USpecialEventCursorWeaponComponent::OnUnEquip(AFortWeapon* Weapon)
{
}

void USpecialEventCursorWeaponComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USpecialEventCursorWeaponComponent, CursorPawnComponent);
}
