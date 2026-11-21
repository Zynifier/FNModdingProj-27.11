// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GameStartCountdown.generated.h"

class USoundBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameStartCountdownBegin, float, Duration, int32, StartingCountdownInteger);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameStartCountdownEnd);

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GameStartCountdown : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FGameStartCountdownBegin OnGameStartCountdownBegin;

	UPROPERTY(BlueprintAssignable)
	FGameStartCountdownEnd OnGameStartCountdownEnd;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Countdown")
	TObjectPtr<USoundBase> CountdownMusicStinger;

	UPROPERTY(EditDefaultsOnly, Category="Countdown")
	FScalableFloat CountdownDuration;

	UPROPERTY(EditDefaultsOnly, Category="Countdown")
	FScalableFloat StartingCountdownInteger;

	UPROPERTY(ReplicatedUsing=OnRep_CountdownTimerRunning)
	bool bCountdownTimerRunning;

private:
	UFUNCTION()
	void OnRep_CountdownTimerRunning();

};

