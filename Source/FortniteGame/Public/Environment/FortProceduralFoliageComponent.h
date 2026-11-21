// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralFoliageComponent.h"
#include "FortProceduralFoliageComponent.generated.h"

class AActor;
class UFortFoliageSpawnerSet;
class UMaterialInterface;

UCLASS(Config=Editor)
class UFortProceduralFoliageComponent : public UProceduralFoliageComponent
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TSoftObjectPtr<UFortFoliageSpawnerSet> GlobalFoliageSpawnerSet;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Config, Transient)
	TArray<TSoftObjectPtr<UMaterialInterface>> GlobalFoliageTerrainMaterials;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Config, Transient)
	TArray<TSoftClassPtr<AActor>> AdditionalStaticFoliageMeshActorClasses;
#endif

};

