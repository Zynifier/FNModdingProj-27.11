// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/HoverDronePawn.h"
#include "AutoFrameDronePawn.generated.h"

class AActor;

UENUM()
enum class EAutoFrameMode : uint8
{
	Off = 0,
	ManualOverride = 1,
	AutoFrame = 2,
};

UCLASS(HideCategories=("Navigation"))
class AAutoFrameDronePawn : public AHoverDronePawn
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<AActor>> ActorsToTrack;

	UPROPERTY()
	TMap<TObjectPtr<AActor>, float> TrackedActorTimes;

};

