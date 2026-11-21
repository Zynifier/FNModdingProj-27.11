// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/RidableComponent.h"
#include "Net/UnrealNetwork.h"

URidableComponent::URidableComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool URidableComponent::CanBePet_Implementation(URiderComponent* Rider) const
{
	return false;
}

bool URidableComponent::CanBeRiddenBP_Implementation(URiderComponent* Rider) const
{
	return false;
}

bool URidableComponent::CanRiderPlayEmote_Implementation(const URiderComponent* Rider) const
{
	return false;
}

const FRidingPettingData& URidableComponent::GetPettingData() const
{
	static FRidingPettingData Dummy;
	return Dummy;
}

USceneComponent* URidableComponent::GetRidingAttachComponent_Implementation() const
{
	return nullptr;
}

void URidableComponent::GetRidingCapsuleSize_Implementation(const URiderComponent* Rider, float OriginalRadius, float OriginalHalfHeight, float& OutRadius, float& OutHalfHeight) const
{
}

void URidableComponent::GetRidingEmoteCapsuleSize_Implementation(const URiderComponent* Rider, float OriginalRadius, float OriginalHalfHeight, float& OutRadius, float& OutHalfHeight) const
{
}

void URidableComponent::HandleRiderEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void URidableComponent::HandleRiderStartedRiding_Implementation(URiderComponent* Rider)
{
}

void URidableComponent::HandleRiderStoppedRiding_Implementation(URiderComponent* Rider)
{
}

bool URidableComponent::IsBeingRidden() const
{
	return false;
}

bool URidableComponent::IsFlying() const
{
	return false;
}

bool URidableComponent::IsSprinting() const
{
	return false;
}

void URidableComponent::OnRep_ActiveRider()
{
}

bool URidableComponent::ShouldCameraFocusOnRidable_Implementation(const URiderComponent* Rider) const
{
	return false;
}

void URidableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(URidableComponent, ActiveRider);
}
