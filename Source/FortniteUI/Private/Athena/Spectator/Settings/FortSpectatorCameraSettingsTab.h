// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/FortReplayViewSettingsTabBase.h"
#include "FortSpectatorCameraSettingsTab.generated.h"

class UCommonUserWidget;
enum class EThirdPersonAutoFollowMode : uint8;

UCLASS(Abstract, MinimalAPI)
class UFortSpectatorCameraSettingsTab : public UFortReplayViewSettingsTabBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBattleMapAutomaticCameraPlacementChanged(bool bInBattleMapAutomaticCameraPlacement);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBattleMapShowAllSquadMembersChanged(bool bBattleMapShowAllSquadMembers);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBattleMapShowNearbyChestsChanged(bool bBattleMapShowNearbyChests);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBattleMapShowTimeIndicatorChanged(bool bBattleMapShowTimeIndicator);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamageFxEnabledChanged(bool bDamageFxEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDroneIgnoreJumpChanged(bool bDroneIgnoreJump);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFirstPlaceHighlightEnabledChanged(bool bFirstPlaceHighlightEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHighQualityFxEnabledChanged(bool bHighQualityFxEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerOutlinesEnabledChanged(bool bPlayerOutlinesEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRelevancyZoneVisibleChanged(bool bRelevancyZoneVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSafeZoneOpacityChanged(float SafeZoneOpacity);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSessionIDWatermarkChanged(bool bShowSessionIDWatermark);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShareLensSettingsChanged(bool bShareLensSettings);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStormEffectsEnabledChanged(bool bStormEffectsEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnThirdPersonAutoFollowModeChanged(EThirdPersonAutoFollowMode ThirdPersonAutoFollowMode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnThirdPersonCameraCollisionChanged(bool bThirdPersonCameraCollision);

	UFUNCTION(BlueprintImplementableEvent)
	void OnThirdPersonDistanceToSubjectChanged(float ThirdPersonDistanceToSubject);

	UFUNCTION(BlueprintCallable)
	void SetBattleMapAutomaticCameraPlacement(bool bBattleMapAutomaticCameraPlacement);

	UFUNCTION(BlueprintCallable)
	void SetBattleMapShowAllSquadMembers(bool bBattleMapShowAllSquadMembers);

	UFUNCTION(BlueprintCallable)
	void SetBattleMapShowNearbyChests(bool bBattleMapShowNearbyChests);

	UFUNCTION(BlueprintCallable)
	void SetBattleMapShowTimeIndicator(bool bBattleMapShowTimeIndicator);

	UFUNCTION(BlueprintCallable)
	void SetDamageFxEnabled(bool bDamageFxEnabled);

	UFUNCTION(BlueprintCallable)
	void SetDroneIgnoreJump(bool bDroneIgnoreJump);

	UFUNCTION(BlueprintCallable)
	void SetFirstPlaceHighlightEnabled(bool bFirstPlaceHighlightEnabled);

	UFUNCTION(BlueprintCallable)
	void SetHighQualityFxEnabled(bool bHighQualityFxEnabled);

	UFUNCTION(BlueprintCallable)
	void SetPlayerOutlinesEnabled(bool bPlayerOutlinesEnabled);

	UFUNCTION(BlueprintCallable)
	void SetRelevancyZoneVisible(bool bRelevancyZoneVisible);

	UFUNCTION(BlueprintCallable)
	void SetSafeZoneOpacity(float SafeZoneOpacity);

	UFUNCTION(BlueprintCallable)
	void SetSessionIdWatermark(bool bShowSessionIdWatermark);

	UFUNCTION(BlueprintCallable)
	void SetShareLensSettings(bool bShareLensSettings);

	UFUNCTION(BlueprintCallable)
	void SetStormEffectsEnabled(bool bStormEffectsEnabled);

	UFUNCTION(BlueprintCallable)
	void SetThirdPersonAutoFollowMode(EThirdPersonAutoFollowMode ThirdPersonAutoFollowMode);

	UFUNCTION(BlueprintCallable)
	void SetThirdPersonCameraCollision(bool bThirdPersonCameraCollision);

	UFUNCTION(BlueprintCallable)
	void SetThirdPersonDistanceToSubject(float ThirdPersonDistanceToSubject);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSpectatorCameraSettingsTab", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> Rotator_PlayerOutlines;

};

