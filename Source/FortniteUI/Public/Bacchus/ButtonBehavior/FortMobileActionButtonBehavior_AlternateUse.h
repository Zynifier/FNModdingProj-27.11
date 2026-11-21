// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_AlternateUse.generated.h"

class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_AlternateUse : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> DBNOHoistSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> DBNOPlaceSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> HeldObjectPlaceSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> CraftSprite;

};

