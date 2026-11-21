// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_OctopusToggleGrapple.generated.h"

class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_OctopusToggleGrapple : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleTowhookAttached();

	UFUNCTION()
	void HandleTowhookDetached();

	UFUNCTION()
	void HandleTowhookHolstered();

	UFUNCTION()
	void HandleTowhookShot();

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_OctopusToggleGrapple")
	TObjectPtr<UPaperSprite> GrappleStopSprite;

};

