// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerCharm.h"

USceneComponent* AFortPlayerCharm::GetCharmAttachedToComponent() const
{
	return nullptr;
}

FName AFortPlayerCharm::GetCharmAttachedToSocket() const
{
	return FName();
}

USkeletalMeshComponentBudgeted* AFortPlayerCharm::GetCharmMeshComponent() const
{
	return nullptr;
}

USoundBase* AFortPlayerCharm::GetCharmSoundAssetByDescName(const FName DescNameIn, bool& bValidOut) const
{
	return nullptr;
}

USoundBase* AFortPlayerCharm::GetCharmSoundAssetByIndex(const int32 IndexIn, bool& bValidOut) const
{
	return nullptr;
}
