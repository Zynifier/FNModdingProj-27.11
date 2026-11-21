// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "UI/FortAthenaCompassIcon.h"
#include "FortAthenaMutator_MarkerUtilities.generated.h"

class AActor;

USTRUCT()
struct FMarkerUtilitiesCompassPlacementIcon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesCompassPlacementIcon")
	FFortAthenaCompassIcon PlacementCompassIcon;

	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesCompassPlacementIcon")
	FFortAthenaCompassIcon SquadmatePlacementCompassIcon;

	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesCompassPlacementIcon")
	FScalableFloat MinimumTeamScoreToShow;

	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesCompassPlacementIcon")
	bool bMinimumTeamScoreToShowIsPercent;

};

USTRUCT()
struct FMarkerUtilitiesMapIcon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesMapIcon")
	FSlateBrush MapIcon;

	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesMapIcon")
	FScalableFloat MapIconScale;

};

USTRUCT()
struct FMarkerUtilitiesMapPlacementIcon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesMapPlacementIcon")
	FMarkerUtilitiesMapIcon PlacementMapIcon;

	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesMapPlacementIcon")
	FMarkerUtilitiesMapIcon SquadmatePlacementMapIcon;

	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesMapPlacementIcon")
	FScalableFloat MinimumTeamScoreToShow;

	UPROPERTY(EditDefaultsOnly, Category="MarkerUtilitiesMapPlacementIcon")
	bool bMinimumTeamScoreToShowIsPercent;

};

USTRUCT()
struct FMarkerUtilitiesTeamPlacement
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 TeamId;

	UPROPERTY()
	int32 Placement;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_MarkerUtilities : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	const FFortAthenaCompassIcon& GetIndicatedActorCompassIcon(AActor* Actor) const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void OverrideIndicatedActorCompassIcon(AActor* Actor, const FFortAthenaCompassIcon CompassIcon);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void RestoreIndicatedActorCompassIcon(AActor* Actor);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Compass")
	FScalableFloat bMarkIndicatedPlayersOnCompass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Compass")
	FFortAthenaCompassIcon IndicatedPlayerCompassIcon;

	UPROPERTY(EditDefaultsOnly, Category="Map")
	FScalableFloat bMarkIndicatedPlayersOnMap;

	UPROPERTY(EditDefaultsOnly, Category="Map")
	FMarkerUtilitiesMapIcon IndicatedPlayerMapIcon;

	UPROPERTY(EditDefaultsOnly, Category="Top Scoring Teams")
	FScalableFloat NumTopScoringTeamsToShowOnMap;

	UPROPERTY(EditDefaultsOnly, Category="Top Scoring Teams")
	FScalableFloat bDisplayLocalPlayerAsTopScoringTeamsOnMap;

	UPROPERTY(EditDefaultsOnly, Category="Top Scoring Teams")
	FScalableFloat bOverlayTopScoringTeamIndicatorOnLocalPlayerOnMap;

	UPROPERTY(EditDefaultsOnly, Category="Top Scoring Teams")
	TArray<FMarkerUtilitiesMapPlacementIcon> PlacementBasedMapIcons;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Top Scoring Teams")
	FGameplayTag TopScoringPlayerSpecialActorTag;

	UPROPERTY(EditDefaultsOnly, Category="Top Scoring Teams")
	FScalableFloat TopScoringPlayerSpecialActorRepInterval;

	UPROPERTY(EditDefaultsOnly, Category="Top Scoring Teams")
	FScalableFloat NumTopScoringTeamsToShowOnCompass;

	UPROPERTY(EditDefaultsOnly, Category="Top Scoring Teams")
	TArray<FMarkerUtilitiesCompassPlacementIcon> PlacementBasedCompassIcons;

	UPROPERTY(EditDefaultsOnly, Category="Top Scoring Teams")
	FScalableFloat bDrawLocalPlayerTopScoringTeamOnCompass;

	UPROPERTY(EditDefaultsOnly, Category="World Indicators")
	FScalableFloat WorldIndicator_IndicatorZOffset;

	UPROPERTY(EditDefaultsOnly, Category="World Indicators")
	FScalableFloat bWorldIndicator_IndicatorClampToScreen;

	UPROPERTY(EditDefaultsOnly, Category="World Indicators")
	FScalableFloat bDrawMarkedActorStencils;

	UPROPERTY(EditDefaultsOnly, Category="Leading Players Highlight")
	FName StencilName;

private:
	UPROPERTY()
	TMap<TWeakObjectPtr<AActor>, FFortAthenaCompassIcon> IndicatedActorCompassIconOverrideMap;

	UPROPERTY(Replicated)
	TArray<FMarkerUtilitiesTeamPlacement> ReplicatedTeamPlacements;

	UPROPERTY(EditDefaultsOnly, Category="World Indicators")
	FScalableFloat bUseAthenaTeamScoreForRanking;

};

