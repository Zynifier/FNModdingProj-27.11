// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortDynamicBuildingDeconstructor.generated.h"

class ABuildingActor;
class UBillboardComponent;

UCLASS(BlueprintType, HideCategories=("Input", "Replication", "Rendering", "Gameplay", "Navigation", "Culling", "Team"))
class AFortDynamicBuildingDeconstructor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	FBoxSphereBounds Bounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bDebugDrawBounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bSelectiveDestruction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bIgnoreMissionActors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bShrinkAndDestroyEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	int32 NumOfPiecesToDestroyAtOnce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	float TimeBetweenChunks;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

	UPROPERTY()
	TArray<TWeakObjectPtr<ABuildingActor>> SortedBuildingActors;

	UPROPERTY()
	int32 CurrentIndex;

};

