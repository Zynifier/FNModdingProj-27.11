// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortTableCache.generated.h"

class UCurveTable;
class UDataTable;

USTRUCT()
struct FFortGameFeatureDataBaseCurveTableOverrides
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureDataBaseCurveTableOverrides")
	TSoftObjectPtr<UCurveTable> BaseTable;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureDataBaseCurveTableOverrides")
	TMap<FGameplayTag, TSoftObjectPtr<UCurveTable>> PlaylistToOverrideTableMap;

};

USTRUCT()
struct FFortGameFeatureDataBaseDataTableOverrides
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureDataBaseDataTableOverrides")
	TSoftObjectPtr<UDataTable> BaseTable;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureDataBaseDataTableOverrides")
	TMap<FGameplayTag, TSoftObjectPtr<UDataTable>> PlaylistToOverrideTableMap;

};

USTRUCT()
struct FFortPlaylistBaseCurveTableOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPlaylistBaseCurveTableOverride")
	TSoftObjectPtr<UCurveTable> BaseTable;

	UPROPERTY(EditDefaultsOnly, Category="FortPlaylistBaseCurveTableOverride")
	TSoftObjectPtr<UCurveTable> OverrideTable;

};

USTRUCT()
struct FFortPlaylistBaseDataTableOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPlaylistBaseDataTableOverride")
	TSoftObjectPtr<UDataTable> BaseTable;

	UPROPERTY(EditDefaultsOnly, Category="FortPlaylistBaseDataTableOverride")
	TSoftObjectPtr<UDataTable> OverrideTable;

};

