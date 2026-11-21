// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaRewardSchedule.h"
#include "CatalogTypes.h"
#include "Items/AthenaSeasonItemData.h"
#include "AthenaSeasonItemData_BattlePass.generated.h"

USTRUCT()
struct FBattlePassLevelReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BattlePassLevelReward")
	FString OfferId;

	UPROPERTY(EditAnywhere, Category="BattlePassLevelReward")
	bool bHideFromGiftBox;

	UPROPERTY(EditAnywhere, Category="BattlePassLevelReward")
	int32 GrantedOnLevel;

	UPROPERTY(EditAnywhere, Category="BattlePassLevelReward")
	FAthenaRewardItemReference Reward;

};

USTRUCT()
struct FBattlePassOfferData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString OfferId;

	UPROPERTY()
	TArray<FItemQuantity> RewardItemQuantity;

	UPROPERTY()
	bool bIsFreePassReward;

	UPROPERTY()
	int32 Cost;

	UPROPERTY()
	FString CurrencyId;

	UPROPERTY()
	int32 SectionOffersNeededForUnlock;

	UPROPERTY()
	int32 CategoryOffersNeededForUnlock;

	UPROPERTY()
	TArray<FString> RequiredItemsForUnlock;

	UPROPERTY()
	int32 DaysAfterSeasonStartUnlockTime;

	UPROPERTY()
	int32 LevelsNeededForUnlock;

};

USTRUCT()
struct FBattlePassOfferSectionData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 CategoryIndex;

	UPROPERTY()
	int32 SectionIndex;

	UPROPERTY()
	int32 SectionRewardCount;

	UPROPERTY()
	int32 CategoryRewardCount;

	UPROPERTY()
	int32 NumLevelsNeededForSectionUnlock;

	UPROPERTY()
	int32 NumCategoryRewardsNeededForSectionUnlock;

	UPROPERTY()
	TArray<FBattlePassOfferData> SectionOfferList;

};

UCLASS(Abstract, MinimalAPI)
class UAthenaSeasonItemData_BattlePass : public UAthenaSeasonItemData
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(meta=(CallInEditor="true"))
	virtual void GenerateNewOfferIds();
#endif

protected:
	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonItemData_BattlePass")
	TArray<FBattlePassLevelReward> RewardsGrantedForPremiumBattlePassLevels;

};

