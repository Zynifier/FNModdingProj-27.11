// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortPawnComponent.h"
#include "FortTaggedNavFiltersComponent.generated.h"

class UNavigationQueryFilter;

USTRUCT()
struct FFortAITaggedNavFilterOverrideEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAITaggedNavFilterOverrideEntry")
	FGameplayTagQuery OwnerRequiredTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAITaggedNavFilterOverrideEntry", meta=(Categories="NavFilter"))
	TMap<FGameplayTag, TSubclassOf<UNavigationQueryFilter>> NavFilters;

};

USTRUCT()
struct FFortAITaggedNavFilterData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAITaggedNavFilterData")
	TArray<FFortAITaggedNavFilterOverrideEntry> OverrideTaggedNavFilters;

	UPROPERTY(EditDefaultsOnly, Category="FortAITaggedNavFilterData", meta=(Categories="NavFilter"))
	TMap<FGameplayTag, TSubclassOf<UNavigationQueryFilter>> DefaultTaggedNavFilters;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortTaggedNavFiltersComponent : public UFortPawnComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortTaggedNavFiltersComponent")
	FFortAITaggedNavFilterData TaggedNavFilterData;

};

