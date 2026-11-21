// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralGeneratorContext.generated.h"

class UObject;
class UProceduralGenerationContext;
class UProceduralGenerator;
class UProceduralGeneratorContext;
class UProceduralPointCloud;

// Manages generation process, visualization & stores intermediate data

UCLASS(Abstract, BlueprintType, Blueprintable)
class PROCEDURAL_API UProceduralGeneratorContext : public UObject
{
	GENERATED_BODY()

public:
	/** Entry point of clearing generated content. */
	UFUNCTION(BlueprintCallable, Category="Procedural Generator Context")
	void ClearGeneratedContent();

	/** Entry point of generation. */
	UFUNCTION(BlueprintCallable, Category="Procedural Generator Context")
	bool Generate();

	UFUNCTION(BlueprintPure, Category="Procedural Generator Context")
	TArray<UProceduralGeneratorContext*> GetGeneratedContexts() const;

	UFUNCTION(BlueprintCallable, Category="Procedural Generator Context")
	void GetOrCreateGeneratorContext(UProceduralGenerator* Generator, UProceduralGeneratorContext*& Context);

	/** Override to clear generated content. */
	UFUNCTION(BlueprintNativeEvent)
	void OnClearGeneratedContent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDrawVisualization() const;

	/** Override to customize procedural generation. */
	UFUNCTION(BlueprintNativeEvent)
	bool OnGenerate();

protected:
	/** Associated generator */
	UPROPERTY(BlueprintReadOnly, Category="Procedural Generation Context")
	TObjectPtr<UProceduralGenerator> Generator;

	/** Parent generation context */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Procedural Generation Context")
	TObjectPtr<UProceduralGenerationContext> GenerationContext;

	/** Owner generator context */
	UPROPERTY(Transient)
	TObjectPtr<UProceduralGeneratorContext> OwnerContext;

	/** Generated objects. */
	UPROPERTY(BlueprintReadWrite, Category="Procedural Generation Context")
	TArray<TObjectPtr<UObject>> GeneratedObjects;

	/** Exported point cloud. */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Procedural Generation COntext")
	TObjectPtr<UProceduralPointCloud> ExportedPointCloud;

};

