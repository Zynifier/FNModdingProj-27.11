// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/PrimaryAssetId.h"
#include "Items/FortItemTypeEnum.h"
#include "FortCustomSpawnCollectionManager.generated.h"

UCLASS(Config=Creative, MinimalAPI)
class UFortCustomSpawnCollectionManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Asset Manager")
	TArray<FPrimaryAssetId> PrimaryAssetIds;

	UPROPERTY(EditAnywhere, Config, Category="Asset Manager")
	TMap<EFortItemType, int32> SpawnAmountMap;

};

