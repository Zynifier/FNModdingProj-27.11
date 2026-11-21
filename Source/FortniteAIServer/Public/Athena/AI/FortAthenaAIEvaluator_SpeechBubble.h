// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIEvaluator_NearbyActorsPerception.h"
#include "FortAthenaAIEvaluator_SpeechBubble.generated.h"

class UFortPawnComponent_SpeechBubble;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIEvaluator_SpeechBubble : public UFortAthenaAIEvaluator_NearbyActorsPerception
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPawnComponent_SpeechBubble> CachedSpeechBubbleComponent;

};

