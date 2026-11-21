// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortOptionsSettingsType.generated.h"

UENUM(BlueprintType)
enum class ESettingType : uint8
{
	None = 0,
	Header = 1,
	/* Video Tab Settings */
	WindowMode = 2,
	DisplayResolution = 3,
	FrameRateLimit = 4,
	VideoQuality = 5,
	// @Owner Bob.Tellez, BaseScalability.ini -> DefaultScalability.ini -> (Platform)Scalability.ini

	ThreeDResolution = 6,
	// Subsetting of VideoQuality

	ViewDistance = 7,
	// Subsetting of VideoQuality

	Shadows = 8,
	// Subsetting of VideoQuality

	AntiAliasing = 9,
	// Subsetting of VideoQuality

	Textures = 10,
	// Subsetting of VideoQuality

	Effects = 11,
	// Subsetting of VideoQuality

	PostProcessing = 12,
	// Subsetting of VideoQuality

	VSync = 13,
	MotionBlur = 14,
	ShowGrass = 15,
	MobileFPSType = 16,
	// @Owner Mic.Rooney

	ShowFPS = 17,
	// @Owner Carlos.Cuello

	AllowLowPower = 18,
	// @Owner Mic.Rooney

	AllowVideoPlayback = 19,
	// @Owner Chris.Bunner

	AllowDynamicResolution = 20,
	// @Owner Philip.Buuck

	Disabled_AllowMultithreadedRendering = 21 UMETA(Hidden),
	// @Owner Nicolas.Mercier; Setting is not used anymore,
// but keep the slot in the enum to preserve the indices.

	RenderingAPI = 22,
	// @Owner Emil.Persson

	UseGPUCrashDebugging = 23,
	/* Game Tab Settings */
	RegionHeader = 24,
	Language = 25,
	Region = 26,
	// @Owner Josh.Markiewicz

	MouseSensitivityYaw = 27,
	// @Owner Mike.Fricker, Mic.Rooney

	MouseSensitivityPitch = 28,
	// @Owner Mike.Fricker, Mic.Rooney

	MouseSensitivityMultiplierForAircraft = 29,
	// @Owner Steven.Barnett

	TouchDragSensitivity = 30,
	// @Owner Mic.Rooney

	ControllerLookSensitivityYaw = 31,
	// @Owner Aaron.Eady

	ControllerLookSensitivityPitch = 32,
	// @Owner Aaron.Eady

	MouseTargetingMultiplier = 33,
	// @Owner Peter.Knepley

	MouseScopedMultiplier = 34,
	// @Owner Peter.Knepley

	GamepadTargetingMultiplier = 35,
	// @Owner Peter.Knepley

	GamepadScopedMultiplier = 36,
	// @Owner Peter.Knepley

	GamepadBuildingMultiplier = 37,
	// @Owner Peter.Knepley

	GamepadEditModeMultiplier = 38,
	// @Owner Todd.Eckert

	TouchLookAccelerationMultiplier = 39,
	// @Owner Mic.Rooney

	TouchDragTargetingSensitivity = 40,
	// @Owner Mic.Rooney

	TouchDragScopedSensitivity = 41,
	// @Owner Mic.Rooney

	TouchBuildingMultiplier = 42,
	// @Owner Mic.Rooney

	TouchEditModeMultiplier = 43,
	// @Owner Mic.Rooney

	TouchVerticalSensitivity = 44,
	// @Owner Mic.Rooney

	InvertPitch = 45,
	// @Owner Aaron.Eady

	InvertYaw = 46,
	// @Owner Aaron.Eady

	InvertPitchForMotion = 47,
	// @Owner Aaron.Eady

	InvertPitchForAircraftPrimary = 48,
	// @Owner Steven.Barnett

	InvertPitchForAircraftSecondary = 49,
	// @Owner Steven.Barnett

	InvertYawForMotion = 50,
	// @Owner Aaron.Eady

	GyroEnabled = 51,
	// @Owner Mic.Rooney

	GyroYawAxis = 52,
	// @Owner Mic.Rooney

	GyroSensitivity = 53,
	// @Owner Mic.Rooney

	GyroTargetingSensitivity = 54,
	// @Owner Mic.Rooney

	GyroScopedSensitivity = 55,
	// @Owner Mic.Rooney

	GyroHarvestingToolSensitivity = 56,
	// @Owner Aaron.Eady

	SafeZone = 57,
	// @Owner Philip.Buuck

	AnonymousMode = 58,
	// @Owner Don.Eubanks

	AnonymousCharacterMode = 59,
	// @Owner Jon.Lietz

	HideOtherPlayerNames = 60,
	// @Owner Don.Eubanks

	HiddenMatchmakingDelay = 61,
	// @Owner Matt.Stone

	AutoJoinGameVoiceChannel = 62,
	//@Owner Matt.Stone

	ShowVoiceIndicators = 63,
	//@Owner Matt.Stone

	HUDScale = 64,
	// @Owner Nick.Darnell

	ShowViewerCount = 65,
	// @Owner Stanley.Hayes

	FirstPersonCamera = 66,
	//

	PeripheralLighting = 67,
	//
// @Owner Peter.Knepley

	PingPlaceDangerMarkerWhenTargeting = 68,
	// @Owner Nick.Darnell

	ShowGlobalChat = 69,
	// @Owner Bryan.Wagstaff

	ConsoleUnlockedFPS = 70,
	// @Owner Carlos.Cuello

	ToggleDoubleTapAutorun = 71,
	//@Owner Mathieu.Chamberland

	AutorunLockZonePreference = 72,
	//@Owner Mathieu.Chamberland

	ToggleSprint = 73,
	//

	SprintByDefault = 74,
	//
// OBSOLETE!  @Owner Nick.Cooper

	SprintCancelsReload = 75,
	// @Owner Nick.Cooper

	TapInteract = 76,
	// @Owner Nick.Cooper

	InWorldInteract = 77,
	// @Owner Mic.Rooney

	ToggleTargeting = 78,
	// @Owner Nick.Cooper

	HoldToSwapPickup = 79,
	// @Owner Peter.Knepley

	AutoEquipBetterItems = 80,
	//

	EquipFirstBuildingPieceWhenSwappingQuickbars = 81,
	//
// @Owner John.Abercrombie, Peter.Knepley

	EquipFirstBuildingPieceWhenSwappingQuickbarsAthena = 82,
	// @Owner Peter.Knepley

	DisablePreEditsWhenPlacingBuilding = 83,
	// @Owner Boson.Huang

	AimAssist = 84,
	EditModeAimAssist = 85,
	// @Owner Mike.Fricker

	TouchEdit = 86,
	// @Owner Mic.Rooney

	EditConfirmOnRelease = 87,
	// @Owner Mic.Rooney

	QuickEdit = 88,
	// @Owner Peter.Knepley

	TurboBuild = 89,
	// @Owner Aaron.Eady

	CreativeTurboDelete = 90,
	// @Owner Aidan.McInerny

	AutoChangeMaterial = 91,
	// @Owner Aaron.Eady (Deleted, always true now)

	GamepadAutoRun = 92,
	// @Owner Peter.Knepley

	CrossplayPreference = 93,
	// @Owner Don.Eubanks

	AutoOpenDoors = 94,
	// @Owner Mic.Rooney

	AutoPickupWeapons = 95,
	// @Owner Mic.Rooney

	AutoPickupWeaponsConsolePC = 96,
	// @Owner Nick.Cooper, Mic.Rooney

	AutoSortConsumablesToRight = 97,
	// @Owner Nick.Cooper

	EnableTryBuildOnFocus = 98,
	// @Owner Aaron.Eady

	EditButtonHoldTime = 99,
	// @Owner Aaron.Eady

	SlideButtonHoldTime = 100,
	// @Owner Brian.Zaugg

	AccessoriesHeader = 101,
	// @Owner Eric.Feldman

	ForceFeedback = 102,
	// @Owner Philip.Buuck

	ContextTutorial = 103,
	// @Owner Mathieu.Roy

	ReplayRecording = 104,
	// @Owner Jeff.Farris

	ReplayRecordingLargeTeams = 105,
	// @Owner Jeff.Farris

	ReplayRecordingCreativeMode = 106,
	// @Owner Jon.Nabozny

	UsePowerSavingMode = 107,
	// @Owner Mic.Rooney

	ShadowPlayHighlights = 108,
	// @Owner Peter.Knepley

	ShowTemperature = 109,
	//@Owner Nicolas.Bongi

	BuildingPossession = 110,
	/* Brightness Tab Settings */
	GammaValue = 111,
	/* Audio Tab Settings */
	MasterVolume = 112,
	// @Owner Jeffrey.Bauer

	MusicVolume = 113,
	SoundFXVolume = 114,
	DialogVolume = 115,
	VoiceChatVolume = 116,
	CinematicsVolume = 117,
	// @Owner Jesse.Ziglar

	Subtitles = 118,
	// @Owner Daniel.Broder

	Quality = 119,
	// @Owner Bob.Tellez

	VoiceChat = 120,
	// @Owner Peter.Knepley (Athena), Alex.Thurman (STW)

	PushToTalk = 121,
	// @Owner Peter.Knepley

	ProximityVoiceChat = 122,
	// @Owner Peter.Knepley

	VoiceChatInputDevice = 123,
	// @Owner Peter.Knepley

	VoiceChatOutputDevice = 124,
	// @Owner Peter.Knepley

	AllowBackgroundAudio = 125,
	/* Accessibility Tab Settings */
	ColorBlindMode = 126,
	// @Owner Nick.Darnell

	ColorBlindStrength = 127,
	// @Owner Nick.Darnell

	IgnoreGamepadInput = 128,
	// @Owner Nick.Darnell

	LockPrimaryInputMethodToMouse = 129,
	// @Owner Nick.Darnell

	EnableRudderControl = 130,
	// @Owner Peter.Knepley

	RudderDeadZone = 131,
	// @Owner Peter.Knepley

	RudderMaxThrottle = 132,
	// @Owner Peter.Knepley

	VisualizeSoundEffects = 133,
	// @Owner Nick.Darnell

	VisualizeSoundEffectsHeader = 134,
	/* Gamepad Config Tab Settings */
	MoveStickDeadZone = 135,
	// @Owner Aaron.Eady

	LookStickDeadZone = 136,
	// @Owner Aaron.Eady

	LookSensitivityPreset = 137,
	LookSensitivityPresetAds = 138,
	LookBuildModeMultiplier = 139,
	LookEditModeMultiplier = 140,
	UseAdvancedOptions = 141,
	LookHorizontalSpeed = 142,
	LookVerticalSpeed = 143,
	LookHorizontalSpeedAds = 144,
	LookVerticalSpeedAds = 145,
	LookHorizontalBoostSpeed = 146,
	LookVerticalBoostSpeed = 147,
	LookBoostAccelerationTime = 148,
	LookHorizontalBoostSpeedAds = 149,
	LookVerticalBoostSpeedAds = 150,
	LookBoostAccelerationTimeAds = 151,
	InstantBoostWhenBuilding = 152,
	LookEaseTime = 153,
	LookInputCurve = 154,
	AimAssistStrength = 155,
	UseLegacyControls = 156,
	/* Account Tab Settings */
	PlayerSurveysAllowed = 157,
	// @Owner Greg.Beauchesne

	LocalNotifications = 158,
	// @Owner Nicolas Bongi

	FireMode = 159,
	// @Owner Michel.Champoux

	COUNT = 160 UMETA(Hidden),
};

