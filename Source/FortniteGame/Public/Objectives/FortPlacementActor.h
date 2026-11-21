// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingActor.h"
#include "FortPlacementActor.generated.h"

class AActor;
class UBillboardComponent;
class UBoxComponent;
class UTexture2D;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Collision", "Culling", "Rendering", "Replication", "Gameplay", "Navigation", "BuildingBounds", "Game|Damage"), ClassGroup=("Game"), SparseClassDataType=BuildingActorClassData)
class AFortPlacementActor : public ABuildingActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> OccupyingActor;

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="EditorVisuals")
	TObjectPtr<UTexture2D> EditorIcon;
#endif

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> BoxComponent;
#endif

};

