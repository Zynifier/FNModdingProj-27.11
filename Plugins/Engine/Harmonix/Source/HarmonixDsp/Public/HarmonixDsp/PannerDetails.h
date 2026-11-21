// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PannerDetails.generated.h"

UENUM(BlueprintType)
enum class EPannerMode : uint8
{
	LegacyStereo = 0 UMETA(Json="legacy_stereo"),
	Stereo = 1 UMETA(Json="stereo"),
	Surround = 2 UMETA(Json="surround"),
	PolarSurround = 3 UMETA(Json="polar"),
	DirectAssignment = 4 UMETA(Json="direct_assign"),
	Num = 5 UMETA(Hidden),
	Invalid = 6 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FPannerDetails
{
	GENERATED_BODY()

};

