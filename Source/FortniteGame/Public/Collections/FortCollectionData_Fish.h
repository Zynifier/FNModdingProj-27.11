// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Collections/FortCollectionData.h"
#include "FortCollectionData_Fish.generated.h"

class UObject;

UCLASS(MinimalAPI, AutoExpandCategories=("Fish"))
class UFortCollectionDataEntryFish : public UFortCollectionDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Fish")
	FGameplayTag EntryTag;

	UPROPERTY(EditDefaultsOnly, Category="Fish")
	FText EntryName;

	UPROPERTY(EditDefaultsOnly, Category="Fish")
	FText EntryDescription;

	UPROPERTY(EditDefaultsOnly, Category="Fish")
	FText AdditionalEntryDescription;

	UPROPERTY(EditDefaultsOnly, Category="Fish", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> SmallIcon;

	UPROPERTY(EditDefaultsOnly, Category="Fish", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> LargeIcon;

	UPROPERTY(EditDefaultsOnly, Category="Fish")
	FScalableFloat Size;

	UPROPERTY(EditDefaultsOnly, Category="Fish")
	bool bNeedsProFishingRod;

};

UCLASS(MinimalAPI)
class UFortCollectionDataFishing : public UFortCollectionData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCollectionDataFishing", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float TwoStarRating;

	UPROPERTY(EditDefaultsOnly, Category="FortCollectionDataFishing", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float ThreeStarRating;

};

