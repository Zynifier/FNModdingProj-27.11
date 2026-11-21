// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Internal/OnlineDiscoveryServiceMcpTypes.h"
#include "FortCreativeDiscoverySurfaceManager.generated.h"

class UFortCreativeDiscoverySurface;

UCLASS(Config=Game)
class UFortCreativeDiscoverySurfaceManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortCreativeDiscoverySurface>> Surfaces;

	UPROPERTY(Config)
	float SurfaceRefreshRate;

	UPROPERTY(Config)
	TArray<FOnlineDiscoveryModeSetDef> ModeSetEntries;

	UPROPERTY(Config)
	bool bForceShowModeSetEntries;

	UPROPERTY(Config)
	TArray<FString> DevelopmentLinkCodes;

	UPROPERTY(Config)
	TArray<FOnlineDiscoverySurfaceDevelopmentLinkCodes> PerSurfaceDevelopmentLinkCodes;

	UPROPERTY(Config)
	TArray<FName> SurfacesToDirtyOnPartyChanges;

};

