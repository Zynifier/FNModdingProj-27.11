// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeModalDialogOptionTypes.generated.h"

UENUM(BlueprintType)
enum class ECreativeModalBackActionBoundButtonOption : uint8
{
	None = 0,
	LastButton = 1,
	Button1 = 2,
	Button2 = 3,
	Button3 = 4,
	Button4 = 5,
	Button5 = 6,
	Button6 = 7,
};

UENUM(BlueprintType)
enum class ECreativeModalDialogAlignmentOption : uint8
{
	TopLeft = 0,
	TopCenter = 1,
	TopRight = 2,
	MiddleLeft = 3,
	Centered = 4,
	MiddleRight = 5,
	BottomLeft = 6,
	BottomCenter = 7,
	BottomRight = 8,
	CenteredFull = 9,
	LeftTall = 10,
	CenteredTall = 11,
	RightTall = 12,
	TopWide = 13,
	CenteredWide = 14,
	BottomWide = 15,
};

UENUM(BlueprintType)
enum class ECreativeModalDialogTimerOption : uint8
{
	None = 0,
	Countdown = 1,
};

