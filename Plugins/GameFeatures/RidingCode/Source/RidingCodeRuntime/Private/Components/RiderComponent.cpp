// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/RiderComponent.h"
#include "Net/UnrealNetwork.h"

void URiderComponent::ClientHandleFinishedCharacterCustomization(AFortPlayerPawn* PlayerPawn)
{
}

void URiderComponent::ClientNotifyEmoteFailure_Implementation(const FGameplayTagContainer ErrorTags)
{
}

void URiderComponent::HandleActorEndPlayWhileRiding(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void URiderComponent::HandleDBNOWhileRiding()
{
}

void URiderComponent::HandleDeferredExitVelocity(const FVector ExitVelocity)
{
}

void URiderComponent::HandleGamepadRidingExitReleased()
{
}

void URiderComponent::HandleOnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void URiderComponent::HandlePawnDiedWhileRiding(AFortPawn* DeadPawn)
{
}

void URiderComponent::HandlePawnTeleported(AFortPawn* TeleportedPawn)
{
}

void URiderComponent::HandleRidableMovementModeChanged(ACharacter* InCharacter, EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
}

void URiderComponent::HandleRiderDidDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum)
{
}

void URiderComponent::HandleRiderTakenDamage(AActor* DamageOnOwnerPawnDamageddActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void URiderComponent::HandleRidingExitPressed()
{
}

void URiderComponent::HandleRidingExitReleased()
{
}

void URiderComponent::HandleStartedRiding_Implementation(URidableComponent* Ridable)
{
}

void URiderComponent::HandleStoppedRiding_Implementation(URidableComponent* Ridable)
{
}

bool URiderComponent::IsRidingActor() const
{
	return false;
}

void URiderComponent::OnMovementModeChanged(ACharacter* InCharacter, EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
}

void URiderComponent::OnRep_ActiveRidable()
{
}

void URiderComponent::OnRep_IsSprintingReplay()
{
}

void URiderComponent::OnRep_RidableControlRuntimeUpdated()
{
}

void URiderComponent::ServerRidingExit_Implementation()
{
}
bool URiderComponent::ServerRidingExit_Validate()
{
	return true;
}

bool URiderComponent::StartRidingActor(AActor* TargetActor)
{
	return false;
}

bool URiderComponent::StopRidingActor(bool bLaunchRider, bool bFindDismountLocation, bool bIsJumpExit)
{
	return false;
}

void URiderComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(URiderComponent, ActiveRidable);
	DOREPLIFETIME(URiderComponent, RidableControlRuntimeData);
	DOREPLIFETIME(URiderComponent, bIsSprintingReplay);
	DOREPLIFETIME(URiderComponent, bPreventExitRidingFromInput);
}
