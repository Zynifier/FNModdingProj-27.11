// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AudioShapePrimitiveComponent.h"
#include "AudioShapeLineListComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, ClassGroup=("AudioShapes"), meta=(BlueprintSpawnableComponent))
class UAudioShapeLineListComponent : public UAudioShapePrimitiveComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Control")
	int32 AddPoint(const FVector& InPoint);

	UFUNCTION(BlueprintPure, Category="Control")
	void GetPoints(TArray<FVector>& OutPoints) const;

	UFUNCTION(BlueprintCallable, Category="Control")
	bool RemovePoint(int32 InIndex);

	UFUNCTION(BlueprintCallable, Category="Control")
	bool UpdatePoint(int32 InIndex, const FVector& InPoint);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config")
	TArray<FVector> PointList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config")
	bool bClosedLoop;

};

