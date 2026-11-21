// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddClientSettingRecordPartition.generated.h"

class UFortClientSettingRecordPartition;
class UFortGameSettingRegistryExtensionBase;

UCLASS(MinimalAPI, meta=(DisplayName="Add Client Setting Record Partition"))
class UFortGameFeatureAction_AddClientSettingRecordPartition : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_AddClientSettingRecordPartition")
	bool bAddSettingClassesAtRegistrationTime;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_AddClientSettingRecordPartition", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortClientSettingRecordPartition> ClientSettingRecordPartitionClass;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_AddClientSettingRecordPartition", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortGameSettingRegistryExtensionBase> SettingRegistryExtensionClass;

};

