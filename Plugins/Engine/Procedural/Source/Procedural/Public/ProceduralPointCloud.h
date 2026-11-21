// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralPointCloudPoint.h"
#include "ProceduralPointCloud.generated.h"

UCLASS(BlueprintType)
class UProceduralPointCloud : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Procedural Scatter Point Cloud")
	void Empty();

	UFUNCTION(BlueprintCallable, Category="Procedural Scatter Point Cloud")
	TArray<FProceduralPointCloudPoint> GetPointsByTag(FName InTag);

	UPROPERTY(BlueprintReadWrite, Category="Procedural Scatter Point Cloud")
	TArray<FProceduralPointCloudPoint> Points;

};

