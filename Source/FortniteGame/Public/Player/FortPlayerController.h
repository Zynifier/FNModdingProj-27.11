// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CommonInputTypeEnum.h"
#include "Curves/CurveFloat.h"
#include "Engine/DataTable.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Online/CoreOnline.h"
#include "UObject/PrimaryAssetId.h"
#include "Abilities/AttributeModifierInfo.h"
#include "Analytics/FortAnalyticsControllerInterface.h"
#include "Building/BuildingClassData.h"
#include "Building/BuildingTypes.h"
#include "Building/BuildingWeakSpot.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/FortCosmeticLoadoutOwner.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Creative/FortCreativeEventSystemType.h"
#include "FGF_PlayerController.h"
#include "FortChoiceData.h"
#include "FortClientSettingsRecord.h"
#include "FortCompositeBool.h"
#include "FortDamageNumbersActor.h"
#include "FortDamageZoneEnum.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortGameplayStateEnum.h"
#include "FortItemVariantHandle.h"
#include "FortRequirementsInfo.h"
#include "FortSubGameTypes.h"
#include "FortTeamActorInterface.h"
#include "FortTypes.h"
#include "FortVehicleUserInterface.h"
#include "Items/FortInventoryOwnerInterface.h"
#include "Items/FortItemEntry.h"
#include "Items/FortPersistentGameplayStatValue.h"
#include "Items/FortPersistentTypes.h"
#include "Items/FortQuickBars.h"
#include "Items/FortRewardReport.h"
#include "McpProfileUpdateTypes.h"
#include "Online/Collections/FortCollectionsTypes.h"
#include "Pawns/FortPlayerPawn.h"
#include "FortPlayerController.generated.h"

class AActor;
class ABattleMapPawnLive;
class ABuildingActor;
class ABuildingPlayerPrimitivePreview;
class ABuildingSMActor;
class ABuildingTrapDefender;
class ABuildingWeakSpot;
class AController;
class AFortAIDirectorDataManager;
class AFortAIPawn;
class AFortDamageNumbersActor;
class AFortDecoHelper;
class AFortInventory;
class AFortMarkActor;
class AFortMinigameSettingsBuilding;
class AFortMusicManager;
class AFortObjectiveBase;
class AFortPawn;
class AFortPickup;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortQuickBars;
class AFortReplayMovableSpotLight;
class AFortSprayDecalInstance;
class AFortVolume;
class AFortWeapon;
class APawn;
class UActorComponent;
class UAthenaCharacterItemDefinition;
class UAthenaCosmeticItemDefinition;
class UAthenaItemWrapDefinition;
class UAthenaMarkerComponent;
class UAudioComponent;
class UBuildingEditModeMetadata;
class UForceFeedbackEffect;
class UFortAbilitySystemComponent;
class UFortAccountItem;
class UFortAccountItemDefinition;
class UFortCinematicCamera;
class UFortClientBotManager;
class UFortClientPilot_Base;
class UFortCollectionBookManager;
class UFortControllerComponent;
class UFortControllerComponent_Aircraft;
class UFortControllerComponent_Collections;
class UFortControllerComponent_CosmeticLoadout;
class UFortControllerComponent_InputContextTracker;
class UFortControllerComponent_Interaction;
class UFortControllerComponent_InventoryNetworkManagement;
class UFortControllerComponent_Minimap;
class UFortControllerComponent_PinQuest;
class UFortControllerComponent_QuestGates;
class UFortControllerComponent_Quests;
class UFortControllerComponent_QuickEdit;
class UFortControllerComponent_SharedQuests;
class UFortControllerComponent_SmartBuild;
class UFortControllerComponent_StreamingSources;
class UFortControllerComponent_SurvivorTiers;
class UFortControllerComponent_Telemetry;
class UFortCustomizationAssetLoader;
class UFortDefenderItem;
class UFortGameplayAbility;
class UFortGameplayMessageComponentBase;
class UFortIndicatorManager;
class UFortInteractContextInfoWidget;
class UFortItem;
class UFortItemDefinition;
class UFortLevelStreamComponent;
class UFortMcpProfileAthena;
class UFortMcpProfileCampaign;
class UFortMcpProfileCommonCore;
class UFortMcpProfileCommonPublic;
class UFortMcpProfileCreative;
class UFortMcpProfileMetadata;
class UFortMinigameItemContainerComponent;
class UFortMinigameManager;
class UFortMontageItemDefinitionBase;
class UFortQuestItemDefinition;
class UFortQuestManager;
class UFortRegisteredPlayerInfo;
class UFortStatEventManager;
class UFortWorldItem;
class UHeartbeatManager;
class UInputComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMaterialParameterCollection;
class UMcpProfileGroup;
class UMediaPlayer;
class UMediaSource;
class UObject;
class UQuickHealItemPicker;
class USceneComponent;
class USoundBase;
class USoundEffectSourcePresetChain;
class USoundMix;
class UStatManager;
class UStreamMediaSource;
class UUserWidget;
class UWidget;
enum class EAthenaCustomizationCategory : uint8;
enum class EFortCollectedVariantClientUpdate : int32;
enum class EFortEmotePlayMode : uint8;
enum class EFortItemTier : uint8;
enum class EFortItemType : uint8;
enum class EFortObjectiveStatus : uint8;
enum class EFortQuestObjectiveStatEvent : uint8;
enum class EFortQuickBars : uint8;
enum class ELockOnState : uint8;
enum class ERichPresenceStateChange : uint8;
enum class ESpatialLoadingState : uint8;
enum class EStatCategory : uint8;
enum class EStatMod : uint8;
enum class EStatRecordingPeriod : uint8;
enum class ESubGame : uint8;

UENUM()
enum class ECreativeQuickbarSlots : uint8
{
	// This is setup in PlayerController data for the creative quickslot, if we change this it also needs to be updated there.

	Phone = 0,
	Max_None = 1,
};

UENUM()
enum class EFortBuildPreviewMarkerOptionalAdjustment : uint8
{
	/** Do nothing, let the default placement work. */
	None = 0,
	/** The current piece is too far in the terrain. Build a free piece on top of this one. */
	FreeWallPieceOnTop = 1,
	/** The current piece is above the terrain but leaves a gap under it. Build a free piece below this one. */
	FreeWallPieceOnBottom = 2,
};

UENUM()
enum class EFortCrucibleWhitelistLevel : uint8
{
	None = 0,
	Basic = 1,
	Advanced = 2,
};

UENUM()
enum class EFortDelayedQuickBarAction : uint8
{
	Add = 0,
	Remove = 1,
	Replace = 2,
	Invalid = 3,
};

UENUM()
enum class EFortEmotePlayMode : uint8
{
	CheckIfOwned = 0,
	ForcePlay = 1,
};

UENUM(BlueprintType)
enum class EFortPCTutorialCompletedState : uint8
{
	Unknown = 0,
	Incomplete = 1,
	Complete = 2,
};

UENUM()
enum class EFortPickerToDisplay : uint8
{
	TrapPicker = 0,
	SocialPicker = 1,
	ChatPicker = 2,
	NotePicker = 3,
	EmotePicker = 4,
	SquadQuickChatPicker = 5,
	MusicSourcePicker = 6,
	NPCCommandPicker = 7,
	SquadRequestPicker = 8,
};

UENUM(BlueprintType)
enum class ELockOnState : uint8
{
	NoTarget = 0,
	// No targets under the reticle

	TargetAcquired = 1,
	// Target just got under the reticle

	LockingOnToTarget = 2,
	// Interpolating the camera to the lock on point

	TargetLockedOn = 3,
	// Locked on to the target

	Cooldown = 4,
	// Cannot lock on to a target for a while

	COUNT = 5,
};

UENUM()
enum class EQuickbarSlots : uint8
{
	HarvestingTool = 0,
	Weapon1 = 1,
	Weapon2 = 2,
	Weapon3 = 3,
	Consumable = 4,
	Gadget1 = 5,
	Gadget2 = 6,
	Ability1 = 7,
	Ability2 = 8,
	Ability3 = 9,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortPlayerControllerOnLoadoutChanged, AFortPlayerController*, PlayerController, const FFortAthenaLoadout&, Loadout);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortPlayerControllerOnPickupCreated, const AFortPlayerController*, PlayerController, AFortPickup*, Pickup);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAttributeSourcesReceived, const FGameplayAttribute&, Attribute);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAutoRunEnabled, bool, bAutoRunEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBoundActionFreed, FName, ActionFreed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBuildPreviewMarkerVisibilityChanged, const bool, bHidden);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChosenSignature, int32, ChosenIndex, int32, MenuIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClientRefreshHUDForRespawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDelayForPreServerTransitionAnimation, float, DelayLength);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnterVehicleDriver);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnterVehiclePassenger);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnteredEditMode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExitVehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImprovedDBNOStateChanged, bool, bImprovedDBNOEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInputActionHoldStarted, FName, InputActionName, float, Duration);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInputActionHoldStopped, FName, InputActionName, bool, bCompletedSuccessfully);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInteractContextOverrideAdded, TSubclassOf<UFortInteractContextInfoWidget>, ContextOverride, bool, bPrimary);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInteractContextOverrideRemoved, TSubclassOf<UFortInteractContextInfoWidget>, ContextOverride, bool, bPrimary);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMcpProfilesInitialized);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNotifyInputFiltered, ECommonInputType, AttemptedInputType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenVoteDialog);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerEnteredBuildMode, bool, bEnteredBuildMode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerPawnPossessed, APawn*, PossessedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerSpawnedBuildingActor, AFortPlayerController*, Spawner, ABuildingActor*, SpawnedBuilding);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnQuestObjectiveStateChanged, AFortPlayerController*, Controller, const UFortQuestItemDefinition*, QuestDef, FName, BackendName, int32, CompletionCount, bool, ObjectiveCompleted, bool, QuestCompleted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReadyCheckCompleteBP, bool, Result);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRegainedFocus);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReloadCancelingSprint);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetFirstPersonCamera, bool, bFirstPersonCameraEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowFPSChange, bool, bShowFPS);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowTemperatureChange, bool, bShowTemperature);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTetherChanged, bool, bIsTethered);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVehicleAbilitiesRemoved, AFortPlayerController*, ExitedPlayerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnVehicleSeatChangedComplete);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVehicleSeatChanged, const int32, SeatIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnViewTargetChanged, AFortPlayerController*, PlayerController, AActor*, OldViewTarget, AActor*, NewViewTarget);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeakSpotReset, AFortPlayerController*, Controller, const ABuildingSMActor*, ParentBuilding);

USTRUCT()
struct FAIDirectorDebugInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float TimeStamp;

	UPROPERTY(Transient)
	TArray<float> DebugGraphData;

};

USTRUCT()
struct FCraftingQueueInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FCreateBuildingActorData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	uint32 BuildingClassHandle;

	UPROPERTY(Transient)
	FVector_NetQuantize10 BuildLoc;

	UPROPERTY(Transient)
	FRotator BuildRot;

	UPROPERTY(Transient)
	bool bMirrored;

	UPROPERTY(Transient)
	float SyncKey;

private:
	UPROPERTY(Transient)
	FBuildingClassData BuildingClassData;

};

USTRUCT()
struct FCreativeToolPersistentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 GridSnapIndex;

	UPROPERTY()
	uint8 RotationAxisIndex;

	UPROPERTY()
	uint8 SelectedScaleAxis;

	UPROPERTY()
	bool bShouldUsePrecisionGridSnapping;

	UPROPERTY()
	bool bAllowGravityOnPlace;

	UPROPERTY()
	bool bShouldDestroyPropsWhenPlacing;

	UPROPERTY()
	uint8 HitTraceRule;

	UPROPERTY()
	bool bIsScalingInsteadOfRotating;

};

USTRUCT()
struct FDelayedQuickBarAction : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 ActionId;

	UPROPERTY()
	EFortDelayedQuickBarAction Action;

	UPROPERTY()
	FGuid ItemGuid;

	UPROPERTY()
	FPrimaryAssetId ItemDefinitionAssetId;

	UPROPERTY()
	EFortQuickBars QuickBarType;

	UPROPERTY()
	int32 QuickBarSlot;

	UPROPERTY()
	bool bForceExecution;

};

USTRUCT()
struct FDelayedQuickBarActionContainer : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FDelayedQuickBarAction> Items;

};

USTRUCT(BlueprintType)
struct FFortPickupTossOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortPickupTossOverrideData")
	bool bIsValid;

	UPROPERTY(BlueprintReadWrite, Category="FortPickupTossOverrideData")
	float MinTossDist;

	UPROPERTY(BlueprintReadWrite, Category="FortPickupTossOverrideData")
	float MaxTossDist;

	UPROPERTY(BlueprintReadWrite, Category="FortPickupTossOverrideData")
	float SpawnDirectionConeHalfAngle;

};

USTRUCT()
struct FFortPipTest : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Picture-in-Picture Test")
	TObjectPtr<UMediaPlayer> MediaPlayer;

	UPROPERTY(EditDefaultsOnly, Category="Picture-in-Picture Test")
	TObjectPtr<UStreamMediaSource> StreamMediaSource;

	UPROPERTY(EditDefaultsOnly, Category="Picture-in-Picture Test")
	TSubclassOf<UObject> WidgetClass;

};

USTRUCT()
struct FFortPlayerControllerDuringPhysicsTickFunction : public FActorTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FFortPlayerControllerDuringPhysicsTickFunction> : public TStructOpsTypeTraitsBase2<FFortPlayerControllerDuringPhysicsTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

USTRUCT()
struct FFortRebootEligiblePartyFriendInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl UserId;

	UPROPERTY()
	bool bIsPlatformFriend;

};

USTRUCT()
struct FLastBuildableState
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeMetadata> LastBuildableMetaData;

	UPROPERTY(Transient)
	bool LastBuildableMirrored;

	UPROPERTY(Transient)
	int32 LastBuildableRotationIterations;

};

USTRUCT()
struct FLockOnInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	ELockOnState State;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> Weapon;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> LockOnTarget;

	UPROPERTY(Transient)
	FRotator CamRotAtTargetAcquisiton;

	UPROPERTY(Transient)
	FVector2D LockOnCoords;

	UPROPERTY(Transient)
	float TargetAcquisitionTime;

	UPROPERTY(Transient)
	float TargetLockOnTime;

	UPROPERTY(Transient)
	float TargetOutOfSightTime;

	UPROPERTY(Transient)
	float CooldownStartTime;

};

USTRUCT()
struct FQueuedItemsToDropViaPickup
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> DestructionPawn;

	UPROPERTY(Transient)
	int32 TotalNumItemsToDrop;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortWorldItem>> ItemsToDrop;

};

USTRUCT()
struct FRecentlyRemovedQuickbarInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid ItemGuid;

	UPROPERTY()
	int32 RemovedFromSlot;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDefinition;

};

USTRUCT(BlueprintType)
struct FServerSideHitMarker
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FVoiceChatDistanceAttenuationSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VoiceChat|Attenuation", meta=(Keywords="Voice Chat"))
	FVector2D DistanceRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VoiceChat|Attenuation", meta=(Keywords="Voice Chat"))
	FRuntimeFloatCurve AttenuationCurve;

};

USTRUCT()
struct FVoiceChatUsageAnalytics
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerController : public AFGF_PlayerController, public ICosmeticLoadoutOwner, public IFortAnalyticsControllerInterface, public IFortInventoryOwnerInterface, public IFortTeamActorInterface, public IFortVehicleUserInterface, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFortPawnChanged, AFortPawn*, NewPawn);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerControllerComponentAttached, AFortPlayerController*, OwnerController, UFortControllerComponent*, AttachedComponent);

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(CPP_Default_bIsCriticalDamage="false", CPP_Default_OverridePosition, CPP_Default_HitNormal))
	virtual void AddDamageNumber(float Damage, AActor* DamagedActor, APawn* DamageCauser, const FGameplayEffectContextHandle& EffectContext, const FGameplayTagContainer& DamageTags, bool bIsCriticalDamage, const FVector& OverridePosition, const FVector& HitNormal, bool bShowZeroDamage = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	virtual void AddInventoryItemWithAlterationBasedOnLootLevel(FFortItemEntry ItemDescription);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(CPP_Default_OverrideSpawnLocation))
	virtual void AddInventoryItemWithAnimation(const FFortItemEntry& ItemDescription, const FVector OverrideSpawnLocation);

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void AddItemToQuickBars(UFortItemDefinition* ItemDefinition, EFortQuickBars QuickBarType, int32 SlotIndex);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	virtual void AddZeroDamageNumber(AActor* DamagedActor, APawn* DamageCauser, const FVector& HitLocation);

	UFUNCTION(BlueprintCallable)
	void ApplyOverrideWrapToVehicle(const TSoftObjectPtr<UAthenaItemWrapDefinition>& ItemWrap);

	UFUNCTION(BlueprintPure, Category="HUD")
	bool AreHUDElementsVisible(const FGameplayTagContainer& HUDElementTags) const;

	UFUNCTION(BlueprintPure, Category="Inventory", meta=(DisplayName="FindExistingItemForDefinition"))
	UFortItem* BP_FindExistingItemForDefinition(const UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, bool bInStorageVault = false) const;

	UFUNCTION(BlueprintCallable, Category="Inventory", meta=(DisplayName="FindItemInstancesFromDefinition"))
	void BP_FindItemInstancesFromDefinition(const UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, UPARAM(ref) TArray<UFortItem*>& ItemArray);

	UFUNCTION(BlueprintPure, Category="Inventory", meta=(DisplayName="GetInventoryItemWithGuid"))
	UFortItem* BP_GetInventoryItemWithGuid(FGuid ItemGuid) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void BroadcastOnPickupCreated(AFortPickup* Pickup);

	UFUNCTION(BlueprintPure, Category="Creative")
	virtual bool CanAlterHostileWalls() const;

	UFUNCTION(BlueprintPure)
	bool CanEnableBattleMapSpectator() const;

	UFUNCTION(BlueprintPure)
	virtual bool CanPerformNativeAction(const FGameplayTag& ActionTag) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void ChangeActiveVariantForCosmeticItem(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn = nullptr);

	UFUNCTION(Exec)
	void Cheat(const FString& Msg);

	UFUNCTION(Server, Reliable, WithValidation)
	void Cheat_ClearForcedCosmeticItems();

	UFUNCTION(Server, Reliable, WithValidation)
	void Cheat_ClearForcedCosmeticVariantChannels();

	UFUNCTION(Server, Reliable, WithValidation)
	void Cheat_ForceAthenaCosmeticItemInSlot(const UAthenaCosmeticItemDefinition* CosmeticItem, EAthenaCustomizationCategory Slot, int32 Index);

	UFUNCTION(Server, Reliable, WithValidation)
	void Cheat_ForceCosmeticVariantChannels(const TArray<FMcpVariantChannelInfo>& CosmeticVariantChannels);

	UFUNCTION(Server, Unreliable, WithValidation)
	void Cheat_ForcePlayEmoteItem(const UFortMontageItemDefinitionBase* EmoteAsset);

	UFUNCTION(Server, Reliable, WithValidation)
	void Cheat_ForcePlayerToAssembledMeshSchema(const FString& AssembledMeshSchemaName);

	UFUNCTION(Server, Reliable, WithValidation)
	void Cheat_StopObjectiveServer(AFortObjectiveBase* Objective, const EFortObjectiveStatus Status);

	UFUNCTION(Exec)
	void CheatAll(const FString& Msg);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	bool CheckPossessionOfAmountOfItems(EFortItemType Type, int32 AmountToCheck);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category="Quickbars")
	void ClientActivateSlot(EFortQuickBars InQuickBar, int32 Slot, float ActivateDelay = 0.000000f, bool bUpdatePreviousFocusedSlot = true, bool bForceExecution = false);

	UFUNCTION(Client, Unreliable)
	void ClientAddDamageNumber(float Damage, AActor* DamagedActor, APawn* DamageCauser, const FGameplayEffectContextHandle& EffectContext, const FGameplayTagContainer& DamageTags, bool bIsCriticalDamage, const FVector& OverridePosition, const FVector& HitNormal);

	UFUNCTION(Client, Unreliable)
	void ClientAddScoreNumber(int32 Score, EStatCategory ScoreCategory, const FVector_NetQuantize& ScoreLocation, bool bDisplayScoreOnPlayer);

	UFUNCTION(Client, Reliable)
	void ClientBotEnqueueCommand(const FString& CommandToEnqueue);

	UFUNCTION(Client, Reliable)
	void ClientBotSetModuleToUse(const FString& PilotCategory, const FString& NewModule, bool bResetNow);

	UFUNCTION(Client, Reliable)
	void ClientCancelCrafting();

	UFUNCTION(Client, Reliable)
	void ClientConfirmTargetData(uint16 UniqueId, bool bSuccess, const TArray<uint8>& HitReplaces);

	UFUNCTION(Client, Reliable)
	void ClientCreateOrJoinChatRoom(const FString& ChatRoomId);

	UFUNCTION(Client, Reliable)
	void ClientEndGameKick();

	UFUNCTION(Client, Reliable)
	void ClientEquipItem(const FGuid& ItemGuid, bool bForceExecution);

	UFUNCTION(Client, Reliable)
	void ClientFailedToBeginEditingBuildingActor(ABuildingSMActor* BuildingActorToStopEditing);

	UFUNCTION(Client, Reliable)
	void ClientFinishedInteractionInZone();

	UFUNCTION(Client, Reliable)
	void ClientForceCancelBuildingTool();

	UFUNCTION(Client, Reliable)
	void ClientForceProfileQuery();

	UFUNCTION(Client, Reliable, BlueprintCallable, Category="QuickBars")
	void ClientForceUpdateQuickbar(EFortQuickBars QuickbarToRefresh);

	UFUNCTION(Client, Reliable)
	void ClientForceWorldInventoryUpdate();

	UFUNCTION(Client, Reliable)
	void ClientGivePlayerLocalAccountItem(UFortAccountItemDefinition* ItemDefinition, int32 Count);

	UFUNCTION(Client, Unreliable)
	void ClientHandleHitNotifyAudio(const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AFortPawn* PawnInstigator, AActor* DamageCauser, AActor* DamagedActor);

	UFUNCTION(Client, Reliable, WithValidation)
	void ClientJoinConsoleSession(const FString& ConsoleSession);

	UFUNCTION(Client, Reliable)
	void ClientLogDebugString(const FString& Msg);

	UFUNCTION(Client, Reliable)
	void ClientOnGenericPlayerInitialization();

	UFUNCTION(Client, Reliable)
	void ClientPingMinimap(FVector WorldLocation, FLinearColor PingColor);

	UFUNCTION(Client, Reliable, BlueprintCallable)
	void ClientPrecacheMediaSource(UMediaPlayer* InMediaPlayer, UMediaSource* InMediaSource);

	UFUNCTION(Client, Reliable)
	void ClientReadyCheckComplete(bool bPassed);

	UFUNCTION(Client, Reliable)
	void ClientReceivedAttributeSources(FGameplayAttribute Attribute, UFortAbilitySystemComponent* AbilitySystemComponent, const TArray<FAttributeModifierInfo>& Sources);

	UFUNCTION(Client, Reliable)
	void ClientReceivePresetTeamChat(const FText& ChatText, FUniqueNetIdRepl SenderID);

	UFUNCTION(Client, Reliable)
	void ClientRegisterWithParty();

	UFUNCTION(Client, Unreliable)
	void ClientReportDamagedResourceBuilding(ABuildingSMActor* BuildingSMActor, EFortResourceType::Type PotentialResourceType, int32 PotentialResourceCount, bool bDestroyed, bool bJustHitWeakspot);

	UFUNCTION(Client, Unreliable)
	void ClientReportGotResourceFromVehicle(AActor* Vehicle, int32 ResourceCount);

	UFUNCTION(Client, Reliable)
	void ClientRequestReadyCheck(const FText& QueryText, const FText& YesText, const FText& NoText);

	UFUNCTION(Client, Reliable)
	void ClientRetryLocalPlaceBuildableClass();

	UFUNCTION(Client, Reliable, BlueprintCallable, Category="Tutorial")
	void ClientSetActionMappingEnabled(FName ActionName, bool bEnabled);

	UFUNCTION(Client, Reliable)
	void ClientSetSpectatorCamera(FVector CameraLocation, FRotator CameraRotation);

	UFUNCTION(Client, Reliable)
	void ClientSpawnWeakSpotOnBuildingActor(const FBuildingWeakSpotData& ReplicatedWeakSpotData);

	UFUNCTION(Client, Reliable)
	void ClientStopAutoRun();

	UFUNCTION(Client, Reliable)
	void ClientStopUIFeedbackEvent(FName EventName);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category="Quickbars")
	void ClientSwapQuickBarFocus(EFortQuickBars InQuickBar, int32 SlotOverride = -1, bool bForceExecution = false);

	UFUNCTION(Client, Reliable)
	void ClientTriggerUIFeedbackEvent(FName EventName);

	UFUNCTION(Client, Reliable)
	void ClientUpdateRichPresence(ERichPresenceStateChange RichPresenceChange, bool bImportant);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category="Tutorial")
	void ClientUpdateServerOnPlayerChangedBuildMode();

	UFUNCTION(BlueprintPure, Category="Inventory")
	virtual int32 CountInventoryOverflowFromAddingItem(const FFortItemEntry& ItemDescription, bool bIsClassItem, bool bFromPickup) const;

	UFUNCTION(BlueprintCallable, Category="Defenders")
	void DeployDefender(ABuildingTrapDefender* DefenderTrap, const UFortDefenderItem* DefenderItem, const FName& DefenderSquadId, const UFortItem* WeaponItem, const int32 AmmoQuantity);

	UFUNCTION(Exec)
	void DisplayHUDElementVisibility() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropAllItems(const UFortItemDefinition* IgnoreItemDef, const UFortItemDefinition* AdditionalIgnoreItemDef, bool bIgnoreBuildingMaterials = false, bool bSpawnPickups = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropItemsByCreativeTags(const TArray<FName>& DropCreativeTags, const TArray<FName>& IgnoreCreativeTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropSpecificItem(const UFortItemDefinition* DropItemDef, bool bSpawnPickups = true);

	UFUNCTION(Exec)
	void DumpHomebaseRatingInfo() const;

	UFUNCTION(Exec)
	virtual void Emote(const FName& AssetName);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void ExecuteInventoryItemDefinition(UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, float Delay = 0.000000f, bool bForceExecute = false, bool bActivateSlotAfterSettingFocused = true);

	UFUNCTION(BlueprintPure, Category="Quickbars")
	virtual bool FindItem(const UFortItem* Item, EFortQuickBars& OutQuickBar, int32& OutSlot) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	void ForceCancelBuildingTool();

	UFUNCTION(BlueprintCallable)
	void ForceExitBuildMode();

	UFUNCTION(BlueprintCallable, Category="UI")
	virtual void ForcePickerClose();

	UFUNCTION(Client, Unreliable)
	void FortClientPlaySound(USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier);

	UFUNCTION(Client, Unreliable)
	void FortClientPlaySoundAtLocation(USoundBase* Sound, FVector Location, float VolumeMultiplier, float PitchMultiplier);

	UFUNCTION(Server, Reliable, WithValidation)
	void ForwardActiveVariantChangeRequest(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn);

	UFUNCTION(BlueprintPure, Category="AI")
	UFortAccountItem* GetAccountItem(const FString& Id) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Stats")
	int32 GetAccountLevel() const;

	UFUNCTION(BlueprintPure, Category="Reticle")
	AActor* GetActorUnderReticle() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AIDirectorDataManager")
	AFortAIDirectorDataManager* GetAIDirectorDataManager();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	UFortControllerComponent_Aircraft* GetAircraftComponent() const;

	UFUNCTION(BlueprintCallable, Category="PlayerController")
	bool GetAtNameHomeBaseScreen();

	UFUNCTION(BlueprintPure, Category="Building")
	ABuildingPlayerPrimitivePreview* GetBuildPreviewMarker() const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	UFortCollectionBookManager* GetCollectionBookManager() const;

	UFUNCTION(BlueprintPure)
	UFortControllerComponent_InputContextTracker* GetContextTrackerComponent() const;

	UFUNCTION(BlueprintCallable, Category="PlayerController")
	UWidget* GetCurrentlyBoundEntryFromActions(const TArray<FName>& InBoundActionsToCheck);

	UFUNCTION(BlueprintPure)
	AFortVolume* GetCurrentVolume() const;

	UFUNCTION(BlueprintPure, Category="Quickbars")
	int32 GetFocusedSlot(const EFortQuickBars InQuickbar) const;

	UFUNCTION(BlueprintPure, Category="Focus Target")
	const AActor* GetFocusTarget() const;

	UFUNCTION(BlueprintPure)
	bool GetForceAllowCameraMode() const;

	UFUNCTION(BlueprintCallable, Category="HUD")
	int32 GetFPSForHUD();

	UFUNCTION(BlueprintPure, Category="Default")
	FUniqueNetIdRepl GetGameAccountId() const;

	UFUNCTION(BlueprintPure, Category="Customization")
	FText GetGliderDisplayName() const;

	UFUNCTION(BlueprintPure)
	bool GetIgnoreSignifanceBasedCustomDepthRendering();

	UFUNCTION(BlueprintPure, Category="Profile")
	virtual bool GetItemDefinitionOwnershipState(const UFortItemDefinition* ItemDefinition, bool& bIsOwned) const;

	UFUNCTION(BlueprintCallable, Category="Inventory")
	UFortItem* GetItemInQuickbarSlot(EFortQuickBars QuickBarType, int32 SlotIndex);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	int32 GetItemNumInStackByGuid(FGuid ItemGuid);

	UFUNCTION(BlueprintPure, Category="Emote")
	const UFortMontageItemDefinitionBase* GetLastEmotePlayed() const;

	UFUNCTION(BlueprintPure)
	const FRotator& GetLastInputRotation() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Reticle")
	FVector GetLocationUnderReticle() const;

	UFUNCTION(BlueprintPure, Category="Target Lock On")
	ELockOnState GetLockOnState() const;

	UFUNCTION(BlueprintPure)
	virtual UAthenaMarkerComponent* GetMarkerComponent() const;

	UFUNCTION(BlueprintPure)
	UFortMcpProfileAthena* GetMcpAthenaProfile() const;

	UFUNCTION(BlueprintPure, Category="Profile")
	UFortMcpProfileCampaign* GetMcpCampaignProfile() const;

	UFUNCTION(BlueprintPure, Category="Awards")
	virtual UFortMinigameManager* GetMinigameManager(ESubGame SubGame = ESubGame::Invalid) const;

	UFUNCTION(BlueprintPure)
	UFortControllerComponent_Minimap* GetMiniMapComponent() const;

	UFUNCTION(BlueprintCallable, Category="Inventory")
	int32 GetNumQuickbarSlots(EFortQuickBars QuickBarType);

	UFUNCTION(BlueprintPure)
	UFortControllerComponent_PinQuest* GetPinQuestComponent() const;

	UFUNCTION(BlueprintPure, Category="Game|Player", meta=(Keywords="Pawn"))
	virtual AFortPlayerPawn* GetPlayerPawn() const;

	UFUNCTION(BlueprintPure, Category="Pawn")
	AFortPlayerPawn* GetPlayerPawnOrVehicleDriver() const;

	UFUNCTION(BlueprintPure, Category="Quests")
	virtual UFortQuestManager* GetQuestManager(ESubGame SubGame = ESubGame::Invalid) const;

	UFUNCTION(BlueprintPure, Category="EditMode")
	UFortControllerComponent_QuickEdit* GetQuickEditComponent() const;

	UFUNCTION(BlueprintCallable)
	UAthenaCharacterItemDefinition* GetRandomDefaultAthenaCharacterDefinition(UFortMcpProfileAthena* McpAthenaProfile);

	UFUNCTION(BlueprintPure, Category="Player")
	UFortRegisteredPlayerInfo* GetRegisteredPlayerInfo() const;

	UFUNCTION(BlueprintPure, Category="Audio")
	bool GetRevertPlayerListenerChangeFlag() const;

	UFUNCTION(BlueprintPure, Category="Input")
	virtual bool GetRotatePawnToCamera() const;

	UFUNCTION(BlueprintPure, Category="Stats")
	int32 GetStatValue(FName StatName, EStatRecordingPeriod Period) const;

	UFUNCTION(BlueprintPure)
	UFortControllerComponent_SurvivorTiers* GetSurvivorTiersComponent() const;

	UFUNCTION(BlueprintPure)
	ABuildingActor* GetTargetedBuilding() const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	int32 GetTeamPerkProgressiveActivationLevel() const;

	UFUNCTION(BlueprintPure)
	virtual float GetTimeRemainingForRespawnBP() const;

	UFUNCTION(BlueprintPure, Category="Input")
	bool GetUseHoldToSwapPickupSetting() const;

	UFUNCTION(BlueprintPure, Category="Voice")
	const FVoiceChatDistanceAttenuationSettings& GetVoiceChatDistanceAttenuationSettings() const;

	UFUNCTION(BlueprintPure, Category="Voice")
	USoundEffectSourcePresetChain* GetVoiceInputEffectChain() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortWeapon")
	void GivePlayerAmmo(int32 AmmoCount);

	UFUNCTION(BlueprintCallable, Category="Camera")
	void HandleNonZeroRollSetOnCamera();

	UFUNCTION()
	void HandleOutpostInventoryLocalUpdate();

	UFUNCTION()
	void HandleViewTargetInventoryLocalUpdate();

	UFUNCTION()
	virtual void HandleWorldInventoryLocalUpdate();

	UFUNCTION(BlueprintPure, Category="Target Lock On")
	bool HasLockOnTarget() const;

	UFUNCTION(BlueprintPure)
	virtual bool HasPermissionToEditWorld(const ABuildingActor* Building, const FVector& Location, const FRotator& Rotation) const;

	UFUNCTION()
	void InitializeZeroingCameraRoll();

	UFUNCTION(BlueprintPure, Category="Input")
	bool IsActionInputIgnored() const;

	UFUNCTION(BlueprintCallable, Category="Creative", meta=(CallableWithoutWorldContext, WorldContext="WorldContextObject"))
	static bool IsAnyPlayerOwnerOfCurrentExperience(const UObject* WorldContextObject);

	UFUNCTION()
	bool IsAutoChangeMaterialOn();

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsBuildToolOverridden() const;

	UFUNCTION(BlueprintPure, Category="Bots")
	bool IsClientBot() const;

	UFUNCTION(BlueprintPure, Category="Default")
	bool IsClientTimingOut() const;

	UFUNCTION(BlueprintPure, Category="PlayerController")
	bool IsHiddenControllerOnly(AActor* TargetActor) const;

	UFUNCTION(BlueprintPure, Category="Aircraft")
	virtual bool IsInAircraft() const;

	UFUNCTION(BlueprintPure, Category="QuickBars")
	bool IsInBuildMode() const;

	UFUNCTION(BlueprintPure)
	bool IsInRespawnCountdown() const;

	UFUNCTION(BlueprintPure, Category="PlayerController")
	virtual bool IsInSplitscreen() const;

	UFUNCTION(BlueprintPure, Category="Combat")
	bool IsNearActiveEncounters() const;

	UFUNCTION(BlueprintPure)
	virtual bool IsPartyLeader() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	virtual bool IsPersonalVehicleActive() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	virtual bool IsPersonalVehicleAvailable() const;

	UFUNCTION(BlueprintPure, Category="Creative")
	bool IsPlayerInAnExperienceTheyOwn() const;

	UFUNCTION(BlueprintPure, Category="Emote")
	virtual bool IsPlayingEmote() const;

	UFUNCTION(BlueprintPure, Category="Stats")
	virtual bool IsRequirementsMet(const FFortRequirementsInfo& InRequirements, bool bUsePhoenixStats) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Cosmetics")
	void IsUsingCosmeticsOwnedByStWHero(bool& bIsUsingOutfitOwnedByHero, bool& bIsUsingBackblingOwnedByHero) const;

	UFUNCTION(BlueprintPure, Category="Camera")
	bool IsUsingFirstPersonCamera() const;

	UFUNCTION(BlueprintPure, Category="Input")
	bool IsUsingGamepad() const;

	UFUNCTION(BlueprintPure, Category="Input")
	bool IsUsingHarvestingTool() const;

	UFUNCTION(BlueprintPure, Category="Input")
	bool IsUsingTouch() const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnEnterVolume", ScriptName="OnEnterVolume"))
	void K2_OnEnterVolume(AFortVolume* Volume);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnLeaveVolume", ScriptName="OnLeaveVolume"))
	void K2_OnLeaveVolume(AFortVolume* Volume);

	UFUNCTION(BlueprintCallable, Category="Fortnite UI")
	virtual void LocalOnUiChoiceCompleted(int32 ChosenItem, int32 MenuIdentifier);

	UFUNCTION(BlueprintCallable)
	void LocalOverrideBuildMode(bool bVisible, TSubclassOf<ABuildingSMActor> InBuildingClass, FVector3f BuildingOverrideDistance, UMaterialInterface* PreviewMaterial, FVector NewScale = FVector(1.000000, 1.000000, 1.000000), FRotator NewRotation = FRotator(0.000000, 0.000000, 0.000000));

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Game|Feedback")
	void LocalPlayForceFeedback(UForceFeedbackEffect* ForceFeedbackEffect, bool bLooping, FName Tag);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Game|Feedback")
	void LocalStopForceFeedback(UForceFeedbackEffect* ForceFeedbackEffect, FName Tag);

	UFUNCTION(Server, Reliable)
	void MarkCollectionItemSeen(const FString& CollectionType, const FString& Category, const FString& Variant);

	UFUNCTION(BlueprintCallable, Category="Stats")
	void ModifyStat(FName StatName, int32 Amount, EStatMod ModType, bool bForceStatSave = false);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Building")
	void MulticastClearWeakSpotData(UObject* ParentBuilding);

	UFUNCTION(BlueprintCallable, Category="Voice")
	void MutePlayer(const FUniqueNetIdRepl& UniqueNetId);

	UFUNCTION(Exec)
	void NotifyMeshNetPlayer(FName Tag);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayHitMarker(const FGameplayTagContainer& HitTags, EFortDamageZone::Type Zone);

	UFUNCTION()
	virtual void OnMinigameSpatialLoadingStateChanged(ESpatialLoadingState NewState, AFortVolume* Volume);

	UFUNCTION()
	void OnRep_IntensityGraphInfo();

	UFUNCTION()
	void OnRep_MeshParentIds();

	UFUNCTION()
	void OnRep_PIDContributionsGraphInfo();

	UFUNCTION()
	void OnRep_PIDValuesGraphInfo();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="UI")
	void OpenChoiceUI(FChoiceData ChoiceData);

	UFUNCTION(BlueprintCallable)
	void OpenInventory(const FName InventoryTabId);

	UFUNCTION(BlueprintCallable, Category="UI")
	void OpenVoteDialog();

	UFUNCTION(BlueprintPure)
	bool OwnsCurrentIslandVolume() const;

	UFUNCTION(BlueprintPure)
	bool OwnsIslandVolume(AFortVolume* Volume) const;

	UFUNCTION(BlueprintCallable, Exec)
	virtual void PlayEmoteItem(const UFortMontageItemDefinitionBase* EmoteAsset, EFortEmotePlayMode PlayMode = EFortEmotePlayMode::CheckIfOwned);

	UFUNCTION(BlueprintCallable)
	virtual void PlayerRequestClearIslandData();

	UFUNCTION(BlueprintCallable, Category="Controller")
	void PlaySpatialSound(USoundBase* Sound, FVector Location);

	UFUNCTION(Exec)
	void PostHeroStatCollectionBookProgressMade(int32 LevelReached);

	UFUNCTION(Exec)
	void PostHeroStatMissionCompleted(int32 DifficultyRating);

	UFUNCTION(Exec)
	void PostHeroStatSkillPointsEarned(int32 NumSkillPoints);

	UFUNCTION(Exec)
	virtual void PrintDebugInfo();

	UFUNCTION(Exec)
	void PrintEventInfo();

	UFUNCTION(Client, Reliable)
	void ProcessMcpProfileUpdate(const FProfileUpdate& Update);

	UFUNCTION(BlueprintCallable, Category="HUD")
	virtual void RefreshHUDElementVisibilitiesToSettings();

	UFUNCTION(BlueprintCallable, Category="Tutorial")
	void RemoveItemFromQuickBars(UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void RemoveItemsByCreativeTags(const TArray<FName>& RemoveCreativeTags, const TArray<FName>& IgnoreCreativeTags);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Movie")
	void ReportVideoStreamingError(UMediaPlayer* MediaPlayer, bool bLocalContentFallback, const FString& LastError) const;

	UFUNCTION(BlueprintCallable, Category="Input")
	void ResetForcedInputRotationSpeed();

	UFUNCTION(BlueprintCallable, Category="HUD")
	void ResetHUDElementVisibilityToSettings(const FGameplayTagContainer& HUDElementTags);

	UFUNCTION(BlueprintCallable, Category="Input")
	void ResetInputRotationScale();

	UFUNCTION(BlueprintCallable)
	virtual void ReturnToAthenaItemShop();

	UFUNCTION(BlueprintCallable, Category="Travel")
	virtual void ReturnToMainMenu();

	UFUNCTION(BlueprintCallable, Category="Controller")
	virtual void SendMessage(const FText& Message);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Movie")
	void SendStreamingAnalytics(UMediaPlayer* MediaPlayer) const;

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAddPawnMovementInput(AFortPawn* InChar, FVector WorldDirection, float ScaleValue, bool bForce);

	UFUNCTION(Server, Reliable)
	void ServerAnnouncementStoppedOnClient(FGuid AnnouncementID);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerApplyOverrideWrapToItem(const FGuid& GUID, const TSoftObjectPtr<UAthenaItemWrapDefinition>& ItemWrap);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerApplyOverrideWrapToVehicle(const TSoftObjectPtr<UAthenaItemWrapDefinition>& ItemWrap);

	UFUNCTION(Server, Reliable)
	void ServerAttemptInventoryDrop(FGuid ItemGuid, int32 Count, bool bTrash);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerBeginEditingBuildingActor(ABuildingSMActor* BuildingActorToEdit);

	UFUNCTION(Server, Reliable, Category="Tutorial")
	void ServerBroadcastPlayerChangedBuildMode(bool bIsInBuildMode);

	UFUNCTION(Server, Reliable)
	void ServerCheat(const FString& Msg);

	UFUNCTION(Server, Reliable)
	void ServerCheatAll(const FString& Msg);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerClearItemList(UFortMinigameItemContainerComponent* ItemContainerComponent);

	UFUNCTION(Server, Reliable)
	void ServerCombineInventoryItems(FGuid TargetItemGuid, FGuid SourceItemGuid);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerConvertToDirectBinding(AFortMinigameSettingsBuilding* Target);

	UFUNCTION(Server, Reliable)
	void ServerCraftSchematic(const FString& ItemId, int32 PostCraftSlot, int32 CraftAmount, EFortItemTier RequestedTier, bool bIsQuickCrafted);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreateBuildingActor(FCreateBuildingActorData CreateBuildingData);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDropAllItems(const UFortItemDefinition* IgnoreItemDef);

	UFUNCTION(Server, Reliable)
	void ServerDropCarriedObject();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerEditBuildingActor(ABuildingSMActor* BuildingActorToEdit, TSubclassOf<ABuildingSMActor> NewBuildingClass, uint8 RotationIterations, bool bMirrored);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerEndEditingBuildingActor(ABuildingSMActor* BuildingActorToStopEditing);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerExecutePresetTeamChat(const FText& ChatText, FUniqueNetIdRepl SenderID);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerFinishedLevelStreaming(UFortLevelStreamComponent* ComponentStreamingFinishedFor);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Missions")
	void ServerHandleMissionEvent_StartLeavingZone();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Missions")
	void ServerHandleMissionEvent_ToggledCursorMode(bool bOpened);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Missions")
	void ServerHandleMissionEvent_ToggledEditMode(ABuildingSMActor* EditableActor, bool bOpened);

	UFUNCTION(Server, Reliable)
	void ServerItemWillBeDestroyed(FGuid DestroyedItemGuid, int32 Count);

	UFUNCTION(Server, Reliable)
	void ServerKickPlayer(const FUniqueNetIdRepl& PlayerToKick, const FText& Reason);

	UFUNCTION(Server, Reliable)
	void ServerLoadingScreenDropped();

	UFUNCTION(Server, Reliable)
	void ServerModifyStat(FName StatName, int32 Amount, EStatMod ModType, bool bForceStatSave);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerNotifyMeshNetPlayer(FName Tag);

	UFUNCTION(Server, Reliable)
	void ServerPingMinimap(FVector WorldLocation, FLinearColor PingColor, uint8 RequiredTeam);

	UFUNCTION(Server, Reliable)
	void ServerPlayerRequestClearIslandData();

	UFUNCTION(Server, Reliable)
	void ServerReAimAllReplaySpotLights(FVector NewLocation, FRotator NewRotation);

	UFUNCTION(Server, Reliable)
	void ServerReAimCurrentReplaySpotLight(FVector NewLocation, FRotator NewRotation);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRepairBuildingActor(ABuildingSMActor* BuildingActorToRepair);

	UFUNCTION(Server, Reliable)
	void ServerReplyToReadyCheck(bool bReady);

	UFUNCTION(Server, Reliable)
	void ServerRequestAIDebug();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRequestAttributeSources(FGameplayAttribute Attribute, UFortAbilitySystemComponent* AbilitySystemComponent);

	UFUNCTION(Server, Reliable)
	void ServerRequestGameplayAction(EFortRequestedGameplayAction::Type RequestedAction);

	UFUNCTION(Server, Reliable)
	void ServerRequestPresetCosmeticSwap(const UAthenaCosmeticItemDefinition* ItemDef, int32 SwapIndex);

	UFUNCTION(Server, Reliable)
	void ServerRetryLocalPlaceBuildableClass();

	UFUNCTION(Server, Reliable)
	void ServerSendClientProgressUpdate(const TArray<uint8>& ClientProgressUpdate);

	UFUNCTION(Server, Reliable)
	void ServerSendCustomStatEventWithTags(EFortQuestObjectiveStatEvent Type, FGameplayTagContainer AdditionalSourceTags, FGameplayTagContainer TargetTags, int32 Count);

	UFUNCTION(Server, Reliable)
	void ServerSetAutoEquipBetterItems(bool bAutoEquip);

	UFUNCTION(Server, Reliable)
	void ServerSetCurrentReplaySpotLight(AFortReplayMovableSpotLight* NewReplaySpotLight);

	UFUNCTION(Server, Reliable)
	void ServerSetCurrentReplaySpotLightColor(int32 R, int32 G, int32 B);

	UFUNCTION(Server, Reliable)
	void ServerSetCurrentReplaySpotLightDebugDraw(bool bEnabled);

	UFUNCTION(Server, Reliable)
	void ServerSetMarkText(AFortMarkActor* MarkActor, const FString& MarkText);

	UFUNCTION(Server, Reliable)
	void ServerSetReadyToContinue(bool bReady, EFortGameplayState::Type RequestedState, bool bTryStartTimer);

	UFUNCTION(Server, Reliable)
	void ServerSetReplaySpotLightGroupMoveLocked(uint32 Number, bool bLocked);

	UFUNCTION(Server, Reliable)
	void ServerSetShouldUseBotManager(bool InValue);

	UFUNCTION(Server, Reliable)
	void ServerSetShouldUsePilotComponent(bool InValue);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetWeaponAutoPickups(bool bEnablePickups);

	UFUNCTION(Server, Reliable)
	void ServerStartIntensityGraphing();

	UFUNCTION(Server, Reliable)
	void ServerStartPIDContributionsGraphing();

	UFUNCTION(Server, Reliable)
	void ServerStartPIDValueGraphing();

	UFUNCTION(Server, Reliable)
	void ServerSuicide();

	UFUNCTION(Server, Reliable)
	void ServerTeamChatRoomReady(const FString& ChatRoomId);

	UFUNCTION(Server, Reliable)
	void ServerTeleportToReticle(FVector TeleportLocation);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Mission")
	void ServerTriggerGenericObjectiveEvent(AFortObjectiveBase* Objective);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateActorOptions(AActor* OptionsTarget, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues, const TArray<FFortGameplayEventContainer_Named>& AddedSubscriptions, const TArray<FFortGameplayEventContainer_Named>& RemovedSubscriptions);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateGameDescriptionData(AActor* DataTarget, const FText& GameName, const TArray<FText>& GameDescriptionText);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateGameplayOptions(const TArray<FString>& UserOptionsKeys, const TArray<FString>& UserOptionsValues);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateItemListOptions(UFortMinigameItemContainerComponent* ItemContainerComponent, int32 ItemIndex, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateMessageComponents(const TArray<UFortGameplayMessageComponentBase*>& ModifiedComponents, const TArray<FGameplayTagContainer>& NewChannelIds);

	UFUNCTION(Server, Reliable)
	void ServerUpdateSprintToggleable(const bool bShouldBeToggleable);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpgradeBuildingActor(ABuildingActor* BuildingActorToUpgrade, int32 NewUpgradeLevel);

	UFUNCTION(BlueprintCallable, Category="PlayerController")
	bool SetActorHiddenControllerOnly(AActor* TargetActor, const bool bNewHidden);

	UFUNCTION(BlueprintCallable, Category="PlayerController")
	void SetAtNameHomeBaseScreen(bool AtScreen);

	UFUNCTION(BlueprintCallable, Category="Weapon")
	void SetAttemptReloadOnEquip(bool bAttemptReloadOnEquip = true);

	UFUNCTION(BlueprintCallable, Category="PlayerController")
	void SetBoundEntryToActions(const TArray<FName>& InBoundActions, UWidget* EntryToBind);

	UFUNCTION(BlueprintCallable)
	virtual void SetBuildingHighlight(const TArray<ABuildingActor*>& TargetedBuildings, EBuildingHighlightType::Type HighlightType, bool bValidHighlight = true);

	UFUNCTION(BlueprintCallable, Category="Game|Cinematic", meta=(bAffectsHUD="true", bHidePlayer="true", bHideWeapon="true"))
	virtual void SetCinematicModeWithWeapon(bool bInCinematicMode, bool bHidePlayer, bool bHideWeapon, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning);

	UFUNCTION(BlueprintCallable, Category="Game|Player", meta=(Keywords="Camera"))
	void SetCinematicOverrideClass(TSubclassOf<UFortCinematicCamera> OverrideCameraClass);

	UFUNCTION(BlueprintCallable, Category="Pawn")
	void SetClientPawnNewRotation(const FRotator& NewRotation);

	UFUNCTION(BlueprintCallable, Category="PlayerController")
	bool SetCompHiddenControllerOnly(USceneComponent* SceneComp, const bool bNewHiddenGame, const bool bPropagateToChildren);

	UFUNCTION(BlueprintCallable, Category="PlayerController")
	bool SetCompHiddenOtherLocalControllersOnly(USceneComponent* SceneComp, const bool bNewHiddenGame, const bool bPropagateToChildren);

	UFUNCTION(BlueprintCallable)
	void SetDisableNativeDamageNumbers(const bool bNewDisableNativeDamageNumbers);

	UFUNCTION(BlueprintCallable)
	void SetDisableNativeHitMarker(const bool bNewDisableNativeHitMarker);

	UFUNCTION(BlueprintCallable, Category="Camera")
	virtual void SetFirstPersonCamera(bool bNewUseFirstPersonCamera);

	UFUNCTION(BlueprintCallable, Category="Input")
	void SetForcedInputRotationSpeed(float InForcedInputRotationSpeed);

	UFUNCTION(BlueprintCallable, Category="HUD")
	virtual void SetHUDElementVisibility(const FGameplayTagContainer& HUDElementTags, const bool bHideElements, const FName ReasonName = NAME_None, const FString& LogContext = TEXT(""));

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Rendering", meta=(AdvancedDisplay="1", DefaultToSelf="ModifyingObject"))
	void SetIgnoreSignifanceBasedCustomDepthRendering(bool bValue, UObject* ModifyingObject);

	UFUNCTION(BlueprintCallable, Category="Input")
	void SetInputPitchScale(float InInputPitchScale);

	UFUNCTION(BlueprintCallable, Category="Input")
	void SetInputYawScale(float InInputYawScale);

	UFUNCTION(BlueprintCallable, Category="Target Lock On")
	void SetLockOnTargetStickCoords(const FVector2D& Coords);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetPickerEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void SetRotatePawnToCamera(bool bNewRotatePawnToCamera);

	UFUNCTION(BlueprintCallable, Category="Sprint")
	void SetSprintBehaviorIsOverridden(bool bNewSprintBehaviorIsOverridden, bool bNewSprintByDefaultWhenSprintIsOverridden = true);

	UFUNCTION(BlueprintCallable, Category="Voice")
	void SetVoiceChatDistance(const FUniqueNetIdRepl& UniqueNetId, float Distance);

	UFUNCTION(BlueprintCallable, Category="Voice")
	void SetVoiceChatDistanceAttenuationEnabled(bool bInEnabled);

	UFUNCTION(BlueprintCallable, Category="Voice")
	void SetVoiceChatDistanceAttenuationSettings(const FVoiceChatDistanceAttenuationSettings& InSettings);

	UFUNCTION(BlueprintCallable, Category="Voice")
	void SetVoiceInputEffectChain(USoundEffectSourcePresetChain* InSourceEffectPresetChain);

	UFUNCTION(BlueprintPure)
	virtual bool ShouldShowInfoIndicator(const AActor* TestActor) const;

	UFUNCTION(BlueprintCallable, Exec)
	ABattleMapPawnLive* SpawnBattleMapSpectator();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	AActor* SpawnToyInstance(TSubclassOf<AActor> ToyClass, FTransform SpawnPosition);

	UFUNCTION(BlueprintCallable, Exec, BlueprintAuthorityOnly, Category="UI")
	bool StartReadyCheck(FText QueryText, FText YesText, FText NoText, float PercentageToPass);

	UFUNCTION()
	void StartZeroingCameraRoll();

	UFUNCTION(BlueprintCallable)
	bool StopBattleMapSpectator();

	UFUNCTION(BlueprintCallable, Exec)
	virtual void Suicide();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="UI")
	void SuppressEventNotifications(bool bSuppress);

	UFUNCTION(Exec)
	void TestStreamedVideo(const FString& URLInQuotes);

	UFUNCTION(BlueprintCallable, Exec)
	void ToggleBattleMapSpectator();

	UFUNCTION(Exec)
	void ToggleClientBot();

	UFUNCTION(BlueprintCallable)
	void ToggleCursorMode(FName ActionName);

	UFUNCTION(Exec)
	void ToggleInventory();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void TossSpecificItem(const UFortItemDefinition* DropItemDef, const FFortPickupTossOverrideData& TossOverrideData);

	UFUNCTION(BlueprintCallable)
	void TryActivatePrimaryQuickbarFocusedWeapon();

	UFUNCTION(BlueprintCallable, Category="Voice")
	void UnMutePlayer(const FUniqueNetIdRepl& UniqueNetId);

	UFUNCTION(Client, Reliable)
	void UpdateClientCollection(const FString& CollectionType, const FString& Category, const FFortMcpCollectedItemProperties& Properties, EFortCollectedVariantClientUpdate UpdateKind);

	UPROPERTY(BlueprintAssignable, Category="Game|Player", meta=(Keywords="Pawn Possess"))
	FOnPlayerPawnPossessed OnPlayerPawnPossessed;

	UPROPERTY(BlueprintAssignable, Category="EditMode", meta=(Keywords="Building Edit Mode Enter"))
	FOnEnteredEditMode OnEnteredEditMode;

	UPROPERTY(BlueprintAssignable)
	FFortPlayerControllerOnPickupCreated OnPickupCreated;

	UPROPERTY(BlueprintAssignable)
	FFortPlayerControllerOnLoadoutChanged OnLoadoutChanged;

	UPROPERTY(BlueprintAssignable)
	FOnViewTargetChanged OnViewTargetChanged;

	UPROPERTY(BlueprintAssignable, Category="Input")
	FOnNotifyInputFiltered OnInputFiltered;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> SkydiveMusicAudioComp;

	UPROPERTY(Replicated)
	uint8 bFailedToRespawn : 1;

	UPROPERTY()
	uint8 bIsDisconnecting : 1;

	UPROPERTY()
	uint8 bIsBeingKicked : 1;

	UPROPERTY(Replicated)
	uint8 bHasInitiallySpawned : 1;

	UPROPERTY()
	uint8 bAssignedStartSpawn : 1;

	UPROPERTY()
	uint8 bReadyToStartMatch : 1;

	UPROPERTY()
	uint8 bClientPawnIsLoaded : 1;

	UPROPERTY(Transient)
	uint8 bWantsWeaponAutoPickup : 1;

	UPROPERTY(Transient)
	FVector SpawnLoc;

	UPROPERTY()
	int32 NumPreviousSpawns;

	UPROPERTY(Transient)
	bool bCanSpectateBot;

	UPROPERTY(BlueprintAssignable, Category="UI")
	FOnReadyCheckCompleteBP OnBlueprintReadyCheckCompleted;

	UPROPERTY(BlueprintAssignable, Category="UI", meta=(DisplayName="On Delay For PreServer Transition Animation"))
	FOnDelayForPreServerTransitionAnimation OnDelayForPreServerTransitionAnimationEvent;

	UPROPERTY(Transient)
	bool bLoadingScreenDropped;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortPlayerController")
	bool bRevertPlayerListenerChange;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> VehicleInputComponent;

	UPROPERTY()
	bool bHoldingPrimaryFireFromTouch;

	UPROPERTY(Config)
	bool bSupportNextPieceAssist;

	UPROPERTY(Config)
	bool bAutoBuildForTrapPlacement;

	UPROPERTY(Config)
	bool bAutoBuildForFloorTrapPlacement;

	UPROPERTY(Config)
	bool bAutoBuildForWallTrapPlacement;

	UPROPERTY(Config)
	bool bAutoBuildForCeilingTrapPlacement;

	UPROPERTY(Config)
	bool bNoControllerLighting;

	UPROPERTY(Config)
	float ReturnToMainMenuTimeoutDelay;

	UPROPERTY(BlueprintAssignable)
	FOnQuestObjectiveStateChanged OnQuestObjectiveStateChanged;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> LastDamager;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> LastFallInstigator;

	UPROPERTY(Config)
	float LastDamagerCreditThresholdDropElim;

	UPROPERTY(Config)
	float LastDamagerCreditThresholdSelfElim;

	UPROPERTY(Config)
	float LastDamagerCreditThresholdStormElim;

	UPROPERTY(Config)
	bool bGiveLastDamagerElimCreditOnDrop;

	UPROPERTY(Config)
	bool bGiveLastDamagerElimCreditOnSelfDamage;

	UPROPERTY(Config)
	bool bGiveLastDamagerElimCreditOnStormDamage;

	UPROPERTY(Config)
	bool bShowHitMarkersForFriendlyFire;

	UPROPERTY(Config)
	bool bServerSideHitMarkers;

	UPROPERTY(BlueprintAssignable, Category="UI")
	FOnChosenSignature OnUiChoiceCompleted;

	UPROPERTY(BlueprintAssignable, Category="PlayerController")
	FOnRegainedFocus OnRegainedFocus;

	UPROPERTY(BlueprintAssignable, Category="PlayerController")
	FOnReloadCancelingSprint OnReloadCancelingSprint;

	UPROPERTY(BlueprintAssignable, Category="UI")
	FOnOpenVoteDialog OnOpenVoteDialog;

	UPROPERTY(ReplicatedUsing=OnRep_IntensityGraphInfo)
	FAIDirectorDebugInfo IntensityGraphInfo;

	UPROPERTY(ReplicatedUsing=OnRep_PIDValuesGraphInfo)
	FAIDirectorDebugInfo PIDValuesGraphInfo;

	UPROPERTY(ReplicatedUsing=OnRep_PIDContributionsGraphInfo)
	FAIDirectorDebugInfo PIDContributionsGraphInfo;

	UPROPERTY(BlueprintAssignable, Category="Building")
	FOnBuildPreviewMarkerVisibilityChanged OnBuildPreviewMarkerVisibilityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnWeakSpotReset OnWeakSpotReset;

	UPROPERTY(Config)
	bool bUsePredictedBuildingActors;

	UPROPERTY(Config)
	bool bRegisterPredictedBuildingActorsWithGrid;

	UPROPERTY(Config)
	bool bPredictedBuildingWallsHaveNoCollision;

	UPROPERTY(Config)
	float PredictedActorLifespan;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<ABuildingSMActor>> PredictedBuildingSMActors;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortPlayerController")
	uint8 bBuildFree : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerController")
	bool bShouldForceDeleteDroppedItems;

	UPROPERTY(Replicated)
	uint8 bAutoEquipBetterItems : 1;

	UPROPERTY(Transient)
	TObjectPtr<UFortCustomizationAssetLoader> LocalPawnCustomizationAssetLoader;

	UPROPERTY()
	bool bDropWeaponsDuringAllMissionStates;

	UPROPERTY()
	TObjectPtr<UStatManager> StatManager;

	UPROPERTY()
	TObjectPtr<UHeartbeatManager> HeartbeatManager;

	UPROPERTY()
	TObjectPtr<UFortStatEventManager> StatEventManager;

	UPROPERTY()
	bool bShouldReceiveCriticalMatchBonus;

	UPROPERTY()
	bool bIgnoreExperienceOwnership;

	UPROPERTY(BlueprintAssignable, Category="QuickBars")
	FOnPlayerEnteredBuildMode OnPlayerChangedBuildMode;

	UPROPERTY(BlueprintAssignable, Category="Movement")
	FOnAutoRunEnabled OnAutoRunEnabled;

	UPROPERTY(Transient)
	FVector LocationUnderReticle;

	UPROPERTY(Transient)
	uint8 bEnableVoiceChatPTT : 1;

	UPROPERTY(Transient)
	EFortVoiceChatMethod VoiceChatMethod;

	UPROPERTY(Transient)
	uint8 bVoiceChatPTTTransmit : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bInfiniteAmmo : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bInfiniteConsumables : 1;

	UPROPERTY(Transient)
	uint8 bInfiniteMagazine : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bNoCoolDown : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bInfiniteDurability : 1;

	UPROPERTY(Config, Transient)
	uint8 bUsePickers : 1;

	UPROPERTY(Transient)
	uint8 bPickerOpen : 1;

	UPROPERTY(Transient)
	uint8 bPickerEnabled : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CheatMovement)
	uint8 bCheatGhost : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CheatMovement)
	uint8 bCheatFly : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bEnableShotLogging : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsNearActiveEncounters : 1;

	UPROPERTY(Transient, Replicated)
	int32 OverriddenBackpackSize;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortReplayMovableSpotLight> CurrentReplaySpotLight;

	UPROPERTY(Config, Replicated)
	uint32 AimHelpMode;

	UPROPERTY(Config, Transient, Replicated)
	TEnumAsByte<EFortJumpStaminaCost::Type> JumpStaminaCost;

	UPROPERTY(Config, Transient, Replicated)
	FName CameraPrototypeName;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerController")
	bool bHideHudEnglishText;

	UPROPERTY()
	bool bAutoChangeMaterial;

	UPROPERTY(Config)
	bool bServerAutoChangeMaterial;

	UPROPERTY(Transient)
	bool bPeripheralLightingEnabled;

	UPROPERTY(Transient)
	bool bRudderControlEnabled;

	UPROPERTY(Transient)
	float RudderDeadZone;

	UPROPERTY(Transient)
	float RudderMaxThrottle;

	UPROPERTY(Config)
	bool bSyncPeripheralLightingWithEmoteMusic;

	UPROPERTY(BlueprintReadOnly, Category="HUD")
	bool bUsesWidgetForFPSDisplay;

	UPROPERTY(BlueprintReadOnly, Category="HUD")
	bool bShowFPS;

	UPROPERTY(BlueprintAssignable)
	FOnShowFPSChange OnShowFPSChange;

	UPROPERTY(BlueprintReadOnly, Category="HUD")
	bool bShowTemperature;

	UPROPERTY(BlueprintAssignable)
	FOnShowTemperatureChange OnShowTemperatureChange;

	UPROPERTY(Transient)
	bool bLockPrimaryInputMethodToMouse;

	UPROPERTY(Transient)
	bool bUseActionRouterIgnoreLookInput;

	UPROPERTY(Transient)
	EFortPawnStasisMode PreviousStasisMode;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapPawnLive> BattleMapSpectatorClass;

	UPROPERTY(Config)
	bool bReleaseBuildingContextOnPlace;

	UPROPERTY(Config)
	float TurboPlaceFirstInterval;

	UPROPERTY(Config)
	float TurboPlaceInterval;

	UPROPERTY()
	bool bCreativeTurboDelete;

	UPROPERTY(Config)
	float TurboDeleteFirstInterval;

	UPROPERTY(Config)
	float TurboDeleteInterval;

	UPROPERTY(BlueprintAssignable, Category="Building")
	FOnPlayerSpawnedBuildingActor OnPlayerSpawnedBuildingActor;

	UPROPERTY(ReplicatedUsing=OnRep_MeshParentIds)
	TArray<FString> MeshParentIds;

	UPROPERTY(BlueprintAssignable)
	FOnBoundActionFreed OnBoundActionFreed;

protected:
	UFUNCTION()
	void AlternateInteractCarryHoldStopped(FName InputActionName, bool bCompletedSuccessfully);

	UFUNCTION()
	bool AreActionsBoundToSameKey(FName FirstActionName, FName SecondActionName, const EInputEvent InputEvent);

	UFUNCTION(Client, Reliable)
	void ClientDeveloper_GetConsoleVariable(const FString& ConsoleVariable, const FString& Value);

	UFUNCTION(Client, Reliable)
	void ClientExecuteInventoryItem(FGuid ItemGuid, float Delay, bool bForceExecute, bool bActivateSlotAfterSettingFocused);

	UFUNCTION(Client, Reliable)
	void ClientOpenChoiceUI(FChoiceData ChoiceItems);

	UFUNCTION(Client, Reliable)
	void ClientSendMessage(const FText& Message, USoundBase* StartSound);

	UFUNCTION(Client, Reliable)
	void ClientSetInviteFlags(const FJoinabilitySettings& Settings);

	UFUNCTION()
	void ClientSideEditPredictionTimedOut();

	UFUNCTION()
	void DBNOCarryDrop();

	UFUNCTION()
	void DBNOCarryHoist();

	UFUNCTION()
	void DBNOCarryThrow();

	UFUNCTION()
	bool DBNOTryStartCarry();

	UFUNCTION(BlueprintCallable)
	void FixupInteractionWidgetsOnUnzoom();

	UFUNCTION()
	virtual void HandleDifferentHeroLoadoutActivated(const UFortMcpProfileCampaign* Profile);

	UFUNCTION()
	void LocalOnBlueprintEdit(ABuildingSMActor* EditedActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalInteraction(AActor* ReceivingActor);

	UFUNCTION()
	void OnRep_bHasServerFinishedLoading();

	UFUNCTION()
	void OnRep_CheatMovement();

	UFUNCTION()
	void OnRep_HoldingObject();

	UFUNCTION()
	void OnRep_LatestRewardReport();

	UFUNCTION()
	void OnRep_UpdatedObjectiveStats();

	UFUNCTION()
	void OnRep_UpdatedUnsavedPrimaryMissionProgress();

	UFUNCTION(Server, Reliable)
	void ServerAcknowledgeDelayedQuickBarAction(const TArray<uint32>& ProcessedActionIds);

	UFUNCTION(Server, Reliable)
	void ServerBroadcastUIFeedbackEvent(FName EventName);

	UFUNCTION(Server, Reliable)
	void ServerClientPawnLoaded(bool bIsPawnLoaded);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDeployDefender(ABuildingTrapDefender* DefenderTrap, const FString& SelectedItemInstanceId, const FName& DefenderSquadId, const FGuid WeaponToGiveGuid, const int32 AmmoQuantity);

	UFUNCTION(Server, Reliable)
	void ServerDeveloper_GetConsoleVariable(const FString& ConsoleVariable);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDisassembleInventoryItems(const TArray<FGuid>& ItemGuids, const TArray<int32>& ItemCounts);

	UFUNCTION(Server, Unreliable)
	void ServerEmote(const FName& AssetName);

	UFUNCTION(Server, Reliable)
	void ServerExecuteInventoryItem(FGuid ItemGuid);

	UFUNCTION(Server, Reliable)
	void ServerKillAllAIPawnsAroundPlayer();

	UFUNCTION(Server, Reliable)
	void ServerOnMaterialSelection(EFortResourceType::Type NewResourceType, EFortResourceLevel::Type NewResourceLevel);

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerPlayEmoteItem(const UFortMontageItemDefinitionBase* EmoteAsset, float EmoteRandomNumber);

	UFUNCTION(Server, Reliable)
	void ServerReadyToStartMatch();

	UFUNCTION(Server, Reliable)
	void ServerReleaseInventoryItemKey(FGuid ItemGuid);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRemoveDefender(ABuildingTrapDefender* DefenderTrap);

	UFUNCTION(Server, Reliable)
	void ServerRemoveInventoryItem(FGuid ItemGuid, int32 Count, bool bForceRemoval, bool bForcePersistWhenEmpty);

	UFUNCTION(Server, Reliable)
	void ServerRemoveInventoryStateValue(FGuid ItemGuid, EFortItemEntryState::Type StateValueType);

	UFUNCTION(Server, Reliable)
	void ServerReturnToMainMenu();

	UFUNCTION(Server, Reliable)
	void ServerSetAntiAddictionPlayTimeMultiplier(float NewPlayTimeRewardRate);

	UFUNCTION(Server, Reliable)
	void ServerSetClientHasFinishedLoading(bool bInHasFinishedLoading);

	UFUNCTION(Server, Reliable)
	void ServerSetInventoryStateValue(FGuid ItemGuid, FFortItemEntryStateValue StateValue);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSpawnMark(AActor* ActorToAttachTo, FVector AttachOffset, const FText& PreapprovedText);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSpotActor(AActor* NewlySpottedActor);

	UFUNCTION(Server, Unreliable)
	void ServerTouchActiveTime();

	UFUNCTION(Server, Reliable)
	void ServerUIChoiceCompleted(int32 ChosenItem, int32 MenuIdentifier);

	UFUNCTION(Server, Reliable)
	void TogglePersonalVehicle(bool bOn);

	UFUNCTION()
	bool WantsToDBNOCarry();

	UFUNCTION()
	bool WantsToSecondaryInteract();

	UPROPERTY(BlueprintAssignable)
	FOnFortPawnChanged OnFortPawnChangedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerControllerComponentAttached OnControllerComponentAttachedEvent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> AircraftInputComponent;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<USoundMix> SimpleLoadingScreenSoundMix;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAIPawn>> ManagedAIs;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> MyFortPawn;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> CachedFortPawn;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> MyFortPawnBeforeTakeoverOfScriptedPawn;

	UPROPERTY(Transient)
	TObjectPtr<AController> ScriptedPawnControllerBeforeTakeover;

	UPROPERTY()
	bool bHasClientFinishedLoading;

	UPROPERTY(ReplicatedUsing=OnRep_bHasServerFinishedLoading)
	bool bHasServerFinishedLoading;

	UPROPERTY(Transient)
	float TimeStartedWaiting;

	UPROPERTY(Transient)
	float TimeFinishedNavigationBuild;

	UPROPERTY(EditDefaultsOnly, Category="Material")
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY()
	FVector PendingSpectatorLocation;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ActorUnderReticle;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> AutoFireReticleTarget;

	UPROPERTY(Transient)
	FTimerHandle AutofireTimerHandle;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingWeakSpot> WeakspotUnderReticle;

	UPROPERTY(Transient)
	TArray<FBuildingWeakSpotData> ActiveWeakSpots;

	UPROPERTY()
	float IdleKickLastTimeActive;

	UPROPERTY()
	float LastTimeActive;

	UPROPERTY(BlueprintAssignable)
	FOnMcpProfilesInitialized OnMcpProfilesInitializedEvent;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnEnterVehicleDriver OnEnterVehicleDriver;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnEnterVehiclePassenger OnEnterVehiclePassenger;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnExitVehicle OnExitVehicle;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnExitVehicle OnFullyExitVehicle;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleSeatChanged OnVehicleSeatChanged;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleSeatChangedComplete OnVehicleSeatChangedComplete;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleAbilitiesRemoved OnVehicleAbilitiesRemoved;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnTetherChanged OnTetherChanged;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnClientRefreshHUDForRespawn OnClientRefreshHUDForRespawn;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_HoldingObject)
	uint8 bHoldingObject : 1;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> DBNOCarryInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> HeldObjectsInputComponent;

	UPROPERTY(Transient)
	uint8 bWantsToSprint : 1;

	UPROPERTY(Transient)
	uint8 bHoldingSprint : 1;

	UPROPERTY(Transient)
	uint8 bSprintToggleable : 1;

	UPROPERTY(Transient)
	uint8 bForcingJogFromToggle : 1;

	UPROPERTY(Transient)
	uint8 bForceJogHeld : 1;

	UPROPERTY(Transient)
	uint8 bForceBinaryForward : 1;

	UPROPERTY(Transient)
	uint8 bSprintWasCanceledByReload : 1;

	UPROPERTY(Transient)
	uint8 bShouldAttemptReloadOnEquip : 1;

	UPROPERTY(Transient)
	uint8 bSprintBehaviorIsOverridden : 1;

	UPROPERTY(Transient)
	uint8 bSprintByDefaultWhenSprintIsOverridden : 1;

	UPROPERTY(Transient)
	uint8 bSprintByDefault : 1;

	UPROPERTY(Transient)
	uint8 bAutoRunOn : 1;

	UPROPERTY(Transient)
	uint8 bUseHoldToSwapPickup : 1;

	UPROPERTY(Transient)
	uint8 bTargetingToggleable : 1;

	UPROPERTY(Transient)
	uint8 bTargetingToggleableWithTouch : 1;

	UPROPERTY(Transient)
	uint8 bMovementDisabledDueToCancellableAction : 1;

	UPROPERTY(Transient)
	uint8 bIsPlayerActivelyMoving : 1;

	UPROPERTY(Transient)
	uint8 bPlaceHeldObjectPressed : 1;

	UPROPERTY(Transient)
	uint8 bJumpInputPressed : 1;

	UPROPERTY(Transient)
	uint8 bIsRunningAllowedByMoveKeys : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerController")
	uint8 bShowDamageNumbersOfConvertedNPC : 1;

	UPROPERTY(Transient)
	int32 InMovementCancellableAction;

	UPROPERTY()
	bool bAllowHoldForAmmoCrafting;

	UPROPERTY(Transient)
	bool bIsClientTimingOut;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	float ClientTimeoutBlockInputTime;

	UPROPERTY(Transient)
	uint64 LastMoveInputFrame;

	UPROPERTY(Transient)
	float LastPressGamepadSprintTime;

	UPROPERTY(Transient)
	bool bAutoRunWasHoldingForward;

	UPROPERTY(Transient)
	bool bAtNameBaseScreen;

	UPROPERTY(BlueprintAssignable, Category="Camera")
	FOnSetFirstPersonCamera OnSetFirstPersonCamera;

	UPROPERTY(Transient)
	TSubclassOf<UFortCinematicCamera> CinematicCameraClassOverride;

	UPROPERTY(Transient)
	bool bOnPressExecuteJetpack;

	UPROPERTY(Transient)
	bool bGamepadAbilityPending;

	UPROPERTY(Transient)
	float LastSpotTime;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerController")
	FVector2D LastPlayerLocalMoveInput;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortMarkActor>> CurrentMarks;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FName, TObjectPtr<UAudioComponent>> LoopingUIFeedbackComponents;

	UPROPERTY()
	TObjectPtr<UFortGameplayAbility> PreviewAbility;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerController")
	bool bDisableNativeHitMarker;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerController")
	bool bDisableNativeDamageNumbers;

	UPROPERTY()
	TObjectPtr<AFortAIDirectorDataManager> AIDirectorDataManager;

	UPROPERTY()
	TObjectPtr<AFortMusicManager> MusicManager;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> BuildPreviewModeInputComponent;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingPlayerPrimitivePreview> BuildPreviewMarker;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingPlayerPrimitivePreview> BuildPreviewMarkerExtraPiece;

	UPROPERTY(Config)
	bool bAllowBuildingPreviewAutoRotation;

	UPROPERTY(Config)
	bool bRequireTraceToExistingBuildingToSetContext;

	UPROPERTY(Config)
	bool bAllowTraceToExistingBuildingToSetContextToRedirectToBlockingBuilding;

	UPROPERTY(Config)
	bool bRequireTraceToExistingBuildingToSetContextExcludeCurrentContext;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> TargetedBuilding;

	UPROPERTY(Transient)
	TObjectPtr<AActor> TargetedVehicle;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> TargetedFortPawn;

	UPROPERTY(Transient)
	TSubclassOf<ABuildingSMActor> ContextualConversionClass;

	UPROPERTY(Transient)
	TSoftObjectPtr<USoundBase> StartUpgradeSound;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingActor>> HighlightedPrimaryBuildings;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingActor>> HighlightedInteractionBuildings;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingActor> HighlightedPrimaryBuilding;

	UPROPERTY(Transient)
	TSoftObjectPtr<UMaterialInterface> BuildPreviewMarkerParentMaterial;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInstanceDynamic>> BuildPreviewMarkerMIDs;

	UPROPERTY(Transient)
	uint8 BuildPreviewRotationIterations;

	UPROPERTY(Transient)
	uint8 bBuildPreviewMirrored : 1;

	UPROPERTY(Transient)
	EFortBuildPreviewMarkerOptionalAdjustment BuildPreviewMarkerOptionalAdjustment;

	UPROPERTY(Transient, Replicated)
	uint8 bCraftFree : 1;

	UPROPERTY(Transient)
	TEnumAsByte<EFortCostInfoTypes::Type> CurrentCostInfoType;

	UPROPERTY(Transient)
	TSubclassOf<ABuildingSMActor> CurrentBuildableClass;

	UPROPERTY(Transient)
	TSubclassOf<ABuildingSMActor> PreviousBuildableClass;

	UPROPERTY(Transient)
	TEnumAsByte<EFortResourceLevel::Type> CurrentResourceLevel;

	UPROPERTY(Transient)
	TEnumAsByte<EFortResourceType::Type> CurrentResourceType;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortBuildingType"))
	FLastBuildableState LastBuildableStateData[12];

	UPROPERTY(Transient)
	TArray<FFortDamageNumberInfo> QueuedDamageNumbers;

	UPROPERTY(Transient)
	TObjectPtr<AFortDamageNumbersActor> DamageNumbersActor;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> EditModeInputComponent;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingSMActor> EditBuildingActor;

	UPROPERTY(Transient)
	float EditModeDistance;

	UPROPERTY(Transient)
	FVector LastBuildPreviewGridSnapLoc;

	UPROPERTY(Transient)
	FRotator LastBuildPreviewGridSnapRot;

	UPROPERTY(Transient)
	FVector LastBuildPreviewGridSnapCentroid;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> PickerInputComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortDecoHelper> TrapPickerDecoHelper;

	UPROPERTY()
	TArray<FHitResult> TouchEditResults;

	UPROPERTY(Config)
	bool bBuildingPlacementTraceSkipInitialPenetrationOfBuildingSMActor;

	UPROPERTY(Config)
	bool bBuildingPlacementTraceSkipInitialPenetrationOfStaticMesh;

	UPROPERTY()
	TObjectPtr<AFortQuickBars> ClientQuickBars;

	UPROPERTY(Transient)
	TArray<FRecentlyRemovedQuickbarInfo> RecentlyRemovedQuickbarInfo;

	UPROPERTY(Transient)
	FQueuedItemsToDropViaPickup QueuedItemsToDrop;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerController")
	TSubclassOf<AFortInventory> WorldInventoryClass;

	UPROPERTY(ReplicatedUsing=HandleWorldInventoryLocalUpdate)
	TObjectPtr<AFortInventory> WorldInventory;

	UPROPERTY(ReplicatedUsing=HandleOutpostInventoryLocalUpdate)
	TObjectPtr<AFortInventory> OutpostInventory;

	UPROPERTY(ReplicatedUsing=HandleViewTargetInventoryLocalUpdate)
	TObjectPtr<AFortInventory> ViewTargetInventory;

	UPROPERTY()
	uint8 bHasInitializedWorldInventory : 1;

	UPROPERTY()
	uint8 bHasInitializedHeroInventory : 1;

	UPROPERTY()
	uint8 bAccountInventoryWasUpdated : 1;

	UPROPERTY()
	uint8 bForceWorldInventoryUpdate : 1;

	UPROPERTY()
	uint8 bIsSavingGadgetLoadout : 1;

	UPROPERTY(Transient)
	TObjectPtr<UFortClientPilot_Base> BotPilot;

	UPROPERTY(Transient)
	TObjectPtr<UFortClientBotManager> BotManager;

	UPROPERTY(EditDefaultsOnly, Category="Bots")
	TSubclassOf<UFortClientBotManager> ClientBotManagerClass;

	UPROPERTY(ReplicatedUsing=OnRep_LatestRewardReport)
	FFortRewardReport LatestRewardReport;

	UPROPERTY()
	TObjectPtr<UFortRegisteredPlayerInfo> MyPlayerInfo;

	UPROPERTY(ReplicatedUsing=OnRep_UpdatedObjectiveStats)
	TArray<FFortUpdatedObjectiveStat> UpdatedObjectiveStats;

	UPROPERTY(ReplicatedUsing=OnRep_UpdatedUnsavedPrimaryMissionProgress)
	bool bHasUnsavedPrimaryMissionProgress;

	UPROPERTY()
	FFortPersistentGameplayStatContainer CachedPersistentGameplayStats;

	UPROPERTY(Transient)
	TObjectPtr<UFortMontageItemDefinitionBase> LastEmotePlayed;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UFortMontageItemDefinitionBase>, int32> EmoteUsageCounts;

	UPROPERTY(Transient)
	TArray<FVector> AnalyticsBuildingWallTooLowLocations;

	UPROPERTY(Transient)
	TSet<TObjectPtr<AFortPlayerPawn>> NearbyEmotingPawns;

	UPROPERTY(Transient)
	TMap<FName, int32> NearbyEmotingPawnCount;

	UPROPERTY(Transient)
	TObjectPtr<UMcpProfileGroup> McpProfileGroup;

	UPROPERTY(Transient)
	TObjectPtr<UFortMcpProfileCommonPublic> CommonPublicMcpProfile;

	UPROPERTY(Transient)
	TObjectPtr<UFortMcpProfileCommonCore> CommonCoreMcpProfile;

	UPROPERTY(Transient)
	TObjectPtr<UFortMcpProfileCampaign> MainMcpProfile;

	UPROPERTY(Transient)
	TObjectPtr<UFortMcpProfileAthena> AthenaProfile;

	UPROPERTY(Transient)
	TObjectPtr<UFortMcpProfileMetadata> MetadataProfile;

	UPROPERTY(Transient)
	TObjectPtr<UFortMcpProfileCreative> CreativeModeProfile;

	UPROPERTY(Transient)
	TObjectPtr<USoundEffectSourcePresetChain> VoiceInputSourceEffectPresetChain;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortSprayDecalInstance>> ActiveSprayInstances;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> ActiveToyInstances;

	UPROPERTY(Transient)
	TMap<TSubclassOf<UObject>, int32> ToySummonCounts;

	UPROPERTY(Config)
	bool bPushEmoteAudioDataToCosmeticMaterials;

	UPROPERTY(Transient)
	float LastEmoteMusicFFT100hz;

	UPROPERTY(Transient)
	float LastEmoteMusicFFT2000hz;

	UPROPERTY(Config)
	float EmoteMusicBeatThreshold;

	UPROPERTY(Transient)
	float EmoteMusicEnvelopeBeatCount;

	UPROPERTY(Transient)
	bool bZeroingCameraRoll;

	UPROPERTY(Transient)
	bool bTryPickupSwap;

	UPROPERTY(Config)
	bool bClientSideEditPrediction;

	UPROPERTY(Config)
	float ClientSideEditPredictionTimeout;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingSMActor> PendingEnterEditModeActor;

	UPROPERTY(Transient)
	int32 RandomCharacterIndex;

	UPROPERTY(Transient)
	float AntiAddictionPlayTimeMultiplier;

	UPROPERTY(Transient)
	FLockOnInfo LockOnInfo;

	UPROPERTY(Transient, Replicated)
	TWeakObjectPtr<AActor> FocusTarget;

	UPROPERTY()
	bool bTurboBuild;

	UPROPERTY(Config)
	float TurboBuildFirstInterval;

	UPROPERTY(Config)
	float TurboBuildRequestFailedInterval;

	UPROPERTY(Config)
	float TurboBuildInterval;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Telemetry> FortControllerComponent_Telemetry;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_InventoryNetworkManagement> InventoryNetworkManagementComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Interaction> InteractionComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerController", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Quests> QuestsComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerController", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_SharedQuests> SharedQuestsComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerController", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_QuestGates> QuestGatesComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerController", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Minimap> MiniMapComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerController", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_PinQuest> PinQuestComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerController", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_SurvivorTiers> SurvivorTiersComponent;

	UPROPERTY(EditDefaultsOnly, Config, Category="WorldPartition")
	TSubclassOf<UFortControllerComponent_StreamingSources> StreamingSourcesComponentClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_StreamingSources> StreamingSourcesComponent;

	UPROPERTY(EditDefaultsOnly, Export, Category="EditMode", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_QuickEdit> QuickEditComponent;

	UPROPERTY(EditDefaultsOnly, Export, Category="Building", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_SmartBuild> SmartBuildComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Collections> CollectionsComponent;

	UPROPERTY(VisibleDefaultsOnly, Export, Category="FortPlayerController", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_CosmeticLoadout> CosmeticLoadoutComponent;

	UPROPERTY(Transient)
	FItemVariantHandle PendingExecuteInventoryItemHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerController")
	TSubclassOf<UQuickHealItemPicker> QuickHealItemPickerClass;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerController")
	float ForcedInputRotationSpeed;

	UPROPERTY()
	FCompositeBool IgnoreSignifanceBasedCustomDepthRendering;

private:
	UFUNCTION()
	void HandleBattleMapSpectatorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void HandleWinnerAnnounced(const FString& WinnerPlayerName);

	UFUNCTION()
	void OnRep_DelayedQuickBarActions();

	UFUNCTION(Server, Reliable)
	void ServerSetPartyOwner(const FUniqueNetIdRepl& PartyOwnerUniqueId);

	UFUNCTION(Server, Reliable)
	void ServerSetRebootEligiblePartyFriendsList(const TArray<FFortRebootEligiblePartyFriendInfo>& NewRebootEligiblePartyFriends);

	UPROPERTY(Transient)
	bool bInPossession;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UActorComponent> SprintOverrideComponent;

	UPROPERTY(Transient)
	FGameplayTag SprintOverrideAbilityGameplayTag;

	UPROPERTY()
	bool bForceAllowCursorMode;

	UPROPERTY()
	bool bForceAllowCameraMode;

	UPROPERTY()
	bool bSuppressEventNotifications;

	UPROPERTY(ReplicatedUsing=OnRep_DelayedQuickBarActions)
	FDelayedQuickBarActionContainer DelayedQuickBarActions;

	UPROPERTY(Transient)
	TSet<uint32> ClientProcessedQuickBarActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization", meta=(AllowPrivateAccess="TRUE"))
	FFortAthenaLoadout CosmeticLoadoutPC;

	UPROPERTY(Transient, Replicated)
	EFortPCTutorialCompletedState TutorialCompletedState;

	UPROPERTY()
	TObjectPtr<UFortIndicatorManager> IndicatorManager;

	UPROPERTY(Replicated)
	bool bFinalXPUpdateFailed;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> TestUserWidget;

	UPROPERTY()
	TObjectPtr<APawn> PendingClientRestartPawn;

};

