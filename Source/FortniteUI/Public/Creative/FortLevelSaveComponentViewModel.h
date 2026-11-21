// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "FortLevelSaveComponent.h"
#include "FortLevelSaveComponentViewModel.generated.h"

enum class EBackupSaveState : uint8;

UCLASS(BlueprintType, meta=(MVVMAllowedContextCreationType="Manual"))
class UFortLevelSaveComponentViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BackupIsland();

	UFUNCTION(BlueprintPure)
	bool CanBackupAndRestoreIsland() const;

	UFUNCTION(BlueprintPure)
	bool CanResetIsland() const;

	UFUNCTION(BlueprintPure)
	FTimespan GetTimeSinceLastCheckpoint() const;

	UFUNCTION(BlueprintCallable)
	void InitializeViewModel();

	UFUNCTION(BlueprintPure)
	bool IsLastCheckpointDateSet() const;

	UFUNCTION(BlueprintPure)
	bool IsPublishingEnabled() const;

	UFUNCTION(BlueprintCallable)
	void ResetIsland();

	UFUNCTION(BlueprintCallable)
	void RestoreIslandFromBackup();

	UFUNCTION(BlueprintCallable)
	void UnbindViewModel();

private:
	UFUNCTION()
	void HandleBackupRestoreStateChanged(EBackupSaveState RestoreState);

	UFUNCTION()
	void HandleBackupSaveStateChanged(EBackupSaveState SaveState);

	UFUNCTION()
	void HandleCheckpointDateChanged(FDateTime CheckpointDate);

	UPROPERTY(BlueprintReadOnly, Category="FortLevelSaveComponentViewModel", meta=(AllowPrivateAccess))
	EBackupSaveState CachedBackupSaveState;

	UPROPERTY(BlueprintReadOnly, Category="FortLevelSaveComponentViewModel", meta=(AllowPrivateAccess))
	EBackupSaveState CachedBackupRestoreState;

	UPROPERTY(BlueprintReadOnly, Category="FortLevelSaveComponentViewModel", meta=(AllowPrivateAccess))
	bool bCachedIsOnPublishedIsland;

};

