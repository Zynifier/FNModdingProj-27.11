// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeIslandSelectV2.h"
#include "FortCreativeIslandSelectDiscovery.generated.h"

class UFortCreativeDiscoverySurfaceManager;
class UFortCreativeIslandSelectTab;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandSelectDiscovery : public UFortCreativeIslandSelectV2
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortCreativeDiscoverySurfaceManager> Manager;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandSelectDiscovery")
	FName DiscoverySurfaceName;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandSelectDiscovery")
	TSubclassOf<UFortCreativeIslandSelectTab> SurfaceWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandSelectDiscovery")
	uint32 InsertDiscoveryTabsAtIndex;

};

