// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedPlayerInput.h"
#include "InputCoreTypes.h"
#include "Math/MathFwd.h"
#include "Input/FortActionKeyMapping.h"
#include "Input/FortPlayerInputTypes.h"
#include "FortPlayerInput.generated.h"

class UFortPlayerInputSettings;

USTRUCT()
struct FFortAxisSmoothing
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ZeroTime;

	UPROPERTY()
	FVector AverageValue;

	UPROPERTY()
	int32 Samples;

	UPROPERTY()
	float TotalSampleTime;

};

USTRUCT()
struct FFortGyroV2Settings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float GyroV2Sensitivity;

	UPROPERTY()
	EGyroSpace GyroV2DetachedSpace;

	UPROPERTY()
	EGyroSpace GyroV2AttachedSpace;

	UPROPERTY()
	EAxisDirection GyroV2YawDirection;

	UPROPERTY()
	EAxisDirection GyroV2PitchDirection;

	UPROPERTY()
	EAxisDirection GyroV2RollDirection;

	UPROPERTY()
	EGyroActiveMode GyroV2ActiveMode;

	UPROPERTY()
	EGyroActiveBuildMode GyroV2ActiveBuildMode;

	UPROPERTY()
	EGyroStickMode GyroV2StickMode;

	UPROPERTY()
	EGyroTouchMode GyroV2TouchMode;

	UPROPERTY()
	bool bGyroV2AimAssist;

	UPROPERTY()
	float GyroV2AccelMultiplier;

	UPROPERTY()
	float GyroV2AccelMinThreshold;

	UPROPERTY()
	float GyroV2AccelMaxThreshold;

	UPROPERTY()
	EGyroAcceleration GyroV2AccelerationMode;

	UPROPERTY()
	float GyroV2VerticalMultiplier;

	UPROPERTY()
	float GyroV2BuildingMultiplier;

	UPROPERTY()
	float GyroV2EditingMultiplier;

	UPROPERTY()
	float GyroV2DeadZone;

	UPROPERTY()
	float GyroV2SmoothingThreshold;

	UPROPERTY()
	float GyroV2SmoothingWindow;

	UPROPERTY()
	float GyroV2Tightening;

	UPROPERTY()
	EGyroButtonResponse GyroV2ButtonX;

	UPROPERTY()
	EGyroButtonResponse GyroV2ButtonY;

	UPROPERTY()
	float GyroV2TrackballDecay;

	UPROPERTY()
	float GyroV2ButtonHoldTime;

	UPROPERTY()
	bool bGyroV2DisabledWhileDriving;

	UPROPERTY()
	bool bUseZoomSensitivityScaling;

	UPROPERTY()
	bool bGyroV2VibrationCompensationEnabled;

	UPROPERTY()
	bool bFlickStickEnabled;

	UPROPERTY()
	float FlickTime;

	UPROPERTY()
	float FlickSmoothingThreshold;

	UPROPERTY()
	float FlickDeadZone;

	UPROPERTY()
	float FlickForwardDeadZone;

	UPROPERTY()
	float FlickWindingSpeed;

	UPROPERTY()
	bool bZoomScalesWinding;

};

USTRUCT(BlueprintType)
struct FFortInputActionDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Input")
	EFortInputActionType InputActionType;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	FKey ActionKey;

};

USTRUCT()
struct FFortInputActionGroupContext
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName ActionName;

	UPROPERTY(Config)
	EFortInputActionGroup InputActionGroup;

};

USTRUCT()
struct FFortInputActionKeyAlias
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName ActionName;

	UPROPERTY(Config)
	FKey KeyAlias;

	UPROPERTY(Config)
	EFortInputActionType InputActionType;

};

USTRUCT(BlueprintType)
struct FFortInputActionThatShouldAlwaysBeBound
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName ActionName;

	UPROPERTY(Config)
	TArray<FName> AlternateActionNames;

};

USTRUCT()
struct FFortPerModeInputConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName InputConfigName;

	UPROPERTY(Config)
	FString DefaultKeyboardMouseLayoutPresetName;

	UPROPERTY(Config)
	TArray<FString> ResetKeyboardMouseLayoutPresetNames;

	UPROPERTY(Config)
	FString DefaultControllerLayoutPresetName;

	UPROPERTY(Config)
	FString CustomControllerLayoutPresetName;

	UPROPERTY(Config)
	TArray<FString> FortPlayerInputSettingsNames;

};

UCLASS(MinimalAPI)
class UFortPlayerInput : public UEnhancedPlayerInput
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString CampaignDefaultKBMPresetName;

	UPROPERTY(Config)
	FString AthenaDefaultKBMPresetName;

	UPROPERTY(EditAnywhere, Config, Category="Bindings")
	TArray<FString> CampaignKBMResetToDefaultPresetNames;

	UPROPERTY(EditAnywhere, Config, Category="Bindings")
	TArray<FString> AthenaKBMResetToDefaultPresetNames;

	UPROPERTY(Config)
	FString DefaultGamepadPresetName;

	UPROPERTY(Config)
	FString DefaultGamepadPresetNameAthena;

	UPROPERTY(Config)
	FString DefaultGamepadPresetNameAthenaMobile;

	UPROPERTY(Config)
	FString CustomGamepadPresetNameAthena;

	UPROPERTY()
	FString CreatorCustomGamepadPresetName;

	UPROPERTY(EditAnywhere, Config, Category="Bindings")
	TArray<FString> FortPlayerInputSettingsNames;

protected:
	UPROPERTY(Transient)
	TArray<FFortActionKeyMapping> InputOptionListOverride;

	UPROPERTY()
	float TouchLookAccelerationMultiplier;

	UPROPERTY()
	float TouchBuildingMultiplier;

	UPROPERTY()
	float TouchEditModeMultiplier;

	UPROPERTY()
	EFortMotionYawAxis MotionYawAxis;

	UPROPERTY()
	float TargetingMultiplier;

	UPROPERTY()
	float ScopedMultiplier;

	UPROPERTY()
	float BuildingMultiplier;

	UPROPERTY()
	float EditingMultiplier;

	UPROPERTY()
	float GamepadTargetingMultiplier;

	UPROPERTY()
	float GamepadScopedMultiplier;

	UPROPERTY()
	float GamepadBuildingMultiplier;

	UPROPERTY()
	float GamepadEditModeMultiplier;

	UPROPERTY()
	bool bInvertedPitchForMotion;

	UPROPERTY()
	bool bInvertedYawMobile;

	UPROPERTY()
	float MotionTargetingMultiplier;

	UPROPERTY()
	float MotionScopedMultiplier;

	UPROPERTY()
	float MotionHarvestingToolMultiplier;

	UPROPERTY()
	FFortGyroV2Settings GyroV2Settings;

	UPROPERTY()
	float GamepadMoveStickDeadZone;

	UPROPERTY()
	float GamepadLookStickDeadZone;

private:
	UFUNCTION()
	void HandleDesiredGamepadInputSettingsReloadConfig(UFortPlayerInputSettings* GamepadSettings);

	UFUNCTION()
	void HandleDesiredKBMInputSettingsReloadConfig(UFortPlayerInputSettings* KBMSettings);

	UPROPERTY(Transient)
	TMap<FString, TObjectPtr<UFortPlayerInputSettings>> AllPlayerInputSettings;

	UPROPERTY()
	TObjectPtr<UFortPlayerInputSettings> DesiredKBMPlayerInputSettings;

	UPROPERTY()
	TObjectPtr<UFortPlayerInputSettings> DesiredGamepadPlayerInputSettings;

	UPROPERTY(Config)
	TArray<FText> InputActionTypeFriendlyNames;

	UPROPERTY(Config)
	TArray<FFortInputActionGroupContext> InputActionGroupContexts;

	UPROPERTY(Config)
	TArray<EFortInputActionGroup> InputActionGroupExemptFromAllModesCheck;

	UPROPERTY(Config)
	TArray<FFortPerModeInputConfig> PerModeInputConfigs;

	UPROPERTY(Transient)
	FFortPerModeInputConfig ActivePerModeInputConfig;

};

