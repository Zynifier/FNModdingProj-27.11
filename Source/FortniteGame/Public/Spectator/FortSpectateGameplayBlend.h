// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Spectator/FortSpectateBlend.h"
#include "FortSpectateGameplayBlend.generated.h"

class AFortPlayerCameraSpectator;

UENUM()
enum class ESpectateBlendEasing : uint8
{
	Linear = 0,
	EaseOutQuad = 1,
};

UCLASS()
class UFortSpectateGameplayBlend : public UFortSpectateBlend
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<AFortPlayerCameraSpectator> CameraManager;

};

