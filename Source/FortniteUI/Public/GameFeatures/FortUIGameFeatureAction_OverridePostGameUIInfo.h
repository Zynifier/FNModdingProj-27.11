// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_OverridePostGameUIInfo.generated.h"

class UFortPlaylistUIInfo;

UCLASS(MinimalAPI, meta=(DisplayName="Override PostGame UI Info"))
class UFortUIGameFeatureAction_OverridePostGameUIInfo : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSoftObjectPtr<UFortPlaylistUIInfo> PostGameUIData;

};

