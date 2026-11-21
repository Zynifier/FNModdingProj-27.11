// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/FortSoundLibrary_Weapon.h"

void UFortWeaponSoundLibraryComponent::CacheMetaSound(UMetaSoundSource* InMetaSound)
{
}

UMetaSoundSource* UFortWeaponSoundLibraryComponent::GetCachedMetaSound() const
{
	return nullptr;
}

UFortSoundIndicatorComponent* UFortWeaponSoundLibraryComponent::GetSoundIndicatorComponent() const
{
	return nullptr;
}

AFortWeapon* UFortWeaponSoundLibraryComponent::GetWeaponActor() const
{
	return nullptr;
}

bool UFortWeaponSoundLibraryComponent::IsLocallyViewed() const
{
	return false;
}

void UFortWeaponSoundLibraryComponent::ShowWeaponFireSoundIndicator()
{
}

void UFortWeaponSoundLibraryContext::ConfigureMetaSoundSource(UMetaSoundSource* MetaSoundSource, USoundClass* InClass, USoundAttenuation* InAttenuation, TSet<USoundConcurrency*> InConcurrency)
{
}

void UFortWeaponSoundLibraryContext::SetAudioComponentSoundClass(UAudioComponent* InAudioComponent, USoundClass* InClass)
{
}
