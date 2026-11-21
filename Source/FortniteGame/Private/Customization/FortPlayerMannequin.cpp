// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/FortPlayerMannequin.h"

void AFortPlayerMannequin::ChoosePartsForHeroType(UFortHeroType* HeroType, const TArray<FMcpVariantChannelInfo> InOverrideVariants, const bool bClearOldParts)
{
}

void AFortPlayerMannequin::ClearExistingCosmeticPetInstance()
{
}

AFortPlayerPet* AFortPlayerMannequin::CreateCosmeticPetInstance(AFortPlayerPawn* InPawn)
{
	return nullptr;
}

bool AFortPlayerMannequin::CyclePartBP(EFortCustomPartType::Type Part, bool bNextPart)
{
	return false;
}

FGameplayTagContainer AFortPlayerMannequin::GatherMetaTags(const UAthenaCosmeticItemDefinition* CosmeticItem) const
{
	return FGameplayTagContainer();
}

void AFortPlayerMannequin::GetAllPartSkeletalMeshComponents(TArray<USkeletalMeshComponent*>& SkeletalMeshComponents)
{
}

const UAthenaCharacterItemDefinition* AFortPlayerMannequin::GetAthenaCharacterItemDefinition() const
{
	return nullptr;
}

TArray<UCustomCharacterPart*> AFortPlayerMannequin::GetCustomCharacterParts()
{
	return TArray<UCustomCharacterPart*>();
}

UAudioComponent* AFortPlayerMannequin::GetEmoteAudioComponent(const FName InSoundId) const
{
	return nullptr;
}

EFortCustomGender::Type AFortPlayerMannequin::GetGender() const
{
	return EFortCustomGender::Type();
}

USkeletalMeshComponent* AFortPlayerMannequin::GetPartSkeletalMeshComponent(EFortCustomPartType::Type Part) const
{
	return nullptr;
}

USkeletalMeshComponent* AFortPlayerMannequin::GetWeaponSkeletalMeshComponent() const
{
	return nullptr;
}

FCosmeticsEventHandle AFortPlayerMannequin::RegisterOnCosmeticApplicationCompleted_BP(const FCosmeticsEventTargetDynamicDelegate& Delegate, int32 Flags)
{
	return FCosmeticsEventHandle();
}

bool AFortPlayerMannequin::RemovePart(EFortCustomPartType::Type Part)
{
	return false;
}

void AFortPlayerMannequin::ResetAthenaCharacterDefAndVariants(UAthenaCharacterItemDefinition* NewAthenaCharacter, const TArray<FMcpVariantChannelInfo>& InOverrideVariants)
{
}

void AFortPlayerMannequin::SetAllowEmoteAudioComponents(const bool InAllowEmoteAudioComponents)
{
}

void AFortPlayerMannequin::SetAthenaBackpackAndCharacterDefAndVariants(UAthenaBackpackItemDefinition* NewAthenaBackpack, const TArray<FMcpVariantChannelInfo>& InBackpackOverrideVariants, UAthenaCharacterItemDefinition* NewAthenaCharacter, const TArray<FMcpVariantChannelInfo>& InCharacterOverrideVariants)
{
}

void AFortPlayerMannequin::SetAthenaBackpackDefAndVariants(UAthenaBackpackItemDefinition* NewAthenaBackpack, const TArray<FMcpVariantChannelInfo>& InOverrideVariants)
{
}

void AFortPlayerMannequin::SetAthenaCharacterDefAndVariants(UAthenaCharacterItemDefinition* NewAthenaCharacter, const TArray<FMcpVariantChannelInfo>& InOverrideVariants)
{
}

void AFortPlayerMannequin::SetHeroType(UFortHeroType* NewHeroType)
{
}

void AFortPlayerMannequin::SetMannequinLightingChannels(bool bChannel0, bool bChannel1, bool bChannel2)
{
}

bool AFortPlayerMannequin::SetPart(EFortCustomPartType::Type Part, UCustomCharacterPart* PartAsset)
{
	return false;
}

void AFortPlayerMannequin::SetSkeletalMesh(USkeletalMesh* SkeletalMesh)
{
}

bool AFortPlayerMannequin::SetWeaponSkeletalMesh(USkeletalMesh* SkeletalMesh)
{
	return false;
}

void AFortPlayerMannequin::ToggleGenderBP()
{
}

void AFortPlayerMannequin::UpdateMorphTargets()
{
}
