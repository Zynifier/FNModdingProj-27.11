// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "STW/FortGameStatePvE.h"
#include "FortGameStateBoss.generated.h"

class AActor;
class AController;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateBoss : public AFortGameStatePvE
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Game State Boss")
	void AllPlayersDied();

	UFUNCTION(BlueprintCallable, Category="Game State Boss")
	void BossKilled(const AController* InstigatingController, const AActor* DamageCausingActor, const FGameplayTagContainer& DamageTags);

	UFUNCTION(BlueprintCallable, Category="Game State Boss")
	void BossSpawned();

};

