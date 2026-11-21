// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/FortReplayViewSettingsTabBase.h"
#include "FortSpectatorNameplateSettingsTab.generated.h"

class UCommonUserWidget;
enum class ESpectatorSquadIdMode : uint8;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortSpectatorNameplateSettingsTab : public UFortReplayViewSettingsTabBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool GetDisplaySessionRanks() const;

	UFUNCTION(BlueprintPure)
	void GetMinMaxNameplateDistance(float& MinDistance, float& MaxDistance) const;

	UFUNCTION(BlueprintPure)
	void GetMinMaxNameplateScale(float& MinScale, float& MaxScale) const;

	UFUNCTION(BlueprintPure)
	bool GetNameplatesEnabled() const;

	UFUNCTION(BlueprintPure)
	bool GetScalingOptionsEnabled() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnArrowColorEnabledChanged(bool bArrowColorEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnArrowDistanceChanged(float ArrowDistance);

	UFUNCTION(BlueprintImplementableEvent)
	void OnArrowScaleMaxChanged(float ArrowScaleMax);

	UFUNCTION(BlueprintImplementableEvent)
	void OnArrowScaleMinChanged(float ArrowScaleMin);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplaySessionRanksChanged(bool bDisplaySessionRanks);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHighDetailScaleMaxChanged(float HighDetailScaleMax);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHighDetailScaleMinChanged(float HighDetailScaleMin);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLowDetailDistanceChanged(float LowDetailDistance);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLowDetailScaleMaxChanged(float LowDetailScaleMax);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLowDetailScaleMinChanged(float LowDetailScaleMin);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNameplatesEnabledChanged(bool bNameplatesEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnScalingOptionsEnabledChanged(bool bScalingOptionsEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowTeamColorChanged(bool bShowTeamColor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadIdModeChanged(ESpectatorSquadIdMode SquadIdMode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnViewDistanceChanged(float ViewDistance);

	UFUNCTION(BlueprintCallable)
	void SetArrowColorEnabled(bool bArrowColorEnabled);

	UFUNCTION(BlueprintCallable)
	void SetArrowDistance(float ArrowDistance);

	UFUNCTION(BlueprintCallable)
	void SetArrowScaleMax(float ArrowScaleMax);

	UFUNCTION(BlueprintCallable)
	void SetArrowScaleMin(float ArrowScaleMin);

	UFUNCTION(BlueprintCallable)
	void SetDisplaySessionRanks(bool bDisplaySessionRanks);

	UFUNCTION(BlueprintCallable)
	void SetHighDetailScaleMax(float HighDetailScaleMax);

	UFUNCTION(BlueprintCallable)
	void SetHighDetailScaleMin(float HighDetailScaleMin);

	UFUNCTION(BlueprintCallable)
	void SetLowDetailDistance(float LowDetailDistance);

	UFUNCTION(BlueprintCallable)
	void SetLowDetailScaleMax(float LowDetailScaleMax);

	UFUNCTION(BlueprintCallable)
	void SetLowDetailScaleMin(float LowDetailScaleMin);

	UFUNCTION(BlueprintCallable)
	void SetNameplatesEnabled(bool bNameplatesEnabled);

	UFUNCTION(BlueprintCallable)
	void SetScalingOptionsEnabled(bool bScalingOptionsEnabled);

	UFUNCTION(BlueprintCallable)
	void SetShowTeamColor(bool bShowTeamColor);

	UFUNCTION(BlueprintCallable)
	void SetSquadIdMode(ESpectatorSquadIdMode SquadIdMode);

	UFUNCTION(BlueprintCallable)
	void SetViewDistance(float ViewDistance);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSpectatorNameplateSettingsTab", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> Rotator_NameplatesEnabled;

};

