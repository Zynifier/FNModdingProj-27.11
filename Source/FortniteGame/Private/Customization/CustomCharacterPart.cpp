// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/CustomCharacterPart.h"

TSubclassOf<UAnimInstance> UCustomCharacterPart::GetAnimClass() const
{
	return TSubclassOf<UAnimInstance>();
}

EFortCustomPartType::Type UCustomCharacterPart::GetCharacterPartType() const
{
	return EFortCustomPartType::Type();
}

TSoftObjectPtr<UParticleSystem> UCustomCharacterPart::GetEffectCascade() const
{
	return TSoftObjectPtr<UParticleSystem>();
}

TSoftObjectPtr<UNiagaraSystem> UCustomCharacterPart::GetEffectNiagara() const
{
	return TSoftObjectPtr<UNiagaraSystem>();
}

TSubclassOf<UAnimInstance> UCustomCharacterPart::GetFrontEndAnimClass() const
{
	return TSubclassOf<UAnimInstance>();
}

FName UCustomCharacterPart::GetIdleFXSocketName() const
{
	return FName();
}

TSubclassOf<UAnimInstance> UCustomCharacterPart::GetMannequinAnimClass() const
{
	return TSubclassOf<UAnimInstance>();
}

TMap<int32, UMaterialInterface*> UCustomCharacterPart::GetMaterialOverridesByIndex()
{
	return TMap<int32, UMaterialInterface*>();
}

EFortCustomPartType::Type UCustomCharacterPart::GetPartType() const
{
	return EFortCustomPartType::Type();
}

USkeletalMesh* UCustomCharacterPart::GetSkeletalMesh() const
{
	return nullptr;
}

TSoftClassPtr<UAnimInstance> UCustomCharacterPart::GetSoftAnimClass() const
{
	return TSoftClassPtr<UAnimInstance>();
}

bool UCustomCharacterPart::ShouldAutoActivate() const
{
	return false;
}
