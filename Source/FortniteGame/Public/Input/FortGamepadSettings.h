// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Abilities/FortAbilityTargetSelection.h"
#include "Input/FortAimAssistSettings.h"
#include "FortGamepadSettings.generated.h"

class UCurveFloat;

USTRUCT()
struct FFortFollowCam_Settings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat TurnDampeningStart;

	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat TurnFullRate;

	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat TurnFullDeflectionThreshold;

	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat TurnBoostRate;

	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat TurnDampeningRecoveryRate;

	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat TurnDeadZone;

	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat HorizonPullDelay;

	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat HorizonPullDampeningTime;

	UPROPERTY(EditAnywhere, Category="FortFollowCam_Settings")
	FScalableFloat HorizonPullHalfTime;

};

UCLASS()
class UFortGamepadSettings : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Gamepad Look Settings")
	TObjectPtr<UCurveFloat> GamepadLookCurve;

	UPROPERTY(EditAnywhere, Category="Gamepad Look Settings")
	TObjectPtr<UCurveFloat> GamepadLookSensitivityCurve;

	UPROPERTY(EditAnywhere, Category="Gamepad Look Settings")
	FVector2D GamepadLookScale;

	UPROPERTY(EditAnywhere, Category="Gamepad Look Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float GamepadLookScaleDownsights;

	UPROPERTY(EditAnywhere, Category="Gamepad Look Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float GamepadLookScaleScope;

	UPROPERTY(EditAnywhere, Category="Gamepad Look Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float GamepadLookScaleDownsightsDecayTime;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float AimAssistStrength;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float AimAssistStrengthDownsights;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float AimAssistStrengthDBNO;

	UPROPERTY(EditAnywhere, Category="Gamepad Look Settings")
	float GamepadLookAccelTime;

	UPROPERTY(EditAnywhere, Category="Gamepad Look Settings")
	float GamepadLookDecelTime;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float AimAssistPullStrength;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float AimAssistPullMaxRate;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float AimAssistPullRampUpTime;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float AimAssistPullDecayTime;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMax="10.0", ClampMin="0.0", UIMax="10.0", UIMin="0.0"))
	float AimAssistInitialDownsightStrength;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float AimAssistInitialDownsightTime;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float SlowMinDistance;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float SlowMinStrength;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float SlowMaxDistance;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float SlowMaxStrength;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float SlowDecayTime;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModePullStrengthStationary;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModePullStrengthMovingNewTile;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModePullStrengthMovingWithinTile;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModePullMinDistance;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModePullMaxDistance;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModePullScaleFlat;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModePullMaxRate;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModeSlowMinDistance;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float EditModeSlowMinStrength;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMin="0.0", UIMin="0.0"))
	float EditModeSlowMaxDistance;

	UPROPERTY(EditAnywhere, Category="Edit Mode Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float EditModeSlowMaxStrength;

	UPROPERTY(EditAnywhere, Category="Aim Assist Settings")
	FFortAbilityTargetSelection AimAssistTargetSelection;

};

UCLASS()
class UFortGamepadSettingsV2 : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Look Settings")
	TObjectPtr<UCurveFloat> LookInputCurve;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookAdsEnterEaseTime;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookAdsExitEaseTime;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookAdsEaseExponent;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookBoostDeflection;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookBoostAccelerationTime;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookBoostAccelerationTimeAds;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookEaseTime;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookBuildModeMultiplier;

	UPROPERTY(EditAnywhere, Category="Look Settings")
	FScalableFloat LookEditModeMultiplier;

	UPROPERTY(EditAnywhere, Category="Look Sensitivity Presets")
	FScalableFloat LookHorizontalSpeed;

	UPROPERTY(EditAnywhere, Category="Look Sensitivity Presets")
	FScalableFloat LookVerticalSpeed;

	UPROPERTY(EditAnywhere, Category="Look Sensitivity Presets")
	FScalableFloat LookHorizontalSpeedAds;

	UPROPERTY(EditAnywhere, Category="Look Sensitivity Presets")
	FScalableFloat LookVerticalSpeedAds;

	UPROPERTY(EditAnywhere, Category="Look Sensitivity Presets")
	FScalableFloat LookHorizontalBoostSpeed;

	UPROPERTY(EditAnywhere, Category="Look Sensitivity Presets")
	FScalableFloat LookVerticalBoostSpeed;

	UPROPERTY(EditAnywhere, Category="Look Sensitivity Presets")
	FScalableFloat LookHorizontalBoostSpeedAds;

	UPROPERTY(EditAnywhere, Category="Look Sensitivity Presets")
	FScalableFloat LookVerticalBoostSpeedAds;

	UPROPERTY(EditAnywhere, Category="Aim Assist")
	FFortAimAssist2D_Settings AimAssistSettings;

	UPROPERTY(EditAnywhere, Category="Follow Camera")
	FFortFollowCam_Settings FollowCamSettings;

};

