// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "FortVolumeMiniMapIndicator.generated.h"

UCLASS()
class UFortVolumeMiniMapIndicator : public UFortMiniMapIndicator
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FSlateBrush PerimeterBrush;

	UPROPERTY(Transient)
	FSlateBrush OnRadarBrush;

};

