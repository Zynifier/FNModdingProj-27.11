// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortLevelSaveComponentViewModel.h"

void UFortLevelSaveComponentViewModel::BackupIsland()
{
}

bool UFortLevelSaveComponentViewModel::CanBackupAndRestoreIsland() const
{
	return false;
}

bool UFortLevelSaveComponentViewModel::CanResetIsland() const
{
	return false;
}

FTimespan UFortLevelSaveComponentViewModel::GetTimeSinceLastCheckpoint() const
{
	return FTimespan();
}

void UFortLevelSaveComponentViewModel::HandleBackupRestoreStateChanged(EBackupSaveState RestoreState)
{
}

void UFortLevelSaveComponentViewModel::HandleBackupSaveStateChanged(EBackupSaveState SaveState)
{
}

void UFortLevelSaveComponentViewModel::HandleCheckpointDateChanged(FDateTime CheckpointDate)
{
}

void UFortLevelSaveComponentViewModel::InitializeViewModel()
{
}

bool UFortLevelSaveComponentViewModel::IsLastCheckpointDateSet() const
{
	return false;
}

bool UFortLevelSaveComponentViewModel::IsPublishingEnabled() const
{
	return false;
}

void UFortLevelSaveComponentViewModel::ResetIsland()
{
}

void UFortLevelSaveComponentViewModel::RestoreIslandFromBackup()
{
}

void UFortLevelSaveComponentViewModel::UnbindViewModel()
{
}
