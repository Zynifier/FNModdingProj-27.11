// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/Info.h"
#include "FortSafeZoneIndicatorFuture.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortSafeZoneIndicatorFuture : public AInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated)
	FVector_NetQuantize100 NextNextCenter;

	UPROPERTY(Replicated)
	float NextNextRadius;

};

