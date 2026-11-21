// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Athena/ProfileStats/AthenaProfileStatBox.h"
#include "FortUIDataProfileStats.generated.h"

UCLASS(Config=Game, BlueprintType, Blueprintable)
class UFortUIDataProfileStats : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Battle Royale Stats", meta=(Categories="GameplayStat.Profile"))
	TMap<FGameplayTag, FFortUIStatStyle> ProfileStatStyles;

};

