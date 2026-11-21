// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Conversation/ControllerEffects/FortControllerEffect.h"
#include "FortControllerEffectGiveResource.generated.h"

class UFortResourceItemDefinition;

UCLASS(meta=(DisplayName="Effect: Give Resource"))
class UFortControllerEffect_GiveResource : public UFortControllerEffect
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	TObjectPtr<UFortResourceItemDefinition> ResourceItemDefinition;

	UPROPERTY(EditAnywhere, Category="Filtering")
	FScalableFloat Quantity;

};

