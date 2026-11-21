// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MinimapHiddenComponent.generated.h"

UCLASS(EditInlineNew, HideCategories=("Object", "LOD", "Physics", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Collision"), ClassGroup=("Minimap"), meta=(BlueprintSpawnableComponent))
class UMinimapHiddenComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void PrepareForCapture();

};

