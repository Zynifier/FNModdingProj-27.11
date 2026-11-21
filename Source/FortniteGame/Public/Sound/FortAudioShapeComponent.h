// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "AudioShapeComponent.h"
#include "FortAudioShapeComponent.generated.h"

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortAudioShapeComponent : public UAudioShapeComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FTimerHandle AudioShapeInitTimer;

};

