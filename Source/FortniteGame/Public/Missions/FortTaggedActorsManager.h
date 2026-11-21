// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "Missions/MissionTypes.h"
#include "FortTaggedActorsManager.generated.h"

class ABuildingActor;

USTRUCT()
struct FFortTaggedActorOctreeFilter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FBoxSphereBounds Bounds;

	UPROPERTY(EditAnywhere, Category="FortTaggedActorOctreeFilter")
	float MinDistanceFromBoundsCenter;

	UPROPERTY(EditAnywhere, Category="FortTaggedActorOctreeFilter")
	TArray<TSubclassOf<ABuildingActor>> OptionalSubclasses;

	UPROPERTY(EditAnywhere, Category="FortTaggedActorOctreeFilter")
	TArray<FFortFinderProperty> RequiredProperties;

	UPROPERTY(EditAnywhere, Category="FortTaggedActorOctreeFilter")
	FGameplayTagQuery TagQuery;

};

UCLASS()
class UFortTaggedActorsManager : public UObject
{
	GENERATED_BODY()

};

