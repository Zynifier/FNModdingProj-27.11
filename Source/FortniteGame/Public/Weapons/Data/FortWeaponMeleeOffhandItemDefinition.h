// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Data/FortWeaponMeleeItemDefinition.h"
#include "FortWeaponMeleeOffhandItemDefinition.generated.h"

class UFortGameplayAbility;

UCLASS(MinimalAPI, BlueprintType)
class UFortWeaponMeleeOffhandItemDefinition : public UFortWeaponMeleeItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	TSubclassOf<UFortGameplayAbility> GetPrimaryOffhandFireAbility() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	TSubclassOf<UFortGameplayAbility> GetSecondaryOffhandFireAbility() const;

protected:
	UPROPERTY(EditAnywhere, Category="Abilities", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload,ItemDetails"))
	TSoftClassPtr<UFortGameplayAbility> PrimaryOffhandFireAbility;

	UPROPERTY(EditAnywhere, Category="Abilities", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftClassPtr<UFortGameplayAbility> SecondaryOffhandFireAbility;

};

