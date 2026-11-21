// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "PictureInPictureBladeMenuButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UPictureInPictureBladeMenuButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandlePiPEnabled(const bool Enabled);

	UFUNCTION()
	void HandlePiPLoginSuccess();

	UFUNCTION()
	void HandlePiPLogoutSuccess();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePiPStatusBP(const bool LoggedIn, const bool Enabled, const bool ParentalControlsEnabled);

private:
	UFUNCTION()
	void OnPartnerListUpdated();

};

