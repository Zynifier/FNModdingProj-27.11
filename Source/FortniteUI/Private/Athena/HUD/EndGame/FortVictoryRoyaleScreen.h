// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/EndGame/FortPostGameScreen.h"
#include "FortVictoryRoyaleScreen.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortVictoryRoyaleScreen : public UFortPostGameScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortVictoryRoyaleScreen")
	float ScreenDuration;

};

