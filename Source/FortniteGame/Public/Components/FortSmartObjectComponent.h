// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "SmartObjectComponent.h"
#include "FortSmartObjectComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Activation", "AssetUserData", "Collision", "Cooking", "HLOD", "Lighting", "LOD", "Mobile", "Mobility", "Navigation", "Physics", "RayTracing", "Rendering", "Tags", "TextureStreaming", "Trigger", "PhysicsVolume"), ClassGroup=("Gameplay"), meta=(BlueprintSpawnableComponent))
class UFortSmartObjectComponent : public USmartObjectComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="SmartObject", meta=(EditCondition="bDisableForeverWhenMovedOrRotated"))
	FVector MaxAbsoluteAngles;

	UPROPERTY(EditAnywhere, Category="SmartObject")
	bool bDisableForeverWhenMovedOrRotated;

	UPROPERTY(EditAnywhere, Category="SmartObject", meta=(EditCondition="bDisableForeverWhenMovedOrRotated"))
	float MinDistanceToMoveToDisable;

	UPROPERTY(EditAnywhere, Category="SmartObject", meta=(EditCondition="bDisableForeverWhenMovedOrRotated"))
	FVector MinEulerAnglesDeltaToDisable;

};

