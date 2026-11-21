// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SquadManagement/FortSquadTypeLandingPageBase.h"
#include "FortDefenderSquadSelectorButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortDefenderSquadSelectorButton : public UFortSquadSelectorButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="SurivivorSquadData")
	bool TryGetPowerLevel(int32& OutPowerLevel);

	UFUNCTION(BlueprintPure, Category="SurivivorSquadData")
	bool TryGetTheaterUniqueId(FString& OutTheaterUniqueId, bool& OutIsUnlocked) const;

};

