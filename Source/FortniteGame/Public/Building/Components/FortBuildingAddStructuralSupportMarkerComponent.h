// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "FortBuildingAddStructuralSupportMarkerComponent.generated.h"

class ABuildingSMActor;

UCLASS(BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortBuildingAddStructuralSupportMarkerComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortBuildingAddStructuralSupportMarkerComponent")
	TSubclassOf<ABuildingSMActor> BuildingClass;

};

