// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/FortMontageItemDefinitionBase.h"

bool UFortMontageItemDefinitionBase::CanAccessMontageItem(const AFortPlayerController* FortPC) const
{
	return false;
}

bool UFortMontageItemDefinitionBase::CanActivateMontageItem(const AFortPlayerController* FortPC, FGameplayTagContainer& OutFailureTags) const
{
	return false;
}

bool UFortMontageItemDefinitionBase::CanShowMontageItem(const FFortAthenaLoadout& Loadout) const
{
	return false;
}

TSoftObjectPtr<UAnimMontage> UFortMontageItemDefinitionBase::GetAnimation(EFortCustomBodyType::Type BodyType, EFortCustomGender::Type Gender, AFortPlayerPawn* PawnContext) const
{
	return TSoftObjectPtr<UAnimMontage>();
}

UAnimMontage* UFortMontageItemDefinitionBase::GetAnimationHardReference(EFortCustomBodyType::Type BodyType, EFortCustomGender::Type Gender, AFortPlayerPawn* PawnContext) const
{
	return nullptr;
}

TSoftObjectPtr<UAnimMontage> UFortMontageItemDefinitionBase::GetFrontendPreviewAnimation(EFortCustomBodyType::Type BodyType, AFortPlayerPawn* PreviewPawn, EFortCustomGender::Type Gender) const
{
	return TSoftObjectPtr<UAnimMontage>();
}

UAnimMontage* UFortMontageItemDefinitionBase::GetFrontendPreviewAnimationHardReference(EFortCustomBodyType::Type BodyType, EFortCustomGender::Type Gender, AFortPlayerPawn* PawnContext) const
{
	return nullptr;
}

bool UFortMontageItemDefinitionBase::HasCosmeticDrivenMotageSection() const
{
	return false;
}

bool UFortMontageItemDefinitionBase::IsMontageItemEmoteWheelExclusive(const AFortPlayerController* FortPC) const
{
	return false;
}

FName UFortMontageItemDefinitionBase::PickCosmeticDrivenSectionByName(AFortPawn* PawnPlayingMotage) const
{
	return FName();
}

FName UFortMontageItemDefinitionBase::PickMontageSection(const UAnimMontage* Montage, AFortPawn* FortPawn) const
{
	return FName();
}

FName UFortMontageItemDefinitionBase::PickRandomSectionByName(float RandomNumber) const
{
	return FName();
}

void UFortMontageItemDefinitionBase::PreviewInPIE()
{
}

bool UFortMontageItemDefinitionBase::ShouldHolsterWeapon(AFortPawn* FortPawn) const
{
	return false;
}

bool UFortMontageItemDefinitionBase::ShouldPlayRandomSectionByName() const
{
	return false;
}
