// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Building/BuildingTypes.h"
#include "FortGenericRecord.h"
#include "FortWorldRecord.h"
#include "FortZoneRecord.generated.h"

class ABuildingActor;

USTRUCT()
struct FContainerStatInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FDefenderNPCStatInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FEnemyNpcStatInfo
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortActorRecord
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RecordData")
	FGuid ActorGuid;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RecordData")
	TEnumAsByte<EFortBuildingPersistentState::Type> ActorState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RecordData")
	TSubclassOf<ABuildingActor> ActorClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RecordData")
	FTransform ActorTransform;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RecordData")
	bool bSpawnedActor;

	UPROPERTY()
	TArray<uint8> ActorData;

};

USTRUCT()
struct FFortLevelRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ParentLevelIndex;

	UPROPERTY()
	FGuid BoundActorGuid;

	UPROPERTY()
	FName PackageName;

	UPROPERTY()
	TArray<FFortActorRecord> SavedActors;

	UPROPERTY()
	int32 X_Loc;

	UPROPERTY()
	int32 Y_Loc;

	UPROPERTY()
	uint8 Rotation;

};

USTRUCT()
struct FFortZoneStats
{
	GENERATED_BODY()

};

UCLASS()
class UFortZoneRecord : public UFortGenericRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 WorldSaveCount;

	UPROPERTY()
	int32 ZoneIndex;

	UPROPERTY()
	FName PersistentLevelName;

	UPROPERTY()
	TArray<FFortLevelRecord> SavedLevels;

	UPROPERTY()
	int32 NumSavedLevels;

	UPROPERTY()
	int32 ZoneTileSeed;

	UPROPERTY()
	TArray<FStatManagerPeriodRecord> PlayerMapStatManagerPeriods;

	UPROPERTY()
	int32 CloudSaveItemDefContentVersion;

protected:
	UPROPERTY(Transient)
	bool bNeedsFullActorSave;

};

