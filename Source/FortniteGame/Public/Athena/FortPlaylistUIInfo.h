// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "FortOptionsMenuData.h"
#include "FortPlaylistUIInfo.generated.h"

class USoundCue;
class UUserWidget;

USTRUCT(BlueprintType)
struct FPostGameScreenTagClassPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PostGameScreenTagClassPair")
	FGameplayTag ScreenType;

	UPROPERTY(EditAnywhere, Category="PostGameScreenTagClassPair", meta=(AllowedClasses="/Script/FortniteUI.FortPostGameScreen"))
	TSubclassOf<UUserWidget> PostGameScreenClass;

};

UCLASS(MinimalAPI)
class UFortPlaylistUIInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="OptionsMenu")
	TArray<FFortOptionsMenuData> OptionsMenuOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Victory", meta=(AllowedClasses="/Script/FortniteUI.PostGamePlacementOverlay"))
	TSubclassOf<UUserWidget> PostGamePlacementOverlayClass;

	UPROPERTY(EditDefaultsOnly, Category="Victory")
	bool bIsPlacementAboveContent;

	UPROPERTY(EditDefaultsOnly, Category="PostGame")
	TArray<FPostGameScreenTagClassPair> PostGameScreenOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Victory")
	TObjectPtr<USoundCue> VictoryStinger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Victory")
	FText VictoryText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Victory")
	bool bIsCinematicVictory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Victory")
	bool bShouldPushEmoteInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Victory")
	bool bShouldPlayOnLoss;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Victory")
	float StingerFadesToAudioMusicAfter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Map")
	FSlateBrush MinimapOverride;

};

