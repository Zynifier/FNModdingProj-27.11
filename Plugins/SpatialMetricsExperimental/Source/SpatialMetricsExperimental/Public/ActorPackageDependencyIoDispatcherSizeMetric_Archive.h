// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialMetric.h"
#include "SpatialMetricsActorIndexerSubscriber.h"
#include "ActorPackageDependencyIoDispatcherSizeMetric_Archive.generated.h"

UENUM()
enum class EIoDispatcherChunkTypeFlags : uint32
{
	ExportBundleData = 1,
	BulkData = 2,
	OptionalBulkData = 4,
	MemoryMappedBulkData = 8,
	ScriptObjects = 16,
	ContainerHeader = 32,
	ExternalFile = 64,
	ShaderCodeLibrary = 128,
	ShaderCode = 256,
	PackageStoreEntry = 512,
	DerivedData = 1024,
	EditorDerivedData = 2048,
	PackageResource = 4096,
	None = 0,
	Default = 15,
	All = 8191,
};

UCLASS(meta=(DisplayName="ActorPackageDependencyIoDispatcherSizeMetric (Archive References)"))
class UActorPackageDependencyIoDispatcherSizeMetric_Archive : public USpatialMetric, public ISpatialMetricsActorIndexerSubscriber
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EIoDispatcherChunkTypeFlags ChunkTypeFlags;

};

