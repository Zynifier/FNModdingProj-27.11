// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativePropLockInPlace.generated.h"

class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_CreativePropLockInPlace : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePropLockedInPlaceChanged(bool bPropLockedInPlace);

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativePropLockInPlace")
	TObjectPtr<UPaperSprite> LockedSprite;

};

