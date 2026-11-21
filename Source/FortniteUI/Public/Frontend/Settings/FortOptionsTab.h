// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Kismet/KismetTextLibrary.h"
#include "UObject/NoExportTypes.h"
#include "FortTypes.h"
#include "Frontend/Settings/FortOptionsSettingsType.h"
#include "FortOptionsTab.generated.h"

class UFortOptionsMenuSetting;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTabActivated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTabDeactivated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTabSettingChanged);

UCLASS(meta=(DisableNativeTick))
class FORTNITEUI_API UFortOptionsTab : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="FortOptionsTab")
	virtual void ActivateTab();

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	bool AreParentalControlsEnabled();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="FortOptionsTab")
	void CenterOnTab();

	UFUNCTION(BlueprintCallable, Category="FortOptionsTab")
	virtual void DeactivateTab();

	UFUNCTION(BlueprintCallable, Category="FortOptionsTab")
	bool IsAthena();

	UFUNCTION(BlueprintPure, Category="FortOptionsTab")
	bool IsControllerDefaultInputType() const;

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	virtual void ResetOptionsToDefault();

	UFUNCTION(BlueprintCallable, Category="FortOptionsTab")
	virtual void TempNew_UpdateOptionsTab();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="FortOptionsTab")
	void UpdateOptionsTab();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="FortOptionsTab")
	FOnTabSettingChanged OnTabSettingChanged;

	UPROPERTY(BlueprintAssignable, Category="FortOptionsTab")
	FOnTabActivated OnTabActivated;

	UPROPERTY(BlueprintAssignable, Category="FortOptionsTab")
	FOnTabDeactivated OnTabDeactivated;

	UPROPERTY(BlueprintReadOnly, Category="FortGameOptions", meta=(ExposeOnSpawn="TRUE"))
	ESettingTab TabType;

};

UCLASS(BlueprintType)
class UFortSettingInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	ESettingType SettingType;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	TSubclassOf<UFortOptionsMenuSetting> SettingWidgetType;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	FText OptionDisplayText;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	FText OptionHoverText;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	int32 MinIntegralDigits;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	int32 MaxIntegralDigits;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	int32 MinFractionalDigits;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	int32 MaxFractionalDigits;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	float StepSize;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	float MinSensitivityValue;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	float MaxSensitivityValue;

	UPROPERTY(BlueprintReadWrite, Category="FortSettingInfo")
	TEnumAsByte<ERoundingMode> RoundingMode;

};

