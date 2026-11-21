// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortSubGameTypes.h"
#include "Input/FortActionKeyMapping.h"
#include "FortInputDataSubsystem.generated.h"

USTRUCT()
struct FFortGameFeatureKeyboardMouseKeybindInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureKeyboardMouseKeybindInfo")
	FName ActionName;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureKeyboardMouseKeybindInfo")
	EFortInputActionGroup ActionGroup;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureKeyboardMouseKeybindInfo")
	ESubGame SubGameUsedIn;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureKeyboardMouseKeybindInfo")
	FText LocalizedCategory;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureKeyboardMouseKeybindInfo")
	FText LocalizedName;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureKeyboardMouseKeybindInfo")
	bool bIsAxisMapping;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureKeyboardMouseKeybindInfo", meta=(EditCondition="bIsAxisMapping", EditConditionHides))
	float AxisInputScale;

};

USTRUCT()
struct FFortGameFeatureKeyboardMouseKeybindArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureKeyboardMouseKeybindArray")
	TArray<FFortGameFeatureKeyboardMouseKeybindInfo> Data;

};

UCLASS(MinimalAPI)
class UFortInputDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FGameplayTag, FFortGameFeatureKeyboardMouseKeybindArray> KeyboardMouseKeybinds;

};

