// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLevelLightSwitchInterface.generated.h"

UINTERFACE(BlueprintType)
class UFortLevelLightSwitchInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortLevelLightSwitchInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void DisableLevelSetLighting();

	UFUNCTION(BlueprintImplementableEvent)
	void EnableLevelSetLighting();

};

