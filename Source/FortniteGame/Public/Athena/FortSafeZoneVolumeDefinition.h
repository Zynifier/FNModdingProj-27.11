// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "FortSafeZoneVolumeDefinition.generated.h"

class AVolume;

USTRUCT(BlueprintType)
struct FFortSafeZoneVolumeDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortSafeZoneVolumeDefinition")
	TObjectPtr<AVolume> Volume;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneVolumeDefinition")
	FScalableFloat RejectionChance;

};

