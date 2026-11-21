// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_OutsideSafeZone.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(DisplayName="GCNL OutsideSafeZone", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_OutsideSafeZone : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="GCNL OutsideSafeZone")
	void OnStormEffectsEnabled(bool bEnabled);

};

