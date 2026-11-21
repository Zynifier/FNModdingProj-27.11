// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortCharacterVehicle.h"
#include "Net/UnrealNetwork.h"

bool AFortCharacterVehicle::AllowInteractionBetweenFortVolume() const
{
	return false;
}

bool AFortCharacterVehicle::BP_CanInteract_Implementation(AController* InController)
{
	return false;
}

bool AFortCharacterVehicle::DoesDamageCauserPreventDamageFromBeingNulled_Implementation(AActor* DamageCauser)
{
	return false;
}

UAbilitySystemComponent* AFortCharacterVehicle::GetAbilitySystemComponent() const
{
	return nullptr;
}

USkeletalMeshComponent* AFortCharacterVehicle::GetEmoteMesh() const
{
	return nullptr;
}

bool AFortCharacterVehicle::GetHasGunner() const
{
	return false;
}

bool AFortCharacterVehicle::GetIsChargedJumpActive() const
{
	return false;
}

USkeletalMeshComponent* AFortCharacterVehicle::GetMechMesh() const
{
	return nullptr;
}

USkeletalMeshComponent* AFortCharacterVehicle::GetSkeletalMeshComponent() const
{
	return nullptr;
}

void AFortCharacterVehicle::OnPawnExitVehicle_Implementation(AFortPlayerPawn* PlayerPawn, FName ExitSocketName)
{
}

void AFortCharacterVehicle::OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
}

void AFortCharacterVehicle::OnRep_OverrideAbilitySystemComponent()
{
}

void AFortCharacterVehicle::OnRep_OverrideWrap()
{
}

void AFortCharacterVehicle::SetAllowInteractionBetweenFortVolumes(bool bInteractBetweenVolumes)
{
}

void AFortCharacterVehicle::StopEmoting()
{
}

void AFortCharacterVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCharacterVehicle, SoftOverrideItemWrap);
	DOREPLIFETIME(AFortCharacterVehicle, OverrideAbilitySystemComponent);
}
