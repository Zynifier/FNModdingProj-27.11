// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ProceduralPointCloudPoint.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FProceduralPointCloudPoint
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Procedural Point Cloud Point")
	FTransform Transform;

	UPROPERTY(BlueprintReadWrite, Category="Procedural Point Cloud Point")
	FVector SurfaceNormal;

	UPROPERTY(BlueprintReadWrite, Category="Procedural Point Cloud Point")
	TObjectPtr<UObject> SurfaceObject;

	UPROPERTY(BlueprintReadWrite, Category="Procedural Point Cloud Point")
	TObjectPtr<UObject> Object;

	UPROPERTY(BlueprintReadWrite, Category="Procedural Point Cloud Point")
	int32 ObjectVariation;

	UPROPERTY(BlueprintReadWrite, Category="Procedural Point Cloud Point")
	TArray<FName> Tags;

	UPROPERTY(BlueprintReadWrite, Category="Procedural Point Cloud Point")
	float CollisionRadius;

	UPROPERTY(BlueprintReadWrite, Category="Procedural Point Cloud Point")
	float SourcePointGeneratorIndex;

};

