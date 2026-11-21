// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHarvesterToolTypes.generated.h"

UENUM()
enum class EAnimNotifyTracks : uint8
{
	GenericNotifies = 0,
	DualWield = 1,
	DecisionWindow = 2,
	AbilityTrigger = 3,
	AudioParameters = 4,
	ReloadFx = 5,
	MeleeTrails = 6,
	StopMeleeTrailsOnEnd = 7,
	PlaySwimmingSounds = 8,
	Count = 9,
};

UENUM()
enum class EHarvestSwingPhase : uint8
{
	Swing = 0,
	End = 1,
};

UENUM()
enum class ESwingSequence : uint8
{
	UpperBodySwing = 0,
	UpperBodyReturn = 1,
	CrouchUpperBodySwing = 2,
	CrouchUpperBodyReturn = 3,
	CrouchInPlaceAdditiveSwing = 4,
	CrouchInPlaceAdditiveReturn = 5,
	SwingSequenceCount = 6,
};

UENUM()
enum class ESwingType : uint8
{
	Swing1 = 0,
	Swing2 = 1,
	Swing3 = 2,
	Swing4 = 3,
	UniqueSwingCount = 4,
};

