// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortAthenaSurvivorTiersQuestRewardsPanel.generated.h"

UCLASS()
class UFortAthenaSurvivorTiersQuestRewardsPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaSurvivorTiersQuestRewardsPanel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="SurvivorTierBadge", meta=(DisplayName="OnSurvivorTierStateChanged"))
	void BP_OnSurvivorTierStateChanged(int32 PrestigeLevel, int32 TierRaw, int32 TierDisplay);

	UFUNCTION()
	void OnSurvivorTierStateChanged(const int32 Prestige, int32 TierRaw, int32 TierDisplay);

};

