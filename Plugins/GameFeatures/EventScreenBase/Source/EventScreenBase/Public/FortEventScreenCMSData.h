// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEventScreenCMSData.generated.h"

USTRUCT()
struct FEventScreenCMSResourceGroupOverride
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ResourceValue;

	UPROPERTY()
	FString KeyArtOverrideURL;

};

USTRUCT()
struct FEventScreenMoreInfoGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText Header;

	UPROPERTY()
	FText Body;

	UPROPERTY()
	FString IconURL;

};

USTRUCT()
struct FEventScreenCMSData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString EventCMSId;

	UPROPERTY()
	FText EventName;

	UPROPERTY()
	FText EventDescription;

	UPROPERTY()
	FText ResourceHeader;

	UPROPERTY()
	FText StarterHeader;

	UPROPERTY()
	FText CompletionHeader;

	UPROPERTY()
	FText EventCTA;

	UPROPERTY()
	FText EventCTACompleted;

	UPROPERTY()
	FText HeaderCTA;

	UPROPERTY()
	FText ItemShopCallout;

	UPROPERTY()
	FString CTAIconURL;

	UPROPERTY()
	FString KeyArtURL;

	UPROPERTY()
	FText MoreInfoHeader;

	UPROPERTY()
	FText MoreInfoSubHeader;

	UPROPERTY()
	FText MoreInfoLegal;

	UPROPERTY()
	TArray<FEventScreenMoreInfoGroup> MoreInfoGroups;

	UPROPERTY()
	FText PurchaseLegal;

	UPROPERTY()
	FText RewardTrackLegal;

	UPROPERTY()
	FString ItemShopOfferId;

	UPROPERTY()
	FText PremiumUpsellUnownedHeader;

	UPROPERTY()
	FText PremiumUpsellUnownedBody;

	UPROPERTY()
	FText PremiumUpsellOwnedHeader;

	UPROPERTY()
	FText PremiumUpsellOwnedBody;

	UPROPERTY()
	FString PremiumUpsellIconURL;

	UPROPERTY()
	FText PurchasePremiumTrackHeader;

	UPROPERTY()
	TArray<FText> PurchasePremiumTrackBodyList;

	UPROPERTY()
	FText InspectSpecialItemUnowned;

	UPROPERTY()
	FText InspectSpecialItemOwned;

	UPROPERTY()
	FText InspectSpecialPremiumItemUnowned;

	UPROPERTY()
	FText InspectSpecialPremiumItemOwned;

	UPROPERTY()
	TArray<FEventScreenCMSResourceGroupOverride> ResourceGroupOverrides;

};

USTRUCT()
struct FEventScreenCMSGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FEventScreenCMSData> EventScreens;

};

