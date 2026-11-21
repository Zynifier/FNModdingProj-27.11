// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_Focus.generated.h"

class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_Focus : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCanUseEventModeFocusChanged(bool bCanUseEventModeFocus);

	UFUNCTION()
	void HandleEventModeFocusingChanged(bool bIsEventModeFocusing);

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_Focus")
	TObjectPtr<UPaperSprite> StopFocusingSprite;

};

