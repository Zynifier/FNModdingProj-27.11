// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_CreativeRespawnWave.h"
#include "Athena/Modifiers/FortAthenaMutator_PlayerSettingsBase.h"
#include "Creative/FortCreativeClassOption.h"
#include "Creative/FortCreativeIconOption.h"
#include "FortAthenaMutator_PlayerTeamSettings.generated.h"

class AFortMinigame;
class UFortPlayerTeamSettingsComponent;
class UObject;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerTeamSettings : public AFortAthenaMutator_PlayerSettingsBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="TeamSettings")
	bool AddDataSourceForTeam(uint8 TeamIndex, const UObject* DataSource);

	UFUNCTION(BlueprintCallable, Category="TeamSettings")
	bool RemoveDataSource(const UObject* DataSource);

protected:
	UFUNCTION(BlueprintPure, Category="TeamSettings")
	UFortPlayerTeamSettingsComponent* GetComponentForEnabledSetting(const FName& PropertyName, bool bFallbackToDefaultTeam = true) const;

	UFUNCTION(BlueprintPure, Category="TeamSettings")
	uint8 GetTeamContext() const;

	UFUNCTION(BlueprintCallable, Category="TeamSettings")
	void SetTeamContext(uint8 TeamIndex);

	UFUNCTION(BlueprintNativeEvent, Category="TeamSettings")
	bool SetupGameRulesForTeamContext(AFortMinigame* Minigame);

	UPROPERTY(EditDefaultsOnly, Category="TeamSettings")
	TSubclassOf<UFortPlayerTeamSettingsComponent> TeamSettingsClass;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	bool bUseTeamScoreByDefault;

private:
	UPROPERTY(Transient)
	TMap<uint8, FMutatorPlayerSettingsData> TeamSettingsDataMap;

};

UCLASS(BlueprintType, Blueprintable)
class UFortPlayerTeamSettingsComponent : public UFortPlayerSettingsComponentBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Transient, Replicated, Category="FortPlayerTeamSettingsComponent")
	uint8 TeamIndex;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	FText TeamName;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	FText TeamDescription;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	FCreativeIconOption TeamIcon;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	int32 TeamColorIndex;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Game Rules")
	bool bRunOutTimeToWin;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	bool bUseTeamScore;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	FCreativeClassOption DefaultClassIdentifier;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	uint8 DefaultClassSlot;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	ECreativeRespawnWaveType RespawnWaveType;

};

