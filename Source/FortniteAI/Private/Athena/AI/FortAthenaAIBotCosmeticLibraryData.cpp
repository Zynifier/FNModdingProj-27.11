// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaAIBotCosmeticLibraryData.h"

bool UBotCosmeticBlueprintHelperLibrary::ExportDataTableToSourceCSV(const UDataTable* DataTable, const bool bCanCheckOutFile)
{
	return false;
}

bool UBotCosmeticBlueprintHelperLibrary::GenerateWeightedCSV(const FString& AssetTypeName, const TArray<FString>& AssetNames, const TArray<int32>& AssetWeight, FString& CSV)
{
	return false;
}

bool UBotCosmeticBlueprintHelperLibrary::LoadDataFromCSV(const FString& FilePath, const TArray<FString>& ForbiddenAssetNames, const TArray<FString>& ForbiddenAssetPrefix, TArray<FString>& AssetNames, TArray<FString>& AssetTypes, TArray<int32>& AssetUsageCounts, TArray<int32>& AssetTypeSplitIndices)
{
	return false;
}

TArray<FString> UBotCosmeticBlueprintHelperLibrary::OpenCSVFileDialog(const FString& TitleDetails, const bool bAllowMultipleFiles)
{
	return TArray<FString>();
}

bool UBotCosmeticBlueprintHelperLibrary::SplitDataArrayByType(const TArray<FString>& InAssetNames, const TArray<FString>& InAssetTypes, const TArray<int32>& InAssetUsageCounts, const TArray<int32>& InAssetTypeSplitIndices, int32 CurrentSplitIndex, FString& OutAssetType, TArray<FString>& OutAssetNames, TArray<int32>& OutAssetUsageCounts)
{
	return false;
}

bool UFortAthenaAIBotCosmeticLibraryData::FillDataTableValuesFromSourceLibrary(const UFortAthenaAIBotCosmeticLibraryData* SourceLibrary)
{
	return false;
}

UDataTable* UFortAthenaAIBotCosmeticLibraryData::FindDataTableFromAssetType(const FString& AssetType)
{
	return nullptr;
}

TArray<UDataTable*> UFortAthenaAIBotCosmeticLibraryData::RetrieveDataTables() const
{
	return TArray<UDataTable*>();
}
