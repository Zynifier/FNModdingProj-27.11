// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MusicalTimebase.generated.h"

UENUM(BlueprintType)
enum class ECalibratedMusicTimebase : uint8
{
	/*
	 * Tells you almost exactly where the audio renderer is right now (smoothed version of the jittery, 
	 * raw position of the audio rendering). Useful for queuing up musical events based on the current
	 * song time.
	 */
	AudioRenderTime = 0,
	/*
	 * Tells you what the player is actually hearing & seeing this instant (when properly calibrated). 
	 * Useful for scoring player input.
	 */
	ExperiencedTime = 1,
	/*
	 * Tells you what you should be drawing right now so it appears *in sync with the music.* (when properly calibrated).
	 * Useful for synchronizing animations, ui, and other visuals to the music.
	 */
	VideoRenderTime = 2,
};

