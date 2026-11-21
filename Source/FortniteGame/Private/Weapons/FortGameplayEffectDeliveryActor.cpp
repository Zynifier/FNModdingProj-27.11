// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortGameplayEffectDeliveryActor.h"
#include "Net/UnrealNetwork.h"

void AFortGameplayEffectDeliveryActor::AddAdditionalExplodeEffectContainer(const FFortGameplayEffectContainerSpec& ExplodeContainer)
{
}

void AFortGameplayEffectDeliveryActor::BroadcastExplosion_Implementation(const TArray<AActor*>& HitActors, const TArray<FHitResult>& HitResults)
{
}

void AFortGameplayEffectDeliveryActor::ChangeInstigator(APawn* NewInstigator)
{
}

void AFortGameplayEffectDeliveryActor::DoExplosion()
{
}

void AFortGameplayEffectDeliveryActor::DoExplosionAsync()
{
}

void AFortGameplayEffectDeliveryActor::DoExplosionAtLocation(const FVector& ExplosionLocation)
{
}

void AFortGameplayEffectDeliveryActor::DoSingleActorHit(const FHitResult& Hit, const bool bBroadcastHit)
{
}

const UFortWorldItemDefinition* AFortGameplayEffectDeliveryActor::GetAssociatedItemDefinition() const
{
	return nullptr;
}

UPrimitiveComponent* AFortGameplayEffectDeliveryActor::GetCollisionComponent() const
{
	return nullptr;
}

void AFortGameplayEffectDeliveryActor::HandleMoveIgnoredActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

bool AFortGameplayEffectDeliveryActor::IsBeingKilled() const
{
	return false;
}

void AFortGameplayEffectDeliveryActor::Kill()
{
}

void AFortGameplayEffectDeliveryActor::KillTimerExpired()
{
}

void AFortGameplayEffectDeliveryActor::OnAssociatedItemDefinitionSet_Implementation(const UFortWorldItemDefinition* NewAssociatedWID)
{
}

void AFortGameplayEffectDeliveryActor::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AFortGameplayEffectDeliveryActor::OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AFortGameplayEffectDeliveryActor::OnComponentTouch(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void AFortGameplayEffectDeliveryActor::OnRep_HasExplodedReplay()
{
}

void AFortGameplayEffectDeliveryActor::OnRep_IsBeingKilled(bool bPreviousValue)
{
}

void AFortGameplayEffectDeliveryActor::SetCollisionComponent(UPrimitiveComponent* NewCollisionComponent)
{
}

void AFortGameplayEffectDeliveryActor::SetIgnoreInstigatorCollision(bool bShouldIgnore)
{
}

void AFortGameplayEffectDeliveryActor::SetNoiseMakingInstigatorOverride(AActor* NewActor)
{
}

void AFortGameplayEffectDeliveryActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameplayEffectDeliveryActor, bIsBeingKilled);
	DOREPLIFETIME(AFortGameplayEffectDeliveryActor, bHasExploded);
	DOREPLIFETIME(AFortGameplayEffectDeliveryActor, SpawnContext);
}
