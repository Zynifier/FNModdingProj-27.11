// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManagerSettings.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "DeltaFile.h"
#include "FortCreativeVkPalette.h"
#include "ObjectTracking/ObjectTracking.h"
#include "LevelSaveRecord.generated.h"

class AActor;
class UActorComponent;
class ULevelRecordSpawner;
class ULevelSaveRecord;
class UWorld;

USTRUCT()
struct FActorComponentRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName ComponentName;

	UPROPERTY()
	TSoftClassPtr<UActorComponent> ComponentClass;

	UPROPERTY()
	TArray<uint8> ComponentData;

	UPROPERTY()
	TArray<FSoftObjectPath> ComponentDataReferenceTable;

	UPROPERTY()
	TArray<bool> ComponentDataHardReferences;

	UPROPERTY()
	TMap<FString, FGuid> ComponentRecordPropertyToActorGuid;

	UPROPERTY()
	uint32 DataHash;

	UPROPERTY()
	uint16 DataHeaderSize;

};

USTRUCT()
struct FActorInstanceRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint64 RecordID;

	UPROPERTY()
	uint64 TemplateRecordID;

	UPROPERTY()
	FName ActorID;

	UPROPERTY()
	FGuid ActorGUID;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ActorPtr;

};

USTRUCT()
struct FActorTemplateRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint64 ID;

	UPROPERTY()
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY()
	TArray<FActorComponentRecord> ActorComponents;

	UPROPERTY()
	TArray<uint8> ActorData;

	UPROPERTY()
	TArray<FSoftObjectPath> ActorDataReferenceTable;

	UPROPERTY()
	TArray<bool> ActorDataHardReferences;

	UPROPERTY()
	TMap<FString, FGuid> PropertyToActorGuid;

	UPROPERTY()
	uint32 DataHash;

	UPROPERTY()
	uint16 DataHeaderSize;

	UPROPERTY()
	int16 LevelRecordSaveVersion;

	UPROPERTY()
	bool bUsingRecordDataReferenceTable;

};

USTRUCT()
struct FAdditionalLSRSaveProperty
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ClassName;

	UPROPERTY()
	FString PropertyName;

};

USTRUCT()
struct FComponentRecordRedirect
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ClassName;

	UPROPERTY()
	FString OldComponentClass;

	UPROPERTY()
	FString OldComponentName;

	UPROPERTY()
	FString NewComponentClass;

	UPROPERTY()
	FString NewComponentName;

};

USTRUCT()
struct FDeleteActorRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint64 RecordID;

	UPROPERTY()
	FName ActorID;

	UPROPERTY()
	TSoftClassPtr<AActor> ActorClass;

};

USTRUCT()
struct FLevelInstanceActorRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LevelInstanceName;

	UPROPERTY()
	FGuid ActorGUID;

};

USTRUCT()
struct FLevelSaveRecordCollectionItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<ULevelSaveRecord> LevelSaveRecord;

	UPROPERTY()
	FName RecordUniqueName;

	UPROPERTY()
	FTransform Transform;

};

USTRUCT()
struct FLevelSaveRecordRedirect : public FAssetManagerRedirect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AssetRedirect")
	TArray<FName> ConditionTags;

};

USTRUCT()
struct FLevelStreamedDeleteActorRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName ActorID;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY()
	TSoftObjectPtr<UWorld> OwningLevel;

};

USTRUCT()
struct FRecordBucket
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<int32> RecordIndices;

};

USTRUCT()
struct FRecordBucketMap
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<FIntPoint, FRecordBucket> PositionToRecord;

	UPROPERTY(Transient)
	TArray<int32> DuplicateRecords;

};

USTRUCT()
struct FStructRecord
{
	GENERATED_BODY()

};

USTRUCT()
struct FSaveStructFile
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FStructRecord> StructRecords;

};

UCLASS(Config=Game, DefaultConfig)
class UFortComponentRecordRedirects : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FComponentRecordRedirect> ComponentRecordRedirects;

};

UCLASS(MinimalAPI)
class ULevelSaveRecord : public UObject, public IDeltaFile
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FObjectCostVersion CreateVersion;

	UPROPERTY()
	FVector HalfBoundsExtent;

	UPROPERTY()
	FRotator Rotation;

	UPROPERTY()
	FVector Scale;

	UPROPERTY()
	FFortCreativeVkPalette VkPalette;

	UPROPERTY()
	FString PersistenceSharedProjectId;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> RecentlySpawnedActors;

private:
	UFUNCTION()
	void FailsafeTimerExpired();

	UPROPERTY()
	FVector Center;

	UPROPERTY()
	uint64 LastTemplateID;

	UPROPERTY()
	uint64 LastRecordID;

	UPROPERTY()
	TMap<int32, FActorTemplateRecord> TemplateRecords;

	UPROPERTY()
	TMap<FGuid, FActorInstanceRecord> ActorInstanceRecords;

	UPROPERTY()
	TMap<FGuid, FLevelInstanceActorRecord> LevelInstanceActorRecords;

	UPROPERTY()
	TMap<FGuid, FActorInstanceRecord> VolumeInfoActorRecords;

	UPROPERTY()
	int32 PlayerPersistenceUserWipeNumber;

	UPROPERTY()
	FString LevelInstanceName;

	UPROPERTY()
	TSet<FName> LevelSaveTags;

	UPROPERTY()
	TArray<FDeleteAction> DeleteActions;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ULevelRecordSpawner>> ActiveSpawners;

	UPROPERTY(Transient)
	FRecordBucketMap RecordBucketMap;

	UPROPERTY()
	bool bRequiresGridPlacement;

};

UCLASS(Config=Game, DefaultConfig)
class ULevelSaveRecordActorClassRedirects : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FLevelSaveRecordRedirect> LevelSaveRecordActorClassRedirects;

};

UCLASS(Config=Game, DefaultConfig)
class ULevelSaveRecordAdditionalSaveProperties : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FAdditionalLSRSaveProperty> AdditionalPropertyToSave;

};

UCLASS()
class ULevelSaveRecordCollection : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FLevelSaveRecordCollectionItem> Items;

};

