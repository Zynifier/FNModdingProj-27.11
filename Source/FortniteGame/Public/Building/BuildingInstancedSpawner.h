// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingSMActor.h"
#include "BuildingInstancedSpawner.generated.h"

class ABuildingSMActor;
class APlayerController;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), ClassGroup=("Minigame"), SparseClassDataType=BuildingSMActorClassData)
class AFortBuildingInstancedSpawner : public ABuildingSMActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandlePlayerAdded(APlayerController* AddedPlayer);

private:
	UPROPERTY(EditAnywhere, Category="FortBuildingInstancedSpawner")
	TSubclassOf<ABuildingSMActor> BuildingToInstance;

};

