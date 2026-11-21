// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DiscoveryShared/FortActivityView.h"
#include "FortActivityBrowserView.generated.h"

enum class EFortInvalidActivityReason : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityBrowserView : public UFortActivityView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortInvalidActivityReason GetInvalidActivityReason() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSurfaceDataDirty();

private:
	UPROPERTY(EditAnywhere, Category="FortActivityBrowserView")
	bool bShowCustomMatchmakingModalButton;

	UPROPERTY(EditAnywhere, Category="FortActivityBrowserView")
	bool bShowSpectateMatchModalButton;

	UPROPERTY(EditAnywhere, Category="FortActivityBrowserView")
	bool bShowMobileGameDetailsButton;

	UPROPERTY(EditAnywhere, Category="FortActivityBrowserView")
	bool bShowMobileAcceptButton;

	UPROPERTY(EditAnywhere, Category="FortActivityBrowserView")
	bool bShowBackToTopButton;

	UPROPERTY(EditAnywhere, Category="FortActivityBrowserView")
	FName DiscoverySurfaceName;

};

