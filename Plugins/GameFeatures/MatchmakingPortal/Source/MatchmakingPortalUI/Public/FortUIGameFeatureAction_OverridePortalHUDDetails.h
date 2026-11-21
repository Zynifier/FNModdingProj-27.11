// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_OverridePortalHUDDetails.generated.h"

class UUserWidget;

UCLASS(meta=(DisplayName="Override Portal HUD Details"))
class UFortUIGameFeatureAction_OverridePortalHUDDetails : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortUIGameFeatureAction_OverridePortalHUDDetails")
	TSoftClassPtr<UUserWidget> SoftPortalHUDDetailsClass;

};

