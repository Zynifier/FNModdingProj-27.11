// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortHeldObjectComponent.h"
#include "Net/UnrealNetwork.h"

bool UFortHeldObjectComponent::CanInteract(const AFortPlayerPawn* RequestingPawn)
{
	return false;
}

void UFortHeldObjectComponent::DropHeldObject()
{
}

void UFortHeldObjectComponent::DropObjectHeldInVehicle()
{
}

bool UFortHeldObjectComponent::GetAllowObjectToBeHeldInVehicle() const
{
	return false;
}

bool UFortHeldObjectComponent::GetBlocksVehicleDriverSeat() const
{
	return false;
}

float UFortHeldObjectComponent::GetGravityScale() const
{
	return float();
}

float UFortHeldObjectComponent::GetGravityZ() const
{
	return float();
}

AFortPlayerPawn* UFortHeldObjectComponent::GetInstigator() const
{
	return nullptr;
}

FFortItemEntry UFortHeldObjectComponent::GetItemEntry() const
{
	return FFortItemEntry();
}

float UFortHeldObjectComponent::GetMaxSpeed() const
{
	return float();
}

UMeshComponent* UFortHeldObjectComponent::GetMeshComponent() const
{
	return nullptr;
}

float UFortHeldObjectComponent::GetSweptTraceRadius() const
{
	return float();
}

void UFortHeldObjectComponent::GuideProjectileStopped(const FHitResult& ImpactResult)
{
}

void UFortHeldObjectComponent::HandleGuideProjectileDestroyed(AActor* DestroyedActor)
{
}

void UFortHeldObjectComponent::HandleOwnerDestroyed(AActor* DestroyedActor)
{
}

void UFortHeldObjectComponent::HandleOwnerDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortHeldObjectComponent::HoldObjectInVehicle()
{
}

bool UFortHeldObjectComponent::IsDropped() const
{
	return false;
}

bool UFortHeldObjectComponent::IsHeld() const
{
	return false;
}

bool UFortHeldObjectComponent::IsHeldInVehicle() const
{
	return false;
}

bool UFortHeldObjectComponent::IsPlaced() const
{
	return false;
}

bool UFortHeldObjectComponent::IsThrown() const
{
	return false;
}

bool UFortHeldObjectComponent::IsUnheld() const
{
	return false;
}

bool UFortHeldObjectComponent::OnCanInteract_Implementation(const AFortPlayerPawn* RequestingPawn)
{
	return false;
}

void UFortHeldObjectComponent::OnRep_bCollisionBlockedByPawns()
{
}

void UFortHeldObjectComponent::OnRep_OwningPawn(AFortPlayerPawn* LastOwningPawn)
{
}

void UFortHeldObjectComponent::OnRep_UsePreviewMaterial()
{
}

void UFortHeldObjectComponent::OnThrowComplete()
{
}

void UFortHeldObjectComponent::OnWeaponUnequipped()
{
}

void UFortHeldObjectComponent::PickupHeldObject(AFortPlayerPawn* PlayerPawn)
{
}

void UFortHeldObjectComponent::PlaceHeldObject()
{
}

void UFortHeldObjectComponent::RemoveHeldObjectFromVehicle()
{
}

void UFortHeldObjectComponent::SetMeshComponent(UMeshComponent* InMeshComponent)
{
}

void UFortHeldObjectComponent::SetPreviousOwner(AFortPlayerPawn* PlayerPawn)
{
}

void UFortHeldObjectComponent::ThrowHeldObject(const FVector& DetachLocation, const FRotator& ThrowDirection)
{
}

void UFortHeldObjectComponent::ThrownObjectEnteredWater(AFortWaterBodyActor* WaterBody, UFortWaterInteractionComponent* WaterInteractionComponent, bool bIsFirstBody)
{
}

void UFortHeldObjectComponent::ThrownObjectStopped(const FHitResult& ImpactResult)
{
}

void UFortHeldObjectComponent::TurnOffCollisionSettings()
{
}

void UFortHeldObjectComponent::TurnOnCollisionSettings()
{
}

void UFortHeldObjectComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortHeldObjectComponent, bUsePreviewMaterial);
	DOREPLIFETIME(UFortHeldObjectComponent, bCollisionBlockedByPawns);
	DOREPLIFETIME(UFortHeldObjectComponent, HeldObjectState);
	DOREPLIFETIME(UFortHeldObjectComponent, OwningPawn);
	DOREPLIFETIME(UFortHeldObjectComponent, ObjectPickupRotation);
	DOREPLIFETIME(UFortHeldObjectComponent, GuideProjectile);
}

void UFortHoldingObjectComponent::OnRep_HoldingObjectData(const FHoldingObjectData& PreviousData)
{
}

void UFortHoldingObjectComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortHoldingObjectComponent, HoldingObjectData);
}
