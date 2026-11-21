// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "ProceduralGenerationBlockingVolume.generated.h"

class AProceduralGenerationVolume;
class UBoundsCopyComponent;

/** An invisible volume used to block procedural generation to generate content inside this volume */
UCLASS(MinimalAPI, HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AProceduralGenerationBlockingVolume : public AVolume
{
	GENERATED_BODY()

public:
	/** Procedural Generation Volumes to block. Blocks all generation volumes if none is specified. */
	UPROPERTY(EditAnywhere, Category="ProceduralGeneration")
	TArray<TObjectPtr<AProceduralGenerationVolume>> BlockedVolumes;

private:
#if WITH_EDITORONLY_DATA
	/** Component that enables Editor bounds copy functionality. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Transform", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UBoundsCopyComponent> BoundsCopyComponent;
#endif

};

