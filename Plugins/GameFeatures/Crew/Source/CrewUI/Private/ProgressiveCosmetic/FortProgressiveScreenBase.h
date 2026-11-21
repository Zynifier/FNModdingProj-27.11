// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CrewScreenContentBlockingInterface.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "ProgressiveCosmetic/FortProgressiveContentInterface.h"
#include "FortProgressiveScreenBase.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressiveScreenBase : public UFortItemPreviewScreen, public IFortProgressiveContentInterface, public ICrewScreenContentBlockingInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Container Tab Visibility Updated"))
	void BP_OnContainerTabVisibilityUpdated(const bool bTabsVisible, const float SpacingAdjustmentForTabs);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortProgressiveScreenBase")
	float RewardPreviewTime;

};

