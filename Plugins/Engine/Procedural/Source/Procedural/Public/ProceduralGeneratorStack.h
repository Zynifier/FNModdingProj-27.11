// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralGenerator.h"
#include "ProceduralGeneratorStack.generated.h"

class UProceduralGenerator;

USTRUCT()
struct PROCEDURAL_API FProceduralGenerationStackElement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Generator", meta=(InlineEditConditionToggle))
	bool bEnabled;

	// Procedural generator

	UPROPERTY(EditAnywhere, Category="Generator", meta=(EditCondition="bEnabled"))
	TObjectPtr<UProceduralGenerator> Generator;

};

UCLASS(MinimalAPI, NotBlueprintable, AutoExpandCategories=("ProceduralGenerationStack"))
class UProceduralGeneratorStack : public UProceduralGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ProceduralGenerationStack")
	TArray<FProceduralGenerationStackElement> Generators;

};

