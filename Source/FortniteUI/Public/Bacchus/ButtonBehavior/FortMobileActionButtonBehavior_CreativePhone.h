// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativePhone.generated.h"

UCLASS()
class UFortMobileActionButtonBehavior_CreativePhone : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCreativeModeEnabledChanged(bool bEnabled);

	UFUNCTION()
	void HandleCreativeQuickbarEnabledChanged(bool bEnabled);

};

