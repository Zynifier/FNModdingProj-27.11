// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGamepadUserOptions.generated.h"

UENUM(BlueprintType)
enum class EFortGamepadLookInputCurve : uint8
{
	Linear = 0,
	Exponential = 1,
};

UENUM(BlueprintType)
enum class EFortGamepadSensitivity : uint8
{
	Invalid = 0 UMETA(Hidden),
	Slow = 1 UMETA(DisplayName="01 - Slow"),
	SlowPlus = 2 UMETA(DisplayName="02 - Slow+"),
	SlowPlusPlus = 3 UMETA(DisplayName="03 - Slow++"),
	Normal = 4 UMETA(DisplayName="04 - Normal"),
	NormalPlus = 5 UMETA(DisplayName="05 - Normal+"),
	NormalPlusPlus = 6 UMETA(DisplayName="06 - Normal++"),
	Fast = 7 UMETA(DisplayName="07 - Fast"),
	FastPlus = 8 UMETA(DisplayName="08 - Fast+"),
	FastPlusPlus = 9 UMETA(DisplayName="09 - Fast++"),
	Insane = 10 UMETA(DisplayName="10 - Insane"),
	MAX = 11 UMETA(Hidden),
};

USTRUCT()
struct FFortGamepadAdvancedOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="1", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="1"))
	uint32 LookHorizontalSpeed;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="1", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="1"))
	uint32 LookVerticalSpeed;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="1", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="1"))
	uint32 LookHorizontalSpeedAds;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="1", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="1"))
	uint32 LookVerticalSpeedAds;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="0", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="0"))
	uint32 LookHorizontalBoostSpeed;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="0", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="0"))
	uint32 LookVerticalBoostSpeed;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="1", ClampMin="0", EditCondition="bUseAdvancedOptions", UIMax="1", UIMin="0"))
	float LookBoostAccelerationTime;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="0", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="0"))
	uint32 LookHorizontalBoostSpeedAds;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="0", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="0"))
	uint32 LookVerticalBoostSpeedAds;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="1", ClampMin="0", EditCondition="bUseAdvancedOptions", UIMax="1", UIMin="0"))
	float LookBoostAccelerationTimeAds;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(EditCondition="bUseAdvancedOptions"))
	bool bInstantBoostWhenBuilding;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="1", ClampMin="0", EditCondition="bUseAdvancedOptions", UIMax="1", UIMin="0"))
	float LookEaseTime;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(EditCondition="bUseAdvancedOptions"))
	EFortGamepadLookInputCurve LookInputCurve;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(ClampMax="100", ClampMin="0", EditCondition="bUseAdvancedOptions", UIMax="100", UIMin="0"))
	uint32 AimAssistStrength;

	UPROPERTY(EditAnywhere, Category="FortGamepadAdvancedOptions", meta=(EditCondition="bUseAdvancedOptions"))
	bool bUseLegacyControls;

};

USTRUCT()
struct FFortGamepadBasicOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGamepadBasicOptions")
	EFortGamepadSensitivity LookSensitivityPreset;

	UPROPERTY(EditAnywhere, Category="FortGamepadBasicOptions")
	EFortGamepadSensitivity LookSensitivityPresetAds;

	UPROPERTY(EditAnywhere, Category="FortGamepadBasicOptions")
	float LookBuildModeMultiplier;

	UPROPERTY(EditAnywhere, Category="FortGamepadBasicOptions")
	float LookEditModeMultiplier;

	UPROPERTY(EditAnywhere, Category="FortGamepadBasicOptions")
	bool bUseAdvancedOptions;

};

USTRUCT()
struct FFortGamepadUserOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGamepadUserOptions")
	FFortGamepadBasicOptions Basic;

	UPROPERTY(EditAnywhere, Category="FortGamepadUserOptions")
	FFortGamepadAdvancedOptions Advanced;

};

