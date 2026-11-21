// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FortPickupEntryData.generated.h"

USTRUCT()
struct FFortPickupEntryData
{
	GENERATED_BODY()

private:
	UPROPERTY(meta=(IgnoreForMemberInitializationTest))
	FInterpCurveFloat FloatCurve;

	UPROPERTY()
	FGuid PickupGuid;

	UPROPERTY()
	float StartTime;

};

