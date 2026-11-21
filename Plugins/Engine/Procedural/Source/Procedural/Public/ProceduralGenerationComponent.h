// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/Guid.h"
#include "ProceduralGenerationComponent.generated.h"

class AVolume;
class UProceduralGenerationContext;
class UProceduralGenerator;

// Component that manages the whole procedural generation

UCLASS(BlueprintType)
class PROCEDURAL_API UProceduralGenerationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Procedural generator */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProceduralGeneration")
	TObjectPtr<UProceduralGenerator> Generator;

	/** Whether to visualize the generation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="ProceduralGeneration")
	bool bShowDebugVisualization;

private:
	/** Internal unique id of procedural generator's. */
	UPROPERTY(DuplicateTransient)
	FGuid ProceduralGenerationGuid;

	/** Generation volume. */
	UPROPERTY(DuplicateTransient)
	TObjectPtr<AVolume> GenerationVolume;

	/** Generation context that serves as a global entry point for the whole generation process. */
	UPROPERTY(DuplicateTransient)
	TObjectPtr<UProceduralGenerationContext> GenerationContext;

};

