// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemPicker/FortItemPicker.h"
#include "FortHeroLoadoutTeamPerkPicker.generated.h"

class UFortCampaignHeroLoadoutItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHeroLoadoutTeamPerkPicker : public UFortItemPickerBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetTargetLoadout(const UFortCampaignHeroLoadoutItem* LoadoutItem);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleDifferentTargetLoadoutSetBP();

	UPROPERTY(BlueprintReadOnly, Category="FortHeroLoadoutTeamPerkPicker")
	TWeakObjectPtr<UFortCampaignHeroLoadoutItem> TargetLoadoutItem;

};

