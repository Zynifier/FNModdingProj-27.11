// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioShapePrimitiveComponent.h"
#include "AudioShapeCylinderComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, ClassGroup=("AudioShapes"), meta=(BlueprintSpawnableComponent))
class AUDIOSHAPES_API UAudioShapeCylinderComponent : public UAudioShapePrimitiveComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Control")
	void SetHalfHeight(float InHalfHeight);

	UFUNCTION(BlueprintCallable, Category="Control")
	void SetRadius(float InRadius);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	float HalfHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	float Radius;

};

