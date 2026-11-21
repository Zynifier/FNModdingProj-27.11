// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ButterflyEvent.generated.h"

class AFortPlayerPawnAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButterflyPawnBroadcast, const TArray<AFortPlayerPawnAthena*>&, AthenaPawns);

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ButterflyEvent : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Mutator")
	void StartGatheringPawns();

	UFUNCTION(BlueprintCallable, Category="Mutator")
	void StopGatheringPawns();

	UPROPERTY(BlueprintAssignable)
	FOnButterflyPawnBroadcast OnPawnBroadcast;

protected:
	UFUNCTION()
	void UpdatePawnBroadcasting();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ButterflyEvent")
	float PawnGatherFrequency;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ButterflyEvent")
	FScalableFloat PawnSpawnLocationX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ButterflyEvent")
	FScalableFloat PawnSpawnLocationY;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ButterflyEvent")
	FScalableFloat PawnSpawnMinDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ButterflyEvent")
	FScalableFloat PawnSpawnMaxDistance;

};

