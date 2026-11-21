// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortMusicManagerBank.generated.h"

class UFortMusicCombatBank;
class UFortMusicTimeOfDayBank;

UCLASS(BlueprintType)
class UFortMusicManagerBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Music Banks")
	TObjectPtr<UFortMusicTimeOfDayBank> TimeOfDayBank;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Music Banks")
	TObjectPtr<UFortMusicCombatBank> CombatBank;

};

