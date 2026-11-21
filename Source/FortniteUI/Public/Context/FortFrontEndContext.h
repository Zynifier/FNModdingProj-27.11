// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Misc/Timespan.h"
#include "Styling/SlateBrush.h"
#include "BlueprintContext/FortLocalPlayerSubsystem.h"
#include "CatalogTypes.h"
#include "FortItemQuantityPair.h"
#include "FortPawnDisplayContextEnum.h"
#include "STW/AI/GameDifficulty/FortGameDifficultyCalculationData.h"
#include "UI/FrontEnd/FortTheaterInfo.h"
#include "FortFrontEndContext.generated.h"

class AFortPlayerPawn;
class AFortTheaterMapTile;
class UAthenaCosmeticItemDefinition;
class UFortCloudSaveItemDefinition;
class UFortGameplayModifierItemDefinition;
class UFortItem;
class UFortItemDefinition;
class UFortMissionGenerator;
class UFortOutpostItemDefinition;
class UFortQuestItem;
class UFortServerBrowserHelper;
class UFortSocialImportPanel;
class UFortWorldItem;
class UObject;
class USlateBrushAsset;
class UWidget;
enum class EAthenaCustomizationCategory : uint8;
enum class EFortFrontEndFeature : uint8;
enum class EFortFrontEndFeatureState : uint8;
enum class EFortFrontEndFeatureStateReason : uint8;
enum class EFortFrontendInventoryFilter : uint8;
enum class EFortPawnDisplayContext : uint8;
enum class EFrontEndCamera : uint8;

UENUM(BlueprintType)
enum class EFortFrontEndFeature : uint8
{
	/** If the player has access to the primary HomeBase tab */
	ShowHomeBase = 0,
	/** If the player should see the hero list on the home base */
	ShowHeroList = 1,
	/** If the player has access to the vault */
	ShowVault = 2,
	/** If the player is able to open the store tab */
	ShowStore = 3,
	/** If the player is able to play a zone */
	PlayZone = 4,
	/** If the player should see the hero select screen for entering the zone */
	ShowHeroSelect = 5,
	/** If the player is allowed to recruit a new hero */
	RecruitHero = 6,
	/** Show the home base overview screen */
	ShowHomeBaseOverview = 7,
	/** Controls access to the transform screen, which is accessible from the STW armory tab */
	STWArmory_Transform = 8,
	/** Controls access to the collection book screen, which is accessible from the STW armory tab */
	STWArmory_CollectionBook = 9,
	/** Size of the feature list */
	MAX_None = 10 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortFrontEndFeatureState : uint8
{
	/** Feature is fully enabled */
	Enabled = 0,
	/** Feature is disabled but visible to the user*/
	Disabled = 1,
	/** Feature is disabled and hidden from the user*/
	Hidden = 2,
	Invalid = 3,
};

UENUM(BlueprintType)
enum class EFortFrontEndFeatureStateReason : uint8
{
	/** No specific reason provided.  Generally for Enabled states.*/
	Default = 0,
	/** Disabled and hidden states */
	NoHeroes = 1,
	Tutorial = 2,
	BROnly = 3,
	/** Invalid states */
	NoPlayerController = 4,
	UnexpectedFeature = 5,
	Invalid = 6,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFrontEndFeatureStateChangedDelegate, EFortFrontEndFeature, ChangedFeature, EFortFrontEndFeatureState, NewState, EFortFrontEndFeatureStateReason, Reason);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FFrontEndFeatureStateChangedListener, EFortFrontEndFeature, ChangedFeature, EFortFrontEndFeatureState, NewState, EFortFrontEndFeatureStateReason, Reason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLobbyPlayerGadgetsClickedDelegate, int32, PlayerIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCameraChangedDelegate, EFrontEndCamera, NewCamera, EFrontEndCamera, OldCamera);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLobbyPlayerMutingChangedDelegate, FUniqueNetIdRepl, UniqueId, bool, bMuted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLobbyPlayerTalkingChangedDelegate, FUniqueNetIdRepl, UniqueId, bool, bTalking);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyPlayersStoppedTalkingDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMainTabSelectedDelegate, FName, TabName);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRadialPickerStatusChanged, bool, Opened);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSocialImportClosedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerLoginDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSeasonTabVariantPreviewInfoChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetPreviewedSceneTheaterDelegate, FString, TheaterId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShouldShowPhoenixDisplayChanged, bool, ShouldShowPhoenixDisplay);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTheaterDataChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTheaterPinClickedDelegate, FString, TheaterId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTheaterSelectedDelegate, FString, TheaterId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTheaterTileClickedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTheaterTileDoubleClickedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTheaterTileFocusedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVaultItemViewed, const UFortItem*, Item);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVaultItemsViewed, const TArray<UFortItem*>&, Items);

USTRUCT()
struct FFortFrontEndFeatureStruct
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortFrontEndFeatureState CurrentState;

	UPROPERTY()
	EFortFrontEndFeatureState ForcedState;

	UPROPERTY()
	EFortFrontEndFeatureStateReason ForcedStateReason;

	UPROPERTY()
	FFrontEndFeatureStateChangedDelegate ChangeDelegate;

};

USTRUCT(BlueprintType)
struct FFortMissionRewardInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortMissionRewardInfo")
	FSlateBrush Icon;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionRewardInfo")
	FText DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionRewardInfo")
	TObjectPtr<UFortItem> Item;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionRewardInfo")
	bool bIsMissionAlertReward;

};

USTRUCT(BlueprintType)
struct FFortMissionDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	EFortTheaterMapTileType TileType;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FText TheaterDisplayName;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FText MissionName;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FText MissionDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	bool bIsGroupContent;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	TObjectPtr<UFortMissionGenerator> MissionDefinition;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FText ZoneName;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FText ZoneDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FText RegionThemeName;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	TSoftObjectPtr<USlateBrushAsset> RegionThemeIcon;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FText DifficultyName;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	TArray<FFortMissionRewardInfo> MissionRewards;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FTimespan AvailableTime;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	ERatingsEnforcementType RatingsEnforcement;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	int32 RequiredBaseRating;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	int32 RecommendedBaseRating;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	int32 MaxBaseRating;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	int32 ContentDifficultyLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	bool bIsOnboarding;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	int32 LootLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	bool bOverrideConningText;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FText ConningOverrideText;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	FString TheaterUniqueId;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	TObjectPtr<UFortCloudSaveItemDefinition> AssociatedCloudSaveItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> GameplayModifiers;

	UPROPERTY(BlueprintReadOnly, Category="FortMissionDetails")
	TArray<FText> Objectives;

};

USTRUCT(BlueprintType)
struct FUnlockableVariantPreviewInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UnlockableVariantPreviewInfo")
	bool bIsValid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UnlockableVariantPreviewInfo")
	int32 SetNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UnlockableVariantPreviewInfo")
	int32 SetCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UnlockableVariantPreviewInfo", meta=(MultiLine="true"))
	FText UnlockCondition;

};

USTRUCT()
struct FViewVaultItemsParams
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> ItemsToView;

};

UCLASS()
class FORTNITEUI_API UFortFrontEndContext : public UFortLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AccountItemWarning")
	void AccountItemWarningShown();

	UFUNCTION(BlueprintPure, Category="FrontEndContext")
	bool AreProfilesAvailableForWriting() const;

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void BroadcastMainTabSelected(FName TabName);

	UFUNCTION(BlueprintPure, Category="Theater")
	bool CanCompleteQuestInFocusedOrActiveTileMission(UFortQuestItem* QuestItem) const;

	UFUNCTION(BlueprintCallable, Category="Theater")
	bool CanFindTileForQuest(UFortQuestItem* QuestItem);

	UFUNCTION(BlueprintPure, Category="FrontEndLobby")
	bool CanShowLockerSlotType(EAthenaCustomizationCategory SlotType) const;

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void ClearLocalPreview(bool StopUsingLocalPreview);

	UFUNCTION(BlueprintCallable, Category="Theater")
	void ClearSelectedTheater();

	UFUNCTION(BlueprintPure, Category="FrontEndContext")
	void GetAccountLevelUpRewards(TArray<FFortItemQuantityPair>& Rewards, int32 AccountLevel) const;

	UFUNCTION(BlueprintPure, Category="Theater")
	AFortTheaterMapTile* GetActiveTile() const;

	UFUNCTION(BlueprintPure, Category="Theater")
	bool GetActiveTileMissionDetails(FFortMissionDetails& MissionDetails) const;

	UFUNCTION(BlueprintPure, Category="Theater")
	bool GetAllTheaterData(TArray<FFortTheaterMapData>& OutAllTheaterData) const;

	UFUNCTION(BlueprintPure, Category="FrontEndContext")
	TArray<FGameDifficultyInfo> GetAvailableDifficulties(bool bIncludeMissionAlertTiles) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	void GetCriticalMissionRewards(TArray<FFortMissionRewardInfo>& RewardList) const;

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	int32 GetCurrentLockerSubslotIndex();

	UFUNCTION(BlueprintPure, Category="Theater")
	FText GetCurrentTheaterName() const;

	UFUNCTION(BlueprintPure, Category="FrontEnd")
	void GetFeatureState(const EFortFrontEndFeature Feature, EFortFrontEndFeatureState& OutFeatureState, EFortFrontEndFeatureStateReason& OutReason) const;

	UFUNCTION(BlueprintPure, Category="Theater")
	AFortTheaterMapTile* GetFocusedOrActiveTile() const;

	UFUNCTION(BlueprintPure, Category="Theater")
	bool GetFocusedOrActiveTileMissionDetails(FFortMissionDetails& MissionDetails) const;

	UFUNCTION(BlueprintPure, Category="FrontEndCamera")
	EFrontEndCamera GetFrontEndCamera() const;

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	AFortPlayerPawn* GetHeroPlayerPawnByIndex(int32 PartyMemberIndex);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	AFortPlayerPawn* GetHeroPlayerPawnForCurrentDisplayedItem();

	UFUNCTION(BlueprintPure, Category="Outpost")
	bool GetHighestEnduranceWaveReachedByItemDefinition(UFortOutpostItemDefinition* OutpostCoreItemDef, int32& HighestWaveNumber) const;

	UFUNCTION(BlueprintPure, Category="AccountItemWarning")
	EFortFrontendInventoryFilter GetInventoryFilterForAccountItemWarning() const;

	UFUNCTION(BlueprintPure, Category="FrontEndContext")
	UFortItemDefinition* GetItemFromItemQuantityPair(const FFortItemQuantityPair& InPair) const;

	UFUNCTION(BlueprintPure, Category="FrontEndContext")
	FGameDifficultyInfo GetMaxAvailableDifficulty(bool bIncludeMissionAlertTiles) const;

	UFUNCTION(BlueprintPure, Category="FrontEnd")
	FText GetMCPRegion() const;

	UFUNCTION(BlueprintPure, Category="FrontEnd")
	FText GetMCPRegionText() const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	bool GetOutpostCoreLevelByItemDefinition(UFortOutpostItemDefinition* OutpostCoreItemDef, int32& OutCoreLevel) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	bool GetOutpostCoreLevelByTheaterId(const FString& TheaterId, int32& OutCoreLevel) const;

	UFUNCTION(BlueprintPure, Category="FrontEndContext")
	void GetPostMaxAccountLevelUpRewards(TArray<FFortItemQuantityPair>& Rewards, int32 RewardOffset = 0) const;

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	FUnlockableVariantPreviewInfo GetSeasonTabVariantPreviewInfo();

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void GetSelectableGadgets(TArray<UFortWorldItem*>& SelectableGadgets, TArray<UFortWorldItem*>& LastSelectedGadgets);

	UFUNCTION(BlueprintPure, Category="Theater")
	bool GetSelectedTheaterData(FFortTheaterMapData& OutTheaterData) const;

	UFUNCTION(BlueprintPure, Category="Theater")
	FString GetSelectedTheaterId() const;

	UFUNCTION(BlueprintPure, Category="Theater")
	bool GetTheaterData(const FString& TheaterId, FFortTheaterMapData& OutTheaterData) const;

	UFUNCTION(BlueprintPure, Category="Theater")
	bool GetTileMissionDetails(const AFortTheaterMapTile* Tile, FFortMissionDetails& MissionDetails) const;

	UFUNCTION(BlueprintPure, Category="Theater")
	bool GetUIOrderedAllTheaterData(TArray<FFortTheaterMapData>& OutAllTheaterData) const;

	UFUNCTION(BlueprintPure, Category="FrontEndContext")
	UClass* GetUITestingClass() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void HideAthenaStoreNewItemBang() const;

	UFUNCTION(BlueprintPure, Category="Theater")
	bool Is4PlayerTile(const AFortTheaterMapTile* Tile) const;

	UFUNCTION(BlueprintCallable, Category="Theater")
	bool IsActiveTileMissionValid();

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	bool IsCelebrateEffectPlaying();

	UFUNCTION(BlueprintPure, Category="Theater")
	bool IsTileMissionAlertRewardClaimed(const AFortTheaterMapTile* Tile) const;

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void PlayEvolutionEffect();

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void PlayLevelUpEffect();

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void PushContentWidget_Adv(UWidget* Widget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget);

	UFUNCTION(BlueprintCallable, Category="Theater")
	void SelectDefaultTheater();

	UFUNCTION(BlueprintCallable, Category="Theater")
	void SelectDefaultTheaterTile();

	UFUNCTION(BlueprintCallable, Category="Theater")
	bool SelectTileForQuest(UFortQuestItem* QuestItem, float& OutCriticalMissionDifficultyOverrideMin, float& OutCriticalMissionDifficultyOverrideMax);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void SetCurrentLockerSubslotIndex(int32 NewIndex);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void SetDefaultLocalVariantPreview(const UAthenaCosmeticItemDefinition* CosmeticItem);

	UFUNCTION(BlueprintCallable, Category="FrontEndCamera", meta=(CPP_Default_TransitionParams="()"))
	void SetFrontEndCamera(EFrontEndCamera NewState, FViewTargetTransitionParams TransitionParams);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void SetFrontEndVisibility(bool bHideHeader, bool bHideFooter, bool bHideChatWidget);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext", meta=(AdvancedDisplay="CustomData", AutoCreateRefTerm="CustomData"))
	void SetLocalVariantPreview(const UAthenaCosmeticItemDefinition* CosmeticItem, FGameplayTag VariantChannelTag, FGameplayTag VariantTag, const FString& CustomData);

	UFUNCTION(BlueprintCallable, Category="Season")
	void SetSeasonTabVariantPreviewInfo(FUnlockableVariantPreviewInfo Info);

	UFUNCTION(BlueprintCallable, Category="Theater")
	void SetSelectedTheater(const FString& TheaterId);

	UFUNCTION(BlueprintPure, Category="AccountItemWarning")
	bool ShouldShowAccountItemWarning() const;

	UFUNCTION(BlueprintPure, Category="FrontEndContext")
	bool ShouldShowPhoenixDisplay() const;

	UFUNCTION(BlueprintPure, Category="SocialImport")
	bool ShouldShowSocialImport() const;

	UFUNCTION(BlueprintCallable, Category="SocialImport")
	UFortSocialImportPanel* ShowSocialImport(TSubclassOf<UFortSocialImportPanel> PanelClass);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void ViewVaultItem(const UFortItem* ItemToView, bool bIgnoreCurrentlyEquippedFavorites, EFortPawnDisplayContext DisplayContext = EFortPawnDisplayContext::VaultItem);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void ViewVaultItemFromDefinition(const UFortItemDefinition* ItemToViewDefinition, bool bIgnoreCurrentlyEquippedFavorites, EFortPawnDisplayContext DisplayContext = EFortPawnDisplayContext::VaultItemFromDefinition);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void ViewVaultItems(const TArray<UFortItem*>& ItemsToView, bool bIgnoreCurrentlyEquippedFavorites, EFortPawnDisplayContext DisplayContext = EFortPawnDisplayContext::VaultItems);

	UFUNCTION(BlueprintCallable, Category="FrontEndContext")
	void ViewVaultItemsFromOffer(const FCatalogOffer& CatalogOffer, bool bIgnoreCurrentlyEquippedFavorites, EFortPawnDisplayContext DisplayContext = EFortPawnDisplayContext::VaultItemFromDefinition);

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="FrontEndLobby")
	FLobbyPlayerGadgetsClickedDelegate OnLobbyPlayerGadgetsClicked;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="FrontEndLobby")
	FOnRadialPickerStatusChanged OnRadialPickerStatusChanged;

	UPROPERTY(BlueprintAssignable, Category="FrontEndCamera")
	FOnCameraChangedDelegate OnFrontEndCameraChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Theater")
	FTheaterPinClickedDelegate OnTheaterPinClicked;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Theater")
	FSetPreviewedSceneTheaterDelegate OnSetPreviewedSceneTheater;

	UPROPERTY(BlueprintAssignable, Category="Theater")
	FTheaterSelectedDelegate OnTheaterSelected;

	UPROPERTY(BlueprintAssignable, Category="Theater")
	FTheaterDataChangedDelegate OnTheaterDataChanged;

	UPROPERTY(BlueprintAssignable, Category="Theater")
	FTheaterTileClickedDelegate OnTheaterTileClicked;

	UPROPERTY(BlueprintAssignable, Category="Theater")
	FTheaterTileDoubleClickedDelegate OnTheaterTileDoubleClicked;

	UPROPERTY(BlueprintAssignable, Category="Theater")
	FTheaterTileFocusedDelegate OnTheaterTileFocused;

	UPROPERTY(BlueprintAssignable, Category="Theater")
	FTheaterTileFocusedDelegate OnTheaterTileUnfocused;

	UPROPERTY(BlueprintAssignable, Category="Theater")
	FShouldShowPhoenixDisplayChanged OnShouldShowPhoenixDisplayChanged;

	UPROPERTY(BlueprintAssignable, Category="FrontEndContext")
	FVaultItemViewed OnVaultItemViewed;

	UPROPERTY(BlueprintAssignable, Category="FrontEndContext")
	FVaultItemsViewed OnVaultItemsViewed;

	UPROPERTY(BlueprintAssignable, Category="Season")
	FSeasonTabVariantPreviewInfoChanged OnSeasonTabVariantPreviewInfoChanged;

	UPROPERTY(BlueprintAssignable, Category="FrontEndContext")
	FPlayerLoginDelegate OnPlayerLoggedOut;

	UPROPERTY(BlueprintAssignable, Category="FrontEndContext")
	FOnMainTabSelectedDelegate OnMainTabSelected;

	UPROPERTY(BlueprintAssignable, Category="SocialImport")
	FOnSocialImportClosedDelegate OnSocialImportClosed;

private:
	UFUNCTION()
	void HandleDynamicSocialImportClosed();

	UFUNCTION()
	void OnPlayerProfileInitialized();

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteUI.EFortFrontEndFeature"))
	FFortFrontEndFeatureStruct Features[10];

	UPROPERTY(Transient)
	FUnlockableVariantPreviewInfo SeasonTabVariantPreviewInfo;

	UPROPERTY()
	TObjectPtr<UFortServerBrowserHelper> ServerBrowserHelper;

};

