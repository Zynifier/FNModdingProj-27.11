// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "FortTypes.h"
#include "RumbleLeaderWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class URumbleLeaderWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnLeaderboardUpdate(const TArray<FFortInGameLeaderboardPlacementData>& Data);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDisplay(const FFortInGameLeaderboardPlacementData& LeaderEntry, bool bIsTiedForLead);

};

