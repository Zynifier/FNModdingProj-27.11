// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "MapLandComponent.generated.h"

UCLASS(HideCategories=("Object", "LOD", "Physics", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Collision"), ClassGroup=("Minimap"), meta=(BlueprintSpawnableComponent))
class UMapLandComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateMinimapDetailsLocation(const FVector& InLocation);

protected:
	UPROPERTY(EditAnywhere, Category="MapLandComponent")
	FSlateBrush LandIcon;

	UPROPERTY(EditAnywhere, Category="MapLandComponent")
	FVector LandIconWorldOffset;

	UPROPERTY()
	FVector MapLocationOverride;

	UPROPERTY(EditAnywhere, Category="MapLandComponent")
	bool bShadowLayer;

};

