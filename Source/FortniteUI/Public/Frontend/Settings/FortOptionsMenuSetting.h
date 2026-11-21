// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/TimerHandle.h"
#include "Frontend/Settings/FortOptionsSettingsType.h"
#include "FortOptionsMenuSetting.generated.h"

class UAnalogSlider;
class UCommonTextBlock;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSettingValueChanged, float, Value);

UCLASS(meta=(DisableNativeTick))
class UFortOptionsMenuSetting : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="OptionMenuSetting")
	void CenterOnWidget();

	UFUNCTION()
	void HandleAnalogCaptureEnd(float Value);

	UFUNCTION()
	void HandleCaptureEnd();

	UFUNCTION(BlueprintCallable, Category="OptionMenuSetting")
	void UpdateSetting(UCommonTextBlock* TooltipTextBlock);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateVisuals();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSettingValueChanged SettingValueChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortOptionsMenuSetting")
	ESettingType SettingType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortOptionsMenuSetting")
	FText NameText;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortOptionsMenuSetting", meta=(EditInline="true"))
	TObjectPtr<UCommonTextBlock> TabTooltipText;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	FText HoverText;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	FTimerHandle TooltipTimer;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	int32 MinIntegralDigits;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	int32 MaxIntegralDigits;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	int32 MinFractionalDigits;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	int32 MaxFractionalDigits;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	float MinSensitivityValue;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	float MaxSensitivityValue;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	float PreviousSettingValue;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	bool bDisplayRenderScale;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	bool HideLabelText;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuSetting")
	bool HideSpaceRight;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenuSetting", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAnalogSlider> Slider_Menu;

};

