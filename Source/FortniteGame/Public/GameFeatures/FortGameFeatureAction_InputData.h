// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameplayTagContainer.h"
#include "GameData/FortInputDataSubsystem.h"
#include "FortGameFeatureAction_InputData.generated.h"

UENUM(BlueprintType)
enum class EKeyboardMouseKeybindingsAtRegistrationTime : uint8
{
	Invalid = 0 UMETA(Hidden),
	/** WARNING: for legacy input, having this action run at registration time may not be able to read the defaults, leaving the actions unbound.*/
	GameFeatureRegistrationTime = 1 UMETA(DisplayName="Game Feature Registration Time (WARNING: see tooltip)"),
	GameFeatureActivationTime = 2,
};

UCLASS(MinimalAPI, meta=(DisplayName="Input Data"))
class UFortGameFeatureAction_InputData : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Input Data")
	EKeyboardMouseKeybindingsAtRegistrationTime KeyboardMouseKeybindingsRegistrationTime;

	UPROPERTY(EditDefaultsOnly, Category="Input Data")
	TMap<FGameplayTag, FFortGameFeatureKeyboardMouseKeybindArray> KeyboardMouseKeybinds;

	UPROPERTY(EditDefaultsOnly, Category="Input Data")
	bool bIgnoreLegacyInputDataWhenEnhancedInputSettingsOn;

	UPROPERTY(EditAnywhere, Category="Input Data", meta=(DisplayAfter="bIgnoreWhenEnhancedInputSettingsOn", DisplayName="(Optional) Feature Enhanced Input Support Cvar Name", EditCondition="bIgnoreLegacyInputDataWhenEnhancedInputSettingsOn"))
	FString FeatureEnhancedInputSupportCvarName;

};

