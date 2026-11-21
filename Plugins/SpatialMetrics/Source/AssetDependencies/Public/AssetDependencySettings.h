// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AssetDependencySettings.generated.h"

class UObject;

UCLASS(Config=AssetDependencySettings, DefaultConfig)
class ASSETDEPENDENCIES_API UAssetDependencySettings : public UDeveloperSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Config, Category="AssetDependencySettings")
	TArray<FName> ExcludedPaths;

	UPROPERTY(EditDefaultsOnly, Config, Category="AssetDependencySettings")
	TArray<FName> ExcludedPackages;

	UPROPERTY(EditDefaultsOnly, Config, Category="AssetDependencySettings")
	TArray<UClass*> ClassIgnoreList;

	UPROPERTY(Transient)
	TSet<UClass*> ClassIgnoreListSet;

};

