// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Misc/Guid.h"
#include "DeltaFile.generated.h"

class AActor;

USTRUCT()
struct FDeltaAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid ActorGUID;

	UPROPERTY()
	FDateTime CommitTime;

protected:
	UPROPERTY()
	uint32 DataHash;

};

USTRUCT()
struct DELTAFILESYSTEM_API FAddAction : public FDeltaAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY()
	FString JsonStringObjectForPropertyData;

	UPROPERTY()
	FTransform Transform;

};

USTRUCT()
struct DELTAFILESYSTEM_API FDeleteAction : public FDeltaAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ActorName;

	UPROPERTY()
	FTransform Transform;

};

USTRUCT()
struct DELTAFILESYSTEM_API FUpdateAction : public FDeltaAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString JsonStringObjectForPropertyData;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UDeltaComponent : public UActorComponent
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI)
class UDeltaFile : public UInterface
{
	GENERATED_BODY()
};

class DELTAFILESYSTEM_API IDeltaFile
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI)
class UDeltaFileApplier : public UInterface
{
	GENERATED_BODY()
};

class DELTAFILESYSTEM_API IDeltaFileApplier
{
	GENERATED_BODY()

};

