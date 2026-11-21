// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicUI/DynamicUIDirectorBase.h"
#include "DynamicAthenaHUDDirector.generated.h"

class UDynamicUIScene;

UCLASS(HideCategories=("Actor", "ActorTick", "Collision", "Cooking", "DataLayers", "Events", "HLOD", "Input", "LOD", "Physics", "Rendering", "Replication", "WorldPartition"))
class ADynamicAthenaHUDDirector : public ADynamicUIDirectorBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DynamicAthenaHUDDirector")
	TObjectPtr<UDynamicUIScene> VehicleHUDScene;

	UPROPERTY(EditDefaultsOnly, Category="DynamicAthenaHUDDirector")
	TObjectPtr<UDynamicUIScene> CreativeQuickbarScene;

	UPROPERTY(EditDefaultsOnly, Category="Competitive")
	TObjectPtr<UDynamicUIScene> TournamentScene;

	UPROPERTY(EditDefaultsOnly, Category="Competitive")
	TObjectPtr<UDynamicUIScene> ArenaTournamentScene;

private:
	UFUNCTION()
	void HandleCreativeQuickbarEquippedChanged(bool bIsQuickbarEquipped);

	UFUNCTION()
	void HandleEnteringVehicle();

	UFUNCTION()
	void HandleExitingVehicle();

};

