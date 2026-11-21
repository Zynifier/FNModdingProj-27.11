// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "SpatialFactionPerkReward.generated.h"

class UFortPlayerPerksItemDefinition;
class UTexture2D;

UCLASS(Abstract, BlueprintType, Blueprintable)
class USpatialFactionPerkReward : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpatialFactionPerkReward")
	bool bIsTopRow;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFactionSet(bool bIsCurrentFaction);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializePerkReward(int32 FactionNumber, int32 PerkLevel, const TSoftObjectPtr<UTexture2D>& RewardTexture, bool bIsRevealed, bool bIsEarned, bool bIsCurrentFaction, bool bShowBang);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpatialFactionPerkReward")
	TObjectPtr<UFortPlayerPerksItemDefinition> Faction1PerksItemDef;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpatialFactionPerkReward")
	TObjectPtr<UFortPlayerPerksItemDefinition> Faction2PerksItemDef;

};

