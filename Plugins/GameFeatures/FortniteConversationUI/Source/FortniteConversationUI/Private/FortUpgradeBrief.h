// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTransactionBrief.h"
#include "FortUpgradeBrief.generated.h"

class UFortItem;
enum class EFortWeaponUpgradeInteractionResult : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortUpgradeBrief : public UFortItemTransactionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnUnableToUpgrade(EFortWeaponUpgradeInteractionResult CannotUpgradeCause);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnUpgradeInfoReceived(UFortItem* CurrentWeapon);

};

