// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixAudioReactivity/Texture/HarmonixTextureBase.h"
#include "HarmonixHysteresisTextureBase.generated.h"

UCLASS(Abstract, HideCategories=("Object", "Texture", "Adjustments", "Compression", "LevelOfDetail", "Compositing", "ImportSettings"))
class HARMONIXAUDIOREACTIVITY_API UHarmonixHysteresisTextureBase : public UHarmonixTextureBase
{
	GENERATED_BODY()

public:
	// How frequently the texture will get new values and shift out old ones. Smaller is faster; normal unit is seconds per shift.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HysteresisTextureBase", meta=(ClampMin="0"))
	float TicksPerShift;

private:
	// How many frames of hysteresis should we store in the texture?
// (determines the height of the texture)

	UPROPERTY(EditAnywhere, Category="HysteresisTextureBase", meta=(ClampMax="256", ClampMin="1"))
	int32 NumHysteresisSamples;

};

