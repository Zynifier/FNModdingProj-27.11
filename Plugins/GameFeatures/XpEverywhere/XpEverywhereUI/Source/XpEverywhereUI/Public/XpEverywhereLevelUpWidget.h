// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "XpEverywhereLevelUpWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UXpEverywhereLevelUpWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void DisplayLevelUpRewards() const;

	UFUNCTION(BlueprintCallable)
	void DoneLevelingUp();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowWidget(const int32 NewLevel);

};

