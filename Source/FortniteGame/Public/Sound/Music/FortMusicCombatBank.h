// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortMusicCombatBank.generated.h"

class UFortMusicAsset;

UENUM(BlueprintType)
namespace EFortMusicCombatIntensity
{
	enum Type
	{
		Low = 0,
		Medium = 1,
		High = 2,
		VeryHigh = 3,
		Max_None = 4 UMETA(DisplayName="None"),
	};
}

UCLASS(BlueprintType)
class UFortMusicCombatBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Music Assets")
	const UFortMusicAsset* GetAssetFromCombatIntensity(EFortMusicCombatIntensity::Type Intensity) const;

	UPROPERTY(EditDefaultsOnly, Category="Music Assets", meta=(ArraySizeEnum="/Script/FortniteGame.EFortMusicCombatIntensity"))
	TObjectPtr<UFortMusicAsset> Assets[4];

};

