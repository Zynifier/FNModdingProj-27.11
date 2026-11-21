// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortNpcItemDefinition.generated.h"

class UFortChallengeBundleItemDefinition;

UCLASS(BlueprintType, HideCategories=("FrontendPreview", "Functionality", "InventoryLimit", "OwnedTags", "Tooltips", "Rating", "Series"))
class UFortNpcItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	TArray<TSoftObjectPtr<UFortChallengeBundleItemDefinition>> GetChallengeBundles();

protected:
	UPROPERTY(EditAnywhere, Category="NpcData")
	TArray<TSoftObjectPtr<UFortChallengeBundleItemDefinition>> ChallengeBundles;

};

