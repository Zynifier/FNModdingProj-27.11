// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCreativeCaptureScreenshotHUD.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeCaptureScreenshotHUD : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void AcceptPreview();

	UFUNCTION(BlueprintCallable)
	bool BeginPreview();

	UFUNCTION(BlueprintCallable)
	void CancelPreview();

	UFUNCTION(BlueprintCallable)
	void HandleButtonCancelClicked();

	UFUNCTION(BlueprintCallable)
	void HandleButtonConfirmClicked();

	UFUNCTION(BlueprintCallable)
	void HandleButtonResetClicked();

	UFUNCTION(BlueprintCallable)
	void ResetPreview();

};

