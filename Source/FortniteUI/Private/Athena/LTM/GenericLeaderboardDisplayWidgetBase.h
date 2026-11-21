// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "FortTypes.h"
#include "GenericLeaderboardDisplayWidgetBase.generated.h"

UCLASS()
class UGenericLeaderboardDisplayWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDisplay(const TArray<FFortInGameLeaderboardPlacementData>& Data);

};

