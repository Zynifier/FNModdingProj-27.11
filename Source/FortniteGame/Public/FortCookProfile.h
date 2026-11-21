// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManagerTypes.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/SoftObjectPath.h"
#include "FortCookProfile.generated.h"

class UObject;
class UWorld;

USTRUCT()
struct FCookProfileType
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString AssetPath;

};

UCLASS(Config=Game, BlueprintType)
class UFortCookProfile : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Config, Category="Available In Cook")
	TSoftObjectPtr<UWorld> PrimaryMap;

	UPROPERTY(EditAnywhere, Config, Category="Available In Cook", meta=(GetOptions="GetValidPrimaryAssetTypes"))
	TArray<FName> PrimaryAssetTypesToCook;

	UPROPERTY(EditAnywhere, Config, Category="Available In Cook")
	TArray<TSoftObjectPtr<UObject>> PackagesToCook;

	UPROPERTY(EditAnywhere, Config, Category="Available In Cook")
	TArray<FPrimaryAssetTypeInfo> PrimaryAssetTypeOverride;

	UPROPERTY(EditAnywhere, Config, Category="Disabled In Cook", meta=(DisplayAfter="CulturesToStage", Untracked))
	TArray<TSoftObjectPtr<UObject>> PackagesToNeverCook;

	UPROPERTY(EditAnywhere, Config, Category="Disabled In Cook", meta=(DisplayAfter="CulturesToStage", LongPackageName, RelativeToGameContentDir))
	TArray<FDirectoryPath> DirectoriesToNeverCook;

	UPROPERTY(EditAnywhere, Config, Category="GameFeaturePlugins To Cook", meta=(GetOptions="GetValidPluginNames"))
	TArray<FString> Plugins;

	UPROPERTY(EditAnywhere, Category="GameFeaturePlugins To Cook")
	FGameplayTagContainer AddPluginsBasedOnTagContainer;

	UPROPERTY(VisibleAnywhere, Category="GameFeaturePlugins To Cook")
	TArray<FString> PluginsFromTagQuery;

	UPROPERTY(EditAnywhere, Config, Category="Cook Quality Options")
	bool bCookHLOD;

	UPROPERTY(EditAnywhere, Config, Category="Cook Quality Options")
	bool bUseLowMipTextures;

	UPROPERTY(EditAnywhere, Config, Category="Cook Quality Options")
	bool bNoHighMips;

	UPROPERTY(EditAnywhere, Config, Category="Packaging Options")
	bool bGenerateChunks;

	UPROPERTY(EditAnywhere, Config, Category="Packaging Options")
	TArray<FString> CulturesToStage;

private:
#if WITH_EDITOR
	UFUNCTION()
	TArray<FString> GetValidPluginNames() const;
#endif

#if WITH_EDITOR
	UFUNCTION()
	TArray<FName> GetValidPrimaryAssetTypes() const;
#endif

	UPROPERTY(Config, meta=(Untracked))
	TArray<FCookProfileType> CookProfiles;

};

