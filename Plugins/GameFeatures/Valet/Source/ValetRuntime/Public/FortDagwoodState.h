// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "FortDagwoodState.generated.h"

UENUM()
enum class EFortDagwoodSimEvent : uint8
{
	EnterLandscape = 0,
	ExitLandscape = 1,
	EnterRoad = 2,
	ExitRoad = 3,
	Explode = 4,
	FlipImpact = 5,
	StartBoost = 6,
	FinishBoost = 7,
};

USTRUCT()
struct FFortDagwoodCmd
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ForwardAlpha;

	UPROPERTY()
	float RightAlpha;

	UPROPERTY()
	float AccelerationAlpha;

	UPROPERTY()
	FVector_NetQuantize100 MovementDir;

	UPROPERTY()
	uint8 bBoost : 1;

	UPROPERTY()
	uint8 bHandbrake : 1;

};

