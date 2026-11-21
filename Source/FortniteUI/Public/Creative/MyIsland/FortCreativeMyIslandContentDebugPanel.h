// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/MyIsland/FortCreativeMyIslandContentPanelInterface.h"
#include "FortMatchmakingKnobsModal.h"
#include "FortCreativeMyIslandContentDebugPanel.generated.h"

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeMyIslandContentDebugPanel : public UFortMatchmakingKnobsModal, public IFortCreativeMyIslandContentPanelInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FString> OwnerPermissionAllowList;

};

