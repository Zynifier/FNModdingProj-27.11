// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavRelevantInterface.h"
#include "UObject/NoExportTypes.h"
#include "Core/FortSpatialGrid.h"
#include "Curie/FortCurieManagerComponent.h"
#include "Curie/SpatialGrids/FortCurieElementNavRelevantSpatialGrid.h"
#include "CurieManagerComponent.h"
#include "FortCurieSpatialManager.generated.h"

class UFoliageType;
class UFortCurieSpatialManagerConfig;
class UPhysicalMaterial;

USTRUCT()
struct FFortCurieSpatialGrid : public FFortSpatialGrid
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortCurieBuildingGrid : public FFortCurieSpatialGrid
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortCurieGrassGrid : public FFortCurieSpatialGrid
{
	GENERATED_BODY()

};

UCLASS()
class UFortCurieDangerousNavRelevantObject : public UObject, public INavRelevantInterface
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortCurieSpatialManager : public UFortCurieManagerComponent, public IFortCurieNavRelevantSpatialGridInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TObjectPtr<UFoliageType>> GrassFoliageTypePtrs;

	UPROPERTY()
	FFortCurieBuildingGrid CurieBuildingGrid;

	UPROPERTY()
	FFortCurieGrassGrid GrassGrid;

	UPROPERTY()
	FFortCurieNavRelevantSpatialGrid NavRelevantSpatialGrid;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortCurieSpatialManagerConfig> InternalManagerConfig;

};

UCLASS()
class UFortCurieSpatialManagerConfig : public UCurieManagerComponentConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCurieSpatialManagerConfig", meta=(Patchable))
	float ElementOverlapDefaultExpansion;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(EditCondition="bAllowFirePropagationOnGrass", Patchable))
	float GrassWaterContentDecayRate;

	UPROPERTY(EditAnywhere, Category="FortCurieSpatialManagerConfig", meta=(Patchable))
	float AccurateActorOverlapVolumeThreshold;

	UPROPERTY(EditAnywhere, Category="FortCurieSpatialManagerConfig", meta=(Patchable))
	float AccurateActorBoxOverlapVolumeThreshold;

	UPROPERTY(EditAnywhere, Category="FortCurieSpatialManagerConfig")
	TArray<TSoftObjectPtr<UFoliageType>> GrassFoliageTypes;

	UPROPERTY(EditAnywhere, Category="FortCurieSpatialManagerConfig")
	TArray<TSoftObjectPtr<UPhysicalMaterial>> IgnitablePhysicalMaterials;

};

