// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "FortMiniMapRadiusTrackerIndicator.generated.h"

class AFortPlayerController;
class UFortControllerComponent_RadiusTracker;

UCLASS(BlueprintType, Blueprintable)
class UFortMiniMapRadiusTrackerIndicator : public UFortMiniMapIndicator
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_RadiusTracker> RadiusTrackerComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY(Transient)
	float PlatformScale;

	UPROPERTY(Transient)
	TArray<FSlateBrush> MinimapRadiusTrackerCircleBrushes;

};

