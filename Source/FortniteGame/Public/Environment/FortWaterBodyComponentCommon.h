// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "FortWaterBodyComponentCommon.generated.h"

UCLASS(DefaultToInstanced)
class UFortWaterBodyComponentCommon : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Water")
	FScalableFloat WaterVelocityRemapInputRange;

	UPROPERTY(EditAnywhere, Category="Water")
	FScalableFloat WaterVelocityRemapOutputRange;

	UPROPERTY(EditAnywhere, Category="Water")
	FScalableFloat WaterVelocityPerpendicularBias;

	UPROPERTY(EditAnywhere, Category="Water")
	bool bIsSwamp;

};

