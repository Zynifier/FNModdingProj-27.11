// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortStoreDisplayData.generated.h"

class UCommonActivatableWidget;
class UFortPlatformPurchaseErrorCodeModal;

UCLASS(MinimalAPI)
class UFortStoreDisplayData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="RealMoneyStore")
	TArray<FString> AthenaRMTStorefrontNames;

	UPROPERTY(EditDefaultsOnly, Category="RealMoneyStore")
	TArray<FString> CampaignRMTStorefrontNames;

	UPROPERTY(EditDefaultsOnly, Category="RealMoneyStore")
	FString RequiredTokenOfferMetaKey;

	UPROPERTY(EditDefaultsOnly, Category="RealMoneyStore")
	FString GiftableOfferStorefront;

private:
	UPROPERTY(EditAnywhere, Category="ScreenClasses", meta=(AssetBundles="MenuAthena,ZoneAthena"))
	TSoftClassPtr<UCommonActivatableWidget> StandaloneMTXStoreClass;

	UPROPERTY(EditAnywhere, Category="ScreenClasses")
	TSoftClassPtr<UFortPlatformPurchaseErrorCodeModal> PlatformPurchaseErrorCodeModalClass;

};

