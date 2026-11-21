// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_StormVehicleHelper.generated.h"

class AActor;

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_StormVehicleHelper : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPlaylistDataLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(EditAnywhere, Category="Event Name")
	FString EventName;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	float WallHeight;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> VehiclesToDestroy;

};

