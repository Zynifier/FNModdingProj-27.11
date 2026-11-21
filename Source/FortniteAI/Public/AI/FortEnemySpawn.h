// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingActor.h"
#include "FortEnemySpawn.generated.h"

class UBillboardComponent;

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingActorClassData)
class AFortEnemySpawn : public ABuildingActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ClusterRadius;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

};

