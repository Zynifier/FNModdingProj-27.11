// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/CustomCharacterPartModifier.h"

void ACustomCharacterPartModifier::ApplyVariantsToTrackedComponents()
{
}

void ACustomCharacterPartModifier::ForceResetParticleSystems()
{
}

const EFortCustomPartType::Type ACustomCharacterPartModifier::GetCharacterPartType() const
{
	return EFortCustomPartType::Type();
}

FName ACustomCharacterPartModifier::GetIdleFXSocketName() const
{
	return FName();
}

UFXSystemComponent* ACustomCharacterPartModifier::GetIdleVFXComponent() const
{
	return nullptr;
}

UMeshComponent* ACustomCharacterPartModifier::GetSkeletalMeshForAssociatedPlayerPawnPartType() const
{
	return nullptr;
}

void ACustomCharacterPartModifier::SetCharacterActiveVariant(const FGameplayTag& ChannelTag, const FGameplayTag& VariantTag)
{
}

void ACustomCharacterPartModifier::SetChildMeshComponentsHidden(bool bHideChildComponents)
{
}

void ACustomCharacterPartModifier::SetChildParticleComponentsVisible(bool bVisible)
{
}

bool ACustomCharacterPartModifier::UsesIdleVFXNativeCustomAttachment() const
{
	return false;
}
