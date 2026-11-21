// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_RespawnLocation.generated.h"

class AFortPlayerPawn;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_RespawnLocation : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerPawnResurrected(AFortPlayerPawn* PlayerPawn);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RespawnLocation")
	bool bRespawnInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RespawnLocation")
	FGameplayTagQuery LocationQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RespawnLocation")
	bool bRespawnAtDeath;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RespawnLocation")
	float RespawnHeight;

};

