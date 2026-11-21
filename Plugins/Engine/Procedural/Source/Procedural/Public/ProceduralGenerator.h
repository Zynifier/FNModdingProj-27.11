// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralGenerator.generated.h"

USTRUCT(BlueprintType)
struct FProceduralDebugSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugPointCloud;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	FColor DebugPointColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug", meta=(ClampMax="10000000", ClampMin="0", UIMax="10000000", UIMin="0"))
	float DebugCullingDistance;

};

// Base class for all Procedural Generators

UCLASS(Abstract, EditInlineNew, MinimalAPI, BlueprintType)
class UProceduralGenerator : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Debug", meta=(ShowOnlyInnerProperties))
	FProceduralDebugSettings DebugSettings;

};

