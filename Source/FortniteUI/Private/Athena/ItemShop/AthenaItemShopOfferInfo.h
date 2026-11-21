// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Store/FortStoreFrontOfferInfo.h"
#include "AthenaItemShopOfferInfo.generated.h"

class UAthenaItemShopOfferDisplayData;

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class UAthenaItemShopOfferInfo : public UFortStoreFrontOfferInfo
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UAthenaItemShopOfferDisplayData> ItemShopDisplayAsset;

};

