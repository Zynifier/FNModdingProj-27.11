// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SpatialFactionPerkProgress.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class USpatialFactionPerkProgress : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFactionSet(bool bIsCurrentFaction);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializePerkProgress(int32 FactionNumber, int32 PerkLevel, float PercentProgress, bool bIsRevealed, bool bIsCurrentFaction);

};

