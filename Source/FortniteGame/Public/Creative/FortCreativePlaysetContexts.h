// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortCreativePlaysetContexts.generated.h"

class AActor;
class UFortPlaysetItemDefinition;
class ULevelRecordSpawner;

USTRUCT()
struct FPlaysetBaseContext
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> EventOwner;

	UPROPERTY()
	TObjectPtr<UFortPlaysetItemDefinition> Playset;

	UPROPERTY()
	TObjectPtr<ULevelRecordSpawner> LevelRecordSpawner;

};

USTRUCT()
struct FPlaysetPlacedContext : public FPlaysetBaseContext
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FRotator Rotation;

};

