// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "FortAthenaLowGravZone.generated.h"

class AActor;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaLowGravZone : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnVehicleEnterZone(AActor* Vehicle, float GravityMultiplier);

	UFUNCTION(BlueprintCallable)
	void OnVehicleExitZone(AActor* Vehicle);

};

