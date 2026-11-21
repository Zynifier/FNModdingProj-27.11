// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/CustomCharacterPartAnimInstance.h"

bool UCustomCharacterPartAnimInstance::BackpackItemDefinitionHasAnyMetaTag(const TArray<FGameplayTag>& Tags)
{
	return false;
}

bool UCustomCharacterPartAnimInstance::CharacterItemDefinitionHasAnyMetaTag(const TArray<FGameplayTag>& Tags)
{
	return false;
}

void UCustomCharacterPartAnimInstance::CheckForBackbling(bool& bIsWearingBackbling, bool& bIsBackblingACape, bool& bIsBackblingLong, float LongBackblingThreshold) const
{
}

void UCustomCharacterPartAnimInstance::CheckForTail(bool& bHasTail) const
{
}

USkeletalMeshComponent* UCustomCharacterPartAnimInstance::FindChildCommponentFromAttachSocket(USkeletalMeshComponent* Parent, bool bIncludeAllDescendants, FName AttachSocket) const
{
	return nullptr;
}

AFortPlayerPawn* UCustomCharacterPartAnimInstance::GetAssociatedPlayerPawn() const
{
	return nullptr;
}

const EFortCustomPartType::Type UCustomCharacterPartAnimInstance::GetCharacterPartType() const
{
	return EFortCustomPartType::Type();
}

UFortPlayerAnimationInterface* UCustomCharacterPartAnimInstance::GetOwnerAnimationInterface() const
{
	return nullptr;
}

float UCustomCharacterPartAnimInstance::GetOwnerDirection() const
{
	return float();
}

UFortPlayerAnimInstance* UCustomCharacterPartAnimInstance::GetOwnerFortPlayerAnimInstance() const
{
	return nullptr;
}

UFrontendAnimInstance* UCustomCharacterPartAnimInstance::GetOwnerFrontEndAnimInstance() const
{
	return nullptr;
}

EFortCustomGender::Type UCustomCharacterPartAnimInstance::GetOwnerGender() const
{
	return EFortCustomGender::Type();
}

USkeletalMeshComponent* UCustomCharacterPartAnimInstance::GetOwnerSkeletalMeshComponent() const
{
	return nullptr;
}

float UCustomCharacterPartAnimInstance::GetOwnerZVelocity() const
{
	return float();
}

USkeletalMeshComponent* UCustomCharacterPartAnimInstance::GetPartSkeletalMeshComponent() const
{
	return nullptr;
}

bool UCustomCharacterPartAnimInstance::GliderItemDefinitionHasAnyMetaTag(const TArray<FGameplayTag>& Tags, bool bRequiresOpened)
{
	return false;
}

FRotator UCustomCharacterPartAnimInstance::MakeWaveRotator(FRotator Amplitudes, FRotator Frequencies, FRotator Offsets, bool bUseNoise, FVector Min, FVector Max)
{
	return FRotator();
}

float UCustomCharacterPartAnimInstance::MakeWaveScalar(float Amplitude, float Frequency, float Offset, bool bUseNoise, FVector2D MinMax)
{
	return float();
}

FVector UCustomCharacterPartAnimInstance::MakeWaveVector(FRotator Amplitudes, FRotator Frequencies, FRotator Offsets, bool bUseNoise, FVector Min, FVector Max)
{
	return FVector();
}

bool UCustomCharacterPartAnimInstance::PickaxeItemDefinitionHasAnyMetaTag(const TArray<FGameplayTag>& Tags, bool bRequiresEquipped)
{
	return false;
}
