// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "PictureInPictureLoadingScreenOverlayAction.generated.h"

class USubtitleDisplayNative;

UCLASS(MinimalAPI, meta=(DisplayName="Add Loading Screen Overlay"))
class UPictureInPictureLoadingScreenOverlayAction : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<USubtitleDisplayNative> SubtitleDisplay;

};

