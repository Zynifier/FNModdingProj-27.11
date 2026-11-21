// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/DBNOCustomSettings.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_InventoryOverride.h"
#include "Athena/Modifiers/FortAthenaMutator_NamePlate.h"
#include "Creative/FortCreativeTeamOption.h"
#include "FortItemAndCount.h"
#include "FortPlayerCustomizableInterface.h"
#include "FortPropertyOverrideData.h"
#include "FortPropertyOverrideReplication.h"
#include "Minigame/FortMinigameTypes.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortAthenaMutator_PlayerSettingsBase.generated.h"

class UCurveTable;
class UFortAbilitySet;
class UFortMinigameStatFilter;
class UFortPlayerSettingsComponentBase;
class UFortSharedGravityMovementData;
class UPlaylistUserOptions;

UENUM(BlueprintType)
enum class EFlightSpeedPresetOverride : uint8
{
	FlightSpeed0 = 0 UMETA(DisplayName="0.5x"),
	FlightSpeed1 = 1 UMETA(DisplayName="1.0x"),
	FlightSpeed2 = 2 UMETA(DisplayName="1.5x"),
	FlightSpeed3 = 3 UMETA(DisplayName="2.0x"),
	FlightSpeed4 = 4 UMETA(DisplayName="3.0x"),
	FlightSpeed5 = 5 UMETA(DisplayName="4.0x"),
	FlightSpeed6 = 6 UMETA(DisplayName="5.0x"),
};

UENUM(BlueprintType)
enum class EGravityPresetOverride : uint8
{
	Normal = 0,
	Low = 1,
	VeryLow = 2,
	High = 3,
	VeryHigh = 4,
};

UENUM(BlueprintType)
enum class EHarvestStyleOverride : uint8
{
	None = 0,
	Creative = 1,
	BattleRoyale = 2,
	SaveTheWorld = 3,
};

UENUM(BlueprintType)
enum class EIndicatorLineOfSightMode : uint8
{
	AlwaysShow = 0,
	HideBehindObstacles = 1,
};

UENUM(BlueprintType)
enum class ESelfDamageTargetPreset : uint8
{
	NonPlayers = 0 UMETA(DisplayName="Non-Players"),
	PlayersOnly = 1,
	All = 2,
};

UENUM(BlueprintType)
enum class ESelfDamageWeaponTypePreset : uint8
{
	PickaxeOnly = 0,
	MeleeOnly = 1,
	RangedOnly = 2,
	All = 3,
};

USTRUCT()
struct FMutatorPlayerSettingsData
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerSettingsComponentBase> ScopeSettings;

};

USTRUCT()
struct FNameplateAsyncTrace
{
	GENERATED_BODY()

};

USTRUCT()
struct FNameplateAsyncTraceRequest
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerSettingsBase : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator|Abilities")
	TObjectPtr<UFortAbilitySet> AbilitySetToGrant;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator|Abilities")
	TObjectPtr<UPlaylistUserOptions> AbilitySetOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator|Player Movement")
	TObjectPtr<UFortSharedGravityMovementData> GravityPresets;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Inventory")
	FName GameResourcesCreativeTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mutator|Resources")
	TArray<TObjectPtr<UCurveTable>> ResourceRateOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator|Player Self Damage")
	TArray<FGameplayTagQuery> TargetQueries;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator|Player Self Damage")
	TArray<FGameplayTagQuery> WeaponQueries;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator|Stats|Elimination to Score")
	TSubclassOf<UFortMinigameStatFilter> EliminationStat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator|Stats|Elimination to Score")
	FStatEventFilter EliminationScoreStatEvent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator|Stats|Assists to Score")
	TSubclassOf<UFortMinigameStatFilter> AssistStat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator|Stats|Assists to Score")
	FStatEventFilter AssistScoreStatEvent;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, FNameplateAsyncTrace> UncheckedTraces;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerSettingsComponentBase> DefaultScopeSettings;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerSettingsComponentBase> CurrentScopeSettings;

};

UCLASS()
class UFortPlayerSettingsComponentBase : public UActorComponent, public IFortPlayerCustomizable, public IFortPropertyOverrideProvider, public IFortPropertyOverrideReplProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="BlockBuilding")
	const FGameplayTagContainer GetHUDVisibilityTags() const;

	UFUNCTION(BlueprintPure, Category="Mutator|Property Data")
	bool IsSettingEnabled(const FName& PropertyName) const;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Vitals")
	float MaxHealthAlt;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Vitals")
	float MaxHealth;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Vitals")
	float StartingHealth;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Vitals")
	float MaxShield;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Vitals")
	float StartingShield;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Vitals")
	bool bInvincibility;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Vitals")
	EDBNOMutatorType DBNOSetting;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Spawning")
	float RespawnHeight;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Spawning")
	float RespawnTime;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Spawning")
	EFortMinigamePlayerSpawnLocationSetting SpawnLocationSetting;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Spawning")
	bool bOverrideSpawnImmunityTime;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Spawning")
	float SpawnImmunityTime;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Inventory")
	EAthenaLootDropOverride DropAllItemsOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Inventory")
	EAthenaLootDropOverride DropAllResourcesOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Inventory")
	EAthenaLootDropOverride DropAllGameResourcesOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Inventory")
	TArray<FItemAndCount> InventoryItems;

	UPROPERTY(EditDefaultsOnly, Category="Muator|Cosmetics")
	FString CharacterOverride;

	UPROPERTY(EditDefaultsOnly, Category="Muator|Cosmetics")
	FString PickaxeOverride;

	UPROPERTY(EditDefaultsOnly, Category="Muator|Cosmetics")
	FString BackpackOverride;

	UPROPERTY(EditDefaultsOnly, Category="Muator|Cosmetics")
	FString GliderOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Siphon")
	int32 HealthSiphonValue;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Siphon")
	int32 WoodSiphonValue;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Siphon")
	int32 StoneSiphonValue;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Siphon")
	int32 MetalSiphonValue;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Siphon")
	int32 GoldSiphonValue;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Player Self Damage")
	float DamageToDeal;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Player Self Damage")
	bool bRequiresNonZeroDamage;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Player Self Damage")
	ESelfDamageTargetPreset TargetQueryIndex;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Player Self Damage")
	ESelfDamageWeaponTypePreset WeaponQueryIndex;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Player Movement")
	bool bFallDamage;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Player Movement")
	float FallDamageMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Player Movement")
	int32 GravityOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Player Movement")
	EGravityPresetOverride GravityPreset;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	int32 PlayerLives;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	FCreativeTeamOption AfterLastSpawnGoTo;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	uint8 TeamToMoveToWhenOutOfSpawns;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	float EliminationsToScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	float AssistsToScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Resources")
	float HarvestRateMutliplier;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Resources")
	int32 ResourceRateOverrideIndex;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Resources")
	EHarvestStyleOverride HarvestStyle;

protected:
	UFUNCTION()
	void OnRep_bGoldCurrencyResourceWidgetVisible();

	UFUNCTION()
	void OnRep_bInfiniteAmmo();

	UFUNCTION()
	void OnRep_bMetalResourceWidgetVisible();

	UFUNCTION()
	void OnRep_bStoneResourceWidgetVisible();

	UFUNCTION()
	void OnRep_bWoodResourceWidgetVisible();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, Category="Mutator|Building")
	EBuildingMode BuildingMode;

private:
	UFUNCTION()
	void OnRep_AbilitySetOptionData();

	UFUNCTION()
	void OnRep_CreativeBossHealthDisplayMode();

	UFUNCTION()
	void OnRep_EnabledSettings();

	UFUNCTION()
	void OnRep_NameplateDisplayMode();

	UFUNCTION()
	void OnRep_PlayerHealthIndicatorDisplayMode();

	UFUNCTION()
	void ResolvePendingRepOverrides();

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Controls")
	bool bAimAssistAllowed;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Spawning")
	bool bIsPlayerTriggeredRespawnAllowed;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Spawning")
	bool OnlyAllowRespawningIfPlayerStartPadsFound;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Inventory")
	bool bInstantReload;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_bInfiniteAmmo, Category="Mutator|Inventory")
	bool bInfiniteAmmo;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Inventory")
	bool bInfiniteConsumables;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Inventory")
	bool bInfiniteResources;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Inventory")
	bool bAllowItemDrop;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Inventory")
	bool bAllowItemPickUp;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Inventory")
	float MaxItemSlots;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_bWoodResourceWidgetVisible, Category="Mutator|Inventory")
	bool bWoodResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_bStoneResourceWidgetVisible, Category="Mutator|Inventory")
	bool bStoneResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_bMetalResourceWidgetVisible, Category="Mutator|Inventory")
	bool bMetalResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_bGoldCurrencyResourceWidgetVisible, Category="Mutator|Inventory")
	bool bGoldCurrencyResourceWidgetVisible;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Player Movement")
	bool bApplyJumpPenalty;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Player Movement")
	bool bGliderRedeploy;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Player Movement")
	bool bFlyEnabled;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Player Movement")
	bool bAllowFlightSprint;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Player Movement")
	EFlightSpeedPresetOverride FlySpeedPreset;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Player Movement")
	int32 FlySpeedModifierIndex;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Game Rules")
	bool bAllowFriendlyFire;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Game Rules")
	bool bVehiclesDamageObjects;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Game Rules")
	bool bVehiclesDamageVehicles;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Edit Mode")
	bool bEnableVehiclesDamageObjects;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Mutator|Resources")
	int32 MaximumResources;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	EIndicatorDisplayMode NameplateDisplayMode;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	bool bLimitNamePlateMaxDistance;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	float NameplateDisplayDistanceMeters;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	float NameplateDisplayDistance;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	float NameplateFocusAngleDegrees;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	float NameplateFocusAngle;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	float NameplateFocusTime;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	EIndicatorDisplayMode NameplateFocusMode;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_NameplateDisplayMode, Category="Mutator|UI")
	EIndicatorLineOfSightMode NameplateLineOfSight;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_PlayerHealthIndicatorDisplayMode, Category="Mutator|UI")
	EPlayerIndicatorDisplayMode PlayerHealthIndicatorDisplayMode;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_CreativeBossHealthDisplayMode, Category="Mutator|UI")
	ECreativeBossDisplayMode CreativeBossHealthDisplayMode;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_AbilitySetOptionData, Category="Mutator|Abilities")
	FPropertyOverrideData AbilitySetOptionData;

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_EnabledSettings, Category="FortPlayerSettingsComponentBase")
	TArray<FString> EnabledSettings;

};

