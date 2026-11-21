// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistryId.h"
#include "Engine/DataAsset.h"
#include "PersistenceFrameworkSettings.generated.h"

UCLASS(MinimalAPI)
class UPersistenceFrameworkSettings : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Persistence", meta=(AssetBundles="Server"))
	FDataRegistryType PersistenceFrameworkTagToServiceRegistry;

};

