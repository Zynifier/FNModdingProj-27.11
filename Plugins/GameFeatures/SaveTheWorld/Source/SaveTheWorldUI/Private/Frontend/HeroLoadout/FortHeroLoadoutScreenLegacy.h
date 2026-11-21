// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortActivatablePanelWithItemPreview.h"
#include "FortHeroLoadoutScreenLegacy.generated.h"

class UFortCampaignHeroLoadoutItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHeroLoadoutScreenLegacy : public UFortActivatablePanelWithItemPreview
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsLoadoutSwitchingAllowed() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetHeroLoadout(const UFortCampaignHeroLoadoutItem* HeroLoadout);

protected:
	UFUNCTION(BlueprintPure)
	bool GetIsReadOnly() const;

};

