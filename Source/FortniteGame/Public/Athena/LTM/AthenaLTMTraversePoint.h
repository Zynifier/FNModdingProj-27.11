// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Building/AthenaTraversePoint.h"
#include "AthenaLTMTraversePoint.generated.h"

class AActor;

UCLASS(MinimalAPI, HideCategories=("AI", "Foliage", "Input", "Rendering", "Team", "Interaction", "Movement", "Building", "Damage", "Navigation", "GridSnapping", "AI", "Foliage", "Input", "Rendering", "Team", "Interaction", "Movement", "Building", "Damage", "Navigation", "GridSnapping", "Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaLTMTraversePoint : public AAthenaTraversePoint
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Tags")
	FGameplayTagContainer TraversePointGameplayTags;

private:
	UFUNCTION()
	void OnStartOverlap(AActor* OverlappedActor, AActor* OtherActor);

};

