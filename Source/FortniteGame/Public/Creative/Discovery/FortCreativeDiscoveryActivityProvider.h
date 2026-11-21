// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Discovery/FortCreativeIslandHistoryProvider.h"
#include "FortCreativeDiscoveryActivityProvider.generated.h"

class UFortCreativeDiscoverySurface;
class UFortCreativeDiscoverySurfaceManager;

UCLASS(MinimalAPI, BlueprintType)
class UFortCreativeDiscoveryActivityProvider : public UFortCreativeIslandHistoryProvider
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortCreativeDiscoverySurfaceManager> Manager;

	UPROPERTY()
	TObjectPtr<UFortCreativeDiscoverySurface> Surface;

};

