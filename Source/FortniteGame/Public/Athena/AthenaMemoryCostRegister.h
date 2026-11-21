// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AthenaMemoryCostRegister.generated.h"

class UCustomCharacterPart;

USTRUCT()
struct FTotalResKBIncAssetCostPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString AssetName;

	UPROPERTY()
	uint32 CostKBInc;

};

UCLASS()
class UAthenaMemoryCostRegister : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Extra Additions")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> ExtraCharacterParts;

	UPROPERTY()
	TArray<FTotalResKBIncAssetCostPair> TotalResKBIncPerAsset;

};

