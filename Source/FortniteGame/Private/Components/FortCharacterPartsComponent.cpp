// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortCharacterPartsComponent.h"
#include "Net/UnrealNetwork.h"

bool UFortCharacterPartsComponent::ApplyParts(const TArray<UCustomCharacterPart*>& Parts)
{
	return false;
}

TArray<USkeletalMeshComponent*> UFortCharacterPartsComponent::GetSkeletalMeshesForAllParts()
{
	return TArray<USkeletalMeshComponent*>();
}

USkeletalMeshComponent* UFortCharacterPartsComponent::GetSkeletalMeshForPartTag(FGameplayTag PartTag)
{
	return nullptr;
}

USkeletalMeshComponent* UFortCharacterPartsComponent::GetSkeletalMeshForPartType(EFortCustomPartType::Type PartType)
{
	return nullptr;
}

void UFortCharacterPartsComponent::OnRep_CharacterParts(TArray<UCustomCharacterPart*> PreviousParts)
{
}

void UFortCharacterPartsComponent::RemoveAllParts()
{
}

bool UFortCharacterPartsComponent::RemovePart(EFortCustomPartType::Type PartType)
{
	return false;
}

bool UFortCharacterPartsComponent::RemovePartByGameplayTag(FGameplayTag PartTag)
{
	return false;
}

bool UFortCharacterPartsComponent::RestoreParts()
{
	return false;
}

void UFortCharacterPartsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCharacterPartsComponent, CharacterPartList);
}
