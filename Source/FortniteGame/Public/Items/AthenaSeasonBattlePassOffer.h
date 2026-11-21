// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/PrimaryAssetId.h"
#include "UObject/SoftObjectPath.h"
#include "Athena/AthenaRewardSchedule.h"
#include "AthenaSeasonBattlePassOffer.generated.h"

USTRUCT(BlueprintType)
struct FAthenaBattlePassOffer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="AthenaBattlePassOffer", meta=(IgnoreForMemberInitializationTest))
	FString OfferId;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassOffer")
	FAthenaRewardItemReference RewardItem;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassOffer")
	TArray<FAthenaRewardItemReference> ChainedRewardItemList;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassOffer", meta=(RowType="/Script/FortniteGame.AthenaBattlePassOfferPriceRow"))
	FDataTableRowHandle OfferPriceRowHandle;

};

USTRUCT(BlueprintType)
struct FAthenaBattlePassOfferPriceRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaBattlePassOfferPriceRow")
	int32 Cost;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassOfferPriceRow")
	FPrimaryAssetId CurrencyItemTemplate;

	UPROPERTY(EditAnywhere, Category="AthenaBattlePassOfferPriceRow")
	FSoftObjectPath CurrencyItem_IconPath;

};

