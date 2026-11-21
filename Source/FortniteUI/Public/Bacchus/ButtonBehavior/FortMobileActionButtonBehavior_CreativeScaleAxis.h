// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativeScaleAxis.generated.h"

class AFortWeapon;
class UPaperSprite;
enum class EScaleAxis : uint8;

UCLASS()
class UFortMobileActionButtonBehavior_CreativeScaleAxis : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleMoveToolScaleAxisChanged(EScaleAxis Axis);

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeScaleAxis")
	TObjectPtr<UPaperSprite> GrowSprite;

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeScaleAxis")
	TObjectPtr<UPaperSprite> WidthResizeSprite;

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeScaleAxis")
	TObjectPtr<UPaperSprite> HeightResizeSprite;

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeScaleAxis")
	TObjectPtr<UPaperSprite> DepthResizeSprite;

};

