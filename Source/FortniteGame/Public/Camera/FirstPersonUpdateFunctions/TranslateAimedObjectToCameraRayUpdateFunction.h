// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "TranslateAimedObjectToCameraRayUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UTranslateAimedObjectToCameraRayUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TranslateAimedObjectToCameraRayUpdateFunction")
	FVector TranslationRatios;

};

