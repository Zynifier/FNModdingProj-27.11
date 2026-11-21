// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "Misc/Guid.h"
#include "ScalableFloat.h"
#include "FortTieredCollectionLayout.generated.h"

class UFortBadgeItemDefinition;
class UFortQuestItemDefinition;
class UFortQuestManager;
class UFortTieredCollectionLayout;

UENUM()
enum class ECollectionSelectionMethod : uint8
{
	/** Use the specified tier as an array index into the collection; Will fail and select nothing if out of bounds */
	TierAsIndex = 0,
	/** Use the specified tier as an array index into the collection; Will stop at the last valid index if tier is over the maximum; Will fail if array is empty */
	TierAsIndexOverflowToLastValid = 1,
	/** Determine the selection via tier number modulo array size */
	Modulo = 2,
	/** Determine the selection randomly */
	Random = 3,
	/** Don't select anything at all; Implies the collection is unnecessary */
	None = 4,
};

USTRUCT(BlueprintType)
struct FFortTierCollectionLayoutOutput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Enemies")
	FName SpawnCollectionName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Difficulty")
	FName DifficultyRowName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Modifiers")
	FName ModifierProgressionName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Difficulty")
	float AdditiveDifficultyMod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Difficulty")
	TArray<TObjectPtr<UFortBadgeItemDefinition>> RewardBadges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Difficulty")
	TArray<FName> StartTierLootTierGroups;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Difficulty")
	TArray<FName> WaveCompleteLootTierGroups;

};

USTRUCT(BlueprintType)
struct FAvailableTierLayout
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Tiers")
	TObjectPtr<UFortTieredCollectionLayout> Layout;

	UPROPERTY(BlueprintReadWrite, Category="Tiers")
	TArray<FFortTierCollectionLayoutOutput> AvailableTiers;

	UPROPERTY(BlueprintReadWrite, Category="Tiers")
	TArray<FFortTierCollectionLayoutOutput> LockedTiers;

	UPROPERTY(BlueprintReadWrite, Category="Tiers")
	uint8 bLocked : 1;

};

USTRUCT()
struct FTieredCollectionProgressionDataBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TieredCollection")
	ECollectionSelectionMethod SelectionMethod;

};

USTRUCT()
struct FCollectionLootSetData : public FTieredCollectionProgressionDataBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TieredCollection")
	TArray<FName> LootSetNames;

};

USTRUCT()
struct FDifficultyRowProgression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Difficulty")
	FName DifficultyRowName;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty")
	FScalableFloat AdditiveDifficultyMod;

};

USTRUCT()
struct FDifficultyCollectionProgressionData : public FTieredCollectionProgressionDataBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TieredCollection")
	TArray<FDifficultyRowProgression> DifficultyCollections;

};

USTRUCT()
struct FRewardBadgesProgression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Difficulty")
	TArray<TObjectPtr<UFortBadgeItemDefinition>> RewardBadges;

};

USTRUCT()
struct FRewardBadgesCollectionProgressionData : public FTieredCollectionProgressionDataBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TieredCollection")
	TArray<FRewardBadgesProgression> BadgeCollections;

};

USTRUCT()
struct FTieredNamedCollectionProgressionData : public FTieredCollectionProgressionDataBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TieredCollection")
	TArray<FName> CollectionNames;

};

UCLASS(BlueprintType)
class UFortTieredCollectionLayout : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, Category="TieredCollectionLayout")
	bool GetAllValidTiers(TArray<FFortTierCollectionLayoutOutput>& OutTiers, TArray<FFortTierCollectionLayoutOutput>& OutLockedTiers, const TArray<UFortQuestManager*>& QuestManagers) const;

	UFUNCTION(BlueprintPure, Category="TieredCollectionLayout")
	FText GetCollectionLayoutDisplayName() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, Category="TieredCollectionLayout")
	int32 GetMaxTierUnlocked(const TArray<UFortQuestManager*>& QuestManagers) const;

	UFUNCTION(BlueprintPure, Category="TieredCollectionLayout")
	int32 GetMissionPointsForTier(int32 Tier) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TieredCollectionLayout")
	bool GetTierOutput(int32 Tier, UPARAM(ref) FFortTierCollectionLayoutOutput& Output) const;

	UFUNCTION(BlueprintPure)
	bool ShouldUseTierAsRandomSeed() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TieredCollectionLayout")
	void UpdatePlayerTierCompletions(int32 CompletedTier, const TArray<UFortQuestManager*>& QuestManagers) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Tier")
	uint8 bUseTierAsRandomSeed : 1;

	UPROPERTY(EditDefaultsOnly, Category="Tier")
	uint8 bFiniteTiers : 1;

	UPROPERTY(EditDefaultsOnly, Category="Tier", meta=(EditCondition="bFiniteTiers"))
	int32 MaxNumberOfTiersAllowed;

	UPROPERTY(EditDefaultsOnly, Category="Tier")
	int32 InitialTierUnlocked;

	UPROPERTY(EditDefaultsOnly, Category="Progressions")
	FTieredNamedCollectionProgressionData SpawnWaveProgressions;

	UPROPERTY(EditDefaultsOnly, Category="Progressions")
	FDifficultyCollectionProgressionData DifficultyProgressions;

	UPROPERTY(EditDefaultsOnly, Category="Progressions")
	FTieredNamedCollectionProgressionData ModifierProgressions;

	UPROPERTY(EditDefaultsOnly, Category="Progressions")
	FRewardBadgesCollectionProgressionData RewardBadgesProgression;

	UPROPERTY(EditDefaultsOnly, Category="Progressions")
	FCollectionLootSetData LootSetProgression;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	FText CollectionLayoutDisplayName;

	UPROPERTY(EditDefaultsOnly, Category="Prerequisites")
	TSoftObjectPtr<UFortTieredCollectionLayout> PrerequisiteLayout;

	UPROPERTY(EditDefaultsOnly, Category="Missions")
	FCurveTableRowHandle TierToMissionPointLookupTable;

	UPROPERTY(VisibleAnywhere, DuplicateTransient, Category="GUID")
	FGuid LayoutGUID;

	UPROPERTY(EditDefaultsOnly, Category="Tier")
	TObjectPtr<UFortQuestItemDefinition> Quest;

	UPROPERTY(EditDefaultsOnly, Category="Tier")
	FName ObjectiveBackendName;

	UPROPERTY(EditDefaultsOnly, Category="Tier")
	FDataTableRowHandle ObjectiveStatHandle;

};

