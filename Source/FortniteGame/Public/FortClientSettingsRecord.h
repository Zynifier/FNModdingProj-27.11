// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Party/PartyTypes.h"
#include "SocialTypes.h"
#include "Components/FortControllerComponent_Interaction.h"
#include "FortGenericRecord.h"
#include "FortInventoryFilterEnum.h"
#include "FortRarityEnum.h"
#include "FortSubGameTypes.h"
#include "Input/FortActionKeyMapping.h"
#include "Input/FortGamepadUserOptions.h"
#include "Input/FortPlayerInputTypes.h"
#include "Internal/OnlineContentControlsServiceMcpTypes.h"
#include "McpCatalogEnums.h"
#include "Mobile/LayoutProfile/FortMobileHUDProfile.h"
#include "Replay/FortReplayTypes.h"
#include "Settings/FortPreferredItemSlotSettings.h"
#include "Settings/Partitions/FortClientSettingRecordPartitionSchema.h"
#include "SubtitleDisplayOptions.h"
#include "UI/HUDLayoutTool/HUDLayoutToolTypes.h"
#include "FortClientSettingsRecord.generated.h"

class UEnhancedInputUserSettings;
class UFortWorldItemDefinition;
enum class EAutorunLockZonePreferenceMobile : uint8;
enum class EAxisDirection : uint8;
enum class EBrelmarCameraShake : uint8;
enum class ECameraResetAxes : uint8;
enum class EColorBlindMode : uint8;
enum class ECombinedADSFireMode : uint8;
enum class EDoughnutFillingSetting : uint8;
enum class EDoughnutPresetSetting : uint8;
enum class EEditAutoConfirmation : uint8;
enum class EFortAllowBackgroundAudioSetting : uint8;
enum class EFortAutoMulchCategory : uint8;
enum class EFortAutoMulchMode : uint8;
enum class EFortGamepadLookInputCurve : uint8;
enum class EFortGamepadSensitivity : uint8;
enum class EFortMotionYawAxis : uint8;
enum class EFortPreferredItemSlotItemType : uint8;
enum class EFortRarity : uint8;
enum class EFortVoiceChatMethod : uint8;
enum class EGyroAcceleration : uint8;
enum class EGyroActiveBuildMode : uint8;
enum class EGyroActiveMode : uint8;
enum class EGyroButton : uint8;
enum class EGyroButtonResponse : uint8;
enum class EGyroSpace : uint8;
enum class EGyroStickMode : uint8;
enum class EGyroTouchMode : uint8;
enum class EHitFeedbackMode : uint8;
enum class EHitNumbersMode : uint8;
enum class EJoyConMotionSelection : uint8;
enum class ELicensedAudioTreatment : uint8;
enum class EPostpartyClippingState : uint8;
enum class EQuickWeaponToggle : uint8;
enum class ESocialCommsPermission : uint8;
enum class ESpectatorSquadIdMode : uint8;
enum class ESubtitleDisplayBackgroundOpacity : uint8;
enum class ESubtitleDisplayTextBorder : uint8;
enum class ESubtitleDisplayTextColor : uint8;
enum class ESubtitleDisplayTextSize : uint8;
enum class EThirdPersonAutoFollowMode : uint8;
enum class ETouchInteractMode : uint8;
enum class EVisualizeAudioPriority : uint8;

UENUM()
enum class EAndroidAppStoreTypes : uint8
{
	Unset = 0,
	Epic = 1,
	Samsung = 2,
};

UENUM()
enum class EAutorunLockZonePreferenceMobile : uint8
{
	Off = 0,
	Fixed = 1,
	Dynamic = 2,
};

UENUM()
enum class EBrelmarCameraShake : uint8
{
	Default = 0,
	Low = 1,
	Off = 2,
};

UENUM()
enum class EClientSettingsSaveType : uint8
{
	Unknown = 0,
	/** saving locally to the GeneratedConfigDir */
	LocalDisk = 1,
	/** saving to the currently active cloudstorage provider */
	CloudStorage = 2,
};

UENUM()
enum class ECloudFileState : uint8
{
	/** Cloud file has never been retrieved */
	Unitialized = 0,
	/** Active saving to cloud, data is ok to read from */
	Saving = 1,
	/** Active loading from cloud, data is unreliable */
	Loading = 2,
	/** Cloud file has been initialized, neither saving nor loading */
	Idle = 3,
};

UENUM(BlueprintType)
enum class EColorBlindMode : uint8
{
	Off = 0,
	// Deuteranope (green weak/blind)

	Deuteranope = 1,
	// Protanope (red weak/blind)

	Protanope = 2,
	// Tritanope(blue weak / bind)

	Tritanope = 3,
};

UENUM()
enum class EDoughnutFillingSetting : uint8
{
	CeilingAngle = 0,
	CeilingTimeDelay = 1,
	CeilingReleaseInput = 2,
	Never = 3,
	Always = 4,
};

UENUM()
enum class EDoughnutPresetSetting : uint8
{
	Default = 0,
	Beta = 1,
	Gamma = 2,
	Epsilon = 3,
	Taco = 4,
	Zeta = 5,
};

UENUM(BlueprintType)
enum class EFortAllowBackgroundAudioSetting : uint8
{
	Off = 0,
	NotificationsOnly = 1,
	AllSounds = 2,
	Num = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortAutoMulchCategory : uint8
{
	Invalid = 0 UMETA(Hidden),
	Weapon = 1,
	Trap = 2,
	Survivor = 3,
	Defender = 4,
	Hero = 5,
	Num = 6 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortAutoMulchMode : uint8
{
	Off = 0,
	Common = 1,
	Uncommon = 2,
	Rare = 3,
	Epic = 4,
	Num = 5 UMETA(Hidden),
};

UENUM()
enum class EFortPerModeInputType : uint8
{
	/** The keyboard & mouse input type */
	KeyboardMouse = 0,
	/** The controller input type */
	Controller = 1,
};

UENUM()
enum class EFortVoiceChatMethod : uint8
{
	OpenMic = 0,
	PTT = 1,
	Mute = 2,
};

UENUM(BlueprintType)
enum class EHitFeedbackMode : uint8
{
	Invalid = 0 UMETA(Hidden),
	HitAndIcon = 1,
	HitOnly = 2,
	Off = 3,
	Num = 4 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EHitNumbersMode : uint8
{
	Invalid = 0 UMETA(Hidden),
	Cumulative = 1,
	List = 2,
	Num = 3 UMETA(Hidden),
};

UENUM()
enum class EJoyConMotionSelection : uint8
{
	Left = 0,
	Right = 1,
};

UENUM()
enum class EKWSSetttingIndividalMigration : uint8
{
	PartyJoinability = 0,
	ShowSeasonLevenInFeed = 1,
	ShowPlayerSurveys = 2,
	PublicGameStats = 3,
	ReceiveGiftsAllowed = 4,
};

UENUM()
enum class ELicensedAudioTreatment : uint8
{
	None = 0,
	MuteOthers = 1,
	MuteAll = 2,
};

UENUM()
enum class EPostpartyClippingState : uint8
{
	//Default

	Unset = 0,
	//Feature is disabled by the user

	Disabled = 1,
	//Feature is enabled (set when Postparty is connected if previously Unset)

	Enabled = 2,
};

UENUM(BlueprintType)
enum class EQuestMapScreenMode : uint8
{
	Invalid = 0 UMETA(Hidden),
	MainCampaign = 1,
	Event = 2,
};

UENUM(BlueprintType)
enum class EVisualizeAudioPriority : uint8
{
	HighPriority = 0,
	All = 1,
};

USTRUCT()
struct FFortUserInputSettingsPerInputType
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LayoutPresetName;

	UPROPERTY()
	FString TemplateLayoutPresetNameForCustom;

	UPROPERTY()
	TArray<FFortActionKeyMapping> ActionMappings;

};

USTRUCT()
struct FFortUserInputSettingsPerMode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortUserInputSettingsPerInputType KeyboardMouseSettings;

	UPROPERTY()
	FFortUserInputSettingsPerInputType ControllerSettings;

};

USTRUCT()
struct FPlayerLastSelectedPreferredProvider
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl LocalUserId;

	UPROPERTY()
	EAppStore PreferredProvider;

};

USTRUCT()
struct FSettingsSaveContextBehaviorDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString Name;

	UPROPERTY(Config)
	bool bAllowRequestSave;

	UPROPERTY(Config)
	bool bSendAnalytics;

};

USTRUCT()
struct FUserActionBindings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortActionKeyMapping> UserActionBindings;

};

UCLASS(Config=Game, MinimalAPI)
class UFortClientSettingsRecord : public UFortGenericRecord
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMoveStickAcceleratesVehiclesChanged);

public:
	UFUNCTION()
	void AddNewSubscriptionNotificationViewed(const FName& NotificationID);

	UFUNCTION()
	bool DoesMoveStickAccelerateVehicles() const;

	UFUNCTION()
	void ForceToggleHousepartyCastingEnabled();

	UFUNCTION()
	float GetAccelerationMultiplierSetting() const;

	UFUNCTION()
	bool GetAimAssistEnabled() const;

	UFUNCTION()
	EFortAllowBackgroundAudioSetting GetAllowAudioInBackgroundSetting() const;

	UFUNCTION()
	bool GetAllowSidekickFeature1() const;

	UFUNCTION()
	bool GetAnonymousCharacterModeEnabled() const;

	UFUNCTION()
	bool GetAnonymousModeEnabled() const;

	UFUNCTION()
	bool GetAttendingSocialEvent(int32 EventId) const;

	UFUNCTION()
	bool GetAutoChangeMaterial() const;

	UFUNCTION()
	bool GetAutoClamber() const;

	UFUNCTION()
	bool GetAutoEquipBetterItems() const;

	UFUNCTION()
	bool GetAutoHideBuildingMaterials() const;

	UFUNCTION()
	bool GetAutoHurdle() const;

	UFUNCTION()
	bool GetAutoJoinGameVoiceChannel() const;

	UFUNCTION()
	EFortAutoMulchMode GetAutoMulchMode(EFortAutoMulchCategory Category) const;

	UFUNCTION()
	bool GetAutoOpenDoors() const;

	UFUNCTION()
	bool GetAutoPickupWeapons() const;

	UFUNCTION()
	bool GetAutoPickupWeaponsConsolePC() const;

	UFUNCTION()
	EAutorunLockZonePreferenceMobile GetAutorunLockZonePreferenceMobile() const;

	UFUNCTION()
	bool GetAutoSortConsumablesToRight() const;

	UFUNCTION()
	EBrelmarCameraShake GetBrelmarCameraShake() const;

	UFUNCTION()
	bool GetBrunoReplayRecordingEnabled() const;

	UFUNCTION()
	float GetBuildingMultiplier() const;

	UFUNCTION()
	bool GetBuildingPossessionShown() const;

	UFUNCTION()
	ECameraResetAxes GetCameraResetAxes() const;

	UFUNCTION()
	float GetCameraResetTime() const;

	UFUNCTION()
	bool GetChatDisabledForPlatform() const;

	UFUNCTION()
	float GetChatVolume() const;

	UFUNCTION()
	float GetCinematicsVolume() const;

	UFUNCTION()
	bool GetClippingEnabled() const;

	UFUNCTION()
	bool GetClipRemindersEnabled() const;

	UFUNCTION()
	EColorBlindMode GetColorBlindMode() const;

	UFUNCTION()
	int32 GetColorBlindStrength() const;

	UFUNCTION()
	ECombinedADSFireMode GetCombinedADSFireModeSetting() const;

	UFUNCTION()
	EEditAutoConfirmation GetCombinedConfirmEditResetEnabled() const;

	UFUNCTION()
	bool GetConsoleFPSUnlocked() const;

	UFUNCTION()
	bool GetContextTutorialEnabled() const;

	UFUNCTION()
	bool GetContinuousFireEnabledSetting() const;

	UFUNCTION()
	bool GetCreativeModeReplayRecordingEnabled() const;

	UFUNCTION()
	bool GetCreativeTurboDelete() const;

	UFUNCTION()
	ECrossplayPreference GetCrossplayPreference() const;

	UFUNCTION()
	bool GetCustomizeKeyboardDiagonals() const;

	UFUNCTION()
	float GetDamageNumbersScale() const;

	UFUNCTION()
	bool GetDeviceFeedbackBlockedWithAttachedController() const;

	UFUNCTION()
	float GetDialogueVolume() const;

	UFUNCTION()
	EGyroButtonResponse GetDisableFunctionX() const;

	UFUNCTION()
	EGyroButtonResponse GetDisableFunctionY() const;

	UFUNCTION()
	bool GetDisablePreEditsWhenPlacingBuilding() const;

	UFUNCTION()
	EDoughnutFillingSetting GetDoughnutFillingSetting() const;

	UFUNCTION()
	EDoughnutPresetSetting GetDoughnutPresetSetting() const;

	UFUNCTION()
	float GetEditButtonHoldTime() const;

	UFUNCTION()
	bool GetEditConfirmOnReleaseEnabled() const;

	UFUNCTION()
	float GetEditingMultiplier() const;

	UFUNCTION()
	bool GetEnableRudderControl() const;

	UFUNCTION()
	bool GetEnableTryBuildOnFocus() const;

	UFUNCTION()
	float GetFlickDeadZone() const;

	UFUNCTION()
	float GetFlickForwardDeadZone() const;

	UFUNCTION()
	bool GetFlickStickEnabled() const;

	UFUNCTION()
	float GetFlickStickSmoothingThreshold() const;

	UFUNCTION()
	float GetFlickStickWindingSpeed() const;

	UFUNCTION()
	float GetFlickTime() const;

	UFUNCTION()
	bool GetFocusOnFirstBuildingPieceWhenQuickbarSwapped() const;

	UFUNCTION()
	bool GetFocusOnFirstBuildingPieceWhenQuickbarSwappedAthena() const;

	UFUNCTION()
	bool GetForceFeedbackEnabled() const;

	UFUNCTION()
	float GetGamepadBuildingMultiplier() const;

	UFUNCTION()
	float GetGamepadEditModeMultiplier() const;

	UFUNCTION()
	float GetGamepadLookSensitivityX() const;

	UFUNCTION()
	float GetGamepadLookSensitivityY() const;

	UFUNCTION()
	float GetGamepadLookStickDeadZone() const;

	UFUNCTION()
	float GetGamepadMoveStickDeadZone() const;

	UFUNCTION()
	float GetGamepadScopedMultiplier() const;

	UFUNCTION()
	float GetGamepadTargetingMultiplier() const;

	UFUNCTION()
	float GetGyroAccelerationMaxThresholdSetting() const;

	UFUNCTION()
	float GetGyroAccelerationMinThresholdSetting() const;

	UFUNCTION()
	EGyroAcceleration GetGyroAccelerationMode() const;

	UFUNCTION()
	EGyroActiveBuildMode GetGyroActiveBuildMode() const;

	UFUNCTION()
	EGyroActiveMode GetGyroActiveMode() const;

	UFUNCTION()
	bool GetGyroAdvancedSettingsEnabled() const;

	UFUNCTION()
	bool GetGyroAimAssist() const;

	UFUNCTION()
	EGyroButton GetGyroButton() const;

	UFUNCTION()
	float GetGyroButtonHoldTimeSetting() const;

	UFUNCTION()
	float GetGyroDeadZone() const;

	UFUNCTION()
	bool GetGyroDisableWhileDrivingSetting() const;

	UFUNCTION()
	float GetGyroLookSensitivitySetting() const;

	UFUNCTION()
	EAxisDirection GetGyroPitchDirection() const;

	UFUNCTION()
	EAxisDirection GetGyroRollDirection() const;

	UFUNCTION()
	float GetGyroSmoothingThresholdSetting() const;

	UFUNCTION()
	float GetGyroSmoothingWindowSetting() const;

	UFUNCTION()
	EGyroSpace GetGyroSpaceAttachedSetting() const;

	UFUNCTION()
	EGyroSpace GetGyroSpaceDetachedSetting() const;

	UFUNCTION()
	float GetGyroSteadyingThresholdSetting() const;

	UFUNCTION()
	EGyroStickMode GetGyroStickMode() const;

	UFUNCTION()
	float GetGyroTighteningThresholdSetting() const;

	UFUNCTION()
	EGyroTouchMode GetGyroTouchMode() const;

	UFUNCTION()
	float GetGyroTrackballDecaySetting() const;

	UFUNCTION()
	float GetGyroV2BuildingSensitivitySetting() const;

	UFUNCTION()
	float GetGyroV2EditingSensitivitySetting() const;

	UFUNCTION()
	float GetGyroV2HarvestingSensitivitySetting() const;

	UFUNCTION()
	float GetGyroV2ScopedSensitivitySetting() const;

	UFUNCTION()
	float GetGyroV2SensitivitySetting() const;

	UFUNCTION()
	float GetGyroV2TargetingSensitivitySetting() const;

	UFUNCTION()
	float GetGyroVerticalMultiplierSetting() const;

	UFUNCTION()
	bool GetGyroVibrationConpensationSetting() const;

	UFUNCTION()
	EAxisDirection GetGyroYawDirection() const;

	UFUNCTION()
	bool GetHasAttendedEvent(const FString& Event) const;

	UFUNCTION()
	int32 GetHiddenMatchmakingDelayMax() const;

	UFUNCTION()
	bool GetHideOtherPlayerNames() const;

	UFUNCTION()
	bool GetHighQualityReplayRecordingEnabled() const;

	UFUNCTION()
	bool GetHighResTexturesReminderEnabled() const;

	UFUNCTION()
	EHitFeedbackMode GetHitFeedbackMode() const;

	UFUNCTION()
	EHitNumbersMode GetHitNumbersMode() const;

	UFUNCTION()
	bool GetHousepartyCastingEnabled() const;

	UFUNCTION()
	float GetHUDScale() const;

	UFUNCTION()
	float GetHUDScaleMultiplier() const;

	UFUNCTION()
	float GetHUDScaleRaw() const;

	UFUNCTION()
	bool GetIgnoreGamepadInput() const;

	UFUNCTION()
	bool GetInvertedPitch() const;

	UFUNCTION()
	bool GetInvertedPitchForAircraftPrimary() const;

	UFUNCTION()
	bool GetInvertedPitchForAircraftSecondary() const;

	UFUNCTION()
	bool GetInvertedPitchForMotion() const;

	UFUNCTION()
	bool GetInvertedYaw() const;

	UFUNCTION()
	bool GetInvertedYawForMotion() const;

	UFUNCTION()
	bool GetIsEasyLootGridEnabled() const;

	UFUNCTION()
	EJoyConMotionSelection GetJoyConMotionSelection() const;

	UFUNCTION()
	float GetKeyboardBackwardDiagonal() const;

	UFUNCTION()
	float GetKeyboardForwardDiagonal() const;

	UFUNCTION()
	float GetKeyboardStrafeDiagonal() const;

	UFUNCTION()
	bool GetLargeTeamReplayRecordingEnabled() const;

	UFUNCTION()
	int32 GetLastSeenHabaneroSeason() const;

	UFUNCTION()
	ELicensedAudioTreatment GetLicensedAudioTreatment(bool bIgnoreGameStreamingCheck) const;

	UFUNCTION()
	ELicensedAudioTreatment GetLicensedAudioTreatmentInternal() const;

	UFUNCTION()
	bool GetLocalNotificationsEnabled() const;

	UFUNCTION()
	bool GetLockPrimaryInputMethodToMouse() const;

	UFUNCTION()
	float GetMasterVolume() const;

	UFUNCTION()
	bool GetMotionControlsEnabledSetting() const;

	UFUNCTION()
	float GetMotionHarvestingToolMultiplier() const;

	UFUNCTION()
	float GetMotionScopedMultiplier() const;

	UFUNCTION()
	float GetMotionTargetingMultiplier() const;

	UFUNCTION()
	EFortMotionYawAxis GetMotionYawAxisSetting() const;

	UFUNCTION()
	float GetMouseSensitivityMultiplierForAircraft() const;

	UFUNCTION()
	float GetMouseSensitivityX() const;

	UFUNCTION()
	float GetMouseSensitivityY() const;

	UFUNCTION()
	float GetMusicVolume() const;

	UFUNCTION()
	int8 GetNumDiscoveryFlowTooltipsRemaining() const;

	UFUNCTION()
	bool GetPeripheralLightingEnabled() const;

	UFUNCTION()
	float GetPIPVolume() const;

	UFUNCTION()
	bool GetPlaceDangerMarkerWhenTargeting() const;

	UFUNCTION()
	bool GetPlayerSurveysAllowed() const;

	UFUNCTION()
	EPostpartyClippingState GetPostpartyClippingState() const;

	UFUNCTION()
	EFortPreferredItemSlotItemType GetPreferredItemTypeSlotIndex_1();

	UFUNCTION()
	EFortPreferredItemSlotItemType GetPreferredItemTypeSlotIndex_2();

	UFUNCTION()
	EFortPreferredItemSlotItemType GetPreferredItemTypeSlotIndex_3();

	UFUNCTION()
	EFortPreferredItemSlotItemType GetPreferredItemTypeSlotIndex_4();

	UFUNCTION()
	EFortPreferredItemSlotItemType GetPreferredItemTypeSlotIndex_5();

	UFUNCTION()
	void GetPreferredSlotIndices(const EFortPreferredItemSlotItemType ItemType, TArray<int32>& OutIndices) const;

	UFUNCTION()
	void GetPreferredSlotIndicesFromDefinition(const UFortWorldItemDefinition* WorldItemDefinition, TArray<int32>& OutIndices) const;

	UFUNCTION()
	bool GetQuickEditEnabled() const;

	UFUNCTION()
	float GetQuickWeaponDelay() const;

	UFUNCTION()
	bool GetQuickWeaponDiamondEnabled() const;

	UFUNCTION()
	bool GetQuickWeaponToggleEnabled() const;

	UFUNCTION()
	EQuickWeaponToggle GetQuickWeaponToggleMode() const;

	UFUNCTION()
	bool GetReleaseToFireEnabledSetting() const;

	UFUNCTION()
	bool GetReplayRecordingEnabled() const;

	UFUNCTION()
	bool GetReplayRecordingIndicatorEnabled() const;

	UFUNCTION()
	bool GetResetConfirmOnReleaseEnabled() const;

	UFUNCTION()
	float GetRudderDeadZone() const;

	UFUNCTION()
	float GetRudderMaxThrottle() const;

	UFUNCTION()
	bool GetScaleSensitivityWithZoom() const;

	UFUNCTION()
	bool GetScaleWindingWithZoom() const;

	UFUNCTION()
	float GetScopedMultiplier() const;

	UFUNCTION()
	bool GetShadowPlayHighlightsEnabled() const;

	UFUNCTION()
	bool GetShouldShowBothQuickbars() const;

	UFUNCTION()
	bool GetShouldShowContentGatingTutorial() const;

	UFUNCTION()
	bool GetShouldShowHabaneroTutorial() const;

	UFUNCTION()
	bool GetShouldToggleSprint() const;

	UFUNCTION()
	bool GetShowGlobalChatEnabled() const;

	UFUNCTION()
	EFortRarity GetShowPickupDotsOnMapByRarity() const;

	UFUNCTION()
	bool GetShowSeasonLevel() const;

	UFUNCTION()
	bool GetShowTemperature() const;

	UFUNCTION()
	bool GetShowViewerCountEnabled() const;

	UFUNCTION()
	bool GetShowVoiceIndicators() const;

	UFUNCTION()
	float GetSlideButtonHoldTime() const;

	UFUNCTION()
	bool GetSmartBuildEnabled() const;

	UFUNCTION()
	float GetSoundFXVolume() const;

	UFUNCTION()
	ESubtitleDisplayBackgroundOpacity GetSubtitlesBackgroundOpacity() const;

	UFUNCTION()
	bool GetSubtitlesEnabled() const;

	UFUNCTION()
	ESubtitleDisplayTextBorder GetSubtitlesTextBorder() const;

	UFUNCTION()
	ESubtitleDisplayTextColor GetSubtitlesTextColor() const;

	UFUNCTION()
	ESubtitleDisplayTextSize GetSubtitlesTextSize() const;

	UFUNCTION()
	bool GetTankGamepadCameraControls() const;

	UFUNCTION()
	bool GetTankKBMCameraControls() const;

	UFUNCTION()
	bool GetTapInteract() const;

	UFUNCTION()
	float GetTargetingMultiplier() const;

	UFUNCTION()
	bool GetTargetingToggleable() const;

	UFUNCTION()
	bool GetTargetingToggleableWithTouch() const;

	UFUNCTION()
	bool GetTargetTypeIndicatorVisible() const;

	UFUNCTION()
	bool GetToggleDoubleTapAutorunMobile() const;

	UFUNCTION()
	bool GetToggleSprint() const;

	UFUNCTION()
	float GetTouchBuildingMultiplier() const;

	UFUNCTION()
	bool GetTouchEditEnabled() const;

	UFUNCTION()
	float GetTouchEditModeMultiplier() const;

	UFUNCTION()
	ETouchInteractMode GetTouchInteractionMode() const;

	UFUNCTION()
	float GetTouchLookAccelerationMultiplier() const;

	UFUNCTION()
	float GetTouchLookSensitivitySetting() const;

	UFUNCTION()
	float GetTouchScopedMultiplier() const;

	UFUNCTION()
	float GetTouchTargetingMultiplier() const;

	UFUNCTION()
	float GetTouchVerticalMultiplier() const;

	UFUNCTION()
	bool GetTriggerHapticsEnabled() const;

	UFUNCTION()
	uint8 GetTriggerHapticsStartPosition() const;

	UFUNCTION()
	uint8 GetTriggerHapticsStrength() const;

	UFUNCTION()
	bool GetTriggerHapticsUseThreshold() const;

	UFUNCTION()
	bool GetTurboBuild() const;

	UFUNCTION()
	bool GetUseFirstPersonCamera() const;

	UFUNCTION()
	bool GetUsePowerSavingMode() const;

	UFUNCTION()
	EVisualizeAudioPriority GetVisualizeAudioPriority() const;

	UFUNCTION()
	bool GetVisualizeAudioSources() const;

	UFUNCTION()
	bool GetVoiceChat3DEnabled() const;

	UFUNCTION()
	bool GetVoiceChatEnabled() const;

	UFUNCTION()
	const EFortVoiceChatMethod GetVoiceChatMethod() const;

	UFUNCTION()
	ESocialCommsPermission GetVoiceChatParentalRestriction() const;

	UFUNCTION()
	bool GetVoiceChatPTTEnabled() const;

	UFUNCTION()
	ESocialCommsPermission GetVoiceChatSettings() const;

	UFUNCTION()
	bool HasSeenSubscriptionNotification(const FName& NotificationID) const;

	UFUNCTION()
	bool IsPreferredItemSlotsEnabled() const;

	UFUNCTION()
	bool IsUsingAutoCenter() const;

	UFUNCTION()
	bool IsUsingFollowCamera() const;

	UFUNCTION()
	bool IsUsingGamepadAutoRun() const;

	UFUNCTION()
	bool IsUsingGamepadEditModeAimAssist() const;

	UFUNCTION()
	bool IsUsingHoldToSwapPickup() const;

	UFUNCTION()
	void SetAccelerationMultiplierSetting(float InSetting);

	UFUNCTION()
	void SetAimAssistEnabled(const bool bNewValue);

	UFUNCTION()
	void SetAimAssistStrength(uint32 NewValue);

	UFUNCTION()
	void SetAllowAudioInBackgroundSetting(EFortAllowBackgroundAudioSetting Value);

	UFUNCTION()
	void SetAllowSidekickFeature1(bool bNewValue);

	UFUNCTION()
	void SetAndApplyAutoPickupWeapons(const bool bNewValue);

	UFUNCTION()
	void SetAnonymousCharacterModeEnabled(bool bEnable);

	UFUNCTION()
	void SetAnonymousModeEnabled(bool bEnable);

	UFUNCTION(Exec)
	void SetAperture(float InAperture);

	UFUNCTION(Exec)
	void SetArrowColorEnabled(bool bInArrowColorEnabled);

	UFUNCTION(Exec)
	void SetArrowDistance(float InArrowDistance);

	UFUNCTION(Exec)
	void SetArrowScaleMax(float InArrowScaleMax);

	UFUNCTION(Exec)
	void SetArrowScaleMin(float InArrowDetailScaleMin);

	UFUNCTION()
	void SetAttendingSocialEvent(int32 EventId, bool bAttending);

	UFUNCTION()
	void SetAutoChangeMaterial(const bool bNewValue);

	UFUNCTION()
	void SetAutoClamber(const bool bNewValue);

	UFUNCTION()
	void SetAutoEquipBetterItems(bool bAutoEquip);

	UFUNCTION(Exec)
	void SetAutoExposureEnabled(bool bInAutoExposureEnabled);

	UFUNCTION(Exec)
	void SetAutoFocusEnabled(bool bInAutoFocusEnabled);

	UFUNCTION()
	void SetAutoHideBuildingMaterials(bool InAutoHideBuildingMats);

	UFUNCTION()
	void SetAutoHurdle(const bool bNewValue);

	UFUNCTION()
	void SetAutoJoinGameVoiceChannel(bool bNewValue);

	UFUNCTION()
	void SetAutoMulchMode(EFortAutoMulchCategory Category, EFortAutoMulchMode NewMode);

	UFUNCTION()
	void SetAutoOpenDoors(const bool bNewValue);

	UFUNCTION()
	void SetAutoPickupWeapons(const bool bNewValue);

	UFUNCTION()
	void SetAutoPickupWeaponsConsolePC(const bool bNewValue);

	UFUNCTION()
	void SetAutorunLockZonePreferenceMobile(EAutorunLockZonePreferenceMobile AutorunLockZonePreference);

	UFUNCTION()
	void SetAutoSortConsumablesToRight(const bool bNewValue);

	UFUNCTION(Exec)
	void SetBattleMapAutomaticCameraPlacement(bool bInBattleMapAutomaticCameraPlacement);

	UFUNCTION(Exec)
	void SetBattleMapShowAllSquadMembers(bool bInBattleMapShowAllSquadMembers);

	UFUNCTION(Exec)
	void SetBattleMapShowNearbyChests(bool bInBattleMapShowNearbyChests);

	UFUNCTION(Exec)
	void SetBattleMapShowTimeIndicator(bool bInBattleMapShowTimeIndicator);

	UFUNCTION()
	void SetBrelmarCameraShake(EBrelmarCameraShake Value);

	UFUNCTION()
	void SetBrunoReplayRecordingEnabled(bool bEnable);

	UFUNCTION()
	void SetBuildingMultiplier(float InMultiplier);

	UFUNCTION()
	void SetBuildingPossessionShown(bool bShown);

	UFUNCTION()
	void SetCameraResetAxes(const ECameraResetAxes NewValue);

	UFUNCTION()
	void SetCameraResetTime(const float NewValue);

	UFUNCTION()
	void SetChatVolume(float InVolume);

	UFUNCTION()
	void SetCinematicsVolume(float InVolume);

	UFUNCTION()
	void SetClippingEnabled(bool Value);

	UFUNCTION()
	void SetClipRemindersEnabled(bool Value);

	UFUNCTION()
	void SetColorBlindMode(EColorBlindMode InMode);

	UFUNCTION()
	void SetColorBlindStrength(int32 InColorBlindStrength);

	UFUNCTION()
	void SetCombinedADSFireModeSetting(ECombinedADSFireMode InSetting);

	UFUNCTION()
	void SetCombinedConfirmEditResetEnabled(EEditAutoConfirmation NewAutoConfirmEditMode);

	UFUNCTION()
	void SetConsoleFPSUnlocked(bool bNewValue);

	UFUNCTION()
	void SetContextTutorialEnabled(bool bEnabled);

	UFUNCTION()
	void SetContinuousFireEnabledSetting(bool bInSetting);

	UFUNCTION()
	void SetCreativeModeReplayRecordingEnabled(bool bEnabled);

	UFUNCTION()
	void SetCreativeTurboDelete(const bool bNewValue);

	UFUNCTION()
	void SetCrossplayPreference(ECrossplayPreference NewPreference);

	UFUNCTION()
	void SetCustomizeKeyboardDiagonals(bool InEnabled);

	UFUNCTION(Exec)
	void SetDamageFxEnabled(bool bInDamageFxEnabled);

	UFUNCTION()
	void SetDamageNumbersScale(float InScale);

	UFUNCTION()
	void SetDeviceFeedbackBlockedWithAttachedController(bool bForceFeedbackBlocked);

	UFUNCTION()
	void SetDialogueVolume(float InVolume);

	UFUNCTION()
	void SetDisableFunctionX(EGyroButtonResponse InSetting);

	UFUNCTION()
	void SetDisableFunctionY(EGyroButtonResponse InSetting);

	UFUNCTION()
	void SetDisablePreEditsWhenPlacingBuilding(bool InDisablePreEditsWhenPlacingBuilding);

	UFUNCTION(Exec)
	void SetDisplaySessionRank(bool bDisplaySessionRank);

	UFUNCTION()
	void SetDoughnutFillingSetting(EDoughnutFillingSetting Value);

	UFUNCTION()
	void SetDoughnutPresetSetting(EDoughnutPresetSetting Value);

	UFUNCTION(Exec)
	void SetDroneIgnoreJump(bool bInDroneIgnoreJump);

	UFUNCTION()
	void SetEditButtonHoldTime(const float NewValue);

	UFUNCTION()
	void SetEditConfirmOnReleaseEnabled(bool bNewEditConfirmOnRelease);

	UFUNCTION()
	void SetEditingMultiplier(float InMultiplier);

	UFUNCTION()
	void SetEnablePreferredItemSlots(const bool bNewValue);

	UFUNCTION()
	void SetEnableRudderControl(bool bEnable);

	UFUNCTION()
	void SetEnableTryBuildOnFocus(const bool bNewValue);

	UFUNCTION(Exec)
	void SetFirstPlaceHighlightEnabled(bool bInFirstPlaceHighlightEnabled);

	UFUNCTION()
	void SetFlickDeadZone(float InSetting);

	UFUNCTION()
	void SetFlickForwardDeadZone(float InSetting);

	UFUNCTION()
	void SetFlickStickEnabled(bool InSetting);

	UFUNCTION()
	void SetFlickStickSmoothingThreshold(float InSetting);

	UFUNCTION()
	void SetFlickStickWindingSpeed(float InSetting);

	UFUNCTION()
	void SetFlickTime(float InSetting);

	UFUNCTION(Exec)
	void SetFocalLength(float InFocalLength);

	UFUNCTION()
	void SetFocusOnFirstBuildingPieceWhenQuickbarSwapped(bool InFocusOnFirstBuildingPieceWhenQuickbarSwapped);

	UFUNCTION()
	void SetFocusOnFirstBuildingPieceWhenQuickbarSwappedAthena(bool InFocusOnFirstBuildingPieceWhenQuickbarSwapped);

	UFUNCTION()
	void SetForceFeedbackEnabled(bool bForceFeedback);

	UFUNCTION()
	void SetGamepadBuildingMultiplier(float InMultiplier);

	UFUNCTION()
	void SetGamepadEditModeMultiplier(float InMultiplier);

	UFUNCTION()
	void SetGamepadLookSensitivityX(float InSensitivity);

	UFUNCTION()
	void SetGamepadLookSensitivityY(float InSensitivity);

	UFUNCTION()
	void SetGamepadLookStickDeadZone(const float NewValue);

	UFUNCTION()
	void SetGamepadMoveStickDeadZone(const float NewValue);

	UFUNCTION()
	void SetGamepadScopedMultiplier(float InMultiplier);

	UFUNCTION()
	void SetGamepadTargetingMultiplier(float InMultiplier);

	UFUNCTION()
	void SetGyroAccelerationMaxThresholdSetting(float InSetting);

	UFUNCTION()
	void SetGyroAccelerationMinThresholdSetting(float InSetting);

	UFUNCTION()
	void SetGyroAccelerationMode(EGyroAcceleration InSetting);

	UFUNCTION()
	void SetGyroActiveBuildMode(EGyroActiveBuildMode InSetting);

	UFUNCTION()
	void SetGyroActiveMode(EGyroActiveMode InSetting);

	UFUNCTION()
	void SetGyroAdvancedSettingsEnabled(bool InSetting);

	UFUNCTION()
	void SetGyroAimAssist(bool InSetting);

	UFUNCTION()
	void SetGyroButton(const EGyroButton InSetting);

	UFUNCTION()
	void SetGyroButtonHoldTimeSetting(float InSetting);

	UFUNCTION()
	void SetGyroDeadZone(float InSetting);

	UFUNCTION()
	void SetGyroDisableWhileDrivingSetting(bool InSetting);

	UFUNCTION()
	void SetGyroLookSensitivitySetting(float InSetting);

	UFUNCTION()
	void SetGyroPitchDirection(EAxisDirection InSetting);

	UFUNCTION()
	void SetGyroRollDirection(EAxisDirection InSetting);

	UFUNCTION()
	void SetGyroSmoothingThresholdSetting(float InSetting);

	UFUNCTION()
	void SetGyroSmoothingWindowSetting(float InSetting);

	UFUNCTION()
	void SetGyroSpaceAttachedSetting(EGyroSpace InSetting);

	UFUNCTION()
	void SetGyroSpaceDetachedSetting(EGyroSpace InSetting);

	UFUNCTION()
	void SetGyroSteadyingThresholdSetting(float InSetting);

	UFUNCTION()
	void SetGyroStickMode(EGyroStickMode InSetting);

	UFUNCTION()
	void SetGyroTighteningThresholdSetting(float InSetting);

	UFUNCTION()
	void SetGyroTouchMode(EGyroTouchMode InSetting);

	UFUNCTION()
	void SetGyroTrackballDecaySetting(float InSetting);

	UFUNCTION()
	void SetGyroV2BuildingSensitivitySetting(float InSetting);

	UFUNCTION()
	void SetGyroV2EditingSensitivitySetting(float InSetting);

	UFUNCTION()
	void SetGyroV2HarvestingSensitivitySetting(float InSetting);

	UFUNCTION()
	void SetGyroV2ScopedSensitivitySetting(float InSetting);

	UFUNCTION()
	void SetGyroV2SensitivitySetting(float InSetting);

	UFUNCTION()
	void SetGyroV2TargetingSensitivitySetting(float InSetting);

	UFUNCTION()
	void SetGyroVerticalMultiplierSetting(float InSetting);

	UFUNCTION()
	void SetGyroVibrationConpensationSetting(bool InSetting);

	UFUNCTION()
	void SetGyroYawDirection(EAxisDirection InSetting);

	UFUNCTION()
	void SetHasAttendedEvent(const FString& Event);

	UFUNCTION()
	void SetHiddenMatchmakingDelayMax(int32 Value);

	UFUNCTION()
	void SetHideOtherPlayerNames(bool bEnable);

	UFUNCTION(Exec)
	void SetHighDetailScaleMax(float InHighDetailScaleMax);

	UFUNCTION(Exec)
	void SetHighDetailScaleMin(float InHighDetailScaleMin);

	UFUNCTION(Exec)
	void SetHighQualityFxEnabled(bool bInHighQualityFxEnabled);

	UFUNCTION()
	void SetHighQualityReplayRecordingEnabled(bool bEnable);

	UFUNCTION()
	void SetHighResTexturesReminderEnabled(bool bEnable);

	UFUNCTION()
	void SetHitFeedbackMode(EHitFeedbackMode NewMode);

	UFUNCTION()
	void SetHitNumbersMode(EHitNumbersMode NewMode);

	UFUNCTION()
	void SetHousepartyCastingEnabled(bool bEnable);

	UFUNCTION()
	void SetHUDScale(float InScale);

	UFUNCTION()
	void SetHUDScaleMultiplier(float InHUDScaleMultiplier);

	UFUNCTION()
	void SetIgnoreGamepadInput(bool bIgnore);

	UFUNCTION()
	void SetInstantBoostWhenBuilding(bool NewValue);

	UFUNCTION()
	void SetInvertedPitch(bool bInvert);

	UFUNCTION()
	void SetInvertedPitchForAircraftPrimary(bool bInvert);

	UFUNCTION()
	void SetInvertedPitchForAircraftSecondary(bool bInvert);

	UFUNCTION()
	void SetInvertedPitchForMotion(bool bInvert);

	UFUNCTION()
	void SetInvertedYaw(bool bInvert);

	UFUNCTION()
	void SetInvertedYawForMotion(bool bInvert);

	UFUNCTION()
	void SetIsEasyLootGridEnabled(bool bNewValue);

	UFUNCTION()
	void SetJoyConMotionSelection(EJoyConMotionSelection InSetting);

	UFUNCTION()
	void SetKeyboardBackwardDiagonal(float InAngle);

	UFUNCTION()
	void SetKeyboardForwardDiagonal(float InAngle);

	UFUNCTION()
	void SetKeyboardStrafeDiagonal(float InAngle);

	UFUNCTION()
	void SetLargeTeamReplayRecordingEnabled(bool bEnable);

	UFUNCTION()
	void SetLastSeenHabaneroSeason(int32 InLastSeenSeason);

	UFUNCTION()
	void SetLicensedAudioTreatment(ELicensedAudioTreatment InLicensedAudioTreatment);

	UFUNCTION()
	void SetLocalNotificationsEnabled(bool bEnabled);

	UFUNCTION()
	void SetLockPrimaryInputMethodToMouse(bool bLock);

	UFUNCTION()
	void SetLookBoostAccelerationTime(float NewValue);

	UFUNCTION()
	void SetLookBoostAccelerationTimeAds(float NewValue);

	UFUNCTION()
	void SetLookBuildModeMultiplier(float NewValue);

	UFUNCTION()
	void SetLookEaseTime(float NewValue);

	UFUNCTION()
	void SetLookEditModeMultiplier(float NewValue);

	UFUNCTION()
	void SetLookHorizontalBoostSpeed(uint32 NewValue);

	UFUNCTION()
	void SetLookHorizontalBoostSpeedAds(uint32 NewValue);

	UFUNCTION()
	void SetLookHorizontalSpeed(uint32 NewValue);

	UFUNCTION()
	void SetLookHorizontalSpeedAds(uint32 NewValue);

	UFUNCTION()
	void SetLookInputCurve(EFortGamepadLookInputCurve NewValue);

	UFUNCTION()
	void SetLookSensitivityPreset(EFortGamepadSensitivity NewPreset);

	UFUNCTION()
	void SetLookSensitivityPresetAds(EFortGamepadSensitivity NewPreset);

	UFUNCTION()
	void SetLookVerticalBoostSpeed(uint32 NewValue);

	UFUNCTION()
	void SetLookVerticalBoostSpeedAds(uint32 NewValue);

	UFUNCTION()
	void SetLookVerticalSpeed(uint32 NewValue);

	UFUNCTION()
	void SetLookVerticalSpeedAds(uint32 NewValue);

	UFUNCTION(Exec)
	void SetLowDetailDistance(float InLowDetailDistance);

	UFUNCTION(Exec)
	void SetLowDetailScaleMax(float InLowDetailScaleMax);

	UFUNCTION(Exec)
	void SetLowDetailScaleMin(float InLowDetailScaleMin);

	UFUNCTION(Exec)
	void SetManualExposureBias(float InManualExposureBias);

	UFUNCTION(Exec)
	void SetManualFocusDistance(float InManualFocusDistance);

	UFUNCTION()
	void SetMasterVolume(float InVolume);

	UFUNCTION()
	void SetMotionControlsEnabledSetting(bool InSetting);

	UFUNCTION()
	void SetMotionHarvestingToolMultiplier(float InMultiplier);

	UFUNCTION()
	void SetMotionScopedMultiplier(float InMultiplier);

	UFUNCTION()
	void SetMotionTargetingMultiplier(float InMultiplier);

	UFUNCTION()
	void SetMotionYawAxisSetting(EFortMotionYawAxis InSetting);

	UFUNCTION()
	void SetMouseSensitivityMultiplierForAircraft(float InSensitivityMultiplier);

	UFUNCTION()
	void SetMouseSensitivityX(float InSensitivityX);

	UFUNCTION()
	void SetMouseSensitivityY(float InSensitivityY);

	UFUNCTION()
	void SetMoveStickAcceleratesVehicles(const bool InSetting);

	UFUNCTION()
	void SetMusicVolume(float InVolume);

	UFUNCTION(Exec)
	void SetNameplatesEnabled(bool bInNameplatesEnabled);

	UFUNCTION()
	void SetNotifyUsersWhenPlaying(const bool Value);

	UFUNCTION()
	void SetNumDiscoveryFlowTooltipsRemaining(int8 InRemaining);

	UFUNCTION()
	void SetPeripheralLightingEnabled(bool bEnable);

	UFUNCTION()
	void SetPIPVolume(float InVolume);

	UFUNCTION()
	void SetPlaceDangerMarkerWhenTargeting(bool bEnable);

	UFUNCTION(Exec)
	void SetPlayerOutlinesEnabled(bool bInPlayerOutlinesEnabled);

	UFUNCTION()
	void SetPlayerSurveysAllowed(bool Value);

	UFUNCTION()
	void SetPreferredItemTypeSlotIndex_1(const EFortPreferredItemSlotItemType ItemType);

	UFUNCTION()
	void SetPreferredItemTypeSlotIndex_2(const EFortPreferredItemSlotItemType ItemType);

	UFUNCTION()
	void SetPreferredItemTypeSlotIndex_3(const EFortPreferredItemSlotItemType ItemType);

	UFUNCTION()
	void SetPreferredItemTypeSlotIndex_4(const EFortPreferredItemSlotItemType ItemType);

	UFUNCTION()
	void SetPreferredItemTypeSlotIndex_5(const EFortPreferredItemSlotItemType ItemType);

	UFUNCTION()
	void SetQuickEditEnabled(bool bNewQuickEditEnabled);

	UFUNCTION()
	void SetQuickWeaponDelay(float NewQuickWeaponDelay);

	UFUNCTION()
	void SetQuickWeaponToggleEnabled(bool bQuickWeaponEnabled);

	UFUNCTION()
	void SetQuickWeaponToggleMode(EQuickWeaponToggle NewToggleMode);

	UFUNCTION()
	void SetReleaseToFireEnabledSetting(bool bInSetting);

	UFUNCTION(Exec)
	void SetRelevancyZoneVisible(bool bInRelevancyZoneVisible);

	UFUNCTION()
	void SetReplayRecordingEnabled(bool bEnable);

	UFUNCTION()
	void SetReplayRecordingIndicatorEnabled(bool bEnabled);

	UFUNCTION()
	void SetResetConfirmOnReleaseEnabled(bool bNewResetConfirmOnRelease);

	UFUNCTION()
	void SetRudderDeadZone(float NewValue);

	UFUNCTION()
	void SetRudderMaxThrottle(float NewValue);

	UFUNCTION(Exec)
	void SetSafeZoneOpacity(float InSafeZoneOpacity);

	UFUNCTION()
	void SetScaleSensitivityWithZoom(bool InSetting);

	UFUNCTION()
	void SetScaleWindingWithZoom(bool InSetting);

	UFUNCTION(Exec)
	void SetScalingOptionsEnabled(bool bInScalingOptionsEnabled);

	UFUNCTION()
	void SetScopedMultiplier(float InMultiplier);

	UFUNCTION()
	void SetShadowPlayHighlightsEnabled(bool bEnable);

	UFUNCTION(Exec)
	void SetShareLensSettings(bool bInShareLensSettings);

	UFUNCTION()
	void SetShouldShowBothQuickbars(bool bNewValue);

	UFUNCTION()
	void SetShouldShowContentGatingTutorial(const bool bShowTutorial);

	UFUNCTION()
	void SetShouldShowHabaneroTutorial(bool bNewValue);

	UFUNCTION()
	void SetShowGlobalChatEnabled(bool bEnable);

	UFUNCTION()
	void SetShowPickupDotsOnMapByRarity(EFortRarity InRarity);

	UFUNCTION()
	void SetShowSeasonLevel(bool bEnable);

	UFUNCTION(Exec)
	void SetShowSessionIDWatermark(bool bInSessionIDWatermark);

	UFUNCTION(Exec)
	void SetShowTeamColor(bool bInShowTeamColor);

	UFUNCTION()
	void SetShowTemperature(bool bNewValue);

	UFUNCTION()
	void SetShowViewerCountEnabled(bool bEnable);

	UFUNCTION()
	void SetShowVoiceIndicators(bool bNewValue);

	UFUNCTION()
	void SetSlideButtonHoldTime(const float NewValue);

	UFUNCTION()
	void SetSmartBuildEnabled(bool bNewSmartBuildEnabled);

	UFUNCTION()
	void SetSoundFXVolume(float InVolume);

	UFUNCTION(Exec)
	void SetSquadIdMode(ESpectatorSquadIdMode InSquadIdMode);

	UFUNCTION(Exec)
	void SetStormEffectsEnabled(bool bInStormEffectsEnabled);

	UFUNCTION()
	void SetSubtitlesBackgroundOpacity(ESubtitleDisplayBackgroundOpacity Value);

	UFUNCTION()
	void SetSubtitlesEnabled(bool Value);

	UFUNCTION()
	void SetSubtitlesTextBorder(ESubtitleDisplayTextBorder Value);

	UFUNCTION()
	void SetSubtitlesTextColor(ESubtitleDisplayTextColor Value);

	UFUNCTION()
	void SetSubtitlesTextSize(ESubtitleDisplayTextSize Value);

	UFUNCTION()
	void SetTankGamepadCameraControls(bool bInTankGamepadCameraControls);

	UFUNCTION()
	void SetTankKBMCameraControls(bool bInTankKBMCameraControls);

	UFUNCTION()
	void SetTapInteract(bool bTapInteract);

	UFUNCTION()
	void SetTargetingMultiplier(float InMultiplier);

	UFUNCTION()
	void SetTargetingToggleable(bool bToggle);

	UFUNCTION()
	void SetTargetingToggleableWithTouch(bool bToggle);

	UFUNCTION()
	void SetTargetTypeIndicatorVisible(bool bNewValue);

	UFUNCTION(Exec)
	void SetThirdPersonAutoFollowMode(EThirdPersonAutoFollowMode InThirdPersonAutoFollowMode);

	UFUNCTION(Exec)
	void SetThirdPersonCameraCollision(bool bInThirdPersonCameraCollision);

	UFUNCTION(Exec)
	void SetThirdPersonDistanceToSubject(float InThirdPersonDistanceToSubject);

	UFUNCTION()
	void SetToggleDoubleTapAutorunMobile(bool bToggle);

	UFUNCTION()
	void SetToggleSprint(bool bToggle);

	UFUNCTION()
	void SetTouchBuildingMultiplier(float InMultiplier);

	UFUNCTION()
	void SetTouchEditEnabled(bool bTouchEdit);

	UFUNCTION()
	void SetTouchEditModeMultiplier(float InMultiplier);

	UFUNCTION()
	void SetTouchInteractMode(const ETouchInteractMode bNewMode);

	UFUNCTION()
	void SetTouchLookAccelerationMultiplier(float InSetting);

	UFUNCTION()
	void SetTouchLookSensitivitySetting(float InSetting);

	UFUNCTION()
	void SetTouchScopedMultiplier(float InMultiplier);

	UFUNCTION()
	void SetTouchTargetingMultiplier(float InMultiplier);

	UFUNCTION()
	void SetTouchVerticalMultiplier(float InMultiplier);

	UFUNCTION()
	void SetTriggerHapticsEnabled(bool bNewTriggerHapticsEnabled);

	UFUNCTION()
	void SetTriggerHapticsStartPosition(uint8 NewTriggerHapticStartPosition);

	UFUNCTION()
	void SetTriggerHapticsStrength(uint8 NewTriggerHapticStrength);

	UFUNCTION()
	void SetTriggerHapticsUseThreshold(bool bNewTriggerPullUsesHapticThreshold);

	UFUNCTION()
	void SetTurboBuild(const bool bNewValue);

	UFUNCTION()
	void SetUseAdvancedOptions(bool NewUseAdvancedOptions);

	UFUNCTION()
	void SetUseAutoCenter(bool InbUseAutoCenter);

	UFUNCTION()
	void SetUseFirstPersonCamera(bool bUseFirstPerson);

	UFUNCTION()
	void SetUseFollowCamera(bool InbUseFollowCamera);

	UFUNCTION()
	void SetUseGamepadAutoRun(bool InUseGamepadAutoRun);

	UFUNCTION()
	void SetUseGamepadEditModeAimAssist(bool InUseGamepadEditModeAimAssist);

	UFUNCTION()
	void SetUseHoldToSwapPickup(bool InUseHoldToSwapPickup);

	UFUNCTION()
	void SetUseLegacyControls(bool NewUseLegacyControls);

	UFUNCTION()
	void SetUsePowerSavingMode(bool bNewUsePowerSavingMode);

	UFUNCTION(Exec)
	void SetViewDistance(float InViewDistance);

	UFUNCTION()
	void SetVisualizeAudioPriority(const EVisualizeAudioPriority AudioPriority);

	UFUNCTION()
	void SetVisualizeAudioSources(bool bEnable);

	UFUNCTION()
	void SetVoiceChat3DEnabled(bool bEnable);

	UFUNCTION()
	void SetVoiceChatPTTEnabled(bool bEnable);

	UFUNCTION()
	void SetVoiceChatSettings(ESocialCommsPermission InSetting);

	UPROPERTY(Transient)
	FFortGamepadUserOptions LocalGamepadUserOptions;

	UPROPERTY()
	bool bHighResTexturesReminderEnabled;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UEnhancedInputUserSettings> InputUserSettings;

	UPROPERTY()
	float HUDScale;

	UPROPERTY()
	float InitialHUDScale;

	UPROPERTY()
	bool bAutoHideBuildingMaterials;

	UPROPERTY()
	EFortRarity ShowPickupDotsOnMapByRarity;

	UPROPERTY()
	FFortGamepadUserOptions GamepadUserOptions;

	UPROPERTY()
	FVector2D GamepadLookSensitivity;

	UPROPERTY()
	float GamepadMoveStickDeadZone;

	UPROPERTY()
	float GamepadLookStickDeadZone;

	UPROPERTY()
	bool bCustomKeyboardDiagonals;

	UPROPERTY()
	float KeyboardForwardDiagonal;

	UPROPERTY()
	float KeyboardStrafeDiagonal;

	UPROPERTY()
	float KeyboardBackwardDiagonal;

	UPROPERTY()
	float TargetingSlow;

	UPROPERTY()
	float ScopedSlow;

	UPROPERTY()
	float BuildingMultiplier;

	UPROPERTY()
	float EditingMultiplier;

	UPROPERTY()
	float GamepadTargetingSlow;

	UPROPERTY()
	float GamepadScopedSlow;

	UPROPERTY()
	float GamepadBuildingMultiplier;

	UPROPERTY()
	float GamepadEditModeMultiplier;

	UPROPERTY()
	float MotionTargetingSlow;

	UPROPERTY()
	float MotionScopedSlow;

	UPROPERTY()
	float MotionHarvestingToolSlow;

	UPROPERTY()
	float MouseSensitivity;

	UPROPERTY()
	float MouseSensitivityX;

	UPROPERTY()
	float MouseSensitivityY;

	UPROPERTY()
	float MouseSensitivityMultiplierForAircraftValue;

	UPROPERTY()
	float InitialMouseSensitivityMultiplierForAircraft;

	UPROPERTY()
	float TouchLookAccelerationMultiplier;

	UPROPERTY()
	float TouchLookSensitivitySetting;

	UPROPERTY()
	float TouchTargetingSlow;

	UPROPERTY()
	float TouchScopedSlow;

	UPROPERTY()
	float TouchBuildingMultiplier;

	UPROPERTY()
	float TouchEditModeMultiplier;

	UPROPERTY()
	float TouchVerticalMultiplier;

	UPROPERTY()
	ECombinedADSFireMode TouchWeaponCombinedADSFireMode;

	UPROPERTY()
	bool bTouchWeaponReleaseToFireEnabled;

	UPROPERTY()
	bool bTouchWeaponContinuousFireEnabled;

	UPROPERTY()
	bool bMotionControlsEnabled;

	UPROPERTY()
	EFortMotionYawAxis MotionYawAxis;

	UPROPERTY()
	EFortMotionYawAxis MotionYawAxisMobile;

	UPROPERTY()
	EGyroSpace GyroSpaceAttached;

	UPROPERTY()
	EGyroSpace GyroSpaceDetached;

	UPROPERTY()
	EAxisDirection GyroV2YawDirection;

	UPROPERTY()
	EAxisDirection GyroV2PitchDirection;

	UPROPERTY()
	EAxisDirection GyroV2RollDirection;

	UPROPERTY()
	bool bGyroAdvancedSettingsEnabled;

	UPROPERTY()
	bool bGyroUseZoomSensitivityScaling;

	UPROPERTY()
	EGyroAcceleration GyroAccelerationMode;

	UPROPERTY()
	float GyroSensitivity;

	UPROPERTY()
	float GyroV2Sensitivity;

	UPROPERTY()
	float GyroV2TargetingMultiplier;

	UPROPERTY()
	float GyroV2ScopedMultiplier;

	UPROPERTY()
	float GyroV2HarvestingMultiplier;

	UPROPERTY()
	float GyroV2BuildingMultiplier;

	UPROPERTY()
	float GyroV2EditingMultiplier;

	UPROPERTY()
	EGyroActiveMode GyroActiveMode;

	UPROPERTY()
	EGyroActiveBuildMode GyroActiveBuildMode;

	UPROPERTY()
	EGyroStickMode GyroStickMode;

	UPROPERTY()
	EGyroTouchMode GyroTouchMode;

	UPROPERTY()
	EGyroButton GyroButton;

	UPROPERTY()
	bool GyroStickDisables;

	UPROPERTY()
	bool GyroAimAssist;

	UPROPERTY()
	EJoyConMotionSelection JoyConMotionSelection;

	UPROPERTY()
	EGyroButtonResponse GyroButtonModeX;

	UPROPERTY()
	EGyroButtonResponse GyroButtonModeY;

	UPROPERTY()
	float GyroAccelerationMultiplier;

	UPROPERTY()
	float GyroAccelerationMinThreshold;

	UPROPERTY()
	float GyroAccelerationMaxThreshold;

	UPROPERTY()
	float GyroVerticalMultiplier;

	UPROPERTY()
	float GyroSteadyingThreshold;

	UPROPERTY()
	float GyroSmoothingThreshold;

	UPROPERTY()
	float GyroSmoothingWindow;

	UPROPERTY()
	float GyroDeadZone;

	UPROPERTY()
	float GyroTighteningThreshold;

	UPROPERTY()
	float GyroTrackballDecay;

	UPROPERTY()
	float GyroButtonHoldTime;

	UPROPERTY()
	bool bGyroDisabledWhileDriving;

	UPROPERTY()
	bool bGyroVibrationConpensation;

	UPROPERTY()
	FString ControllerPlatform;

	UPROPERTY()
	FString InputKBMPresetNameForCampaign;

	UPROPERTY()
	FString InputKBMPresetNameForAthena;

	UPROPERTY()
	FString InputPresetNameForCampaign;

	UPROPERTY()
	FString InputPresetNameForAthena;

	UPROPERTY()
	FString InputPresetNameForAthenaMobile;

	UPROPERTY()
	FString InputTemplatePresetNameForCampaign;

	UPROPERTY()
	FString InputTemplatePresetNameForAthena;

	UPROPERTY()
	float XboxSafeZone;

	UPROPERTY(Transient)
	FString PendingCulture;

	UPROPERTY()
	TArray<FFortActionKeyMapping> UserActionBindings;

	UPROPERTY()
	TMap<ESubGame, FUserActionBindings> UserBindingsPerSubGame;

	UPROPERTY()
	TArray<FFortActionKeyMapping> DisabledActionBindings;

	UPROPERTY()
	TArray<FFortActionKeyMapping> CustomGamepadActionBindings;

	UPROPERTY()
	TMap<FName, FFortUserInputSettingsPerMode> UserInputSettingsPerMode;

	UPROPERTY(Transient)
	FName InputConfigName;

	UPROPERTY()
	bool bInvertedLook;

	UPROPERTY()
	bool bInvertedLookMobile;

	UPROPERTY()
	bool bInvertedPitchForMotion;

	UPROPERTY()
	bool bInvertedPitchForAircraftPrimary;

	UPROPERTY()
	bool bInvertedPitchForAircraftSecondary;

	UPROPERTY()
	bool bInvertedYaw;

	UPROPERTY()
	bool bInvertedYawMobile;

	UPROPERTY()
	bool bInvertedYawForMotion;

	UPROPERTY()
	bool bTankKBMCameraControls;

	UPROPERTY()
	bool bTankGamepadCameraControls;

	UPROPERTY()
	bool bToggleSprint;

	UPROPERTY()
	bool bToggleSprintMobile;

	UPROPERTY()
	bool bToggleDoubleTapAutorunMobile;

	UPROPERTY()
	EAutorunLockZonePreferenceMobile AutorunLockZonePreferenceMobile;

	UPROPERTY()
	bool bTapInteractEnabled;

	UPROPERTY()
	ETouchInteractMode TouchInteractionMode;

	UPROPERTY()
	bool bTargetingToggleable;

	UPROPERTY()
	bool bTargetingToggleableMobile;

	UPROPERTY()
	bool bAutoEquipBetterItems;

	UPROPERTY()
	bool bAimAssistEnabled;

	UPROPERTY()
	bool bTouchAimAssistEnabled;

	UPROPERTY()
	bool bTouchEditEnabled;

	UPROPERTY()
	bool bEditConfirmOnReleaseEnabled;

	UPROPERTY()
	bool bResetConfirmOnReleaseEnabled;

	UPROPERTY()
	bool bSmartBuildEnabled;

	UPROPERTY()
	bool bQuickEditEnabled;

	UPROPERTY()
	bool bForceFeedbackEnabled;

	UPROPERTY()
	bool bTriggerHapticsEnabled;

	UPROPERTY()
	bool bTriggerPullUsesHapticThreshold;

	UPROPERTY()
	uint8 TriggerHapticStrength;

	UPROPERTY()
	uint8 TriggerHapticStartPosition;

	UPROPERTY()
	bool bMoveStickAcceleratesVehicles;

	UPROPERTY()
	bool bDeviceFeedbackBlockedWithAttachedController;

	UPROPERTY()
	bool bQuickWeaponToggleEnabled;

	UPROPERTY()
	float QuickWeaponDelay;

	UPROPERTY()
	EQuickWeaponToggle QuickWeaponToggleMode;

	UPROPERTY()
	bool bContextTutorialEnabled;

	UPROPERTY()
	bool bBuildingPossessionShown;

	UPROPERTY()
	bool bLocalNotificationsEnabled;

	UPROPERTY()
	bool bUseFirstPersonCamera;

	UPROPERTY()
	bool bUseGamepadEditModeAimAssist;

	UPROPERTY()
	bool bUseHoldToSwapPickup;

	UPROPERTY()
	bool bUseFollowCamera;

	UPROPERTY()
	bool bUseAutoCenter;

	UPROPERTY()
	bool bUseGamepadAutoRun;

	UPROPERTY()
	bool bFlickStickEnabled;

	UPROPERTY()
	float FlickTime;

	UPROPERTY()
	float FlickStickSmoothingThreshold;

	UPROPERTY()
	float FlickStickWindingSpeed;

	UPROPERTY()
	bool bScaleWindingWithZoom;

	UPROPERTY()
	float FlickStickDeadZoneFactor;

	UPROPERTY()
	float FlickForwardDeadZone;

	UPROPERTY()
	bool bFocusOnFirstBuildingPieceWhenQuickbarSwapped;

	UPROPERTY()
	bool bNewFocusOnFirstBuildingPieceWhenQuickbarSwapped;

	UPROPERTY()
	bool bFocusOnFirstBuildingPieceWhenQuickbarSwappedAthena;

	UPROPERTY()
	bool bNewFocusOnFirstBuildingPieceWhenQuickbarSwappedAthena;

	UPROPERTY()
	bool bDisablePreEditsWhenPlacingBuilding;

	UPROPERTY()
	bool bTurboBuild;

	UPROPERTY()
	bool bTurboBuildMobile;

	UPROPERTY()
	bool bCreativeTurboDelete;

	UPROPERTY()
	bool bAutoChangeMaterial;

	UPROPERTY()
	bool bAutoChangeMaterialMobile;

	UPROPERTY()
	bool bAutoOpenDoors;

	UPROPERTY()
	bool bAutoOpenDoorsNonMobile;

	UPROPERTY()
	bool bAutoClamber;

	UPROPERTY()
	bool bShowClamberIndicator;

	UPROPERTY()
	bool bAutoHurdle;

	UPROPERTY()
	bool bAutoPickupWeapons;

	UPROPERTY()
	bool bAutoPickupWeaponsConsolePC;

	UPROPERTY()
	bool bIsEasyLootGridEnabled;

	UPROPERTY()
	bool bEnablePreferredItemSlots;

	UPROPERTY()
	bool bAutoSortConsumablesToRight;

	UPROPERTY()
	bool bEnableTryBuildOnFocus;

	UPROPERTY()
	TArray<FName> SubscriptionNotificationsViewed;

	UPROPERTY()
	float EditButtonHoldTime;

	UPROPERTY()
	float SlideButtonHoldTime;

	UPROPERTY()
	float CameraResetTime;

	UPROPERTY()
	ECameraResetAxes CameraResetAxes;

	UPROPERTY()
	bool bUnlockConsoleFPS;

	UPROPERTY()
	bool bConsoleFPS60;

	UPROPERTY()
	TMap<FGameplayTag, bool> UserHUDVisibiltyMappings;

	UPROPERTY()
	TMap<FGameplayTag, bool> UserHUDDefaultMappings;

	UPROPERTY()
	TMap<int32, EFortPreferredItemSlotItemType> UserHUDQuickbarSlotPreferredItemTypes;

	UPROPERTY()
	EPartyType LastPartyType;

	UPROPERTY()
	bool bLastLeaderInvitesOnly;

	UPROPERTY()
	bool bLastLeaderFriendsOnly;

	UPROPERTY(Transient)
	bool bAudioVolumesInitialized;

	UPROPERTY()
	float MasterVolume;

	UPROPERTY()
	float MusicVolume;

	UPROPERTY()
	float SoundFXVolume;

	UPROPERTY()
	float PIPVolume;

	UPROPERTY()
	float DialogVolume;

	UPROPERTY()
	float ChatVolume;

	UPROPERTY()
	float CinematicsVolume;

	UPROPERTY()
	bool bEnableSubtitles;

	UPROPERTY()
	ESubtitleDisplayTextSize SubtitleTextSize;

	UPROPERTY()
	ESubtitleDisplayTextColor SubtitleTextColor;

	UPROPERTY()
	ESubtitleDisplayTextBorder SubtitleTextBorder;

	UPROPERTY()
	ESubtitleDisplayBackgroundOpacity SubtitleBackgroundOpacity;

	UPROPERTY()
	ESocialCommsPermission VoiceChatSetting;

	UPROPERTY(meta=(DeprecatedProperty, DeprecationMessage="Use VoiceChatSetting instead."))
	bool bEnableVoiceChat;

	UPROPERTY()
	bool bEnableVoiceChat3D;

	UPROPERTY()
	bool bEnableVoiceChatPTT;

	UPROPERTY()
	EFortVoiceChatMethod VoiceChatMethod;

	UPROPERTY()
	bool bDidMigrateFromPTT2VoiceChatMethod;

	UPROPERTY()
	bool bEnableHousepartyCasting;

	UPROPERTY()
	bool bEnablePeripheralLighting;

	UPROPERTY()
	bool bShowViewerCount;

	UPROPERTY()
	bool bAnonymousMode;

	UPROPERTY()
	bool bAnonymousCharacterMode;

	UPROPERTY()
	bool bShowSeasonLevel;

	UPROPERTY()
	bool bHideOtherPlayerNames;

	UPROPERTY()
	int32 HiddenMatchmakingDelayMaxSeconds;

	UPROPERTY()
	bool bReplayRecordingIndicatorEnabled;

	UPROPERTY()
	bool bReplayRecordingEnabled;

	UPROPERTY()
	bool bLargeTeamReplayRecordingEnabled;

	UPROPERTY()
	bool bCreativeModeReplayRecordingEnabled;

	UPROPERTY()
	bool bHighQualityReplayRecordingEnabled;

	UPROPERTY()
	bool bBrunoReplayRecordingEnabled;

	UPROPERTY()
	EBrelmarCameraShake BrelmarCameraShake;

	UPROPERTY()
	EDoughnutFillingSetting DoughnutFillingSetting;

	UPROPERTY()
	EDoughnutPresetSetting DoughnutPresetSetting;

	UPROPERTY()
	bool bShadowPlayHighlightsEnabled;

	UPROPERTY()
	bool bPlaceDangerMarkerWhenTargeting;

	UPROPERTY()
	bool bShowGlobalChatEnabled;

	UPROPERTY()
	float InitialGammaValue;

	UPROPERTY()
	bool bInitialUseTapToShoot;

	UPROPERTY()
	bool InitialbToggleDoubleTapAutorunMobile;

	UPROPERTY()
	EAutorunLockZonePreferenceMobile InitialAutorunPreferenceMobile;

	UPROPERTY()
	bool bInitialAutoOpenDoors;

	UPROPERTY()
	bool bInitialAutoPickupWeapons;

	UPROPERTY()
	bool bInitialAutoPickupWeaponsConsolePC;

	UPROPERTY()
	bool bInitialIsEasyLootGridEnabled;

	UPROPERTY()
	bool bInitialEnablePreferredItemSlots;

	UPROPERTY()
	bool bInitialAutoSortConsumablesToRight;

	UPROPERTY()
	bool bInitialEnableTryBuildOnFocus;

	UPROPERTY()
	float InitialEditButtonHoldTime;

	UPROPERTY()
	float InitialSlideButtonHoldTime;

	UPROPERTY()
	bool bStWQuickbarUpdated;

	UPROPERTY()
	bool bShouldShowBothQuickbars;

	UPROPERTY()
	ELicensedAudioTreatment LicensedAudioTreatment;

	UPROPERTY()
	EColorBlindMode ColorBlindMode;

	UPROPERTY()
	float ColorBlindStrength;

	UPROPERTY()
	bool bVisualizeAudioSources;

	UPROPERTY()
	EVisualizeAudioPriority VisualizeAudioPriority;

	UPROPERTY()
	EVisualizeAudioPriority InitialVisualizeAudioPriority;

	UPROPERTY(Transient)
	EColorBlindMode InitialColorBlindMode;

	UPROPERTY(Transient)
	float InitialColorBlindStrength;

	UPROPERTY()
	bool bIgnoreGamepadInput;

	UPROPERTY(Transient)
	bool bInitialIgnoreGamepadInput;

	UPROPERTY()
	bool bLockPrimaryInputMethodToMouse;

	UPROPERTY(Transient)
	bool bLockPrimaryInputMethodToMouseInitial;

	UPROPERTY()
	bool bEnableRudderControl;

	UPROPERTY()
	float RudderDeadZone;

	UPROPERTY()
	float RudderMaxThrottle;

	UPROPERTY()
	bool bDoNotRemindAboutMultiSubs;

	UPROPERTY()
	FString SelectedRegionId;

	UPROPERTY(Transient)
	FString PrevSavedRegion;

	UPROPERTY()
	FString LastKnownBestRegionId;

	UPROPERTY()
	int32 CrossplayPreference;

	UPROPERTY()
	TSet<EFortInventoryCustomFilter> CustomInventoryFilterSet;

	UPROPERTY(Transient)
	TArray<FName> WatchedVideoIDs;

	UPROPERTY(meta=(DeprecatedProperty, DeprecationMessage="Use  InitializeKWSWithCCSSettings instead."))
	bool bHasMigratedCCSSettings;

	UPROPERTY()
	int32 InitializeKWSWithCCSSettings;

	UPROPERTY()
	int32 CurrentDeltaUpdateKWSWithCCSSettings;

	UPROPERTY()
	int32 SeenReviewSettingsModal;

	UPROPERTY()
	int32 SeenParentalControlsUpdatedModal;

	UPROPERTY()
	int32 SeenEnterCabinModeModal;

	UPROPERTY()
	bool bAllowAudioInBackground;

	UPROPERTY()
	EFortAllowBackgroundAudioSetting AllowAudioInBackground;

	UPROPERTY()
	bool bUsePowerSavingMode;

	UPROPERTY()
	bool bHidePerkRecombobulatorHelp;

	UPROPERTY()
	bool bHideStwItemRefundHelp;

	UPROPERTY()
	EAndroidAppStoreTypes SelectedAndroidAppStore;

	UPROPERTY()
	int32 AndroidStoreSelectionRevision;

	UPROPERTY()
	bool bHasDisabledAutoSlottingOfSurvivorSquadsAfterQuest;

	UPROPERTY()
	bool bHasEnabledAutoSlottingOfSurvivorSquadsDuringOnboarding;

	UPROPERTY()
	bool bWantsAutoSlottingOfSurvivorSquads;

	UPROPERTY()
	TArray<FHUDLayoutData> CustomHUDLayoutData;

	UPROPERTY()
	FFireModeData FireModeData;

	UPROPERTY()
	bool bRequiresHUDConversion;

	UPROPERTY()
	FFortMobileHUDProfileContainer HUDProfileContainer;

	UPROPERTY()
	EQuestMapScreenMode QuestMapMode;

	UPROPERTY()
	FString QuestMapEventName;

	UPROPERTY()
	bool bAutoJoinGameServerChannel;

	UPROPERTY()
	bool bEnablePartyVoiceChannel;

	UPROPERTY()
	bool bEnableGameVoiceChannel;

	UPROPERTY()
	bool bAllowSidekickFeature1;

	UPROPERTY()
	bool bShowVoiceIndicatorsNotifications;

	UPROPERTY()
	TSet<FString> SeenEventFlags;

	UPROPERTY(meta=(DeprecatedProperty, DeprecationMessage="Use ContextTutorialSeenCountGameplayTag instead."))
	TMap<int32, int32> ContextTutorialSeenCount;

	UPROPERTY()
	TMap<FGameplayTag, int32> ContextTutorialSeenCountGameplayTag;

	UPROPERTY()
	bool bHasCompletedGuidedTutorial;

	UPROPERTY()
	TArray<EKWSSetttingIndividalMigration> KWSSettingAlreadyMigrated;

	UPROPERTY()
	int32 CapMipsExperimentVersion;

	UPROPERTY()
	bool bHasCompletedHUDLayoutToolV2Tutorial;

	UPROPERTY()
	bool FortClientSettingRecord;

	UPROPERTY()
	EHitNumbersMode HitNumbersMode;

	UPROPERTY()
	EHitFeedbackMode HitFeedbackMode;

	UPROPERTY()
	float DamageNumbersScale;

	UPROPERTY()
	bool bTargetTypeIndicatorVisible;

	UPROPERTY()
	bool bShowTemperature;

	UPROPERTY(Transient)
	bool bNotifyUsersWhenPlaying;

	UPROPERTY()
	bool bPlayerSurveysAllowed;

	UPROPERTY()
	bool bClipRemindersEnabled;

	UPROPERTY()
	EPostpartyClippingState PostpartyClippingState;

	UPROPERTY()
	FDateTime FlagSelectionLastUpdated;

	UPROPERTY()
	bool bUseSmallInventoryTiles;

	UPROPERTY()
	TMap<uint8, uint32> LastSeenHashByShopSection;

	UPROPERTY()
	TMap<FName, uint32> LastSeenHashByShopSectionId;

	UPROPERTY()
	FDateTime LastTokenRefreshDateNotified;

	UPROPERTY()
	bool HasSeenCommunityVotingTutorial;

	UPROPERTY()
	int32 LastSeenCommunityVotingTutorialVersion;

	UPROPERTY()
	FString LastSeenCommunityVotingVersion;

	UPROPERTY()
	FString LastSeenStandaloneOfferId;

	UPROPERTY()
	TMap<EFortAutoMulchCategory, EFortAutoMulchMode> AutoMulchModeMap;

	UPROPERTY()
	TArray<FPlayerLastSelectedPreferredProvider> LastPlayerSelectedPreferredProvider;

	UPROPERTY()
	uint8 QuestListSortType;

	UPROPERTY()
	uint8 InZoneMapScreenTab;

	UPROPERTY()
	TSet<int32> AttendingSocialEventIds;

	UPROPERTY()
	TArray<FString> EventAttendance;

	UPROPERTY()
	TSet<FString> LastSubscriptionIds;

	UPROPERTY()
	FDateTime LastMultiSubRenewalDate;

	UPROPERTY()
	FGameplayTagContainer SeenOnboardingTutorials;

	UPROPERTY()
	int8 NumDiscoveryFlowTooltipsRemaining;

	UPROPERTY()
	bool bShouldShowHabaneroTutorial;

	UPROPERTY()
	int32 LastSeenHabaneroSeason;

	UPROPERTY()
	bool bShouldShowContentGatingTutorial;

	UPROPERTY()
	bool bAutoExposureEnabled;

	UPROPERTY()
	float ManualExposureBias;

	UPROPERTY()
	float FocalLength;

	UPROPERTY()
	float Aperture;

	UPROPERTY()
	bool bAutoFocusEnabled;

	UPROPERTY()
	float ManualFocusDistance;

	UPROPERTY()
	bool bPlayerOutlinesEnabled;

	UPROPERTY()
	bool bFirstPlaceHighlightEnabled;

	UPROPERTY()
	bool bStormEffectsEnabled;

	UPROPERTY()
	float SafeZoneOpacity;

	UPROPERTY()
	bool bRelevancyZoneVisible;

	UPROPERTY()
	bool bHighQualityFxEnabled;

	UPROPERTY()
	bool bDamageFxEnabled;

	UPROPERTY()
	EThirdPersonAutoFollowMode ThirdPersonAutoFollowMode;

	UPROPERTY()
	float ThirdPersonDistanceToSubject;

	UPROPERTY()
	bool bThirdPersonCameraCollision;

	UPROPERTY()
	bool bShareLensSettings;

	UPROPERTY()
	bool bDroneIgnoreJump;

	UPROPERTY()
	bool bShowSessionIDWatermark;

	UPROPERTY()
	bool bBattleMapShowTimeIndicator;

	UPROPERTY()
	bool bBattleMapShowNearbyChests;

	UPROPERTY()
	bool bBattleMapShowAllSquadMembers;

	UPROPERTY()
	bool bBattleMapAutomaticCameraPlacement;

	UPROPERTY()
	bool bNameplatesEnabled;

	UPROPERTY()
	bool bShowTeamColor;

	UPROPERTY()
	float ViewDistance;

	UPROPERTY()
	float LowDetailDistance;

	UPROPERTY()
	float ArrowDistance;

	UPROPERTY()
	bool bScalingOptionsEnabled;

	UPROPERTY()
	float HighDetailScaleMin;

	UPROPERTY()
	float HighDetailScaleMax;

	UPROPERTY()
	float LowDetailScaleMin;

	UPROPERTY()
	float LowDetailScaleMax;

	UPROPERTY()
	float ArrowScaleMin;

	UPROPERTY()
	float ArrowScaleMax;

	UPROPERTY()
	bool bArrowColorEnabled;

	UPROPERTY()
	bool bDisplaySessionRank;

	UPROPERTY()
	ESpectatorSquadIdMode SquadIdMode;

	UPROPERTY()
	TMap<FString, FString> MediaPartnerData;

	UPROPERTY()
	TArray<FString> HotTamalesWithVeggiesCache;

private:
	UPROPERTY()
	TArray<FFortClientSettingRecordPartitionSchema> SettingRecordPartitionSchemas;

	UPROPERTY(Transient)
	bool bDirty;

	UPROPERTY(Transient)
	uint8 bSaveToCloud : 1;

	UPROPERTY(Transient)
	ECloudFileState CloudFileState;

	UPROPERTY(Transient)
	uint32 bDisableCloudSave;

	UPROPERTY(Transient)
	int32 LastRequestSaveCount;

	UPROPERTY(Transient)
	int32 LastAttemptedSaveCount;

	UPROPERTY(Transient)
	double LastSaveAttemptTime;

	UPROPERTY(Transient)
	double NextCloudSaveTime;

	UPROPERTY(Config)
	TArray<FSettingsSaveContextBehaviorDefinition> ContextBehaviorDefinitions;

	UPROPERTY(Config)
	FSettingsSaveContextBehaviorDefinition DefaultContextBehaviorDefinition;

};

