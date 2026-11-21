// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomItemWrapModifier.h"
#include "CustomItemWrapModifier_Banana_Base.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class ACustomItemWrapModifier_Banana_Base : public ACustomItemWrapModifier
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Banana FX|Timing", meta=(ClampMin="0.0"))
	float FadeTime;

	UPROPERTY(EditDefaultsOnly, Category="Banana FX|Parameters")
	FName ConstrastParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Banana FX|Parameters")
	FName OffsetParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Banana FX|Parameters|Frontend")
	float FrontendContrastValue;

	UPROPERTY(EditDefaultsOnly, Category="Banana FX|Parameters|Frontend")
	float FrontendOffsetValue;

	UPROPERTY(EditDefaultsOnly, Category="Banana FX|Parameters|Fade")
	float MinOffsetValue;

	UPROPERTY(EditDefaultsOnly, Category="Banana FX|Parameters|Fade")
	float MaxOffsetValue;

};

