// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "CorruptionCoverageMap.generated.h"

class UObject;
class UTextureRenderTarget2D;

UCLASS(BlueprintType)
class UCorruptionCoverageMap : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintPure, Category="CorruptionCoverageMap")
	bool IsLocationCorrupted(const FVector& Location, float Padding = 0.000000f) const;

	UFUNCTION(BlueprintCallable, Category="CorruptionCoverageMap", meta=(WorldContext="WorldContextObject"))
	bool UpdateCorruptionCoverageMap(UObject* WorldContextObject, UTextureRenderTarget2D* CorruptionRenderTarget, const FVector& InTopLeftWorldCoordinate, const FVector& InBottomRightWorldCoordinate, float CoverageThreshold, float DebugDrawDuration = -1.000000f);

};

