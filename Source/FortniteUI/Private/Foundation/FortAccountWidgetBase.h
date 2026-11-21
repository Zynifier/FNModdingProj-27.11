// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Athena/AthenaRewardSchedule.h"
#include "FortItemQuantityPair.h"
#include "Online/FortMcpContext.h"
#include "FortAccountWidgetBase.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAccountWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortAccountWidgetBase")
	FText GetCurrentChapterAsText() const;

	UFUNCTION(BlueprintPure, Category="FortAccountWidgetBase")
	FText GetCurrentSeasonNumberAsText() const;

	UFUNCTION(BlueprintPure, Category="FortAccountWidgetBase")
	bool GetNextSeasonChaseReward(FFortItemQuantityPair& Reward, int32& RewardLevel, int32 StartingLevel = -1) const;

	UFUNCTION(BlueprintPure, Category="FortAccountWidgetBase")
	bool GetNextSeasonReward(FFortItemQuantityPair& Reward, int32& RewardLevel) const;

	UFUNCTION(BlueprintPure, Category="FortAccountWidgetBase")
	FAthenaSeasonBannerLevel GetSeasonBannerInfo(int32 Level = 0) const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortAccountWidgetBase")
	void OnAccountInfoChanged(const FFortPublicAccountInfo& Result);

protected:
	UFUNCTION()
	virtual void HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo);

};

