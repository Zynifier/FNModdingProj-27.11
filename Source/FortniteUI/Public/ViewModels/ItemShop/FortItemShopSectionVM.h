// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortGameUserSettings.h"
#include "MultiProductItemShop/FortItemShopCMSData.h"
#include "FortItemShopSectionVM.generated.h"

class UFortItemShopOfferGroupVM;
class UFortItemShopSectionVM;

UCLASS()
class UFortItemShopSectionVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasOffers() const;

private:
	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	FString SectionId;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	FText DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	FString OwningSectionId;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemShopSectionVM>> Subsections;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemShopOfferGroupVM>> OfferGroups;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	FFortItemShopCMSBackground Background;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	int32 CurrentStackRank;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	EFortOfferSeenLevel SeenLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopSectionVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemShopOfferGroupVM>> AllOfferGroupsWithOffers;

};

