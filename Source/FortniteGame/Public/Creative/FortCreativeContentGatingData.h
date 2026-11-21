// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortTypes.h"
#include "FortCreativeContentGatingData.generated.h"

class UFortCreativeTagFilter;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortCreativeContentGatingData : public UDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="FortCreativeContentGatingData", meta=(Patchable))
	TObjectPtr<UFortCreativeTagFilter> CabinFilter;

	UPROPERTY(EditAnywhere, Instanced, Category="FortCreativeContentGatingData", meta=(Patchable))
	TMap<EFortContentRating, TObjectPtr<UFortCreativeTagFilter>> RatingToFilterMap;

};

