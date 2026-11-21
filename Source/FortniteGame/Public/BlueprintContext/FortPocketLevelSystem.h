// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Subsystems/WorldSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "FortPocketLevelSystem.generated.h"

class UFortLocalPlayer;
class UFortPocketLevel;
class ULevelStreamingDynamic;
class UPocketLevelInstance;
class UWorld;

UCLASS(MinimalAPI)
class UFortPocketLevelSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UPocketLevelInstance>> PocketInstances;

};

UCLASS(MinimalAPI)
class UPocketLevelInstance : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortPocketLevel> PocketLevel;

	UPROPERTY()
	TObjectPtr<UWorld> World;

	UPROPERTY()
	TObjectPtr<UFortLocalPlayer> LocalPlayer;

	UPROPERTY()
	FVector SpawnPoint;

private:
	UFUNCTION()
	void HandlePocketLevelLoaded();

	UFUNCTION()
	void HandlePocketLevelShown();

	UPROPERTY()
	TObjectPtr<ULevelStreamingDynamic> StreamingPocketLevel;

};

