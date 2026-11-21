// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "BlueprintContextBase.h"
#include "Building/BuildingTypes.h"
#include "Context/FortHUDContextTypes.h"
#include "FortCombatTypes.h"
#include "FortHUDTagPromptTagMapping.h"
#include "FortItemQuantityPair.h"
#include "FortMultiSize.h"
#include "FortOnUIGameplayCueEvent.h"
#include "Items/FortEndOfDayRecap.h"
#include "Items/FortReplicatedStatTypes.h"
#include "Missions/EarnedBadgeEntry.h"
#include "Missions/FortBadgeCount.h"
#include "Pawns/FortPawn.h"
#include "UI/FrontEnd/FortZoneLoadingScreenConfig.h"
#include "Weapons/FortWeaponDelegates.h"
#include "FortHUDContext.generated.h"

class AActor;
class ABattleMapPawnLive;
class ABuildingActor;
class ABuildingSMActor;
class ABuildingTrap;
class AController;
class AFortBluGloManager;
class AFortGameStateZone;
class AFortMission;
class AFortMissionManager;
class AFortPawn;
class AFortPlayerPawn;
class AFortPlayerState;
class AFortPlayerStateZone;
class AFortWeapon;
class UFocusedBuildingDynamicData;
class UFortGameplayModifierItemDefinition;
class UFortHUDElementWidget;
class UFortHero;
class UFortInteractContextInfo;
class UFortItem;
class UFortItemDefinition;
class UFortItemTileView;
class UFortTouchControlRegion;
class UMediaSource;
class UTexture2D;
class UUserWidget;
enum class EFortCompletionResult : uint8;
enum class EFortHitPointModificationReason : uint8;
enum class EFortIndicatorState : uint8;
enum class EFortItemInspectionMode : uint8;
enum class EFortQuickBars : uint8;
enum class EStatCategory : uint8;

UENUM()
enum class EBuildingFocusType : uint8
{
	Contextual = 0,
	Interactable = 1,
	Normal = 2,
	Count = 3,
};

UENUM(BlueprintType)
enum class EFortBuildingHealthDisplayRule : uint8
{
	// Do not show the health of the building under any circumstance

	Never = 0,
	// Show the health of the building conditionally (left to the BP to decide fade in, out, etc.)

	Allowed = 1,
	// Show the health of the building at all times while focused

	Always = 2,
};

UENUM(BlueprintType)
enum class EFortBuildingInteraction : uint8
{
	// There is no available interaction with the building

	None = 0,
	// The building piece can be built

	Build = 1,
	// The building can be repaired

	Repair = 2,
	// The building can be upgraded

	Upgrade = 3,
	// The building is editable

	Edit = 4,
	// The building is interactable, but is currently undergoing a modification (repair, upgrade, etc.)

	BeingModified = 5,
	// The building piece grid can be edited

	ConfirmEdit = 6,
	// the Building Piece is being interacted by a creative tool.

	Creative = 7,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHUDBasicDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveGameplayModifiersChangedDelegate, const TArray<UFortGameplayModifierItemDefinition*>&, AppliedModifiers);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorFocusedForCreative, AActor*, FocusedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBigHitPointStatChanged, FText, HitPointText, float, HealthPercent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBuildModeChanged, bool, bEntering);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBuildingFocused, ABuildingActor*, FocusedBuilding);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBuildingTrapDurabilityChanged, float, CurrentDurability, float, MaxDurability);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCanInteract, const UFortInteractContextInfo*, ContextInfo);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContextualReticleChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCursorModeChangedDelegate, bool, bCursorModeEnabled, FName, ActionName, UUserWidget*, CursorModeContentWidget);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCursorModeChangingDelegate, bool, bCursorModeEnabled, FName, ActionName);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnDamagedResourceBuilding, ABuildingSMActor*, BuildingSMActor, UFortItem*, PotentialWorldItem, bool, bDestroyed, bool, bJustHitWeakspot);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnDamagedResourceVehicle, AActor*, VehicleActor, UFortItem*, PotentialWorldItem, bool, bDestroyed, bool, bJustHitWeakspot);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDebugHUDObjectiveHeightChanged, bool, bIsDebugging);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEarnedBadgesChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEndOfDayRecap, const FEndOfDayRecap&, EndOfDayRecap);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocusedBuildingAttachedTrapChanged, ABuildingTrap*, BuildingAttachedTrap);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocusedBuildingDynamicDataReceived, const UFocusedBuildingDynamicData*, DynamicData);

USTRUCT(BlueprintType)
struct FFortFocusedBuildingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	bool bIsInteractable;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	bool bCanBePlayerEdited;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	FVector IndicatorRelativeLocation;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	EFortBuildingHealthDisplayRule HealthDisplayRule;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	float MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	bool bIsAnyTrapAttached;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	bool bIsTrapAttachedFacingPlayer;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	bool bIsPreviewTrapAttached;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	float AttachedTrapMaxDurability;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	EFortBuildingInteraction InteractionType;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	int32 InteractionCost;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	TEnumAsByte<EFortResourceType::Type> BuildingMaterial;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	FName QuickEditClass;

	UPROPERTY(BlueprintReadOnly, Category="FocusedBuildingInfo")
	bool bIsPlayerBuilt;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocusedBuildingStateChanged, const FFortFocusedBuildingInfo&, FocusedBuildingInfo);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocusedMissionChanged, AFortMission*, FocusedMission);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameViewportActivationChangedDelegate, bool, bHasFocus);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetHUDElementWidgetsForTagsDelegate, const FGameplayTagContainer&, Tags, TArray<UFortHUDElementWidget*>&, OutWidgets);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHUDElementVisibilityChanged, const FGameplayTagContainer&, HiddenHUDElementTags);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHUDResetToDefaults);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHUDScaleChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHUDStateRefreshed, const FFortHUDState&, NewHUDState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHighlightsCountChanged, int32, NumHighlights);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHitPointStatChanged, float, HitPointStat);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHitPointsModified, float, HitPointValue, EFortHitPointModificationReason, ModificationReason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHordeTierCompleteDelegate, EFortCompletionResult, Result);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHordeTierInitializedDelegate, const TArray<FFortItemInstanceQuantityPair>&, Items);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHordeWaveCompleteDelegate, const int32, Wave, const TArray<FFortItemInstanceQuantityPair>&, Rewards);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIndicatorModeChangedDelegate, bool, bIndicatorsEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractUpdated, const UFortInteractContextInfo*, ContextInfo);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionCostChanged, int32, InteractionCost);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLocalChallengesVisibilityChangedDelegate, bool, bIsVisible);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMgmtMenuTabChangeRequestedDelegate, FName, TabName);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMilestoneQuestCompleted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNumSurvivorsRescuedUpdate, int32, NumSurvivorsRescued);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnOpenInspect, UFortItem*, ItemToInspect, EFortItemInspectionMode, Mode, UFortItemTileView*, CycleTileView, bool, bReadOnly, bool, bAllowFavoriting, bool, bIsTemporaryItem, bool, bAllowRarityUpgrading);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnFocused, AFortPawn*, FocusedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPersonalVehicleModeChange, bool, bEnteredVehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerAIKillsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDeath, const FFortPlayerDeathReport&, DeathReport);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerKillsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerPlaceChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerRevived);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerSpawned);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerTargetingChangedDelegate, bool, bIsTargeting);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnPointOfInterestAdded, AActor*, PointOfInterest, FText, DisplayText, UTexture2D*, DisplayImage, bool, bSpecifyColor, FLinearColor, ImageColor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPointOfInterestRemoved, AActor*, PointOfInterest);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRequestPromptDisplayDelegate, const FFortHUDTagPromptData&, PromptData, const FGameplayTag&, Tag);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestSetInZoneTitleBarVisibility, bool, bNewVisibility);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int32, NewTotalScore);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnScoreStatChanged, int32, StatDelta, const FText&, StatName, TEnumAsByte<EFortReplicatedStat::Type>, StatType, EStatCategory, StatCategory);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSettingsApplied);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShouldTriggerCooldownUpdate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnToggleScoreboardDelegate, bool, bEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnToggledBattleMapLive, ABattleMapPawnLive*, NewSpectatorPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUIResetRequired);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnableToPerformActionDelegate, FGameplayTagContainer, FailedReason, const FText&, FailureText);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVehicleFocused, AActor*, FocusedVehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVehicleStateChanged, AFortPlayerPawn*, PlayerPawn, AActor*, NewVehicle, AActor*, OldVehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWaveBasedModifiersAppliedDelegate, const TArray<UFortGameplayModifierItemDefinition*>&, AppliedModifiers);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnWaveCombatStart, const FText&, LevelText, int32, Level, const FText&, WaveText, int32, WaveNum);

USTRUCT(BlueprintType)
struct FFortBasicMissionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Basic Mission Info")
	FText MissionName;

	UPROPERTY(BlueprintReadOnly, Category="Basic Mission Info")
	FFortMultiSizeBrush MissionIcons;

	UPROPERTY(BlueprintReadOnly, Category="Basic Mission Info")
	FText TheaterName;

	UPROPERTY(BlueprintReadOnly, Category="Basic Mission Info")
	FText DifficultyName;

	UPROPERTY(BlueprintReadOnly, Category="Basic Mission Info")
	TObjectPtr<UMediaSource> EndOfMissionMediaSource;

	UPROPERTY(BlueprintReadOnly, Category="Basic Mission Info")
	TObjectPtr<UMediaSource> EndOfMissionMediaSourceStreamed;

	UPROPERTY(BlueprintReadOnly, Category="Basic Mission Info")
	bool bSkipEndOfMissionVideo;

	UPROPERTY(BlueprintReadOnly, Category="Basic Mission Info")
	bool bIsGroupContent;

};

USTRUCT(BlueprintType)
struct FFortItemDelta
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortItemDelta")
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDelta")
	int32 BaseAmount;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDelta")
	int32 DeltaAmount;

};

UCLASS(meta=(DisableNativeTick))
class UFocusedBuildingDynamicData : public UPrimaryDataAsset
{
	GENERATED_BODY()

};

UCLASS(Config=Game)
class FORTNITEUI_API UFortHUDContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="HUD")
	void AddPointOfInterest(AActor* PointOfInterest, FText DisplayText, UTexture2D* DisplayImage, bool bSpecifyColor, FLinearColor ImageColor);

	UFUNCTION(BlueprintPure, Category="HUD")
	bool AreHUDElementsVisible(const FGameplayTagContainer& HUDElementTags) const;

	UFUNCTION(BlueprintPure, Category="HUD")
	bool AreIndicatorsEnabled() const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	void EnterCameraMode();

	UFUNCTION(BlueprintCallable, Category="HUD")
	void EnterCursorMode(FName ActionName, UUserWidget* CursorModeWidget = nullptr);

	UFUNCTION(BlueprintPure, Category="HUD")
	void GetAccountLevelUpRewards(TArray<FFortItemQuantityPair>& Rewards, int32 AccountLevel) const;

	UFUNCTION(BlueprintPure, Category="HUD")
	AFortBluGloManager* GetBluGloManager() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	bool GetBuildingActorInfo(ABuildingActor* BuildingActor, FFortFocusedBuildingInfo& OutBuildingInfo) const;

	UFUNCTION(BlueprintPure, Category="Missions")
	bool GetCurrentBasicMissionInfo(FFortBasicMissionInfo& BasicMissionInfo) const;

	UFUNCTION(BlueprintPure)
	ABuildingActor* GetCurrentFocusedBuilding() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	UFortHero* GetCurrentHero() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	const FFortHUDState& GetCurrentHUDState() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	FGameplayTagContainer GetCurrentPrimaryMissionTags() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	void GetDifficultyIncreaseRewards(int32 DifficultyIncreaseTier, TArray<FFortItemDelta>& DifficultyIncreaseRewards) const;

	UFUNCTION(BlueprintPure, Category="HUD")
	void GetDifficultyIncreaseRewardsDifference(int32 BaseDifficultyIncreaseTier, int32 ComparedDifficultyIncreaseTier, TArray<FFortItemDelta>& RewardDeltaInfo) const;

	UFUNCTION(BlueprintPure, Category="HUD")
	int32 GetDifficultyIncreaseRewardsTier() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	const TArray<FEarnedBadgeEntry> GetEarnedBadges() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	bool GetFocusedBuildingInfo(FFortFocusedBuildingInfo& OutBuildingInfo) const;

	UFUNCTION(BlueprintPure, Category="HUD")
	AFortMission* GetFocusedMission() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	AFortGameStateZone* GetGameStateZone() const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	void GetHUDElementWidgetsForTags(const FGameplayTagContainer& HUDElementTags, TArray<UFortHUDElementWidget*>& OutWidgets);

	UFUNCTION(BlueprintPure, Category="HUD")
	EFortIndicatorState GetIndicatorsState() const;

	UFUNCTION(BlueprintPure)
	bool GetLocalPlayerHasLosingPlacement() const;

	UFUNCTION(BlueprintPure)
	bool GetLocalPlayerHasPlacement() const;

	UFUNCTION(BlueprintPure)
	bool GetLocalPlayerHasWinningPlacement() const;

	UFUNCTION(BlueprintPure)
	int32 GetLocalPlayerPlacement() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	AFortMissionManager* GetMissionManager() const;

	UFUNCTION(BlueprintPure, Category="Missions")
	TArray<FZoneLoadingScreenHeadingConfig> GetMissionOverviewObjectives() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	void GetMissionRewards(TArray<UFortItem*>& MissionRewards, TArray<UFortItem*>& MissionAlertRewards) const;

	UFUNCTION(BlueprintPure, Category="HUD")
	int32 GetNumAllowedDifficultyIncreases() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	AFortPlayerStateZone* GetPlayerStateZone() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	const TArray<FFortBadgeCount> GetPotentialBadges() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	float GetScoreDisplayFactor() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	float GetTimeToDelayEndOfDayZoneWidgetDisplay() const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	void HideAerialFeedback();

	UFUNCTION(BlueprintPure, Category="HUD")
	bool IsInCursorMode() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	bool IsInEditMode() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	bool IsLocalChallengesVisible() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	bool IsPreparingMgmtMenu() const;

	UFUNCTION(BlueprintCallable, Category="Quickbars")
	bool PreviewItemPickUp(const UFortItem* InItem, const EFortQuickBars InQuickBarType, int32& OutSlotIndex, TMap<int32, int32>& OutItemsToPush, TArray<int32>& OutItemsToDrop);

	UFUNCTION(BlueprintCallable, Category="HUD")
	void RemovePointOfInterest(AActor* PointOfInterest);

	UFUNCTION(BlueprintCallable, Category="HUD")
	void RequestMgmtMenuTab(FName TabName);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="HUD")
	void SendFocusedBuildingDynamicData(const UFocusedBuildingDynamicData* DynamicData) const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	void SetCursorModeLocked(bool bLocked);

	UFUNCTION(BlueprintCallable, Category="HUD", meta=(AutoCreateRefTerm="ReasonName"))
	void SetHUDElementVisibility(const FGameplayTagContainer& HUDElementTags, bool bHideElements, const FName& ReasonName = NAME_None);

	UFUNCTION(BlueprintCallable, Category="HUD")
	void SetIndicatorsAllowed(bool bIndicatorsAllowed);

	UFUNCTION(BlueprintCallable, Category="HUD")
	void SetIndicatorsState(EFortIndicatorState NewState);

	UFUNCTION(BlueprintCallable, Category="HUD")
	void SetIsLocalChallengesVisible(bool bIsVisible);

	UFUNCTION(BlueprintCallable, Category="HUD")
	void SetPreparingMgmtMenu(bool bPreparing);

	UFUNCTION(BlueprintPure, Category="HUD")
	bool ShouldOnlyShowNextPrevBuildingSlotKeybinds() const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	void ShowAerialFeedback(const FName BoundActionName, const FText& FeedbackText);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ToggleFullscreenMap() const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	void TriggerCooldownUpdate();

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnCursorModeChangingDelegate OnCursorModeChanging;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnCursorModeChangedDelegate OnCursorModeChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnRequestPromptDisplayDelegate OnRequestPromptDisplay;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnGameViewportActivationChangedDelegate OnGameViewportActivationChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnMgmtMenuTabChangeRequestedDelegate OnMgmtMenuTabChangeRequested;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnGetHUDElementWidgetsForTagsDelegate OnGetHUDElementWidgetsForTags;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnIndicatorModeChangedDelegate OnIndicatorModeChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnContextualReticleChangedDelegate OnContextualReticleChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnVehicleFocused OnVehicleFocused;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPawnFocused OnPawnFocused;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnBuildingFocused OnBuildingFocused;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnActorFocusedForCreative OnActorFocusedForCreative;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnFocusedBuildingStateChanged OnFocusedBuildingStateChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="HUD")
	FOnOpenInspect OnOpenInspect;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHitPointStatChanged OnFocusedBuildingHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnBigHitPointStatChanged OnFocusedBuildingBigHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnInteractionCostChanged OnFocusedBuildingRepairCostChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnBuildingTrapDurabilityChanged OnFocusedBuildingAttachedTrapDurabilityChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnFocusedBuildingAttachedTrapChanged OnFocusedBuildingAttachedTrapChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnFocusedBuildingDynamicDataReceived OnFocusedBuildingDynamicDataReceived;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnDamagedResourceBuilding OnDamagedResourceBuilding;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnDamagedResourceVehicle OnDamagedResourceVehicle;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnCanInteract OnPlayerCanInteract;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnInteractUpdated OnInteractUpdated;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerTargetingChangedDelegate OnPlayerTargetingChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnScoreChanged OnScoreChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnScoreStatChanged OnScoreStatChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnZoneCompleted;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnPawnSet;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnDamageReceived;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnUnableToPerformActionDelegate OnUnableToPerformAction;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHitPointStatChanged OnLocalPlayerMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHitPointsModified OnLocalPlayerHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerDeath OnLocalPlayerDied;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerSpawned OnLocalPlayerSpawned;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerRevived OnLocalPlayerRevived;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHUDScaleChanged OnHUDScaleChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHUDScaleChanged OnReticleSettingsChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerKillsChanged OnLocalPlayerKillsChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerPlaceChanged OnLocalPlayerPlaceChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerPlaceChanged OnLocalPlayerViewTargetChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnToggledBattleMapLive OnToggledBattleMapLive;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHitPointStatChanged OnLocalPlayerMaxShieldChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHitPointsModified OnLocalPlayerShieldChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHitPointStatChanged OnLocalPlayerMaxStaminaChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHitPointStatChanged OnLocalPlayerStaminaChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnToggleScoreboardDelegate OnToggleScoreboard;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnEndOfDayRecap OnEndOfDayRecap;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnWaveCombatStart OnWaveCombatStart;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnWaveBasedModifiersAppliedDelegate OnWaveBasedModifiersApplied;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnActiveGameplayModifiersChangedDelegate OnActiveGameplayModifiersChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHordeTierInitializedDelegate OnHordeTierInitialized;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHordeTierCompleteDelegate OnHordeTierComplete;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHordeWaveCompleteDelegate OnHordeWaveComplete;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnBuildingMaterialCycled;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHighlightsCountChanged OnHighlightsCountChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHUDStateRefreshed OnHUDStateRefreshed;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnShouldTriggerCooldownUpdate OnShouldTriggerCooldownUpdate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnRequestSetInZoneTitleBarVisibility OnRequestSetInZoneTitleBarVisibility;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnUIGameplayCueEvent OnUIGameplayCue;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FFortPawnEquippedWeaponSignature OnWeaponEquippedDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FFortPawnUnEquippedWeaponSignature OnWeaponUnEquippedDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnWeaponHudKeyActionUpdated OnWeaponHudKeyActionUpdated;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FPawnUpdatedDecisionWindowStackSignature OnAbilityDecisionWindowStackUpdated;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnWorldDaysElapsedChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnNumSurvivorsRescuedUpdate OnNumSurvivorsRescuedChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnEarnedBadgesChanged OnEarnedBadgesChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnPotentialBadgesChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnMissionManagerCreated;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnMissionsUpdated;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnFocusedMissionChanged OnFocusedMissionChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnTheaterUniqueIDChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnZoneDifficultyInfoRowChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnDifficultyIncreaseRewardTierChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnDifficultyIncreaseRewardsChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnMissionGeneratorChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FHUDBasicDelegate OnMissionRewardsChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPointOfInterestAdded OnPointOfInterestAdded;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPointOfInterestRemoved OnPointOfInterestRemoved;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnHUDElementVisibilityChanged OnHUDElementVisibilityChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalChallengesVisibilityChangedDelegate OnLocalChallengesVisibilityChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnDebugHUDObjectiveHeightChanged OnDebugHUDObjectiveHeightChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnBuildModeChanged OnBuildModeChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPersonalVehicleModeChange OnPersonalVehicleModeChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnVehicleStateChanged OnPlayerVehicleStateChanged;

private:
	UFUNCTION()
	void ForwardOnAbilityDecisionWindowStackUpdated();

	UFUNCTION()
	void ForwardOnMissionsUpdated();

	UFUNCTION()
	void ForwardOnNumSurvivorsRescuedChanged(int32 NumSurvivorsRescued);

	UFUNCTION()
	void ForwardOnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION()
	void ForwardOnWeaponHudKeyActionUpdated(AFortWeapon* Weapon);

	UFUNCTION()
	void ForwardOnWeaponUnEquipped();

	UFUNCTION(BlueprintCallable)
	void HandleActorFocusedForCreative(AActor* NewActor);

	UFUNCTION()
	void HandleBuildingModeChanged(bool bEntering);

	UFUNCTION()
	void HandleFocusedBuildingAbilitySystemComponentInitialized();

	UFUNCTION()
	void HandleLocalPawnDied(const FFortPlayerDeathReport& DeathReport);

	UFUNCTION()
	void HandleLocalPawnRevived(const AController* EventInstigator);

	UFUNCTION()
	void HandleLocalPawnSpawned();

	UFUNCTION()
	void HandleLocalPlayerBuildCostChanged();

	UFUNCTION()
	void HandleLocalPlayerKillsChanged();

	UFUNCTION()
	void HandleLocalPlayerPlaceChanged();

	UFUNCTION()
	void HandleLocalPlayerViewTargetChanged();

	UFUNCTION()
	void HandlePersonalVehicleModeChanged(bool bEnteredVehicle);

	UFUNCTION()
	void HandleSpectatorViewTargetChanged();

	UFUNCTION()
	void HandleToggledBattleMapLive(ABattleMapPawnLive* NewSpectatorPawn);

	UFUNCTION()
	void HandleUIGameplayCue(FName CueName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters);

	UFUNCTION()
	void HandleVehicleStateChanged(AFortPlayerPawn* PlayerPawn, AActor* NewVehicle, AActor* OldVehicle);

	UFUNCTION(BlueprintPure)
	bool IsContextTutorialActive(FGameplayTag TutorialType) const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	void RequestPromptDisplay(const FFortHUDTagPromptData& PromptData, const FGameplayTag& Tag);

	UFUNCTION()
	void UpdateTrapAttachedToBuilding();

	UPROPERTY(Config)
	TArray<FString> HotfixElementsToHide;

	UPROPERTY(Transient)
	bool bDebugHudObjectiveHeight;

	UPROPERTY(Transient)
	bool bPendingAttachToHUD;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerState> OwningPlayerState;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingActor> CurFocusedBuilding;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingTrap> CurFocusedTrap;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingActor> BuildingFocusCandidates[3];

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> BoundPlayerPawn;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> CachedCurrentWeapon;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> CachedPreviousWeapon;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortTouchControlRegion> TouchControlRegion;

};

