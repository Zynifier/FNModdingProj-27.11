// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortGameUserSettings.h"
#include "ViewModels/ItemShop/FortItemShopVM.h"
#include "FortItemShopOfferGroupVM.generated.h"

class UFortItemShopOfferVM;

UCLASS()
class UFortItemShopOfferGroupVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasOffers() const;

	UFUNCTION(BlueprintCallable)
	void SendAnalyticsData();

protected:
	UFUNCTION(BlueprintPure)
	FString GetConcatenatedLayout() const;

private:
	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferGroupVM", meta=(AllowPrivateAccess))
	FString OfferGroupId;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferGroupVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemShopOfferVM>> Offers;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferGroupVM", meta=(AllowPrivateAccess))
	FFortItemShopLayout OwningLayout;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopOfferGroupVM", meta=(AllowPrivateAccess))
	int32 CurrentStackRank;

	UPROPERTY(BlueprintReadWrite, Category="FortItemShopOfferGroupVM", meta=(AllowPrivateAccess))
	EFortOfferSeenLevel SeenLevel;

};

