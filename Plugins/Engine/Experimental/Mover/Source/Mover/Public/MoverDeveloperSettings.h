// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettingsBackedByCVars.h"
#include "MoverDeveloperSettings.generated.h"

/** Developer settings for the Mover plugin */
UCLASS(Config=Engine, DefaultConfig, meta=(DisplayName="Mover Settings"))
class MOVER_API UMoverDeveloperSettings : public UDeveloperSettingsBackedByCVars
{
	GENERATED_BODY()

public:
	/**
     * This specifies the number of times a movement mode can refund all of the time in a substep before we back out to avoid freezing the game/editor
     */
	UPROPERTY(EditAnywhere, Config, Category="Mover")
	int32 MaxTimesToRefundSubstep;

};

