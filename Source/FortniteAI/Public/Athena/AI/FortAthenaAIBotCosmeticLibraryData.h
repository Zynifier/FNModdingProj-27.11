// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScalableFloat.h"
#include "FortAthenaAIBotCosmeticLibraryData.generated.h"

class UDataTable;
class UFortAthenaAIBotCosmeticLibraryData;

UCLASS(meta=(ScriptName="BotCosmeticHelperLibrary"))
class UBotCosmeticBlueprintHelperLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI")
	static bool ExportDataTableToSourceCSV(const UDataTable* DataTable, const bool bCanCheckOutFile);

	UFUNCTION(BlueprintCallable, Category="AI")
	static bool GenerateWeightedCSV(const FString& AssetTypeName, const TArray<FString>& AssetNames, const TArray<int32>& AssetWeight, FString& CSV);

	UFUNCTION(BlueprintCallable, Category="AI")
	static bool LoadDataFromCSV(const FString& FilePath, const TArray<FString>& ForbiddenAssetNames, const TArray<FString>& ForbiddenAssetPrefix, TArray<FString>& AssetNames, TArray<FString>& AssetTypes, TArray<int32>& AssetUsageCounts, TArray<int32>& AssetTypeSplitIndices);

	UFUNCTION(BlueprintCallable, Category="AI")
	static TArray<FString> OpenCSVFileDialog(const FString& TitleDetails, const bool bAllowMultipleFiles);

	UFUNCTION(BlueprintCallable, Category="AI")
	static bool SplitDataArrayByType(const TArray<FString>& InAssetNames, const TArray<FString>& InAssetTypes, const TArray<int32>& InAssetUsageCounts, const TArray<int32>& InAssetTypeSplitIndices, int32 CurrentSplitIndex, FString& OutAssetType, TArray<FString>& OutAssetNames, TArray<int32>& OutAssetUsageCounts);

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotCosmeticLibraryData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI")
	bool FillDataTableValuesFromSourceLibrary(const UFortAthenaAIBotCosmeticLibraryData* SourceLibrary);

	UFUNCTION(BlueprintCallable, Category="AI")
	UDataTable* FindDataTableFromAssetType(const FString& AssetType);

	UFUNCTION(BlueprintPure, Category="AI")
	TArray<UDataTable*> RetrieveDataTables() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="PredefineSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> PredefineSetsDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> CharactersDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> GlidersDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> SkyDiveContrailsDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> BackpacksDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> PickaxesDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> FallbackCharactersDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> EmotesDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> BannerIconDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> BannerColorDataTable;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	FScalableFloat OddsToUseSameSetCosmeticItems;

	UPROPERTY(EditDefaultsOnly, Category="RandomizedSets", meta=(AssetBundles="Server"))
	FScalableFloat OddsToUseRandomItemWhenNoneFromSetAvailable;

};

