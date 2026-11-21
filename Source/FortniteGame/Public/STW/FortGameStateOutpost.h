// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTypes.h"
#include "STW/FortGameStatePvE.h"
#include "STW/GameDataSTW.h"
#include "FortGameStateOutpost.generated.h"

class UFortRegisteredPlayerInfo;

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateOutpost : public AFortGameStatePvE
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="GameState")
	const bool DoesOutpostStatusAllowMissionStart() const;

	UFUNCTION(BlueprintPure, Category="PrepTime")
	float GetPrepTime(const FName& OutpostDefenseType) const;

	UFUNCTION(BlueprintPure, Category="PrepTime")
	bool IsWithinPrepTime(const FName& OutpostDefenseType) const;

protected:
	UFUNCTION()
	virtual void OnRep_PlayerWeaponSkillLevel();

	UPROPERTY(Replicated)
	bool bOutpostDefenseActive;

	UPROPERTY(Replicated)
	bool bWargameActive;

	UPROPERTY(Replicated)
	EStormShieldDefense StormShieldDefenseType;

	UPROPERTY(Replicated)
	bool bOutpostStatusAllowsMissionStart;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortRegisteredPlayerInfo>> IronCityEarlyPlayerInfos;

	UPROPERTY(Transient)
	int32 IronCityLowestPlayerAccountLevel;

	UPROPERTY(Transient)
	float IronCityMinPowerLevel;

	UPROPERTY(Transient)
	float IronCityMaxPowerLevel;

	UPROPERTY(Transient)
	FIronCityDifficultyInfo IronCityDifficultyInfo;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayerWeaponSkillLevel)
	float PlayerWeaponSkillLevel;

	UPROPERTY(Config)
	float PrepTimeErrorOffset;

};

