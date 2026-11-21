// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortQuickBars.h"
#include "FortQuickBarsAthena.generated.h"

UCLASS()
class AFortQuickBarsAthena : public AFortQuickBars
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	float ServerPrimarySlotsUpdateDelay;

};

