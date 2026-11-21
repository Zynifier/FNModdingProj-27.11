// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Math/MathFwd.h"
#include "ARScreenCaptureComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Collision", "Object", "Physics", "SceneComponent", "Collision", "Object", "Physics", "SceneComponent", "Mobility", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UARScreenCaptureComponent : public USceneCaptureComponent2D
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateScreenProjectionMatrix(const FVector& ViewLocation, const FVector& PlaneLocation, const FRotator& PlaneRotation, const FVector2D& PlaneSize);

};

