// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/ControllableRidableComponent.h"
#include "Net/UnrealNetwork.h"

bool UControllableRidableComponent::CanBeControlled_Implementation(URiderComponent* Rider) const
{
	return false;
}

void UControllableRidableComponent::CancelBuildBar()
{
}

bool UControllableRidableComponent::CanStartSprinting() const
{
	return false;
}

const FText& UControllableRidableComponent::GetAbilityDisplayText() const
{
	static FText Dummy;
	return Dummy;
}

bool UControllableRidableComponent::IsSprintToggleable() const
{
	return false;
}

void UControllableRidableComponent::OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UControllableRidableComponent::OnRep_IsBeingControlled()
{
}

void UControllableRidableComponent::ServerDoJumpExit_Implementation()
{
}

void UControllableRidableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UControllableRidableComponent, bIsBeingControlled);
}
