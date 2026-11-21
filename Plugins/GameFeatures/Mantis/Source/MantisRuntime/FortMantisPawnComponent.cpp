// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMantisPawnComponent.h"

UFortMantisPawnComponent::UFortMantisPawnComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const FFortMantisTechniqueMetadata& UFortMantisPawnComponent::GetCurrentTechniqueMetadata() const
{
	static FFortMantisTechniqueMetadata Dummy;
	return Dummy;
}

AActor* UFortMantisPawnComponent::GetLockOnTarget() const
{
	return nullptr;
}

const UAnimMontage* UFortMantisPawnComponent::GetMontageForCurrentTechnique() const
{
	return nullptr;
}

bool UFortMantisPawnComponent::HasCurrentTechniqueMetadataBeenSet() const
{
	return false;
}

bool UFortMantisPawnComponent::HasLockOnTarget() const
{
	return false;
}

bool UFortMantisPawnComponent::IsPerformingLockOn() const
{
	return false;
}

bool UFortMantisPawnComponent::IsSpecificInputPressed(EFortMantisTechniqueActivationInputType InputType)
{
	return false;
}

void UFortMantisPawnComponent::OnCharacterMovementPreUpdate(UCharacterMovementComponent* CharMoveComp, float DeltaSeconds)
{
}

void UFortMantisPawnComponent::OnOwnerWeaponHolstered()
{
}

void UFortMantisPawnComponent::OnPostPhysicsRotation(UCharacterMovementComponent* CharMoveComp, float DeltaSeconds)
{
}

void UFortMantisPawnComponent::SetBranchRule(EFortMantisBranchRule InBranchRule, EFortMantisBranchPath InBranchPath)
{
}

void UFortMantisPawnComponent::SetLockOnState(bool bEnabled, AActor* TargetActor)
{
}

void UFortMantisPawnComponent::SimulateInputEvent(EFortMantisTechniqueActivationInputType InputType, EFortMantisTechniqueActivationTimingType InputTiming, const bool bForceProcessEvent)
{
}

bool UFortMantisPawnComponent::TryManuallyEndCurrentTechnique()
{
	return false;
}

bool UFortMantisPawnComponent::TryManuallyStartTechnique(const int32 TechniqueDataIndex)
{
	return false;
}
