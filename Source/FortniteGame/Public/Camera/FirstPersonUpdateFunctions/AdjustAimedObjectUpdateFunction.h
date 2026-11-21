// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "AdjustAimedObjectUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UAdjustAimedObjectUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AdjustAimedObjectUpdateFunction")
	FRotator Rotation;

	UPROPERTY(EditAnywhere, Category="AdjustAimedObjectUpdateFunction")
	FVector Translation;

};

