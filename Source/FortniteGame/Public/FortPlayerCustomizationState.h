// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerCustomizationState.generated.h"

UENUM()
enum class EFortPlayerPartState : uint8
{
	NeverInitalized = 0,
	AssetsPreloading = 1,
	QueuedForInitialization = 2,
	CurrentlyInitializing = 3,
	InitializationComplete = 4,
	InitializationComplete_EmptyPart = 5,
	InitializationComplete_Cancelled = 6,
	InitializationFailed_NoParts = 7,
	NumTypes = 8,
};

UENUM()
enum class EFortPlayerWorkOverFramesMode : uint8
{
	NotProcessing = 0,
	PreInitializeComponents = 1,
	DefaultPartsWhileWaiting = 2,
	UpdateCharacterCustomization = 3,
	NumTypes = 4,
};

UENUM()
enum class EFortPlayerWorkOverFramesStage : uint8
{
	NotProcessing = 0,
	PreloadingParts = 1,
	QueuePostLoad = 2,
	PostLoad = 3,
	InitializeCharacterParts = 4,
	FinishUpdatingParts = 5,
	FinishedCustomization = 6,
	NumTypes = 7,
};

UENUM()
enum class EPartsShowingMode : uint8
{
	// This has never been initialized so nothing to show

	NeverInitalized = 0,
	// Used when delay has elapsed (or if delay is 0) and we show default parts while loading desired parts

	ShowingTemporaryDefaultParts = 1,
	// Used when delay has elapsed (or if delay is 0) and we have a preloaded fallback that matches this pawn's FallbackTag, then we show the fallback parts while loading desired parts

	ShowingTemporaryFallbackParts = 2,
	// Used when there are no slots in the cosmetic budget and the default parts gets loaded

	ShowingDefaultParts = 3,
	// Used when there is no space for desired parts and fallback parts are already loaded and available; alternatively when fallback parts are enforced

	ShowingFallbackParts = 4,
	ShowingDesiredParts = 5,
};

