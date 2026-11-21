// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureStateChangeObserver.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "FortDynamicUIPlayerProxy.generated.h"

UCLASS(MinimalAPI)
class UFortDynamicUIPlayerProxy : public ULocalPlayerSubsystem, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

