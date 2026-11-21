// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "EntityActorCustomReplicationComponent.generated.h"

UENUM()
enum EEntityActorReplicationOverrideType
{
	AutoReplication = 0,
	// Replication settings are determined automatically

	DoNotReplicate = 1,
	// Not replicated

	ReplicateAlways = 2,
	// Relevant to all, costly to networking. Should only be used for global managers

	Static_Spatial = 3,
	// These objects don't move and don't need to be updated every frame.

	Dynamic_Spatial = 4,
	// These objects move frequently and are updated once per frame.

	Dormancy_Spatial = 5,
};

UENUM()
enum EEntityActorReplicationRelevancyBucketType
{
	UseVisualCullDistanceForReplicationRelevancy = 0,
	SmallReplicationRelevancy = 1,
	MediumReplicationRelevancy = 2,
	LargeReplicationRelevancy = 3,
	MaxTargetRangeReplicationRelevancy = 4,
	ImportantReplicationRelevancy = 5,
	CustomReplicationRelevancy = 6,
};

UCLASS()
class ENTITYACTOR_API UEntityActorCustomReplicationComponent : public UEntityComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="NoCategory", meta=(DisplayName="Replication Override Type"))
	TEnumAsByte<EEntityActorReplicationOverrideType> ReplicationOverride;

	UPROPERTY(EditAnywhere, Category="NoCategory", meta=(DisplayName="Replication Relevancy Bucket Type"))
	TEnumAsByte<EEntityActorReplicationRelevancyBucketType> ReplicationRelevancyBucketType;

	UPROPERTY(EditAnywhere, Category="NoCategory", meta=(DisplayName="Custom Replication Relevancy Range"))
	float CustomReplicationRelevancyRange;

};

