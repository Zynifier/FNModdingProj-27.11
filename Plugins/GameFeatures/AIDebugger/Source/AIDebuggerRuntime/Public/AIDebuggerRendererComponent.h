// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "AIDebuggerRendererComponent.generated.h"

class UMaterial;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Activation", "AssetUserData", "Collision", "Cooking", "HLOD", "Lighting", "LOD", "Mobile", "Navigation", "Physics", "RayTracing", "Rendering", "Tags", "TextureStreaming", "Mobility", "VirtualTexture", "Trigger"))
class UAIDebuggerRendererComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="NavMeshVisuals")
	TObjectPtr<UMaterial> NavMeshMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NavMeshVisuals")
	float NavLinkLineThickness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NavMeshVisuals")
	float NavLinkMaxDrawDistance;

};

