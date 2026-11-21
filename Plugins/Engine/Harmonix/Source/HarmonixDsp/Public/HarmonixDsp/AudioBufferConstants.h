// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioBufferConstants.generated.h"

UENUM()
enum class ESpeakerChannelAssignment : uint8
{
	LeftFront = 0,
	RightFront = 1,
	Center = 2,
	LFE = 3,
	LeftSurround = 4,
	RightSurround = 5,
	LeftRear = 6,
	RightRear = 7,
	FrontPair = 8,
	CenterAndLFE = 9,
	SurroundPair = 10,
	RearPair = 11,
	AmbisonicW = 12,
	AmbisonicX = 13,
	AmbisonicY = 14,
	AmbisonicZ = 15,
	AmbisonicWXPair = 16,
	AmbisonicYZPair = 17,
	UnspecifiedMono = 18,
	Num = 19 UMETA(Hidden),
	Invalid = 20 UMETA(Hidden),
};

