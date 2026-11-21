// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAthenaTrackableAIObjectComponent.h"
#include "FortAthenaTrackableAIObjectVehicleComponent.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaTrackableAIObjectVehicleComponent : public UFortAthenaTrackableAIObjectComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleSleepStateChanged(const bool bIsAwake);

};

