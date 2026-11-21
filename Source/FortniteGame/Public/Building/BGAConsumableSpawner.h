// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EQSQueryResultSourceInterface.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Building/BuildingActor.h"
#include "Items/FortItemEntry.h"
#include "BGAConsumableSpawner.generated.h"

class ABuildingActor;
class UBillboardComponent;
class UEQSRenderingComponent;
class UEnvQuery;
class USceneComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingActorClassData)
class ABGAConsumableSpawner : public ABuildingActor, public IEQSQueryResultSourceInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> DummyRoot;

	UPROPERTY(EditAnywhere, Category="Selection")
	FName SpawnLootTierGroup;

	UPROPERTY(EditInstanceOnly, NonPIEDuplicateTransient, Category="Placement")
	TObjectPtr<ABuildingActor> AssociatedBuildingActor;

	UPROPERTY(EditAnywhere, Category="Placement")
	TObjectPtr<UEnvQuery> QueryTemplate;

	UPROPERTY(EditAnywhere, Category="Placement")
	TArray<FAIDynamicParam> QueryConfig;

	UPROPERTY(EditAnywhere, Category="Placement")
	bool bAlignSpawnedActorsToSurface;

	UPROPERTY(Transient)
	TArray<FFortItemEntry> ConsumablesToSpawn;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Category="Placement")
	bool bAllowQueryVisualization;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UEQSRenderingComponent> QueryVisualizationComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Export, Category="Sprite", meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

};

