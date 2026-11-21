// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Items/FortPersistableItemDefinition.h"
#include "FortMedalsPunchCardItemDefinition.generated.h"

UCLASS(BlueprintType, HideCategories=("AccountItem", "Sacrifice", "Conversion", "Level", "FortItemDefinition", "InventoryLimit", "Rating", "Functionality", "Frontend"))
class UFortMedalsPunchCardItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMedalsPunchCardItemDefinition")
	int32 NumPunches;

	UPROPERTY(EditDefaultsOnly, Category="FortMedalsPunchCardItemDefinition")
	bool bAllowMedalReplacement;

	UPROPERTY(EditDefaultsOnly, Category="FortMedalsPunchCardItemDefinition")
	FScalableFloat PunchCardXpRewards;

	UPROPERTY(EditDefaultsOnly, Category="FortMedalsPunchCardItemDefinition")
	FScalableFloat PunchCardRestXp;

};

