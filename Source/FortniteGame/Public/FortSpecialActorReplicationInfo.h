// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Styling/SlateBrush.h"
#include "FortSpecialActorStatData.h"
#include "UI/FortElevationData.h"
#include "FortSpecialActorReplicationInfo.generated.h"

class AActor;
class APlayerState;

USTRUCT()
struct FSpecialActorRepData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName SpecialActorID;

	UPROPERTY()
	FGameplayTag CategoryTag;

	UPROPERTY(NotReplicated)
	TObjectPtr<AActor> SpecialActor;

	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(NotReplicated)
	float ReplicationInterval;

	UPROPERTY(NotReplicated)
	float ReplicationIntervalDeviation;

	UPROPERTY(NotReplicated)
	float NextReplicationTime;

	UPROPERTY(NotReplicated)
	float LastActorNotRelevantTime;

	UPROPERTY(NotReplicated)
	bool bActorIsRelevant;

	UPROPERTY(NotReplicated)
	bool bWasActorRelevantLastUpdate;

	UPROPERTY()
	int16 ReplicatedTransformIndex;

	UPROPERTY(NotReplicated)
	FVector CurrentLocation;

	UPROPERTY(NotReplicated)
	float CurrentYaw;

	UPROPERTY()
	bool bDrawCompassIcon;

	UPROPERTY()
	bool bDrawCompassDistanceText;

	UPROPERTY()
	bool bDrawRotated;

	UPROPERTY()
	float YawOffset;

	UPROPERTY()
	FElevationArrowData ElevationArrowData;

	UPROPERTY()
	uint8 RenderOnMapDuringPhases;

	UPROPERTY()
	float CurrentHealth;

	UPROPERTY()
	float MaxHealth;

	UPROPERTY()
	float CurrentShield;

	UPROPERTY()
	float MaxShield;

	UPROPERTY()
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category="RenderConditions")
	float RenderDistance;

	UPROPERTY(EditDefaultsOnly, Category="RenderConditions")
	FGameplayTagContainer RenderTags;

	UPROPERTY()
	bool bDrawUnderStorm;

	UPROPERTY()
	FGameplayTag SeasonItemTag;

	UPROPERTY()
	FSlateBrush SeasonItemInteractedBrush;

	UPROPERTY()
	int32 Priority;

	UPROPERTY(NotReplicated)
	float AddedToClientTime;

	UPROPERTY(NotReplicated)
	TArray<FSpecialActorSingleStatData> TrackedStats;

private:
	UPROPERTY()
	int8 MinimapIconBrushIndex;

	UPROPERTY()
	int8 MinimapScaleIndex;

	UPROPERTY()
	int8 FullScreenMapIconBrushIndex;

	UPROPERTY()
	int8 FullScreenMapScaleIndex;

	UPROPERTY()
	int8 CompassIconBrushIndex;

	UPROPERTY()
	int8 CompassScaleIndex;

	UPROPERTY(NotReplicated)
	bool bReplicateHealth;

	UPROPERTY(NotReplicated)
	bool bReplicateShield;

	UPROPERTY(NotReplicated)
	float LastLocationReplicationTime;

	UPROPERTY(NotReplicated)
	float PrevLocationReplicatedTime;

	UPROPERTY()
	FVector_NetQuantize InitialRepLocation;

	UPROPERTY(NotReplicated)
	FVector LastRepLocation;

	UPROPERTY(NotReplicated)
	FVector PrevRepLocation;

	UPROPERTY(NotReplicated)
	FVector LerpStartLocation;

	UPROPERTY(NotReplicated)
	float LastYawReplicationTime;

	UPROPERTY(NotReplicated)
	float PrevYawReplicatedTime;

	UPROPERTY()
	float InitialRepYaw;

	UPROPERTY(NotReplicated)
	float LastRepYaw;

	UPROPERTY(NotReplicated)
	float PrevRepYaw;

	UPROPERTY(NotReplicated)
	float LerpStartYaw;

};

USTRUCT()
struct FSpecialActorRepDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FSpecialActorRepData> SpecialActorList;

};

USTRUCT()
struct FSpecialActorTransform
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantize Location;

	UPROPERTY()
	float Yaw;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortSpecialActorReplicationInfo : public AInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated)
	FSpecialActorRepDataArray SpecialActorRepList;

	UPROPERTY(Replicated)
	TArray<FSpecialActorTransform> SpecialActorTransforms;

	UPROPERTY()
	TArray<FSpecialActorStatData> SpecialActorStats;

private:
	UPROPERTY(Replicated)
	TArray<FSlateBrush> SlateBrushes;

	UPROPERTY(Replicated)
	TArray<FVector2D> BrushScales;

};

