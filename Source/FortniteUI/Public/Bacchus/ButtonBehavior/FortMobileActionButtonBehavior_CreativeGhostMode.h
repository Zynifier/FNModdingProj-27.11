// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativeGhostMode.generated.h"

class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_CreativeGhostMode : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCreativeGhostModeEnabledChanged(bool bEnabled);

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeGhostMode")
	TObjectPtr<UPaperSprite> GhostModeOffSprite;

};

