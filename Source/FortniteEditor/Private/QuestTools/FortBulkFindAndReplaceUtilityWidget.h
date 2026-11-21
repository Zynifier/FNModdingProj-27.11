// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "EditorUtilityWidget.h"
#include "UObject/SoftObjectPath.h"
#include "FortBulkFindAndReplaceUtilityWidget.generated.h"

USTRUCT(BlueprintType)
struct FFortBulkFindAndReplaceAssetFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, SaveGame, Category="FortBulkFindAndReplaceAssetFilter")
	TArray<FString> Paths;

	UPROPERTY(BlueprintReadWrite, SaveGame, Category="FortBulkFindAndReplaceAssetFilter")
	TArray<FString> ExcludePathsContaining;

	UPROPERTY(BlueprintReadWrite, SaveGame, Category="FortBulkFindAndReplaceAssetFilter")
	TSet<FSoftClassPath> OnlyIncludeClasses;

	UPROPERTY(BlueprintReadWrite, SaveGame, Category="FortBulkFindAndReplaceAssetFilter")
	TSet<FSoftClassPath> IgnoreClasses;

};

USTRUCT(BlueprintType)
struct FFortBulkFindAndReplaceResultForProperty
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortBulkFindAndReplaceResultForProperty")
	FName PropertyName;

	UPROPERTY(BlueprintReadWrite, Category="FortBulkFindAndReplaceResultForProperty")
	FString OriginalValue;

	UPROPERTY(BlueprintReadWrite, Category="FortBulkFindAndReplaceResultForProperty")
	FString ReplacedValue;

};

USTRUCT(BlueprintType)
struct FFortBulkFindAndReplaceResultForAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortBulkFindAndReplaceResultForAsset")
	FAssetData AssetData;

	UPROPERTY(BlueprintReadWrite, Category="FortBulkFindAndReplaceResultForAsset")
	TArray<FFortBulkFindAndReplaceResultForProperty> Properties;

};

USTRUCT(BlueprintType)
struct FFortBulkFindAndReplaceSearchTerms
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, SaveGame, Category="FortBulkFindAndReplaceSearchTerms")
	TArray<FString> Find;

	UPROPERTY(BlueprintReadWrite, SaveGame, Category="FortBulkFindAndReplaceSearchTerms")
	TArray<FString> Replace;

	UPROPERTY(BlueprintReadWrite, SaveGame, Category="FortBulkFindAndReplaceSearchTerms")
	TEnumAsByte<ESearchCase::Type> SearchCase;

};

UCLASS()
class UFortBulkFindAndReplaceUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Find and Replace")
	static void ApplyFindAndReplacePreview(const TArray<FFortBulkFindAndReplaceResultForAsset>& PreviewToApply, TArray<FFortBulkFindAndReplaceResultForAsset>& OutFinalResults, bool bSkipPropertiesThatChanged = true, bool bSave = true);

	UFUNCTION(BlueprintCallable, Category="Find and Replace")
	static void GetAssetsMatchingFilter(const FFortBulkFindAndReplaceAssetFilter& Filter, TArray<FAssetData>& OutAssetsMatchingFilter, bool bLoadAssets = true);

	UFUNCTION(BlueprintCallable, Category="Find and Replace")
	static void PreviewFindAndReplace(const FFortBulkFindAndReplaceAssetFilter& AssetsFilter, const FFortBulkFindAndReplaceSearchTerms& SearchTerms, TArray<FFortBulkFindAndReplaceResultForAsset>& OutResults, bool bSortResultsByPath = true);

protected:
	UFUNCTION(BlueprintCallable, Category="Find and Replace")
	static void MakeFindResultsEditable(UPARAM(ref) TArray<FFortBulkFindAndReplaceResultForAsset>& FindResults);

};

