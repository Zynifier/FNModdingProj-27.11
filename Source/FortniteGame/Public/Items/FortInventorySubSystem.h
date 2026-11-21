// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortInventorySubSystem.generated.h"

class AFortPlayerController;
class IFortInventoryOwnerInterface;
class UFortItem;
class UFortWorldItem;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemAddedDelegate, UFortItem*, Item, TScriptInterface<IFortInventoryOwnerInterface>, InventoryOwner);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemRemovedDelegate, UFortItem*, Item, TScriptInterface<IFortInventoryOwnerInterface>, InventoryOwner);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnViewTargetInventoryUpdatedDelegate);

UCLASS(MinimalAPI)
class UFortInventorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Activatable From Input")
	FGameplayTag GetActionTagForItem(const UFortItem* Item) const;

	UFUNCTION(BlueprintPure, Category="Activatable From Input")
	UFortWorldItem* GetItemForActionTag(const AFortPlayerController* OwningPlayerController, const FGameplayTag ActionTag) const;

	UFUNCTION(BlueprintPure, Category="Activatable From Input")
	UFortWorldItem* GetViewTargetItemForActionTag(const AFortPlayerController* OwningPlayerController, const FGameplayTag ActionTag) const;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Item Added"))
	FOnItemAddedDelegate OnItemAddedDelegate;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Item Removed"))
	FOnItemRemovedDelegate OnItemRemovedDelegate;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On View Target Inventory Updated"))
	FOnViewTargetInventoryUpdatedDelegate OnViewTargetInventoryUpdatedDelegate;

};

