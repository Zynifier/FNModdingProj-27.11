// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortGender.h"
#include "Items/FortItemTypeEnum.h"
#include "FortHomebaseManager.generated.h"

class UCurveTable;
class UDataTable;
class UFortHomebaseNodeGameplayEffectDataTable;
class UFortHomebaseNodeItemDefinition;
class UFortItemIconDefinition;
class UFortMcpProfileCampaign;
class UFortWorker;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EFortHomebaseSquadType : uint8
{
	AttributeSquad = 0,
	CombatSquad = 1,
	DefenderSquad = 2,
	ExpeditionSquad = 3,
	// Invalid type, used in filters to say "any type"

	Max_None = 4 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
enum class ESquadSlotType : uint8
{
	HeroSquadMissionDefender = 0,
	SurvivorSquadLeadSurvivor = 1,
	SurvivorSquadSurvivor = 2,
	DefenderSquadMember = 3,
	ExpeditionSquadMember = 4,
};

USTRUCT(BlueprintType)
struct FExpeditionSlot : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NodePage")
	FGameplayTag SlotTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NodePage")
	FString LootTierGroup;

};

USTRUCT(BlueprintType)
struct FHomebaseSquadAttributeBonus
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlot")
	FGameplayAttribute AttributeGranted;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlot")
	FCurveTableRowHandle BonusCurve;

};

USTRUCT(BlueprintType)
struct FHomebaseSquadSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlot")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlot")
	TArray<EFortItemType> ValidSlottableItemTypes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlot")
	FGameplayTagContainer TagFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlot")
	TArray<FHomebaseSquadAttributeBonus> SlottingBonuses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlot")
	TObjectPtr<UCurveTable> PersonalityMatchBonusTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlot")
	ESquadSlotType SlotType;

};

USTRUCT(BlueprintType)
struct FHomebaseSquad : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	FText ShortDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	EFortHomebaseSquadType SquadType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	FGameplayTag ManagerSynergyTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	TArray<FHomebaseSquadSlot> CrewSlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	FGameplayTagContainer RequiredTheaterTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	int32 MaxNumDefendersAllowedInLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	int32 MaxNumDefendersAllowedInGroupLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	bool bConsiderNumPlayersForMaxNumDefenders;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	bool bAlwaysRemoveOldestDefenderWhenReplacing;

};

USTRUCT(BlueprintType)
struct FHomebaseSquadSlotId
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	FName SquadId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad")
	int32 SquadSlotIndex;

};

USTRUCT(BlueprintType)
struct FWorkerPortraitData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftObjectPtr<UFortItemIconDefinition> Portrait;

};

USTRUCT(BlueprintType)
struct FWorkerGenderData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<FWorkerPortraitData> PotraitData;

};

USTRUCT(BlueprintType)
struct FManagerSynergyData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(Categories="Homebase.Manager"))
	FGameplayTag SynergyTypeTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<FWorkerGenderData> GenderData;

};

USTRUCT(BlueprintType)
struct FWorkerPersonalityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(Categories="Homebase.Worker.Personality"))
	FGameplayTag PersonalityTypeTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FText PersonalityName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 SelectionWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<FWorkerGenderData> GenderData;

};

USTRUCT(BlueprintType)
struct FWorkerSetBonusData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(Categories="Homebase.Worker.SetBonus"))
	FGameplayTag SetBonusTypeTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 RequiredWorkersCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSubclassOf<UGameplayEffect> SetBonusEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 SelectionWeight;

	UPROPERTY()
	int32 PowerPoints;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortHomebaseManager : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Homebase")
	bool AreNodeCostsMet(const UFortHomebaseNodeItemDefinition* NodeItemDef, UFortMcpProfileCampaign* McpProfile, int32 Level);

	UFUNCTION(BlueprintPure, Category="Homebase")
	FString GetNodeInstanceIdByNodeId(const FString& NodeTemplateId, const UFortMcpProfileCampaign* McpProfile) const;

	UFUNCTION(BlueprintCallable, Category="AccountInventory")
	int32 GetNumAccountInventoryBonusTokens(UFortMcpProfileCampaign* McpProfile);

	UFUNCTION(BlueprintCallable, Category="AccountInventory")
	int32 GetNumAccountLimitedItems(UFortMcpProfileCampaign* McpProfile);

	UFUNCTION(BlueprintCallable, Category="AccountInventory")
	int32 GetNumWorldInventoryBonusTokens(UFortMcpProfileCampaign* McpProfile);

	UFUNCTION(BlueprintCallable, Category="Homebase", meta=(DisplayName="Get Squad By Id"))
	bool GetSquadCopyById(FName SquadId, FHomebaseSquad& OutSquad);

	UFUNCTION(BlueprintPure, Category="Homebase")
	void GetSquadPopulation(FName SquadId, const UFortMcpProfileCampaign* McpProfile, TArray<UFortWorker*>& OutSquadMembers) const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	UFortWorker* GetWorkerInSquadSlot(FName SquadId, int32 SlotIdx, const UFortMcpProfileCampaign* McpProfile) const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	bool IsSquadSlotUnlocked(FName SquadId, int32 SlotIdx, const UFortMcpProfileCampaign* McpProfile) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Nodes")
	TObjectPtr<UFortHomebaseNodeGameplayEffectDataTable> HomebaseNodeGameplayEffectDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Research")
	TObjectPtr<UCurveTable> ResearchSystemUpgradesTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats")
	TSubclassOf<UGameplayEffect> StatsGamplayEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Squads")
	TObjectPtr<UDataTable> HomebaseSquadDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Expeditions")
	TObjectPtr<UDataTable> ExpeditionSlotsDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Squads")
	TObjectPtr<UCurveTable> ManagerSquadSynergyBonusTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squads")
	TSubclassOf<UGameplayEffect> SquadGE;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Workers")
	TArray<FWorkerPersonalityData> WorkerPersonalities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Workers")
	TArray<FWorkerSetBonusData> WorkerSetBonuses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Workers")
	TArray<FManagerSynergyData> ManagerSynergies;

};

