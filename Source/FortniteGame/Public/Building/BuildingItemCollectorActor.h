// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Abilities/FortAbilityTypes.h"
#include "Building/BuildingGameplayActor.h"
#include "FortInteractInterface.h"
#include "FortItemQuantityPair.h"
#include "FortRarityEnum.h"
#include "Items/FortItemEntry.h"
#include "BuildingItemCollectorActor.generated.h"

class AFortAthenaVehicle;
class AFortPlayerController;
class AFortPlayerState;
class UDataTable;
class UFortWorldItemDefinition;
class UTexture;
enum class EFortItemCollectorState : uint8;
enum class EFortRarity : uint8;

UENUM(BlueprintType)
enum class EFortItemCollectorBehavior : uint8
{
	// Team Deposits Item to Goal locks it down as theirs.

	FirstToGoal = 0,
	// Same as FirstToGoal except the Item Collector will not lock down, so teams can both achieve the goal (no CaptureState).

	FreeForAll = 1,
};

UENUM(BlueprintType)
enum class EFortItemCollectorState : uint8
{
	CanInteract = 0,
	Active = 1,
	Inactive = 2,
	Captured = 3,
	Invalid = 4,
};

UENUM(BlueprintType)
enum class EFortItemCollectorTrackingType : uint8
{
	// will track the data by player

	Player = 0,
	// will track the data by team

	Team = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemCollectorHandleManualOutput, AFortPlayerController*, InteractingController, UFortWorldItemDefinition*, InputItem);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemCollectorPickupSpawned);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemCollectorVehicleSpawned, AFortAthenaVehicle*, Vehicle);

USTRUCT()
struct FCollectedItemValue
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortWorldItemDefinition> CollectedItem;

	UPROPERTY()
	int32 DepositAmount;

	UPROPERTY()
	int32 DepositGoal;

	UPROPERTY()
	int32 CaptureCount;

};

USTRUCT(BlueprintType)
struct FCollectorTrackedData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 Team;

	UPROPERTY()
	TObjectPtr<AFortPlayerState> Player;

private:
	UPROPERTY()
	TArray<FCollectedItemValue> TrackedItemValues;

};

USTRUCT(BlueprintType)
struct FCollectorUnitInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CollectorUnitInfo")
	TObjectPtr<UFortWorldItemDefinition> InputItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CollectorUnitInfo")
	FScalableFloat InputCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CollectorUnitInfo")
	TObjectPtr<UTexture> OverrideInputItemTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Requirements")
	uint8 bUseDefinedOutputItem : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CollectorUnitInfo", meta=(EditCondition="bUseDefinedOutputItem"))
	TObjectPtr<UFortWorldItemDefinition> OutputItem;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CollectorUnitInfo")
	TArray<FFortItemEntry> OutputItemEntry;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CollectorUnitInfo")
	FName OverrideOutputItemLootTierGroupName;

	UPROPERTY(EditDefaultsOnly, Category="CollectorUnitInfo")
	FFortGameplayEffectDeliveryInfo OutputGameplayEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CollectorUnitInfo")
	TObjectPtr<UTexture> OverrideOutputItemTexture;

};

USTRUCT()
struct FItemCollectorOverrideItemRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ItemCollectorOverrideItemRow")
	FPrimaryAssetId ItemPrimaryAssetId;

	UPROPERTY(EditDefaultsOnly, Category="ItemCollectorOverrideItemRow")
	int32 Quantity;

};

USTRUCT()
struct FItemCollectorRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ItemCollectorRow")
	TObjectPtr<UDataTable> OverrideItemsTable;

	UPROPERTY(EditDefaultsOnly, Category="ItemCollectorRow", meta=(EditCondition="bUseOverrideRarity"))
	EFortRarity OverrideRarity;

	UPROPERTY(EditDefaultsOnly, Category="ItemCollectorRow")
	int32 OverrideGoal;

	UPROPERTY(EditDefaultsOnly, Category="ItemCollectorRow", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	int32 bOverrideLootRules;

	UPROPERTY(EditDefaultsOnly, Category="ItemCollectorRow", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	int32 bUseOverrideRarity;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingItemCollectorActor : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Loot Drop")
	void ClearLootSpawnWorldTransformOverride();

	UFUNCTION(BlueprintPure, Category="Interact Data")
	UFortWorldItemDefinition* GetCurrentActiveItem() const;

	UFUNCTION(BlueprintPure, Category="Interact Data")
	int32 GetDepositAmount(AFortPlayerController* InFortPC, UFortWorldItemDefinition* InInputItem);

	UFUNCTION(BlueprintPure, Category="Interact Data")
	int32 GetDepositGoal(AFortPlayerController* InFortPC, UFortWorldItemDefinition* InInputItem);

	UFUNCTION(BlueprintPure, Category="Interact Data")
	int32 GetNumberOfCaptures(AFortPlayerController* InFortPC, UFortWorldItemDefinition* InInputItem);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Interact Data")
	bool GetOverrideRarity(EFortRarity& Rarity) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Data")
	int32 GetTeamReachedGoalCount(uint8 InTeam);

	UFUNCTION(BlueprintCallable, Category="Interact Data")
	virtual bool HasEnoughDepositItems(AFortPlayerController* FortPC, UFortWorldItemDefinition* InputItem, bool bAllOrNothing, const EInteractionBeingAttempted InInteractionBeingAttempted);

	UFUNCTION(BlueprintImplementableEvent, Category="Interact Events")
	void OnForcedCycle();

	UFUNCTION(BlueprintImplementableEvent, Category="Interact Events")
	void OnItemCollectorStateChanged(EFortItemCollectorState InItemCollectorState);

	UFUNCTION(BlueprintImplementableEvent, Category="Interact Events")
	void OnReachedDepositGoal(AFortPlayerController* CurrentControllingPlayer, UFortWorldItemDefinition* CurrentActiveInputItem);

	UFUNCTION(BlueprintCallable, Category="Interact Events")
	void RefreshCollectorsActiveItem();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Interact Methods")
	void ServerSpawnItem(const FFortItemEntry OutputItem);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Interact Methods")
	void SetItemCollectorState(EFortItemCollectorState InItemCollectorState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Loot Drop")
	void SetLootSpawnWorldTransformOverride(const FTransform& Transform);

	UFUNCTION(BlueprintImplementableEvent, Category="Interact Events")
	void UpdateCollectorsActiveItem(int32 StartingSeedValue, UFortWorldItemDefinition* InputItem, UTexture* InputTexture, int32 CurrentGoal, int32 CurrentCollectedAmount, int32 CurrentCaptureCount, UTexture* OutputTexture);

protected:
	UFUNCTION()
	void OnRep_ActiveInputItem();

	UFUNCTION()
	void OnRep_ControllingPlayer();

	UFUNCTION()
	void OnRep_ItemCollectorState();

	UFUNCTION()
	void OnRep_TrackedInteractionData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact Methods")
	EFortItemCollectorBehavior ItemCollectorBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact Methods")
	uint8 bRequireAllForInteraction : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact Methods")
	uint8 bRequireAllForTurnIn : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact Methods")
	uint8 bHasToHaveSomething : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact Methods")
	uint8 bIncrementCaptureCountWhenGoalIsReached : 1;

	UPROPERTY(BlueprintReadOnly, Category="Interact Methods")
	uint8 bCurrentInteractionSuccess : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_ItemCollectorState, Category="Interact Methods")
	EFortItemCollectorState ItemCollectorState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_ItemCollectorState, Category="Interact Methods")
	EFortItemCollectorTrackingType TrackingType;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ControllingPlayer, Category="Interact Data")
	TObjectPtr<AFortPlayerController> ControllingPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, SaveGame, Category="Interact Methods")
	FName DefaultItemLootTierGroupName;

	UPROPERTY(EditAnywhere, SaveGame, Category="Interact Methods|Instance Override")
	FDataTableRowHandle ItemCollectorHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact Methods|Instance Override")
	bool bCallOnLocalInteract;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Replicated, Category="Interact Methods|Instance Override")
	bool bUseInstanceLootValueOverrides;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Replicated, Category="Interact Methods|Instance Override", meta=(EditCondition="bUseInstanceLootValueOverrides"))
	TArray<FFortItemQuantityPair> OverrideOutputItems;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Interact Methods|Instance Override", meta=(EditCondition="bUseInstanceLootValueOverrides"))
	int32 OverrideGoal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Interact Methods|Instance Override")
	int32 NumInteractionsAllowed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingItemCollectorActor")
	int32 NumInteractions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, SaveGame, Replicated, Category="Interact Methods")
	TArray<FCollectorUnitInfo> ItemCollections;

	UPROPERTY(BlueprintAssignable)
	FItemCollectorHandleManualOutput ManualOutputOverride;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ActiveInputItem, Category="Interact Data")
	TObjectPtr<UFortWorldItemDefinition> ActiveInputItem;

	UPROPERTY()
	TObjectPtr<UFortWorldItemDefinition> ClientPausedActiveInputItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interact Methods")
	FScalableFloat ActiveItemRotationTime;

	UPROPERTY(BlueprintReadOnly, Category="Interact Methods")
	float ItemRotationTime;

	UPROPERTY(EditDefaultsOnly, Category="Interact Methods")
	float ItemRotationTimeVariation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interact Methods")
	FGameplayTagContainer AllowedItemRotationDamageTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interact Methods")
	FScalableFloat OutputDespenseDelayTime;

	UPROPERTY(BlueprintReadOnly, Category="Interact Methods")
	float DespensingDelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot Drop")
	FVector LootSpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Loot Drop")
	FRotator LootTossDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Loot Drop")
	float LootTossConeHalfAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Loot Drop")
	float LootTossSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Loot Drop")
	bool bTossOnGround;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Loot Drop")
	bool bSpawnAmmoOnlyWhenCarryingWeapon;

	UPROPERTY(Replicated)
	int32 StartingGoalLevel;

	UPROPERTY(EditDefaultsOnly, Category="Loot Drop")
	int32 StartingGoalLevelOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingItemCollectorActor")
	TObjectPtr<UTexture> InactiveItemTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot Drop")
	bool bPickupOwnedByLooter;

	UPROPERTY(BlueprintAssignable)
	FItemCollectorPickupSpawned PickupSpawned;

	UPROPERTY(BlueprintAssignable)
	FItemCollectorVehicleSpawned VehicleSpawned;

private:
	UPROPERTY(ReplicatedUsing=OnRep_TrackedInteractionData)
	TArray<FCollectorTrackedData> TrackedInteractionData;

};

