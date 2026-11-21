// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPawnComponent.h"
#include "DespawnExpiredPawnComponent.generated.h"

class ABuildingRift;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UDespawnExpiredPawnComponent : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddDespawnRift(ABuildingRift* NewRift);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DespawnExpired();

	UFUNCTION(BlueprintCallable)
	TArray<ABuildingRift*> GetDespawnRifts();

};

