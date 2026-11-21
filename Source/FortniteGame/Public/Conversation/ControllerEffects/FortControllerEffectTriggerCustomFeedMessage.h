// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Conversation/ControllerEffects/FortControllerEffect.h"
#include "FortControllerEffectTriggerCustomFeedMessage.generated.h"

UCLASS(meta=(DisplayName="Effect: Trigger Custom Feed Message"))
class UFortControllerEffect_TriggerCustomFeedMessage : public UFortControllerEffect
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortControllerEffect_TriggerCustomFeedMessage", meta=(Categories="CustomFeedMessage"))
	FGameplayTag CustomFeedMessageTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortControllerEffect_TriggerCustomFeedMessage", meta=(Categories="CustomFeedMessage"))
	FVector AdditionalLocalSpaceContextOriginOffset;

};

