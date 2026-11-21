// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/FortReplayViewSettingsTabBase.h"
#include "FortSpectatorLensSettingsTab.generated.h"

class UCommonUserWidget;

UCLASS(Abstract, MinimalAPI)
class UFortSpectatorLensSettingsTab : public UFortReplayViewSettingsTabBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	void GetMinMaxExposure(float& MinExposure, float& MaxExposure) const;

	UFUNCTION(BlueprintPure)
	void GetMinMaxFocusDistance(float& MinFocusDistance, float& MaxFocusDistance) const;

	UFUNCTION(BlueprintPure)
	void GetPresetApertureTexts(TArray<FText>& PresetApertureTexts) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnApertureChanged(int32 PresetApertureIdx);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAutoExposureEnabledChanged(bool bAutoExposureEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAutoFocusEnabledChanged(bool bAutoFocusEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFocalLengthChanged(const TArray<FText>& FocalLengthTexts, int32 PresetFocalLengthIdx);

	UFUNCTION(BlueprintImplementableEvent)
	void OnManualExposureBiasChanged(float ManualExposureBias);

	UFUNCTION(BlueprintImplementableEvent)
	void OnManualFocusDistanceChanged(float ManualFocusDistance);

	UFUNCTION(BlueprintCallable)
	void SetApertureFromIdx(int32 ApertureIdx);

	UFUNCTION(BlueprintCallable)
	void SetAutoExposureEnabled(bool bAutoExposureEnabled);

	UFUNCTION(BlueprintCallable)
	void SetAutoFocusEnabled(bool bAutoFocusEnabled);

	UFUNCTION(BlueprintCallable)
	void SetFocalLengthFromIdx(int32 FocalLengthIdx);

	UFUNCTION(BlueprintCallable)
	void SetManualExposureBias(float ManualExposureBias);

	UFUNCTION(BlueprintCallable)
	void SetManualFocusDistance(float ManualFocusDistance);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSpectatorLensSettingsTab", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> Rotator_AutoExposure;

};

