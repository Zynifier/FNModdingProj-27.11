// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "BlueprintContextBase.h"
#include "FortSettingsContext.generated.h"

enum class EAutorunLockZonePreferenceMobile : uint8;
enum class EFortAllowBackgroundAudioSetting : uint8;
enum class EFortPreferredItemSlotItemType : uint8;
enum class EHitFeedbackMode : uint8;
enum class EHitNumbersMode : uint8;
enum class ESettingType : uint8;
enum class ESocialCommsPermission : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSavedTabChanged, bool, IsTabSaved);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWindowModeChanged, bool, IsWindowedFullscreen);

UCLASS()
class FORTNITEUI_API UFortSettingsContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void AnonymousCharacterModeChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void AnonymousModeChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void AutoEquipChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void AutorunLockZonePreferenceMobileChanged(int32 InAutorunLockZonePreference);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void ChatVolumeChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void CinematicsVolumeChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void DialogVolumeChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void DoubleTapAutorunToggleChanged(bool bToggleState);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void FirstPersonCameraChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void GamepadBuildingMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void GamepadEditModeMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void GamepadLookSensitivityXChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void GamepadLookSensitivityYChanged(float NewValue);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortGameOptions")
	void GamepadLookStickDeadZoneChanged(const float NewValue) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortGameOptions")
	void GamepadMoveStickDeadZoneChanged(const float NewValue) const;

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void GamepadScopedMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void GamepadTargetingMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAimAssistState() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	EFortAllowBackgroundAudioSetting GetAllowGameVolumeWhenMinimized() const;

	UFUNCTION(Category="FortGameOptions")
	bool GetAllowSidekickFeature1() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAnonymousCharacterModeEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAnonymousModeEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAutoChangeMaterial() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAutoClamberEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAutoEquipState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAutoJoinGameVoiceChannel() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAutoOpenDoors() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAutoPickupWeapons() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAutoPickupWeaponsConsolePC() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	EAutorunLockZonePreferenceMobile GetAutorunLockZonePreferenceMobile() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetAutoSortConsumablesToRight() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetBuildingPossessionShown() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	float GetChatVolumeValue() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	float GetCinematicsVolume() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetClipRemindersEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	int32 GetColorBlindMode() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	TArray<FText> GetColorBlindModeNames() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	int32 GetColorBlindStrength() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetContextTutorialState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetCreativeModeReplayRecordingEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetCreativeTurboDelete() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetCrossplayPreference() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetDamageNumbersScale() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	float GetDialogVolumeValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetDisablePreEditsWhenPlacingBuildingState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetDoubleTapAutorunToggleState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetEditButtonHoldTimeValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetEditConfirmOnReleaseState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetEditModeAimAssistState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetEnablePreferredItemSlots() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetEnableRudderControl() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetEnableTryBuildOnFocus() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetFirstPersonCameraState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetFocusOnFirstBuildingPieceWhenQuickbarSwappedState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetFocusOnFirstBuildingPieceWhenQuickbarSwappedStateAthena() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetForceFeedbackState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetGamepadAutoRunState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetGamepadBuildingMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetGamepadEditModeMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	FVector2D GetGamepadLookSensitivityValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetGamepadLookStickDeadZone() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetGamepadMoveStickDeadZone() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetGamepadScopedMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetGamepadTargetingMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetGammaSettings() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetGyroSensitivityValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	int32 GetHiddenMatchmakingDelayMax() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetHideOtherPlayerNames() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	EHitFeedbackMode GetHitFeedbackMode() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	EHitNumbersMode GetHitNumbersMode() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetHoldToSwapPickupState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetHUDScale() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetHUDScaleRaw() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetIgnoreGamepadInput() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetInWorldInteractState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetLargeTeamsReplayRecordingEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetLocalNotificationsState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetLockPrimaryInputMethodToMouse() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	float GetMasterVolumeValue() const;

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	TArray<FText> GetMotionAxisNames();

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	int32 GetMotionAxisValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetMotionControlsEnabledValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetMotionHarvestingToolMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetMotionScopedMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetMotionTargetingMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="OptionMenuSetting")
	float GetMouseSensitivityMultiplierForAircraft() const;

	UFUNCTION(BlueprintPure, Category="OptionMenuSetting")
	FVector2D GetMouseSensitivityValue() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	float GetMusicVolumeValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetPeripheralLightingEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetPitchForAircraftPrimaryInversionState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetPitchForAircraftSecondaryInversionState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetPitchForMotionInversionState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetPitchInversionState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetPlaceDangerMarkerWhenTargeting() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetPlayerSurveysAllowed() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetPowerSaverMode() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	EFortPreferredItemSlotItemType GetPreferredItemSlotType(const int32 SlotIndex) const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	int32 GetQuality() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetQuickEditState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetReplayRecordingEnabled() const;

	UFUNCTION(BlueprintCallable, Category="FortSettingsContext")
	int32 GetRotatorSettingValue(ESettingType InSettingType);

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetRudderDeadZone() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetRudderMaxThrottle() const;

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	float GetSafeZoneValue();

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetScopedMultiplierValue() const;

	UFUNCTION(BlueprintCallable, Category="FortSettingsContext")
	TArray<FText> GetSettingDisplayNames(ESettingType InSettingType);

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetShadowPlayHighlightsEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetShowGlobalChatEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetShowSeasonLevel() const;

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	bool GetShowTemperature();

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetShowViewerCountEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetShowVoiceIndicators() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetSlideButtonHoldTimeValue() const;

	UFUNCTION(BlueprintCallable, Category="FortSettingsContext")
	float GetSliderSettingValue(ESettingType InSettingType);

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetSmartBuildState() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	float GetSoundFXVolumeValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetSprintCancelsReloadState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetSprintToggleState() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	bool GetSubtitlesEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetTapInteractState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetTargetingMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetTargetingToggleState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetTargetTypeIndicatorVisible() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetTouchBuildingMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetTouchDragScopedSensitivityValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetTouchEditModeMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetTouchEditState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetTouchLookAccelerationMultiplier() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetTouchLookSensitivityValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetTouchTargetingMultiplierValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	float GetTouchVerticalSensitivityValue() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetTurboBuild() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetVisualizeAudioSources() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	bool GetVoiceChat3DEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	bool GetVoiceChatEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	bool GetVoiceChatPTTEnabled() const;

	UFUNCTION(BlueprintPure, Category="FortAudioOptions")
	ESocialCommsPermission GetVoiceChatSettings() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetYawForMotionInversionState() const;

	UFUNCTION(BlueprintPure, Category="FortGameOptions")
	bool GetYawInversionState() const;

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void GyroSensitivityValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void HiddenMatchmakingDelayMaxChanged(int32 inValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void HiddenMatchmakingDelayMaxReset();

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void HideOtherPlayerNamesChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void HoldToSwapPickupChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void InWorldInteractChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void MasterVolumeChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void MotionAxisValueChanged(int32 NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void MotionControlEnabledValueChanged(bool NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void MotionHarvestingToolMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void MotionScopedMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void MotionTargetingMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="OptionMenuSetting")
	void MouseSensitivityMultiplierForAircraftChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="OptionMenuSetting")
	void MouseSensitivityXChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="OptionMenuSetting")
	void MouseSensitivityYChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void MusicVolumeChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAimAssistChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAimAssistReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAutoChangeMaterialChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAutoChangeMaterialReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAutoClamberChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAutoOpenDoorsChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAutoPickupWeaponsChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAutoPickupWeaponsConsolePCChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnAutoSortConsumablesToRightChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnBuildingPossessionChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnClipRemindersEnabledChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnContextTutorialChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnCreativeModeReplayRecordingPreferenceChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnCreativeTurboDeleteChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnCreativeTurboDeleteReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnCrossplayPreferenceChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnDisablePreEditsWhenPlacingBuildingChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnEditButtonHoldTimeChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnEditConfirmOnReleaseChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnEditModeAimAssistChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnEnablePreferredItemSlotsChanged(bool bInChanged);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnEnableTryBuildOnFocusChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnFocusOnFirstBuildingPieceWhenQuickbarSwappedChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnFocusOnFirstBuildingPieceWhenQuickbarSwappedChangedAthena(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnForceFeedbackChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnGamepadAutoRunChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnHUDScaleChanged(float bInHUDScale);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnLargeTeamsReplayRecordingPreferenceChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnLocalNotificationsChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnPlaceDangerMarkerWhenTargetingChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnPlayerSurveysAllowedChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnQuickEditChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnReplayRecordingPreferenceChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnShadowPlayHighlightsChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnShowGlobalChatEnabledChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnSlideButtonHoldTimeChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnSmartBuildChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnTouchEditChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnTurboBuildChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void OnTurboBuildReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortSettingsContext")
	void OpenSettingsIfSaved();

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PeripheralLightingChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PitchForAircraftPrimaryInversionChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PitchForAircraftPrimaryInversionReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PitchForAircraftSecondaryInversionChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PitchForAircraftSecondaryInversionReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PitchForMotionInversionChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PitchForMotionInversionReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PitchInversionChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PitchInversionReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void PowerSaverModeChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void ResetGamepadLookStickDeadZone();

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void ResetGamepadMoveStickDeadZone();

	UFUNCTION(BlueprintCallable, Category="FortSettingsContext")
	void RotatorSettingChanged(ESettingType InSettingType, FText NameText, int32 PreviousValue, int32 NewValue);

	UFUNCTION(BlueprintCallable, Category="FortSettingsContext")
	void RotatorSettingReset(ESettingType InSettingType, FText NameText, int32 PreviousValue, int32 NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void RudderDeadZoneChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void RudderMaxThrottleChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SafeZoneChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void ScopedMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void SetAllowGameVolumeWhenMinimized(EFortAllowBackgroundAudioSetting NewValue);

	UFUNCTION(Category="FortGameOptions")
	void SetAllowSidekickFeature1(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetAutoJoinGameVoiceChannel(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetColorBlindMode(int32 InMode);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetColorBlindStrength(int32 InColorBlindStrength);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetEnableRudderControl(bool bEnable);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetIgnoreGamepadInput(bool bIgnore);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetLockPrimaryInputMethodToMouse(bool bLock);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void SetQuality(int32 NewQuality);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetShowVoiceIndicators(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void SetSubtitlesEnabled(bool bNewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SetVisualizeAudioSources(bool bEnable);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void SetVoiceChat3DEnabled(bool bNewValue);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void SetVoiceChatEnabled(bool bNewValue);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void SetVoiceChatPTTEnabled(bool bNewValue);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void SetVoiceChatSettings(ESocialCommsPermission NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void ShowSeasonLevelChanged(bool bInChanged);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void ShowTemperatureChanged(bool IsChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void ShowViewerCountChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortSettingsContext")
	void SliderSettingChanged(ESettingType InSettingType, FText NameText, float PreviousValue, float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortSettingsContext")
	void SliderSettingReset(ESettingType InSettingType, FText NameText, float PreviousValue, float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortAudioOptions")
	void SoundFXVolumeChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SprintCancelsReloadChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void SprintToggleChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TapInteractChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TargetingMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TargetingToggleChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TouchBuildingMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TouchDragScopedSensitivityValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TouchEditModeMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TouchLookAccelerationMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TouchLookSensitivityChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TouchTargetingMultiplierValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void TouchVerticalSensitivityValueChanged(float NewValue);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortGameOptions")
	void UpdateGammaSettings(float GammaValue) const;

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void YawForMotionInversionChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void YawForMotionInversionReset(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void YawInversionChanged(bool bInChecked);

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void YawInversionReset(bool bInChecked);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSettingsContext")
	float MinGammaValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSettingsContext")
	float MaxGammaValue;

};

