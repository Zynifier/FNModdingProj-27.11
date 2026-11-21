// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Building/BuildingFoundation.h"
#include "AthenaBuildingFoundationObjective.generated.h"

class ABuildingActor;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class AAthenaBuildingFoundationObjective : public ABuildingFoundation
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLowHealthPercentReached();

	UPROPERTY(EditDefaultsOnly, Category="AthenaBuildingFoundationObjective")
	FSlateBrush MiniMapBrush;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBuildingFoundationObjective")
	FGameplayTag FoundationTag;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBuildingFoundationObjective")
	FScalableFloat LowHealthPercent;

	UPROPERTY()
	TArray<TObjectPtr<ABuildingActor>> SpawnedBuildingActors;

	UPROPERTY(Replicated)
	float CurrentHealth;

	UPROPERTY(Replicated)
	float MaxHealth;

};

