// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralGenerator.h"
#include "ProceduralCustomGenerator.generated.h"

class UProceduralGeneratorContext;

UCLASS(MinimalAPI)
class UProceduralCustomGenerator : public UProceduralGenerator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="CustomGenerator", meta=(BlueprintBaseOnly))
	TSubclassOf<UProceduralGeneratorContext> GeneratorContextClass;

	UPROPERTY(EditAnywhere, NoClear, Category="CustomGenerator", meta=(EditInline, NoResetToDefault))
	TObjectPtr<UProceduralGeneratorContext> GeneratorContext;

};

