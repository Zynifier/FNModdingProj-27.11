// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "FortAthenaAIBotNameData.generated.h"

class UDataTable;

USTRUCT()
struct FFortAthenaAIBotNameDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotNameDataTableRow")
	FString Name;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotNameDataTableRow")
	FString UniqueID;

};

USTRUCT()
struct FFortAthenaAIBotNameRegionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotNameRegionData")
	FString RegionId;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotNameRegionData", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> NameDataTable;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAthenaAIBotNameDataAsset : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> DefaultNameDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> ChinaNameDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(DisplayName="Regions"))
	TArray<FFortAthenaAIBotNameRegionData> RegionData;

};

