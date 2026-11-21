// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/MyIsland/FortCreativeMyIslandContentPanelInterface.h"
#include "FortMatchmakingKnobsModal.h"
#include "FortCreativeMyIslandContentKnobsPanel.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeMyIslandContentKnobsPanel : public UFortMatchmakingKnobsModal, public IFortCreativeMyIslandContentPanelInterface
{
	GENERATED_BODY()

};

