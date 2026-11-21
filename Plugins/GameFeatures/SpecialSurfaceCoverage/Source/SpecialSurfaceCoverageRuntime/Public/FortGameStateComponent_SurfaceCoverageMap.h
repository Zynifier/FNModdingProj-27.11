// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortGameStateComponent_SurfaceOverride.h"
#include "FortGameStateComponent_SurfaceCoverageMap.generated.h"

class UObject;
class UTextureRenderTarget2D;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_SurfaceCoverageMap : public UFortGameStateComponent_SurfaceOverride
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SurfaceCoverageMap", meta=(WorldContext="WorldContextObject"))
	bool UpdateCoverageMap(UObject* WorldContextObject, UTextureRenderTarget2D* SpecialSurfaceRenderTarget, const FVector& InTopLeftWorldCoordinate, const FVector& InBottomRightWorldCoordinate, float CoverageThreshold, float DebugDrawDuration = -1.000000f);

};

