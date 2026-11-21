// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortMatchStatsScreen.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMatchStatsScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void EventUpdateStats();

};

