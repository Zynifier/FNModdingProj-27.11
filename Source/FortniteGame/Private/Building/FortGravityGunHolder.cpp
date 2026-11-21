// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/FortGravityGunHolder.h"

AActor* AFortGravityGunHolder::AttemptCloneActorToHold(AActor* InActor) const
{
	return nullptr;
}

void AFortGravityGunHolder::CalculateLaunchVelocity(const bool bDropped, float& OutThrowSpeed, FVector& OutVelocity)
{
}

void AFortGravityGunHolder::HandleThrowHeldObject()
{
}

void AFortGravityGunHolder::HeldObjectHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
}

void AFortGravityGunHolder::LogHeldBuildingObjectDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortGravityGunHolder::LogHeldObjectDestroyed(AActor* InHeldObjectDestroying)
{
}

void AFortGravityGunHolder::SetHeldObject(AActor* InHeldObject)
{
}

void AFortGravityGunHolder::UpdateAudio_Implementation(const float DeltaSeconds)
{
}
