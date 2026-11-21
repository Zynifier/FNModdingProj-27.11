// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "Components/FortControllerComponent.h"
#include "FortUIManagerComponent_VictoryCrowns.generated.h"

class AFortPlayerStateAthena;
class UVictoryCrownsIndicator;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortUIManagerComponent_VictoryCrowns : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void RebuildBearerIndicators(const TArray<AFortPlayerStateAthena*>& CrownBearerList);

	UPROPERTY(EditDefaultsOnly, Category="FortUIManagerComponent_VictoryCrowns")
	TSubclassOf<UVictoryCrownsIndicator> VictoryCrownsIndicatorClass;

private:
	UPROPERTY(Transient)
	FUserWidgetPool IndicatorPool;

};

