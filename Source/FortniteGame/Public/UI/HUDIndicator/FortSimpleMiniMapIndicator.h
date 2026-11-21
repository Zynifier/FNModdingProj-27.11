// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "FortSimpleMiniMapIndicator.generated.h"

UCLASS(MinimalAPI)
class UFortSimpleMiniMapIndicator : public UFortMiniMapIndicator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FSlateBrush NormalBrush;

	UPROPERTY(Transient)
	FSlateBrush AboveBelowBrush;

};

