// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "FortRiftBlockerComponent.generated.h"

UCLASS(HideCategories=("Object", "LOD", "Lighting", "TextureStreaming", "Object", "LOD", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Trigger", "VirtualTexture"), ClassGroup=("AI"), meta=(BlueprintSpawnableComponent))
class UFortRiftBlockerComponent : public UBoxComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rift")
	uint8 bStartActive : 1;

};

