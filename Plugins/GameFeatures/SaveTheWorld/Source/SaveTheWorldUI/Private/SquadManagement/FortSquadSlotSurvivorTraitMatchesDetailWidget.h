// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SquadManagement/FortSquadSlotItemDetailsHostPanel.h"
#include "FortSquadSlotSurvivorTraitMatchesDetailWidget.generated.h"

UCLASS()
class UFortSquadSlotSurvivorTraitMatchesDetailWidget : public UFortSquadSlotItemDetailElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleTraitValuesUpdatedBP();

	UPROPERTY(BlueprintReadOnly, Category="FortSquadSlotSurvivorTraitMatchesDetailWidget")
	bool IsSquadLeaderSlot;

	UPROPERTY(BlueprintReadOnly, Category="FortSquadSlotSurvivorTraitMatchesDetailWidget")
	bool LeaderMatchesSquadType;

	UPROPERTY(BlueprintReadOnly, Category="FortSquadSlotSurvivorTraitMatchesDetailWidget")
	int32 SubordinatePersonalityMatchCount;

	UPROPERTY(BlueprintReadOnly, Category="FortSquadSlotSurvivorTraitMatchesDetailWidget")
	bool MatchesLeaderPersonality;

	UPROPERTY(BlueprintReadOnly, Category="FortSquadSlotSurvivorTraitMatchesDetailWidget")
	int32 MatchingSetBonusCount;

	UPROPERTY(BlueprintReadOnly, Category="FortSquadSlotSurvivorTraitMatchesDetailWidget")
	int32 SetBonusSize;

};

