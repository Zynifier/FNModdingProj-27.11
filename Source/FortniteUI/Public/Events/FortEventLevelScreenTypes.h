// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "FortEventLevelScreenTypes.generated.h"

class UAthenaRewardEventGraph;
class UFortActivatableVideoPanel;
class UFortStreamMediaSource;
class UMediaPlayer;

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortEventLevelData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="EventSpecific")
	FString EventLevelStoreFrontName;

	UPROPERTY(EditDefaultsOnly, Category="EventSpecific")
	TSoftObjectPtr<UAthenaRewardEventGraph> EventLevelRewards;

	UPROPERTY(EditDefaultsOnly, Category="VideoStreaming")
	TSubclassOf<UFortActivatableVideoPanel> CinematicMovieWidget;

	UPROPERTY(EditDefaultsOnly, Category="VideoStreaming")
	TObjectPtr<UFortStreamMediaSource> ElectraMediaSource;

	UPROPERTY(EditDefaultsOnly, Category="VideoStreaming")
	TObjectPtr<UMediaPlayer> StreamedMediaPlayer;

	UPROPERTY(EditDefaultsOnly, Category="VideoStreaming")
	FName CinematicVideoName;

	UPROPERTY(EditAnywhere, Category="FortEventLevelData", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InteractionHandle;

};

