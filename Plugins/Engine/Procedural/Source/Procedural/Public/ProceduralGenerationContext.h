// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralGenerationContext.generated.h"

class AVolume;
class UProceduralGenerationComponent;
class UProceduralGeneratorContext;

// Class that stores the global information about the whole generation process

UCLASS(BlueprintType)
class PROCEDURAL_API UProceduralGenerationContext : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Generation Context")
	UProceduralGenerationComponent* GetGenerationComponent() const;

	UFUNCTION(BlueprintPure, Category="Procedural Generation Context")
	AVolume* GetGenerationVolume() const;

private:
	UPROPERTY(DuplicateTransient)
	TObjectPtr<UProceduralGeneratorContext> GeneratorContext;

	/** Generator Context that finished generating. */
	UPROPERTY(Transient)
	TArray<TObjectPtr<UProceduralGeneratorContext>> GeneratedContexts;

	UPROPERTY(DuplicateTransient)
	TArray<TObjectPtr<UProceduralGeneratorContext>> RegisteredContexts;

	UPROPERTY(DuplicateTransient)
	TMap<FGuid, TObjectPtr<UProceduralGeneratorContext>> GeneratorContexts_DEPRECATED;

};

