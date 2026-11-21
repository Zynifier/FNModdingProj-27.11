// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponentTypes.h"
#include "FortMobileActionButtonBehavior_Shoot.generated.h"

class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_Shoot : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnVehicleChanged();

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> PlaceItemSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> ThrowSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> PickaxeSprite;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	FGameplayTagContainer DefaultIconOverrideItems;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<FIconPicker> PawnSpriteOverrides;

};

