// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "DataStores/FortDataStore_EliminationDependent.h"
#include "FortDataStore_HightowerMangoDataStore.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortOnVictimLoadoutUpdated, const TArray<FFortSwapItemAndVariantData>&, InLoadout);

UCLASS(BlueprintType)
class UFortDataStore_HightowerMangoDataStore : public UFortDataStore_EliminationDependent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearDataCache();

	UPROPERTY(BlueprintReadOnly, Category="FortDataStore_HightowerMangoDataStore")
	TArray<FFortSwapItemAndVariantData> LastVictimRelevantLoadout;

};

