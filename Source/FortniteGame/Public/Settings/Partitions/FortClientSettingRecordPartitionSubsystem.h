// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortClientSettingRecordPartitionSubsystem.generated.h"

class UFortClientSettingRecordPartition;
class UFortGameSettingRegistryExtensionBase;

UCLASS(MinimalAPI)
class UFortClientSettingRecordPartitionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<TSubclassOf<UFortClientSettingRecordPartition>, TObjectPtr<UFortGameSettingRegistryExtensionBase>> ClientSettingPartitions;

};

