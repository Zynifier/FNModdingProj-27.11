// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_BuildingLocalizationCache.generated.h"

class UBuildingActorLocalizationCache;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_BuildingLocalization : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_BuildingLocalization")
	UBuildingActorLocalizationCache* BuildingActorLocalization;

};

