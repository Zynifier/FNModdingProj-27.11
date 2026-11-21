// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "FortAthenaLivingWorldDebugDensityMiniMapIndicator.generated.h"

USTRUCT()
struct FFortAthenaActorDensityDebugInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ActorName;

	UPROPERTY()
	FVector ActorPosition;

	UPROPERTY()
	FIntVector MinCellIndex;

	UPROPERTY()
	FIntVector MaxCellIndex;

	UPROPERTY()
	float DensityValue;

};

UCLASS()
class UFortAthenaLivingWorldDebugDensityMiniMapIndicator : public UFortMiniMapIndicator
{
	GENERATED_BODY()

private:
	UPROPERTY(Replicated)
	TArray<FFortAthenaActorDensityDebugInfo> ActorDebugInfos;

	UPROPERTY(Replicated)
	TArray<float> DensityGridValues;

	UPROPERTY(Replicated)
	FVector GridOrigin;

	UPROPERTY(Replicated)
	FIntVector MaxGridSize;

	UPROPERTY(Replicated)
	float CellSize;

	UPROPERTY(Replicated)
	float MaxDensity;

	UPROPERTY(Replicated)
	FString DisplayName;

};

