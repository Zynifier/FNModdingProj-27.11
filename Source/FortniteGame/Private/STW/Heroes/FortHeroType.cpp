// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Heroes/FortHeroType.h"

TSubclassOf<UFrontendAnimInstance> UFortHeroType::GetFrontendAnimClass() const
{
	return TSubclassOf<UFrontendAnimInstance>();
}

UAnimMontage* UFortHeroType::GetFrontendAnimMontageIdleOverride() const
{
	return nullptr;
}

UFortHeroGameplayDefinition* UFortHeroType::GetHeroGameplayDefinition()
{
	return nullptr;
}

void UFortHeroType::GetSpecializations(TArray<UFortHeroSpecialization*>& OutSpecializations) const
{
}

FText UFortHeroType::GetSubType() const
{
	return FText();
}

void UFortHeroType::GetPreviewSkeletalMeshes(TArray<USkeletalMesh*>& OutList, TArray<TSubclassOf<UAnimInstance>>& OutAnimBP) const
{
}
