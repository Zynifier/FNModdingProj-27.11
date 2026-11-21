// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortCollectionBookSlotData.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FFortCollectionBookSlotData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCollectionBookSlotData")
	FName SlotXpWeightName;

	UPROPERTY(EditAnywhere, Category="FortCollectionBookSlotData")
	FName SlotSourceId;

	UPROPERTY(EditAnywhere, Category="FortCollectionBookSlotData")
	FName SlotSourceId2;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookSlotData")
	FString AllowedItemsString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookSlotData")
	FString AllowedPersonalitiesString;
#endif

	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookSlotData", meta=(DataTableImportOptional))
	TArray<TSoftObjectPtr<UFortItemDefinition>> AllowedItems;

	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookSlotData", meta=(DataTableImportOptional))
	TArray<FGameplayTag> AllowedWorkerPersonalities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookSlotData", meta=(DataTableImportOptional))
	FDataTableRowHandle PurchaseCosts;

};

