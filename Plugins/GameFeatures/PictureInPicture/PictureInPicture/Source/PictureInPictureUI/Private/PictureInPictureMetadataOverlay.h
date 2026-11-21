// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "PictureInPictureMetadataOverlay.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UPictureInPictureMetadataOverlay : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleOnPIPVideoResumed();

	UFUNCTION()
	void HandleOnPIPVideoStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMediaStarted();

};

