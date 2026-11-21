// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortMontageLookupTable.generated.h"

class UAnimMontage;

USTRUCT()
struct FMontageLookupData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="MontageLookupData")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, Category="MontageLookupData")
	TSoftObjectPtr<UAnimMontage> AnimMontage;

};

UCLASS(BlueprintType)
class UFortMontageLookupTable : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Montage Lookup Data")
	TArray<FMontageLookupData> MontageLookupDataArray;

};

