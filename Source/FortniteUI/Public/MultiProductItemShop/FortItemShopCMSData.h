// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Misc/DateTime.h"
#include "FortItemShopCMSData.generated.h"

UENUM(BlueprintType)
enum class EFortItemShopContentType : uint8
{
	BattleRoyale = 0,
	TestContentType = 1,
	MAX = 2,
};

UENUM()
enum class EFortItemShopShowIneligibleOffers : uint8
{
	Always = 0,
	OnlyGiftable = 1,
	Never = 2,
};

USTRUCT(BlueprintType)
struct FFortItemShopCMSBackground
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortItemShopCMSBackground")
	FString CustomTexture;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopCMSBackground")
	FString CookedAssetKey;

};

USTRUCT()
struct FFortItemShopCMSStackRank
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime StartDate;

	UPROPERTY()
	int32 StackRankValue;

	UPROPERTY()
	EFortItemShopContentType ContentType;

};

USTRUCT()
struct FFortItemShopCMSOfferGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString OfferGroupId;

	UPROPERTY()
	TArray<FFortItemShopCMSStackRank> StackRanks;

};

USTRUCT()
struct FFortItemShopCMSSectionMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ShowIneligibleOffers;

	UPROPERTY()
	TArray<FJsonObjectWrapper> Subsections;

	UPROPERTY()
	TArray<FFortItemShopCMSOfferGroup> OfferGroups;

	UPROPERTY()
	FFortItemShopCMSBackground Background;

	UPROPERTY()
	TArray<FFortItemShopCMSStackRank> StackRanks;

};

USTRUCT()
struct FFortItemShopCMSSection
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SectionId;

	UPROPERTY()
	FString DisplayName;

	UPROPERTY()
	FFortItemShopCMSSectionMetadata Metadata;

};

USTRUCT()
struct FFortItemShopCMSData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortItemShopCMSSection> Sections;

};

