// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingSMActor.h"
#include "FortPlayerSpawnPad.generated.h"

class AFortPlayerPawn;
class UStaticMeshComponent;

UCLASS(Abstract, MinimalAPI, BlueprintType, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class AFortPlayerSpawnPad : public ABuildingSMActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortPlayerSpawnPad")
	void ChestProgressionUpdate(FVector PrimaryChestOffset, FVector ChestOffset);

	UFUNCTION(BlueprintPure, Category="FortPlayerSpawnPad")
	void GetPossessedPlayerPawnsByID(TArray<AFortPlayerPawn*>& SortedPlayerPawns) const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="FortPlayerSpawnPad")
	int32 GetRewardedChestIndex() const;

	UFUNCTION(BlueprintCallable, Category="FortPlayerSpawnPad")
	void InitializeChestProgression();

	UFUNCTION(BlueprintCallable, Category="FortPlayerSpawnPad")
	void PrestreamChestTextures();

	UPROPERTY(BlueprintReadWrite, Export, Category="FortPlayerSpawnPad", meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> Chests;

};

