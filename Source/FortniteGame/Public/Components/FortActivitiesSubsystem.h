// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortActivitiesSubsystem.generated.h"

USTRUCT()
struct FPlaylistToActivityMapping
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PlaylistName;

	UPROPERTY()
	FString ActivityId;

};

UCLASS(Config=Game, MinimalAPI)
class UFortActivitiesSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FPlaylistToActivityMapping> PlaylistToActivityMap;

};

