// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortDiscoverSurfaceCache.generated.h"

class UFortCreativeDiscoveryActivityProvider;
class UFortGameActivityProvider;

USTRUCT()
struct FCachedSurfaceData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortCreativeDiscoveryActivityProvider>> CachedDataProviders;

	UPROPERTY(Transient)
	bool bIsDirty;

};

UCLASS()
class FORTNITEUI_API UFortDiscoverSurfaceCache : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FCachedSurfaceData> CachedSurfacesData;

	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivityProvider> CachedWinterfestActivityProvider;

};

