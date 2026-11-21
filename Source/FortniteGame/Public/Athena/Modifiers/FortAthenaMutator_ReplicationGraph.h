// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ReplicationGraph.generated.h"

enum class ERepGraphMutatorSpatializationZoneType : uint8;

UENUM(BlueprintType)
enum class ERepGraphMutatorSpatializationZoneType : uint8
{
	/** Zone settings for AI actors that support FastShared replication.
	  * (UFortReplicationGraphNode_DynamicSpatialFrequency::AISettings::ZoneSettings) */
	AI = 0,
	/** Zone settings for AI actors that do NOT support FastShared replication.
	  * (UFortReplicationGraphNode_DynamicSpatialFrequency::AISettings::ZoneSettings_NonFastSharedActors) */
	AINonFast = 1,
	/** Zone settings for non-AI actors that support FastShared replication.
	  * (UReplicationGraphNode_DynamicSpatialFrequency::DefaultSettings::ZoneSettings) */
	NonAI = 2,
	/** Zone settings for non-AI actors that do NOT support FastShared replication.
	  * (UReplicationGraphNode_DynamicSpatialFrequency::DefaultSettings::ZoneSettings_NonFastSharedActors) */
	NonAINonFast = 3,
	COUNT = 4 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FRepGraphMutatorSpatializationZone
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="RepGraphMutatorSpatializationZone")
	FScalableFloat MinDotProduct;

	UPROPERTY(EditDefaultsOnly, Category="RepGraphMutatorSpatializationZone")
	FScalableFloat MinDistPct;

	UPROPERTY(EditDefaultsOnly, Category="RepGraphMutatorSpatializationZone")
	FScalableFloat MaxDistPct;

	UPROPERTY(EditDefaultsOnly, Category="RepGraphMutatorSpatializationZone")
	FScalableFloat MinRepHz;

	UPROPERTY(EditDefaultsOnly, Category="RepGraphMutatorSpatializationZone")
	FScalableFloat MaxRepHz;

	UPROPERTY(EditDefaultsOnly, Category="RepGraphMutatorSpatializationZone")
	FScalableFloat FastPath_MinRepHz;

	UPROPERTY(EditDefaultsOnly, Category="RepGraphMutatorSpatializationZone")
	FScalableFloat FastPath_MaxRepHz;

};

USTRUCT(BlueprintType)
struct FRepGraphMutatorSpatializationZoneArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="RepGraphMutatorSpatializationZoneArray")
	TArray<FRepGraphMutatorSpatializationZone> Zones;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Cooking", "FortAthenaMutator", "LOD", "Mutator", "Replication", "Tick", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ReplicationGraph : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OverrideZones(const ERepGraphMutatorSpatializationZoneType ZoneType, const TArray<FRepGraphMutatorSpatializationZone>& MutatorZones);

	UFUNCTION(BlueprintCallable)
	void RestoreAllZones();

	UFUNCTION(BlueprintCallable)
	void RestoreZones(const ERepGraphMutatorSpatializationZoneType ZoneType);

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_ReplicationGraph")
	TMap<ERepGraphMutatorSpatializationZoneType, FRepGraphMutatorSpatializationZoneArray> MutatorZonesMap;

};

