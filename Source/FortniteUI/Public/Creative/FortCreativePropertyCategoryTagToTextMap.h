// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortCreativePropertyCategoryTagToTextMap.generated.h"

UCLASS(BlueprintType)
class UFortCreativePropertyCategoryTagToTextMap : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FText GetDisplayName(const FGameplayTag& CategoryTag) const;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyCategoryTagToTextMap", meta=(Categories="Creative.Property.Category"))
	TMap<FGameplayTag, FText> CategoryTagToTextMap;

};

