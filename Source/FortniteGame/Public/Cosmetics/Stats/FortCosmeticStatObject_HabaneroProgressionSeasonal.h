// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Cosmetics/Stats/FortCosmeticStatObject_HabaneroProgression.h"
#include "FortCosmeticStatObject_HabaneroProgressionSeasonal.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortCosmeticStatObject_HabaneroProgressionSeasonal : public UFortCosmeticStatObject_HabaneroProgression
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticStatObject_HabaneroProgressionSeasonal")
	FDateTime SeasonDateTime;

};

