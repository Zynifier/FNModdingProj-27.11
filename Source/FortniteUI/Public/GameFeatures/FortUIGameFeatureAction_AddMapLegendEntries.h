// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AddMapLegendEntries.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FAthenaMapLegendEntryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaMapLegendEntryData")
	FText LegendEntryText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaMapLegendEntryData")
	TArray<TSoftObjectPtr<UTexture2D>> LegendEntryTextures;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Map Legend Entries"))
class UFortUIGameFeatureAction_AddMapLegendEntries : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_AddMapLegendEntries")
	TArray<FAthenaMapLegendEntryData> MapLegendEntries;

};

