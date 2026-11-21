// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "SimObjectActor.generated.h"

UENUM()
enum ESimObjectRepNodeMapping
{
	NotReplicated = 0,
	// Not replicated

	RelevantAllInsidePlayspace = 1,
	// Relevant to all

	Spatial_Static = 2,
	// These actors don't move and don't need to be updated every frame.

	Spatial_Dynamic = 3,
	// These actors mode frequently and are updated once per frame.

	Spatial_Dormancy = 4,
};

/** Entity placeholder for customizing how the repgraph handles replication information.
 * @TODO: Allow customizing how entities are replicated without requiring them to participate in the Actor inheritance hierarchy.
 */
UCLASS(HideCategories=("Input"), ConversionRoot, meta=(ChildCanTick, IgnoreCategoryKeywordsInSubclasses="true"))
class ENTITYACTOR_API ASimObject : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};

