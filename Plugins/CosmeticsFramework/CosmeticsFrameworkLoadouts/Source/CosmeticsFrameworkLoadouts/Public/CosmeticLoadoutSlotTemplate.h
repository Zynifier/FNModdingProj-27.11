// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "CosmeticLoadoutSlotRequirements.h"
#include "CosmeticLoadoutSlotTemplate.generated.h"

UCLASS(MinimalAPI, NotBlueprintable)
class UCosmeticLoadoutSlotTemplate : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FPrimaryAssetId GetDefaultCosmeticItemId() const;

	UFUNCTION(BlueprintPure)
	const FGameplayTagContainer& GetMetaTags() const;

	UFUNCTION(BlueprintPure)
	const FCosmeticLoadoutSlotRequirements& GetRequirements() const;

	UFUNCTION(BlueprintPure)
	FGameplayTag GetSlotTag() const;

private:
	UPROPERTY(EditAnywhere, Category="CosmeticLoadoutSlotTemplate")
	FGameplayTag SlotTag;

	UPROPERTY(EditAnywhere, Category="CosmeticLoadoutSlotTemplate")
	FGameplayTagContainer MetaTags;

	UPROPERTY(EditAnywhere, Category="CosmeticLoadoutSlotTemplate")
	FCosmeticLoadoutSlotRequirements Requirements;

	UPROPERTY(EditAnywhere, Category="CosmeticLoadoutSlotTemplate")
	FPrimaryAssetId DefaultCosmeticItemId;

};

