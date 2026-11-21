// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionTypes.h"
#include "AI/AIComponent.h"
#include "AIPerceptionComponentBase.generated.h"

class AActor;

UCLASS(ClassGroup=("Fortnite"))
class VERSEAIBASE_API UAIPerceptionComponentBase : public UAIComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void NotifyTargetPerceptionForgotten(AActor* Actor);

	UFUNCTION()
	void NotifyTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

};

