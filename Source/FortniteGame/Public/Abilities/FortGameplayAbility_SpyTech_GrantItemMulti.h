// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/TimerHandle.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility_SpyTech_GrantItem.h"
#include "FortGameplayAbility_SpyTech_GrantItemMulti.generated.h"

class UDataTable;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FGrantItemMultiData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GrantItemMultiData")
	TSoftObjectPtr<UFortItemDefinition> ItemToGrant;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GrantItemMultiData")
	FScalableFloat NumberOfItemsToGrant;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GrantItemMultiData")
	bool bRemoveExistingBeforeGrant;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GrantItemMultiData")
	bool bRequiresPreviousInstance;

};

UCLASS(HideCategories=("SpyTech"))
class UFortGameplayAbility_SpyTech_GrantItemMulti : public UFortGameplayAbility_SpyTech_GrantItem
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void GrantItems();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grant Item Multi")
	TSoftObjectPtr<UDataTable> GrantableItemListTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grant Item Multi")
	FScalableFloat ActivationUpdateTime;

	UPROPERTY()
	FTimerHandle ActivationUpdateTimeHandle;

};

