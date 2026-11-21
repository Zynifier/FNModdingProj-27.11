// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "FortCreativeBudgeter.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortCreativeRealEstatePlotItemDefinition.generated.h"

class UFortPlaylist;
class UFortPlaysetItemDefinition;

UENUM(BlueprintType)
enum class ERealEstateOffsetType : uint8
{
	// Assumes the level is in the upper right corner

	CustomOffsetFromCorner = 0,
	// Spawn in the Center

	Center = 1,
};

UCLASS(Config=Game, MinimalAPI, BlueprintType)
class UFortCreativeRealEstatePlotItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	FText UIDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot", meta=(MultiLine="TRUE"))
	FText UIDisplayDescription;

	UPROPERTY(EditDefaultsOnly, Category="CreativeRealEstatePlot")
	TSoftObjectPtr<UFortPlaysetItemDefinition> BasePlayset;

	UPROPERTY(EditDefaultsOnly, Category="CreativeRealEstatePlot")
	FString InitialSaveFileName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot", meta=(ClampMin="1"))
	int32 SizeX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot", meta=(ClampMin="1"))
	int32 SizeY;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	FVector LocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	FRotator DefaultRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	ERealEstateOffsetType OffsetType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	FSlateBrush MapImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	int32 SortIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	int32 MaxPlayerOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	bool bIsAvailableToUsers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	TArray<FFortCreativeBudget> CreativeBudgetOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeRealEstatePlot")
	TObjectPtr<UFortPlaylist> OverridePlaylist;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Heatmap Thermometer")
	bool bCreativeHeatmapThermometerEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Heatmap Thermometer")
	float CreativeHeatmapThermometerInfluenceDistanceMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Heatmap Thermometer")
	int32 CreativeHeatmapThermometerCellSizeMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Heatmap Thermometer")
	TArray<FFortCreativeGridCellBudget> CreativeHeatmapThermometerBudgetOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Heatmap Thermometer")
	FScalableFloat bUseMapProjectionForBudgetGridBounds;

};

