// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "BlueprintContextBase.h"
#include "Building/BuildingTypes.h"
#include "FortOnUIGameplayCueEvent.h"
#include "FortSpecialActorReplicationInfo.h"
#include "FortTypes.h"
#include "FortUITypes.h"
#include "FortUrgentQuestData.h"
#include "Items/FortQuickBars.h"
#include "AthenaHUDContext.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerPawnAthena;
class AFortPlayerStateAthena;
class AFortWeapon;
class UAthenaPlayerViewModel;
class UFortAthenaHUDInfoDataAsset;
class UFortItem;
class UFortItemDefinition;
class UMaterialInterface;
class USoundCue;
class UUserWidget;
class UWidget;
enum class EDuelState : uint8;
enum class EEndOfMatchReason : uint8;
enum class EFortQuickBars : uint8;
enum class EPTTState : uint8;
enum class ETouchInteractMode : uint8;
enum class EUIExtensionSlot : uint8;
enum class EUnconvertReason : uint8;

USTRUCT(BlueprintType)
struct FEliminationTimelineEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="EliminationTimelineEntry")
	FString PlayerName;

	UPROPERTY(BlueprintReadOnly, Category="EliminationTimelineEntry")
	FString PlayerRankType;

	UPROPERTY(BlueprintReadOnly, Category="EliminationTimelineEntry")
	int32 PlayerRank;

	UPROPERTY(BlueprintReadOnly, Category="EliminationTimelineEntry")
	float Time;

	UPROPERTY(BlueprintReadOnly, Category="EliminationTimelineEntry")
	bool bStormCircle;

};

UCLASS()
class FORTNITEUI_API UAthenaHUDContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAthenaAutoFireChanged, bool, bEntering);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAthenaHUDAllWinnersAnnounced, const FAthenaWinnerInfo&, WinnerInfo);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCanPTTChange);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClearPlaylistExtensionWidgetNotSupported);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDuelStarted, const EDuelState, DuelState, const FDuelOverlayData&, DuelOverlayData);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFireStopped, int32, StopFireIndex);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnForceAllQuickbarsMinimizedChanged, bool, bEnabled);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnForceStartPostGameFlow);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnForwardStartedFalling);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalPlayerBeginSkydiving);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLocalPlayerDBNOStateChanged, bool, bIsDBNO);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalPlayerDeathOnWin);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLocalPlayerKilledPlayer, const AFortPlayerStateAthena*, Player);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLocalPlayerLost, EEndOfMatchReason, LostReason);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalPlayerWon);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalTeamLost);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalTeamWon);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLowPerformanceMode, bool, bInLowPerformanceMode);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOverrideInventoryPanel, UUserWidget*, Widget);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnEmoteStopped, const UFortItemDefinition*, MontageItemDef, AFortPawn*, PawnEmoting);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerFiredWeapon);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerNameChange, FString, NewName);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlaylistExtensionWidgetCreatedNotSupported, EUIExtensionSlot, ExtensionSlot, UUserWidget*, Widget);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPostGameWidgetPlacement, FName, WidgetPlacement);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRecoverFromPostGameMenu);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResurrectingNow, bool, bResurrectingNow);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShowUrgentQuestMessage, const FUrgentQuestData&, UrgentQuestData, const float, EventTimeRemaining);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSignalQualityChange, float, NewQuality);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpecialActorListChanged);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartPostGameMenu);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPTTStateChange, EPTTState, NewPushToTalkState);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShowMobilePicker);

public:
	UFUNCTION(BlueprintCallable)
	void BeginUseFromHUD();

	UFUNCTION(BlueprintPure)
	bool CanAutoRun() const;

	UFUNCTION(BlueprintPure)
	bool CanCurrentWeaponAutoFireFromReticle() const;

	UFUNCTION(BlueprintPure)
	bool CanShootInVehicle() const;

	UFUNCTION(BlueprintPure)
	bool CurrentWeaponAllowsTargeting() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CycleQuickbar() const;

	UFUNCTION(BlueprintCallable)
	float DisplayPlayerWonTime();

	UFUNCTION(BlueprintPure)
	bool DoesPlaylistUIExtensionSlotContainWidget(EUIExtensionSlot PlaylistSlot) const;

	UFUNCTION(BlueprintCallable)
	void EnableAutoRunFromHUD(bool bEnable);

	UFUNCTION(BlueprintCallable)
	void EndUseFromHUD();

	UFUNCTION(BlueprintCallable)
	void ExecuteActionNameFromHUD(const FName ActionName);

	UFUNCTION(BlueprintCallable)
	void ExecuteActionNameFromHUDWithEventType(const FName ActionName, const EInputEvent KeyEvent);

	UFUNCTION(BlueprintCallable)
	void FireFromHUDStart(int32 TouchIndex, UWidget* DebugWidget = nullptr);

	UFUNCTION(BlueprintCallable)
	void FireFromHUDStop(int32 TouchIndex, UWidget* DebugWidget = nullptr);

	UFUNCTION(BlueprintCallable)
	void ForceFireFromHUDStop();

	UFUNCTION(BlueprintCallable, Category="HUD")
	void ForceStartPostGameFlow();

	UFUNCTION()
	void ForceVictoryRoyaleUI();

	UFUNCTION(BlueprintPure)
	float GetBatteryLevel() const;

	UFUNCTION(BlueprintCallable)
	TArray<FName> GetBoundActions();

	UFUNCTION(BlueprintPure)
	bool GetCanPTT() const;

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UMaterialInterface> GetCustomDBNOReviveMaterial() const;

	UFUNCTION(BlueprintPure)
	TSoftClassPtr<UUserWidget> GetCustomDBNOWidgetClass() const;

	UFUNCTION()
	const TArray<FEliminationTimelineEntry>& GetEliminationTimeline() const;

	UFUNCTION(BlueprintPure)
	float GetGameOverDelayTime() const;

	UFUNCTION(BlueprintPure, Category="HUD")
	FText GetGliderDisplayName() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaHUDInfoDataAsset* GetHUDInfoDataAsset() const;

	UFUNCTION(BlueprintPure)
	bool GetInLowPerformanceMode() const;

	UFUNCTION(BlueprintPure)
	int32 GetInteractPressedTouchIndex() const;

	UFUNCTION(BlueprintPure)
	int32 GetJumpPressedTouchIndex() const;

	UFUNCTION(BlueprintPure)
	bool GetLocalPlayerWonMatch() const;

	UFUNCTION(BlueprintPure)
	void GetLocalTime(int32& Hours, int32& Minutes) const;

	UFUNCTION(BlueprintPure)
	FLinearColor GetPlayerColor() const;

	UFUNCTION(BlueprintPure)
	FString GetPlayerName() const;

	UFUNCTION(BlueprintPure)
	EPTTState GetPTTState() const;

	UFUNCTION(BlueprintPure)
	int32 GetSquadConnectedCount() const;

	UFUNCTION(BlueprintPure)
	int32 GetSquadSize() const;

	UFUNCTION(BlueprintPure)
	ETouchInteractMode GetTouchInteractMode() const;

	UFUNCTION(BlueprintPure)
	USoundCue* GetVictoryStinger() const;

	UFUNCTION(BlueprintPure)
	FText GetVictoryText() const;

	UFUNCTION(BlueprintCallable)
	void GetWinnerText(FText& ReturnText, const FText& WinnerName);

	UFUNCTION(BlueprintPure)
	bool HasAutofireTarget() const;

	UFUNCTION(BlueprintPure)
	bool HasFiringTouch() const;

	UFUNCTION(BlueprintPure)
	bool HasLockOnTarget() const;

	UFUNCTION(BlueprintPure)
	bool HasWifi() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void HideGameModeMessage() const;

	UFUNCTION(BlueprintCallable)
	bool IsActionBound(const FName ActionName);

	UFUNCTION(BlueprintPure)
	bool IsAutoRunEnabled() const;

	UFUNCTION(BlueprintPure)
	bool IsCrouching() const;

	UFUNCTION(BlueprintPure)
	bool IsCurrentWeaponChargeable() const;

	UFUNCTION(BlueprintPure)
	bool IsCurrentWeaponFiring() const;

	UFUNCTION(BlueprintPure)
	bool IsFiringFromTouch(int32 TouchIndex) const;

	UFUNCTION(BlueprintPure)
	bool IsInBuildMode() const;

	UFUNCTION(BlueprintPure)
	bool IsInSelectWidgetToMoveMode() const;

	UFUNCTION(BlueprintPure)
	bool IsMovingSelectedWidget() const;

	UFUNCTION(BlueprintPure)
	bool IsOperatingTurret() const;

	UFUNCTION(BlueprintPure)
	bool IsRunningOnBattery() const;

	UFUNCTION(BlueprintPure)
	bool IsTargeting() const;

	UFUNCTION(BlueprintPure)
	bool IsUsingScope() const;

	UFUNCTION(BlueprintPure)
	bool IsVictoryUICinematic() const;

	UFUNCTION(BlueprintCallable)
	void JumpFromHudEnd();

	UFUNCTION(BlueprintCallable)
	void JumpFromHudStart(int32 TouchIndex);

	UFUNCTION(BlueprintCallable)
	void LookFireFromHUDStart(int32 TouchIndex, UWidget* DebugWidget = nullptr);

	UFUNCTION(BlueprintCallable)
	void LookFireFromHUDStop(int32 TouchIndex, UWidget* DebugWidget = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void OverrideInventoryPanel(UUserWidget* Widget) const;

	UFUNCTION(BlueprintPure)
	bool OwnerOrWeaponHasTag(FGameplayTag InTag) const;

	UFUNCTION(BlueprintCallable)
	void PushGameOverEmoteInput();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void RecoverFromPostGameMenu() const;

	UFUNCTION(BlueprintCallable)
	void ReloadFromHUD();

	UFUNCTION(BlueprintCallable)
	void SelectWidgetToMove(UWidget* Widget);

	UFUNCTION(BlueprintCallable)
	void SetLocalPlayerWonMatch(bool bLocalPlayerWon);

	UFUNCTION(BlueprintCallable)
	void SetLockOnStickCoords(const FVector2D& LockOnCoords);

	UFUNCTION(BlueprintCallable, Category="HUD")
	void SetPostGameWidgetPlacement(FName WidgetPlacement);

	UFUNCTION(BlueprintCallable)
	void SetPTTState(EPTTState NewPushToTalkState);

	UFUNCTION(BlueprintCallable)
	void SetResourceMaterial(EFortResourceType::Type NewMaterial);

	UFUNCTION(BlueprintCallable)
	void SetSelectedInventoryItem(UFortItem* Item);

	UFUNCTION(BlueprintCallable)
	void SetSelectWidgetToMoveMode(bool bSet);

	UFUNCTION(BlueprintCallable)
	void SetTargetingToggleable(const bool bNewValue);

	UFUNCTION(BlueprintCallable)
	bool ShouldAlwaysDisplaySquadInfo();

	UFUNCTION(BlueprintCallable)
	bool ShouldDisplayPlacement();

	UFUNCTION(BlueprintCallable)
	bool ShouldDisplayScoreUI();

	UFUNCTION(BlueprintPure)
	bool ShouldPlayCustomEndScreenAtLoss() const;

	UFUNCTION(BlueprintPure)
	bool ShouldVictoryUIPushEmoteInput() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ShowGameModeMessage() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ShowMarkerGameModeMessage(int32 PlayerID, int32 InstanceID) const;

	UFUNCTION(BlueprintCallable)
	void ShowMobilePicker();

	UFUNCTION(BlueprintCallable)
	void ShowUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData);

	UFUNCTION(BlueprintCallable)
	void SimpleFireStart();

	UFUNCTION(BlueprintCallable)
	void SimpleFireStop();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void StartPostGameMenu() const;

	UFUNCTION(BlueprintCallable)
	void StopItemSelectionInputFromHUD(const int32 TouchIndex, const int32 SlotIdx, EFortQuickBars InQuickBar = EFortQuickBars::Max_None);

	UFUNCTION(BlueprintCallable)
	void StopTargettingFromHUD();

	UFUNCTION(BlueprintCallable)
	void SwapQuickBarFocusFromHUD(EFortQuickBars InQuickBar, int32 SlotOverride = -1);

	UFUNCTION(BlueprintCallable)
	void SwitchToPrimaryQuickbar();

	UFUNCTION(BlueprintCallable)
	void TakeItemSelectionInputFromHUD(const int32 TouchIndex, const int32 SlotIdx, bool& bIsUsing, EFortQuickBars InQuickBar = EFortQuickBars::Max_None, bool bReloadOrUseIfAlreadySelected = true, bool bStopUseImmediately = true);

	UFUNCTION(BlueprintCallable)
	void TakeLookInputFromHUD(FRotator LookRotator);

	UFUNCTION(BlueprintCallable)
	void TakeLookStickInputFromHUD(const FVector2D LookStickPosition);

	UFUNCTION(BlueprintCallable)
	void TakeMovementInputFromHUD(FVector2D MoveVector);

	UFUNCTION(BlueprintCallable)
	void TryBestUseForActor(AActor* ActorToUse);

	UFUNCTION(BlueprintCallable)
	void UpdateSelectedWidgetMoveOffsetVector(const FVector2D& VectorOffset, float fMoveScale = 2.500000f);

	UFUNCTION(BlueprintCallable)
	void UseOrRleoadFromHUDStart();

	UFUNCTION(BlueprintCallable)
	void UseOrRleoadFromHUDStop();

	UFUNCTION(BlueprintPure)
	bool UseTapToShoot() const;

	UFUNCTION(BlueprintPure)
	float VictoryStingerTimeUntilFadeOut() const;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalPlayerWon OnLocalPlayerWon;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalPlayerDeathOnWin OnLocalPlayerDeathOnWin;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalTeamWon OnLocalTeamWon;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalTeamLost OnLocalTeamLost;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalPlayerLost OnLocalPlayerLost;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalPlayerKilledPlayer OnLocalPlayerKilledPlayer;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalPlayerDBNOStateChanged OnLocalPlayerDBNOStateChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPawnEmoteStopped OnPawnEmoteStopped;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnUIGameplayCueEvent OnUIGameplayCue;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLocalPlayerBeginSkydiving OnLocalPlayerBeginSkydiving;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnAthenaAutoFireChanged OnAthenaAutoFireChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerFiredWeapon OnPlayerFiredWeapon;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnShowUrgentQuestMessage OnShowUrgentQuestMessage;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnDuelStarted OnDuelChange;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnLowPerformanceMode OnLowPerformanceMode;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FPTTStateChange OnPTTStateChange;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnCanPTTChange OnCanPTTChange;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FShowMobilePicker ShowMobilePickerDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPlayerNameChange OnPlayerNameChangeDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnResurrectingNow OnResurrectingNowDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnAthenaHUDAllWinnersAnnounced OnAllWinnersAnnouncedDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnSignalQualityChange OnSignalQualityChangeDelegate;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnForwardStartedFalling OnForwardStartedFalling;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnSpecialActorListChanged OnSpecialActorListChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnFireStopped OnFireStopped;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnPostGameWidgetPlacement OnPostGameWidgetPlacementChange;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnForceStartPostGameFlow OnForceStartPostGameFlow;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnForceAllQuickbarsMinimizedChanged OnForceAllQuickbarsMinimizedChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="HUD")
	FOnPlaylistExtensionWidgetCreatedNotSupported OnPlaylistExtensionWidgetCreatedNotSupported;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnClearPlaylistExtensionWidgetNotSupported OnClearPlaylistExtensionWidgetNotSupported;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnStartPostGameMenu OnStartPostGameMenu;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnRecoverFromPostGameMenu OnRecoverFromPostGameMenu;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnOverrideInventoryPanel OnOverrideInventoryPanel;

private:
	UFUNCTION()
	void ForwardOnSpecialActorListChanged(const FSpecialActorRepData& SpecialActorData);

	UFUNCTION()
	void HandleLocalPlayerBeginSkydiving();

	UFUNCTION()
	void HandleLocalPlayerDBNOStateChanged(AFortPawn* FortPawn, bool bIsDBNO);

	UFUNCTION()
	void HandleOnNPCConvertEvent(AFortPawn* ConvertedFortPawn);

	UFUNCTION()
	void HandleOnNPCUnconvertEvent(AFortPawn* UnconvertedFortPawn, EUnconvertReason UnconvertReason);

	UFUNCTION()
	void HandlePawnEmoteStopped(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void HandleSpectatorViewTargetChanged();

	UFUNCTION()
	void HandleUIGameplayCue(FName CueName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters);

	UFUNCTION()
	void HandleWeaponChanged(AFortPawn* InPawn, AFortWeapon* InNewWeapon, AFortWeapon* InPlayerWeapon);

	UFUNCTION()
	void OnAllWinnersAnnounced();

	UFUNCTION()
	void OnReadyForWinnerInfoDisplay();

	UPROPERTY()
	TArray<FEliminationTimelineEntry> EliminationTimeline;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UWidget> MoveButtonWidgetPtr;

	UPROPERTY()
	FAthenaWinnerInfo WinnerInfo;

	UPROPERTY(Transient)
	bool bMoveButtonMode;

	UPROPERTY(Transient)
	bool bPendingAttachToHUD;

	UPROPERTY(Transient)
	bool bLocalPlayerWonMatch;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawnAthena> BoundPlayerPawn;

	UPROPERTY()
	TObjectPtr<UAthenaPlayerViewModel> PlayerViewModel;

};

