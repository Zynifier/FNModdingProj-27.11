// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DAD_IslandQuerier.generated.h"

class UCreativeDynamicXpDataAsset;
class UDAD_FeaturedIslands;
class UDAD_PlaylistCuratedHub;
class UDAD_WellKnownIslands;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWellKnownIslandsUpdated);

UCLASS(Config=Game)
class UDAD_IslandQuerier : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FString GetIslandCodeByWellKnownName(const FString& WellKnownIslandName) const;

	UPROPERTY(BlueprintAssignable)
	FOnWellKnownIslandsUpdated OnWellKnownIslandsUpdated;

private:
	UPROPERTY(Transient)
	TObjectPtr<UDAD_WellKnownIslands> WellKnownIslands;

	UPROPERTY(Transient)
	TObjectPtr<UDAD_FeaturedIslands> FeaturedIslands;

	UPROPERTY(Transient)
	TObjectPtr<UDAD_PlaylistCuratedHub> PlaylistCuratedHub;

	UPROPERTY(Transient)
	TObjectPtr<UCreativeDynamicXpDataAsset> CreativeDynamicXp;

	UPROPERTY(Config)
	bool bResolveMetrics;

	UPROPERTY(Config)
	float UpdateMetricsInterval;

	UPROPERTY(Config)
	bool bShouldUseDiscoveryService;

};

