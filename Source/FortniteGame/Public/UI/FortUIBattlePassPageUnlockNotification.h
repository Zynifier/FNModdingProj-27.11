// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortUINotification.h"
#include "FortUIBattlePassPageUnlockNotification.generated.h"

UCLASS(Abstract, MinimalAPI)
class UFortUIBattlePassPageUnlockNotification : public UFortUINotification
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortUIBattlePassPageUnlockNotification")
	FText BattlePassPageUnlockToastTitle;

	UPROPERTY(EditDefaultsOnly, Category="FortUIBattlePassPageUnlockNotification")
	FText BattlePassPageUnlockToastDescription;

};

