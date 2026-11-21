// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AI/HotSpots/AIHotSpotSlotGenerator.h"
#include "FortAIHotSpotSlotGenerator_FromConfig.generated.h"

class UAIHotSpotConfig;

UCLASS()
class UFortAIHotSpotSlotGenerator_FromConfig : public UAIHotSpotSlotGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UAIHotSpotConfig> BuildingConfig;

	UPROPERTY(Transient)
	FVector Offset;

	UPROPERTY(Transient)
	uint8 bMirrorX : 1;

	UPROPERTY(Transient)
	uint8 bMirrorY : 1;

};

