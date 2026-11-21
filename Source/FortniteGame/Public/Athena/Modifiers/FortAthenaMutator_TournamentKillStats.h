// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_TournamentKillStats.generated.h"

class AFortPlayerState;

USTRUCT()
struct FTournamentWeaponKillStat
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TournamentWeaponKillStat")
	FGameplayTagContainer TagList;

	UPROPERTY(EditDefaultsOnly, Category="TournamentWeaponKillStat")
	FString StatName;

	UPROPERTY(EditDefaultsOnly, Category="TournamentWeaponKillStat")
	FName StatDisplayName;

	UPROPERTY()
	TMap<TObjectPtr<AFortPlayerState>, int32> PlayerStats;

};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TournamentKillStats : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Weapon Kills")
	TArray<FTournamentWeaponKillStat> KillStatList;

};

