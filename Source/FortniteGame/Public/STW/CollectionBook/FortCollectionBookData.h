// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortItemQuantityPair.h"
#include "FortCollectionBookData.generated.h"

class UCurveFloat;
class UDataTable;

UCLASS(MinimalAPI, BlueprintType)
class UFortCollectionBookData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CollectionBook")
	void GetPageIdsFromCategoryId(FName CategoryId, TArray<FName>& PageIds) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="CollectionPageData")
	TObjectPtr<UDataTable> PageCategoryData;

	UPROPERTY(EditDefaultsOnly, Category="CollectionPageData")
	TObjectPtr<UDataTable> PageData;

	UPROPERTY(EditDefaultsOnly, Category="CollectionSectionData")
	TObjectPtr<UDataTable> SectionData;

	UPROPERTY(EditDefaultsOnly, Category="CollectionSlotData")
	TObjectPtr<UDataTable> SlotData;

	UPROPERTY(EditDefaultsOnly, Category="CollectionSlotData")
	TObjectPtr<UDataTable> SlotSourceData;

	UPROPERTY(EditDefaultsOnly, Category="CollectionSlotData")
	TObjectPtr<UDataTable> XPWeightData;

	UPROPERTY(EditDefaultsOnly, Category="CollectionSlotData")
	TObjectPtr<UCurveFloat> SlotRarityFactorData;

	UPROPERTY(EditDefaultsOnly, Category="CollectionBookData")
	TObjectPtr<UDataTable> BookXPData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CollectionBookData")
	TArray<FFortItemQuantityPair> UnslotCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CollectionBookData")
	FGameplayTagContainer UnslotCatalysts;

};

