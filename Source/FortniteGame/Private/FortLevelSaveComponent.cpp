// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortLevelSaveComponent.h"
#include "Net/UnrealNetwork.h"

void UFortLevelSaveComponent::CloudSaveFinished(const FAsyncTaskResult& Result)
{
}

bool UFortLevelSaveComponent::DestroyLevelInstance(FGuid LevelInstanceGuid)
{
	return false;
}

FUniqueNetIdRepl UFortLevelSaveComponent::GetAccountIdOfOwner() const
{
	return FUniqueNetIdRepl();
}

bool UFortLevelSaveComponent::IsCurated() const
{
	return false;
}

bool UFortLevelSaveComponent::IsLoaded() const
{
	return false;
}

void UFortLevelSaveComponent::K2_GetLoadedLinkData(FCreativeLoadedLinkData& LinkData) const
{
}

void UFortLevelSaveComponent::OnRep_AccountIdOfOwner()
{
}

void UFortLevelSaveComponent::OnRep_BackupSaveState(EBackupSaveState OldValue)
{
}

void UFortLevelSaveComponent::OnRep_CachedAnalyticsData()
{
}

void UFortLevelSaveComponent::OnRep_IsAutoSaving(bool bOldValue)
{
}

void UFortLevelSaveComponent::OnRep_LastCheckpointDate(FDateTime OldValue)
{
}

void UFortLevelSaveComponent::OnRep_LevelInstanceList()
{
}

void UFortLevelSaveComponent::OnRep_Loaded()
{
}

void UFortLevelSaveComponent::OnRep_LoadedLinkData()
{
}

void UFortLevelSaveComponent::OnRep_LoadedPlotInstanceId()
{
}

void UFortLevelSaveComponent::OnRep_OwnerCreativePermissions()
{
}

void UFortLevelSaveComponent::OnRep_PaletteLinkCodes()
{
}

void UFortLevelSaveComponent::OnRep_RestoringStateChanged(EBackupSaveState OldValue)
{
}

bool UFortLevelSaveComponent::RenameLevelInstance(FGuid LevelInstanceGuid, const FString& NewLevelName)
{
	return false;
}

void UFortLevelSaveComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortLevelSaveComponent, PaletteLinkCodes);
	DOREPLIFETIME(UFortLevelSaveComponent, CurrentVkProjectInfo);
	DOREPLIFETIME(UFortLevelSaveComponent, AccountIdOfOwner);
	DOREPLIFETIME(UFortLevelSaveComponent, OwnerCreativePermissions);
	DOREPLIFETIME(UFortLevelSaveComponent, bCurated);
	DOREPLIFETIME(UFortLevelSaveComponent, LoadedPlotInstanceId);
	DOREPLIFETIME(UFortLevelSaveComponent, LoadedLinkData);
	DOREPLIFETIME(UFortLevelSaveComponent, CachedAnalyticsData);
	DOREPLIFETIME(UFortLevelSaveComponent, bIsLoaded);
	DOREPLIFETIME(UFortLevelSaveComponent, bIsAutoSaving);
	DOREPLIFETIME(UFortLevelSaveComponent, BackupSaveState);
	DOREPLIFETIME(UFortLevelSaveComponent, RestoringState);
	DOREPLIFETIME(UFortLevelSaveComponent, LastCheckpointDateUtc);
	DOREPLIFETIME(UFortLevelSaveComponent, LevelInstanceList);
	DOREPLIFETIME(UFortLevelSaveComponent, bOptedInForDeviceUpgrades);
	DOREPLIFETIME(UFortLevelSaveComponent, bOptedInForMemorySystemUpgrades);
}
