// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Info.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortPropertyOverrideReplication.generated.h"

class AFortPropertyOverrideReplShared;
class APropertyOverrideDataReplChunkActor;

USTRUCT()
struct FPropertyOverrideId
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint64 PropertyHashes;

};

USTRUCT()
struct FPropertyOverrideRepl : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	FPropertyOverrideId PropertyId;

	UPROPERTY(VisibleAnywhere, Transient, Category="PropertyOverrideRepl")
	FString PropertyScopedName;

	UPROPERTY(VisibleAnywhere, Transient, Category="PropertyOverrideRepl")
	FString PropertyData;

};

USTRUCT()
struct FPropertyOverrideDataRepl : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Transient, Category="PropertyOverrideDataRepl")
	TArray<FPropertyOverrideRepl> PropertyOverridesReplCached;

	UPROPERTY(Transient, NotReplicated)
	TArray<TObjectPtr<APropertyOverrideDataReplChunkActor>> ChunkActors;

};

USTRUCT()
struct FPropertyOverrideDataReplChunk : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Transient, Category="PropertyOverrideDataReplChunk")
	TArray<FPropertyOverrideRepl> PropertyOverridesRepl;

};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPropertyOverrideReplShared : public AInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_ReplOverrides, Category="FortPropertyOverrideReplShared")
	FPropertyOverrideDataRepl ReplOverrides;

private:
	UFUNCTION()
	void OnRep_ReplOverrides();

};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class APropertyOverrideDataReplChunkActor : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_ChunkIndex();

	UFUNCTION()
	void OnRep_PartialReplOverrides();

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_ChunkIndex, Category="PropertyOverrideDataReplChunkActor")
	uint8 ChunkIndex;

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_PartialReplOverrides, Category="PropertyOverrideDataReplChunkActor")
	FPropertyOverrideDataReplChunk PartialReplOverrides;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortPropertyOverrideReplComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FPropertyOverrideDataRepl PendingReplOverrides;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPropertyOverrideReplShared> ReplOverrideData;

};

UINTERFACE()
class UFortPropertyOverrideReplProvider : public UInterface
{
	GENERATED_BODY()
};

class IFortPropertyOverrideReplProvider
{
	GENERATED_BODY()

};

