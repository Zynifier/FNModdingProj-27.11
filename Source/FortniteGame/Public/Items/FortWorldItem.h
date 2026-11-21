// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortAbilitySystemComponentAbilityGivenListenerInterface.h"
#include "FortDamageSourceInterface.h"
#include "Items/FortItem.h"
#include "Items/FortItemEntry.h"
#include "FortWorldItem.generated.h"

class AFortInventory;

UCLASS(MinimalAPI)
class UFortWorldItem : public UFortItem, public IFortDamageSourceInterface, public IGameplayTagAssetInterface, public IFortAbilitySystemComponentAbilityGivenListenerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item")
	FFortItemEntry CreateItemEntryForDrop() const;

	UFUNCTION(BlueprintPure, Category="Item")
	int32 GetFuelChargeValue() const;

	UFUNCTION(BlueprintPure, Category="Item")
	float GetMaxDurability() const;

	UFUNCTION(BlueprintPure, Category="GameplayTags")
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	UFUNCTION(BlueprintCallable, Category="Item")
	void MarkItemAsSeenInFrontend();

	UFUNCTION(BlueprintPure, Category="Item")
	bool SeenInFrontend() const;

protected:
	UPROPERTY()
	bool bIsTemporaryItem;

	UPROPERTY()
	bool bNeedsPersistentUpdate;

	UPROPERTY()
	bool bPendingPersistentDelete;

	UPROPERTY()
	TWeakObjectPtr<AFortInventory> OwnerInventoryWeak;

	UPROPERTY()
	FFortItemEntry ItemEntry;

private:
	UPROPERTY()
	float BaseRegenCooldown;

};

