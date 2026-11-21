// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AudioShapePrimitiveComponent.h"
#include "AudioShapeBoxComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, ClassGroup=("AudioShapes"), meta=(BlueprintSpawnableComponent))
class AUDIOSHAPES_API UAudioShapeBoxComponent : public UAudioShapePrimitiveComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Control")
	void SetBoxTransform(const FTransform& InTransform);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	FTransform BoxTransform;

};

