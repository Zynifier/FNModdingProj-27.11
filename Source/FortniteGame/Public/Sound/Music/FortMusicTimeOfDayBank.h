// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortMusicTimeOfDayBank.generated.h"

class UFortMusicAsset;
enum class EFortDayPhase : uint8;

UCLASS(BlueprintType)
class UFortMusicTimeOfDayBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Music Assets")
	const UFortMusicAsset* GetAssetFromDayPhase(EFortDayPhase DayPhase) const;

	UPROPERTY(EditDefaultsOnly, Category="Music Assets", meta=(ArraySizeEnum="/Script/FortniteGame.EFortDayPhase"))
	TObjectPtr<UFortMusicAsset> Assets[4];

};

