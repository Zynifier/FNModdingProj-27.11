// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaMusicPackItemDefinition.generated.h"

class USoundBase;
class UTexture2D;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaMusicPackItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item")
	TSoftObjectPtr<UTexture2D> GetCoverArt() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> FrontEndLobbyMusic;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> CoverArtImage;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	bool bIsDefaultMusicPack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Audio", meta=(ClampMin="0.0"))
	float MusicPreviewStartTime;

};

