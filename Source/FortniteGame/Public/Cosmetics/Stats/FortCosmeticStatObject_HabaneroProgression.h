// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Stats/FortCosmeticStatObject.h"
#include "FortCosmeticStatObject_HabaneroProgression.generated.h"

UENUM(BlueprintType)
enum class EFortCosmeticHabaneroProgressionType : uint8
{
	/** Checks the current progress for each track when determining overall progress */
	CurrentProgress = 0,
	/** Checks the highest progress achieved for each track when determining overall progress */
	HighestProgress = 1,
};

UCLASS(BlueprintType, Blueprintable)
class UFortCosmeticStatObject_HabaneroProgression : public UFortCosmeticStatObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticStatObject_HabaneroProgression")
	TArray<FString> AllowedHabaneroTypes;

	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticStatObject_HabaneroProgression")
	EFortCosmeticHabaneroProgressionType ProgressionType;

};

