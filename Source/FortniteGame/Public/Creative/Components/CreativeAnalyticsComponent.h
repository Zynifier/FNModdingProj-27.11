// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortLevelSaveComponent.h"
#include "CreativeAnalyticsComponent.generated.h"

UCLASS()
class UCreativeAnalyticsComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FCachedLinkAnalyticsData CreativeCachedAnalyticsData;

	UPROPERTY(Transient)
	FCachedLinkAnalyticsData UpdatedCreativeCachedAnalyticsData;

	UPROPERTY(Transient)
	bool bIsCreativeIslandCurated;

};

