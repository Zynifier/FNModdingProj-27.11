// Copyright Epic Games, Inc. All Rights Reserved.

#include "DynamicCapsuleComponent.h"
#include "Net/UnrealNetwork.h"

bool UDynamicCapsuleComponent::ApplyDynamicCapsule(const FGameplayTag& Tag, float CapsuleRadius, float CapsuleHalfHeight)
{
	return false;
}

bool UDynamicCapsuleComponent::ApplyDynamicCapsuleWithLocationAdjust(const FGameplayTag& Tag, float CapsuleRadius, float CapsuleHalfHeight, double NewRelativeMeshHeight)
{
	return false;
}

void UDynamicCapsuleComponent::OnRep_DynamicCapsuleEntryStack()
{
}

void UDynamicCapsuleComponent::OnRep_ReplicatedCapsuleState()
{
}

bool UDynamicCapsuleComponent::RemoveDynamicCapsule(const FGameplayTag& Tag)
{
	return false;
}

void UDynamicCapsuleComponent::ServerApplyDynamicCapsule_Implementation(const FGameplayTag& Tag, float CapsuleRadius, float CapsuleHalfHeight, double NewRelativeMeshHeight)
{
}
bool UDynamicCapsuleComponent::ServerApplyDynamicCapsule_Validate(const FGameplayTag& Tag, float CapsuleRadius, float CapsuleHalfHeight, double NewRelativeMeshHeight)
{
	return true;
}

void UDynamicCapsuleComponent::ServerRemoveDynamicCapsule_Implementation(const FGameplayTag& Tag)
{
}
bool UDynamicCapsuleComponent::ServerRemoveDynamicCapsule_Validate(const FGameplayTag& Tag)
{
	return true;
}

void UDynamicCapsuleComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UDynamicCapsuleComponent, DynamicCapsuleEntryStack);
	DOREPLIFETIME(UDynamicCapsuleComponent, ReplicatedCapsuleState);
}
