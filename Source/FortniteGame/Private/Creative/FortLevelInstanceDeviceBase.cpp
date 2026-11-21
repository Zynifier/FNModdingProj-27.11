// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortLevelInstanceDeviceBase.h"
#include "Net/UnrealNetwork.h"

void AFortLevelInstanceDeviceBase::AttemptToLoadLastUsedSettings()
{
}

AGameplayVolume* AFortLevelInstanceDeviceBase::GetGameplayVolume() const
{
	return nullptr;
}

void AFortLevelInstanceDeviceBase::OnRep_LevelInstanceSpawnGuid()
{
}

void AFortLevelInstanceDeviceBase::SetLastUsedLevelName(const FString& InLevelName)
{
}

void AFortLevelInstanceDeviceBase::StreamLevelsByWorldAsset(TSoftObjectPtr<UWorld>& StreamLevelWorldAsset)
{
}

void AFortLevelInstanceDeviceBase::UnloadAllStreamedLevels()
{
}

void AFortLevelInstanceDeviceBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortLevelInstanceDeviceBase, GameplayVolume);
	DOREPLIFETIME(AFortLevelInstanceDeviceBase, LevelInstanceSpawnGuid);
}

const FLevelInstanceID& AFortLevelInstanceDeviceBase::GetLevelInstanceID() const
{
	static FLevelInstanceID Dummy;
	return Dummy;
}

bool AFortLevelInstanceDeviceBase::HasValidLevelInstanceID() const
{
	return false;
}

const FGuid& AFortLevelInstanceDeviceBase::GetLevelInstanceGuid() const
{
	static FGuid Dummy;
	return Dummy;
}

const TSoftObjectPtr<UWorld>& AFortLevelInstanceDeviceBase::GetWorldAsset() const
{
	static TSoftObjectPtr<UWorld> Dummy;
	return Dummy;
}

bool AFortLevelInstanceDeviceBase::IsLoadingEnabled() const
{
	return false;
}

#if WITH_EDITOR
ULevelInstanceComponent* AFortLevelInstanceDeviceBase::GetLevelInstanceComponent() const
{
	return nullptr;
}

ELevelInstanceRuntimeBehavior AFortLevelInstanceDeviceBase::GetDesiredRuntimeBehavior() const
{
	return ELevelInstanceRuntimeBehavior();
}

ELevelInstanceRuntimeBehavior AFortLevelInstanceDeviceBase::GetDefaultRuntimeBehavior() const
{
	return ELevelInstanceRuntimeBehavior();
}
#endif
