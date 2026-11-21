// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "BlueprintContextBase.h"
#include "FortItemQuantityPair.h"
#include "FortMultiSize.h"
#include "STW/FortHomebase/FortHomebaseManager.h"
#include "FortHomebaseContext.generated.h"

class UFortCampaignHeroLoadoutItem;
class UFortCollectedResourceItem;
class UFortHero;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHomebaseInventoryUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHomebaseItemUpgradePointsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHomebaseMaximumItemLevelChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemSlottingPreviewInfoChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerInfoChanged, const FUniqueNetIdRepl&, UniqueId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSquadSlotMarkedAsSeen);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWorkerPreviewStateChanged);

USTRUCT(BlueprintType)
struct FHomebaseNodeState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Homebase Node")
	bool bIsOwned;

	UPROPERTY(BlueprintReadOnly, Category="Homebase Node")
	bool bAreCostsPayable;

	UPROPERTY(BlueprintReadOnly, Category="HomebaseNode")
	int32 Level;

};

USTRUCT(BlueprintType)
struct FWorkerSetBonusState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="WorkerSetBonusState")
	FGameplayTag SetBonusTag;

	UPROPERTY(BlueprintReadWrite, Category="WorkerSetBonusState")
	int32 CurrentMatchCount;

	UPROPERTY(BlueprintReadWrite, Category="WorkerSetBonusState")
	int32 RequiredMatchCountToActivate;

};

UCLASS(MinimalAPI)
class UHomeBaseContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Homebase Changed")
	void BroadcastSquadSlotMarkedAsSeen();

	UFUNCTION(BlueprintCallable, Category="Hero Loadout")
	void ClearHeroLoadout(UFortCampaignHeroLoadoutItem* HeroLoadout);

	UFUNCTION(BlueprintPure, Category="Homebase")
	bool DoesTeamMeetMaximumHomebaseRatingRequirement(int32 MaximumAllowedHomebaseRating, bool bUsePhoenixStats = false) const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	bool DoesTeamMeetRequiredHomebaseRating(int32 RequiredHomebaseRating, bool bUsePhoenixStats = false) const;

	UFUNCTION(BlueprintPure, Category="Homebase Squad")
	FName GetActiveDefenderSquadId() const;

	UFUNCTION(BlueprintPure, Category="Hero Loadout")
	UFortCampaignHeroLoadoutItem* GetActiveHeroLoadout() const;

	UFUNCTION(BlueprintCallable, Category="HomeBase")
	void GetAllResourceCollectorRewardEstimates(TArray<FFortItemQuantityPair>& OutEstimates);

	UFUNCTION(BlueprintPure, Category="Defenders")
	int32 GetCurrentDeployedDefenderCount() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	FName GetHomebaseDefenderSquadId() const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	bool GetLocalPlayerHomebaseRating(int32& Rating, float& ProgressFraction, bool bUsePhoenixStats = false) const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	bool GetLocalTeamHomebaseRating(int32& Rating, float& ProgressFraction, bool bUsePhoenixStats = false) const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	int32 GetMaxDeployableDefenderCount() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	FName GetMissionDefenderSquadId() const;

	UFUNCTION(BlueprintCallable, Category="AccountInventory")
	int32 GetNumAccountLimitedItems();

	UFUNCTION(BlueprintCallable, Category="HomeBase")
	void GetResourceCollectorRateInfo(UFortCollectedResourceItem* CollectorType, float& RatePerSecond, int32& MaxCapacity);

	UFUNCTION(BlueprintCallable, Category="HomeBase")
	void GetResourceCollectorRewardsEstimate(UFortCollectedResourceItem* CollectorType, FFortItemQuantityPair& OutEstimate);

	UFUNCTION(BlueprintCallable, Category="HomeBase")
	void GetResourceCollectorRewardsEstimates(const TArray<UFortCollectedResourceItem*>& CollectorTypes, TArray<FFortItemQuantityPair>& OutEstimates);

	UFUNCTION(BlueprintPure, Category="Worker")
	static void GetStaticSetBonusData(const FGameplayTag& InSetBonusTag, FWorkerSetBonusData& OutSetBonusData, FFortMultiSizeBrush& OutBrush);

	UFUNCTION(BlueprintPure, Category="Homebase")
	bool GetTeamHomebaseRating(const FUniqueNetIdRepl& PlayerId, int32& Rating, float& ProgressFraction, bool bUsePhoenixStats = false) const;

	UFUNCTION(BlueprintPure, Category="Homebase")
	bool GetTotalHomebaseRating(const FUniqueNetIdRepl& UniqueId, int32& Rating, float& ProgressFraction, bool bUsePhoenixStats = false) const;

	UFUNCTION(BlueprintPure, Category="SkillPoints")
	int32 GetTotalSkillPointsEarned() const;

	UFUNCTION(BlueprintPure, Category="Hero Loadout")
	bool HasHeroUnlockedCommanderPerk(UFortHero* Hero) const;

	UFUNCTION(BlueprintCallable, Category="Hero Loadout")
	void SetActiveHeroLoadout(UFortCampaignHeroLoadoutItem* HeroLoadout);

	UFUNCTION(BlueprintPure, Category="Homebase Squad")
	bool TryGetHomebaseSquadData(const FName SquadId, FHomebaseSquad& OutHomebaseSquad) const;

	UPROPERTY(BlueprintAssignable, Category="Worker")
	FWorkerPreviewStateChanged OnWorkerPreviewStateChanged;

	UPROPERTY(BlueprintAssignable, Category="Homebase Changed")
	FHomebaseInventoryUpdated OnHomebaseInventoryUpdated;

	UPROPERTY(BlueprintAssignable, Category="Homebase Changed")
	FHomebaseMaximumItemLevelChanged OnMaximumItemLevelChanged;

	UPROPERTY(BlueprintAssignable, Category="Homebase Changed")
	FHomebaseItemUpgradePointsChanged OnItemUpgradePointsChanged;

	UPROPERTY(BlueprintAssignable, Category="Homebase Changed")
	FSquadSlotMarkedAsSeen SquadSlotMarkedAsSeen;

	UPROPERTY(BlueprintAssignable, Category="Homebase Changed")
	FPlayerInfoChanged OnPlayerInfoChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Item Slotting Preview")
	FItemSlottingPreviewInfoChanged OnItemSlottingPreviewInfoChangedEvent;

};

