// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortFoliageSpawnerSet.generated.h"

class UProceduralFoliageSpawner;

UCLASS()
class UFortFoliageSpawnerSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Foliage")
	TArray<TObjectPtr<UProceduralFoliageSpawner>> FoliageSpawners;

};

