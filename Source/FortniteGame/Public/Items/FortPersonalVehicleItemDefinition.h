// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortPersonalVehicleItemDefinition.generated.h"

class UAnimInstance;
class UFortGameplayAbility;
class USkeletalMesh;
class USoundBase;

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UFortPersonalVehicleItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Ability", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UFortGameplayAbility> PersonalVehicleAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	float MountTime;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditDefaultsOnly, Category="Visual")
	TSubclassOf<UAnimInstance> AnimClass;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> ActivateSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> DeactivateSound;

};

