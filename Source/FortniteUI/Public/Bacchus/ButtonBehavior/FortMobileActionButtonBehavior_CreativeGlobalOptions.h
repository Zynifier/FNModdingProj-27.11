// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativeGlobalOptions.generated.h"

UCLASS()
class UFortMobileActionButtonBehavior_CreativeGlobalOptions : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCreativeQuickMenuDisplayedChanged(bool bIsDisplayed);

	UPROPERTY(Transient)
	bool bCreativeQuickMenuDisplayed;

};

