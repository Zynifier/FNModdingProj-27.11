// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/Guid.h"
#include "LevelSaveSpawnableInterface.h"
#include "LevelSaveRecordTests.generated.h"

class AActor;
class UChildActorComponent;
class UObject;

USTRUCT()
struct FLevelSaveTestStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(SaveGame)
	TSoftObjectPtr<UObject> Object;

	UPROPERTY(SaveGame)
	AActor* Actor;

};

USTRUCT()
struct FLevelSaveTestStructArray
{
	GENERATED_BODY()

public:
	UPROPERTY(SaveGame)
	TArray<FLevelSaveTestStruct> Array;

};

UCLASS(MinimalAPI)
class ALSRTestWithChildActorComponent : public AActor, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="LSRTestWithChildActorComponent")
	FGuid SavedActorGuid;

	UPROPERTY(Export, meta=(EditInline="true"))
	UChildActorComponent* TestChildActorComponent;

};

UCLASS(MinimalAPI)
class ALevelSaveTestActor : public AActor, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="LevelSaveTestActor")
	FGuid SavedActorGuid;

	UPROPERTY(SaveGame)
	AActor* SavedActorReference;

	UPROPERTY(SaveGame)
	TArray<AActor*> ActorArray;

	UPROPERTY(SaveGame)
	FLevelSaveTestStruct SimpleStruct;

	UPROPERTY(SaveGame)
	FLevelSaveTestStructArray StructWithArray;

};

UCLASS(MinimalAPI)
class ALevelSaveTestInfoActor : public AActor, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="LevelSaveTestInfoActor")
	FGuid SavedActorGuid;

	UPROPERTY(SaveGame)
	AActor* SavedActorReference;

};

