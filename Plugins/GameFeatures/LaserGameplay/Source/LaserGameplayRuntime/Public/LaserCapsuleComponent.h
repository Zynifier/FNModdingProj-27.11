// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Engine/EngineTypes.h"
#include "LaserCapsuleComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "LOD", "Lighting", "TextureStreaming", "Object", "LOD", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Trigger", "VirtualTexture"))
class ULaserCapsuleComponent : public UCapsuleComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Laser")
	TEnumAsByte<ECollisionEnabled::Type> CollisionWhenEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Laser")
	TEnumAsByte<ECollisionEnabled::Type> CollisionWhenDisabled;

};

