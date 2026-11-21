// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerInputTypes.generated.h"

UENUM(BlueprintType)
enum class EAxisDirection : uint8
{
	Disabled = 0,
	Standard = 1,
	Inverted = 2,
};

UENUM(BlueprintType)
enum class ECameraResetAxes : uint8
{
	Pitch = 0,
	Yaw = 1,
	Both = 2,
};

UENUM(BlueprintType)
enum class ECombinedADSFireMode : uint8
{
	Disabled = 0,
	OnPressed = 1,
	WhileHeld = 2,
};

UENUM(BlueprintType)
enum class EEditAutoConfirmation : uint8
{
	None = 0,
	Edit = 1,
	Reset = 2,
	Both = 3,
};

UENUM(BlueprintType)
enum class EFortInputActionType : uint8
{
	Press = 0,
	Click = 1,
	Hold = 2,
	Release = 3,
};

UENUM(BlueprintType)
enum class EFortInputDevice : uint8
{
	Mouse = 0,
	Keyboard = 1,
	Gamepad = 2,
	Touch = 3,
};

UENUM(BlueprintType)
enum class EFortMotionYawAxis : uint8
{
	Yaw = 0,
	Roll = 1,
};

UENUM(BlueprintType)
enum class EGyroAcceleration : uint8
{
	Off = 0,
	Low = 1,
	Medium = 2,
	High = 3,
	Custom = 4,
	Legacy = 5,
};

UENUM(BlueprintType)
enum class EGyroActiveBuildMode : uint8
{
	None = 0,
	Edit = 1,
	All = 2,
};

UENUM(BlueprintType)
enum class EGyroActiveMode : uint8
{
	None = 0,
	ScopeOnly = 1,
	ScopeADS = 2,
	ScopeADSHarvesting = 3,
	ScopeADSHarvestingFiring = 4,
	All = 5,
};

UENUM(BlueprintType)
enum class EGyroButton : uint8
{
	Custom = 0,
	ReloadInteract = 1,
	TogglePickaxe = 2,
	CrouchSlide = 3,
	ResetCamera = 4,
	Touch = 5,
};

UENUM(BlueprintType)
enum class EGyroButtonResponse : uint8
{
	NoChange = 0,
	Disable = 1,
	Trackball = 2,
	Invert = 3,
	Enable = 4,
};

UENUM(BlueprintType)
enum class EGyroSpace : uint8
{
	Local = 0,
	Player = 1,
};

UENUM(BlueprintType)
enum class EGyroStickMode : uint8
{
	None = 0,
	Disables = 1,
	Enables = 2,
};

UENUM(BlueprintType)
enum class EGyroTouchMode : uint8
{
	None = 0,
	Disables = 1,
	Enables = 2,
};

UENUM(BlueprintType)
enum class EQuickWeaponToggle : uint8
{
	None = 0,
	Secondary = 1,
	PreviouslyEquipped = 2,
};

