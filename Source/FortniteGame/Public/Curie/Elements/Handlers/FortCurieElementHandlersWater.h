// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Curie/Elements/Handlers/FortCurieElementHandlers.h"
#include "FortCurieElementHandlersWater.generated.h"

UCLASS()
class UFortCurieElementAttachConditionHandlerWater : public UFortCurieElementAttachConditionHandler
{
	GENERATED_BODY()

};

UCLASS()
class UFortCurieElementInteractWithMaterialHandlerWater : public UFortCurieElementInteractWithMaterialHandler
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FCurveTableRowHandle WaterMagnitudeToWaterContentIncreaseCurve;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FCurveTableRowHandle WaterMagnitudeToWaterContentIncreaseRateCurve;

};

