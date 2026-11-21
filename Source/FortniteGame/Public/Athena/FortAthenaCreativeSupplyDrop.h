// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaSupplyDrop.h"
#include "FortItemQuantityPair.h"
#include "FortAthenaCreativeSupplyDrop.generated.h"

class AFortPawn;

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaCreativeSupplyDrop : public AFortAthenaSupplyDrop
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Replicated, Category="Creative")
	TArray<FFortItemQuantityPair> SpawnItems;

protected:
	UFUNCTION(BlueprintCallable)
	void SpawnLoot(AFortPawn* Pawn);

	UFUNCTION(BlueprintCallable)
	void ValidateSpawnItems();

};

