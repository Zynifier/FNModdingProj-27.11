// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortActorComponent_StateDriven.h"
#include "Net/UnrealNetwork.h"

FText UFortActorComponent_StateDriven::GetFailedInteractionString(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const
{
	return FText();
}

FText UFortActorComponent_StateDriven::GetInteractionString(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const
{
	return FText();
}

FText UFortActorComponent_StateDriven::GetSlottedItemDisplayName() const
{
	return FText();
}

const FFortItemEntry& UFortActorComponent_StateDriven::GetSlottedItemEntry() const
{
	static FFortItemEntry Dummy;
	return Dummy;
}

void UFortActorComponent_StateDriven::HandleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UFortActorComponent_StateDriven::HandleDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortActorComponent_StateDriven::HandleDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortActorComponent_StateDriven::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void UFortActorComponent_StateDriven::HandleInteraction(ABuildingActor* SelfActor, AFortPawn* InteractingPawn)
{
}

void UFortActorComponent_StateDriven::PlayBurstGameplayCue(const FGameplayTag GameplayCueTag) const
{
}

void UFortActorComponent_StateDriven::PopSlottedItem()
{
}

void UFortActorComponent_StateDriven::SetCurrentState(const FStateDrivenState& InCurrentState)
{
}

void UFortActorComponent_StateDriven::TriggerCustomEvent(const FGameplayTag& EventTag)
{
}

void UFortActorComponent_StateDriven::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortActorComponent_StateDriven, SlottedItemEntry);
}
