// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "VerseGameplayTagContainer.h"
#include "TaggedObjectQueryWorldSubsystemBase.generated.h"

/*
//See FortBuildingOctreeManager and GetBuildingActorsThatMatchFilter for a Fortnite specific implementation
USTRUCT()
struct FTaggedObjectOctreeFilter
{
	GENERATED_USTRUCT_BODY()

	FTaggedObjectOctreeFilter()
	: Bounds(ForceInitToZero)
	, MinDistanceFromBoundsCenter(0.0f)
	{}

	// Determines if the incoming building matches this filter
	bool operator()(const UObject* ObjectToCheck) const;

	// The center of the bounds used by the Oct Tree Iterator
	UPROPERTY()
	FBoxSphereBounds Bounds;

	// The Minimum distance an element has to be from the bounds center to be valid
	UPROPERTY(EditAnywhere)
	float MinDistanceFromBoundsCenter;

	// The Tags that the element must match to be valid
	UPROPERTY(EditAnywhere)
	FVerseGameplayTagQuery TagQuery;
};*/
USTRUCT()
struct FTaggedObjectFinderEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TaggedObject")
	FVerseGameplayTagContainer RequiredTags;

	UPROPERTY(EditDefaultsOnly, Category="TaggedObject")
	FVerseGameplayTagContainer PreferredTags;

	UPROPERTY(EditDefaultsOnly, Category="TaggedObject", meta=(DisplayName="Exclusion Tags"))
	FVerseGameplayTagContainer ExclusionTags;

};

// The Tag Query World Subsystem keeps track of tagged objects spawned in the world.

UCLASS(Abstract)
class VERSEGAMEPLAYTAGS_API UTaggedObjectQueryWorldSubsystemBase : public UWorldSubsystem
{
	GENERATED_BODY()

};

