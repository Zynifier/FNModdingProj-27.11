// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "ProceduralGenerationVolume.generated.h"

class UBoundsCopyComponent;
class UProceduralGenerationComponent;

// Actor used to scope procedural generation inside a volume

UCLASS(BlueprintType, HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class PROCEDURAL_API AProceduralGenerationVolume : public AVolume
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="ProceduralGeneration")
	void ClearGeneratedContent();

	UFUNCTION(BlueprintCallable, Category="ProceduralGeneration")
	void Generate();

	/** Component that will manage the whole procedural generation */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ProceduralGeneration", meta=(EditInline="true"))
	TObjectPtr<UProceduralGenerationComponent> ProceduralComponent;

private:
#if WITH_EDITORONLY_DATA
	/** Component that enables Editor bounds copy functionality. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Transform", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UBoundsCopyComponent> BoundsCopyComponent;
#endif

};

