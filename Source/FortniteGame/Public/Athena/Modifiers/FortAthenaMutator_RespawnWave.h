// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_RespawnWave.generated.h"

class AFortPlayerStateAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRespawnWaveDataChanged);

USTRUCT()
struct FFortAthenaMutator_RespawnWaveTeamData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ReplicatedTimeStamp;

	UPROPERTY()
	TArray<TWeakObjectPtr<AFortPlayerStateAthena>> PlayerStates;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_RespawnWave : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int32 GetNextWavePlayerCount(const AFortPlayerStateAthena* PlayerState);

	UFUNCTION(BlueprintCallable)
	void GetNextWavePlayerStates(const AFortPlayerStateAthena* PlayerState, TArray<AFortPlayerStateAthena*>& OutPlayerStates);

	UFUNCTION(BlueprintCallable)
	float GetTimeUntilNextWave(const AFortPlayerStateAthena* PlayerState);

protected:
	UFUNCTION(BlueprintNativeEvent)
	float GetWaveTime(uint8 Team) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RespawnWave")
	FScalableFloat DefaultWaveTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RespawnWave")
	FScalableFloat WaveTeamImbalanceTimeMultiplier;

	UPROPERTY(BlueprintAssignable, Category="RespawnWave")
	FOnRespawnWaveDataChanged OnWaveDataChanged;

	UPROPERTY(EditDefaultsOnly, Category="RespawnWave")
	FScalableFloat MinRespawnWindowTimeReamining;

private:
	UFUNCTION()
	void OnRep_WaveDataArray();

	UFUNCTION()
	void OnWaveLaunched();

	UPROPERTY(ReplicatedUsing=OnRep_WaveDataArray)
	TArray<FFortAthenaMutator_RespawnWaveTeamData> WaveDataArray;

};

