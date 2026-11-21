// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_OverridePickupClass.generated.h"

class AFortPickup;

UCLASS(meta=(DisplayName="Override Pickup Class"))
class UFortGameFeatureAction_OverridePickupClass : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_OverridePickupClass")
	TSoftClassPtr<AFortPickup> PickupClassPtr;

};

