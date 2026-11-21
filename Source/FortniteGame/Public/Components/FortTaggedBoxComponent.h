// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameplayTagContainer.h"
#include "FortTaggedBoxComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "LOD", "Lighting", "TextureStreaming", "Object", "LOD", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Trigger", "VirtualTexture"), meta=(BlueprintSpawnableComponent))
class UFortTaggedBoxComponent : public UBoxComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortTaggedBoxComponent")
	FGameplayTagContainer GameplayTags;

};

