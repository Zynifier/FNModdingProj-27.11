// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/ControllerEffects/FortControllerEffect.h"
#include "FortControllerEffectNPCGiveGift.generated.h"

UCLASS(meta=(DisplayName="Effect: NPC Give Gift"))
class UFortControllerEffect_NPCGiveGift : public UFortControllerEffect
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bShowUINotifications;

};

