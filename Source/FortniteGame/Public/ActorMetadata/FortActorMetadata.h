// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"
#include "FortActorMetadata.generated.h"

UENUM()
enum class EFortActorTemplateCostUpdateMethod : uint8
{
	Latest = 0,
	// Most recent cost value.

	Smallest = 1,
	// Smallest cost value between existing and most recent value.

	OnlyNew = 2,
	// Only missing template cost values are added. Pre-existing values are preserved.

	Double = 3,
};

USTRUCT()
struct FFortActorTemplateDependency
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<int32> Indices;

};

USTRUCT()
struct FFortActorTemplateData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> IDs;

	UPROPERTY()
	TArray<FName> AssetNames;

	UPROPERTY()
	TArray<int32> InstanceSizes;

	UPROPERTY()
	TArray<int32> AssetPayloads;

	UPROPERTY()
	TArray<int32> InstancePayloads;

	UPROPERTY()
	TArray<FFortActorTemplateDependency> AssetDependencies;

};

USTRUCT()
struct FFortAssetDependencyData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> AssetNames;

	UPROPERTY()
	TArray<int32> AssetSizes;

	UPROPERTY()
	TArray<int32> AssetPayloads;

};

USTRUCT()
struct FFortPlaysetTemplateDependency
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<int32> Indices;

	UPROPERTY()
	TArray<int32> Instances;

};

USTRUCT()
struct FFortPlaysetTemplateData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> AssetNames;

	UPROPERTY()
	TArray<FFortPlaysetTemplateDependency> TemplateDependencies;

};

USTRUCT()
struct FFortActorMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortAssetDependencyData AssetDependencyData;

	UPROPERTY()
	FFortActorTemplateData ActorTemplateData;

	UPROPERTY()
	FFortPlaysetTemplateData PlaysetTemplateData;

};

USTRUCT()
struct FFortAssetDependency
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName AssetName;

	UPROPERTY()
	int32 AssetSize;

};

USTRUCT()
struct FFortActorTemplateAssetData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName AssetName;

	UPROPERTY()
	int32 InstanceSize;

	UPROPERTY()
	TArray<FFortAssetDependency> AssetDependencies;

};

USTRUCT(BlueprintType)
struct FFortActorTemplateStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSoftObjectPath Actor;

	UPROPERTY()
	int32 SharedAssetSize;

	UPROPERTY()
	int32 ExclusiveAssetSize;

	UPROPERTY()
	int32 TotalInstanceSize;

	UPROPERTY()
	int32 MinInstanceSize;

	UPROPERTY()
	int32 MaxInstanceSize;

	UPROPERTY()
	int32 NumInstances;

};

