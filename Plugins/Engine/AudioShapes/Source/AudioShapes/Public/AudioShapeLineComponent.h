// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AudioShapePrimitiveComponent.h"
#include "AudioShapeLineComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, ClassGroup=("AudioShapes"), meta=(BlueprintSpawnableComponent))
class UAudioShapeLineComponent : public UAudioShapePrimitiveComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Control")
	void SetEndPoint(const FVector& InEndPoint);

	UFUNCTION(BlueprintCallable, Category="Control")
	void SetStartPoint(const FVector& InStartPoint);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	FVector StartPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	FVector EndPoint;

};

