// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScalableFloat.h"
#include "FortMovingPlatformComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UFortMovingPlatformComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Moving Platform|Pickups")
	FScalableFloat MaximumPickupStationaryTime;

	UPROPERTY(EditDefaultsOnly, Category="Moving Platform|Pickups")
	FScalableFloat MaximumPickupAttachTime;

	UPROPERTY(EditDefaultsOnly, Category="Moving Platform|Pickups")
	FScalableFloat PickupRelevanceTime;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Moving Platform")
	FScalableFloat AttachActorIgnoreBaseRotation;

	UPROPERTY(EditDefaultsOnly, Category="Moving Platform|Pickups")
	FScalableFloat AttachPickupsToPlatform;

};

