// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Building/BuildingProp.h"
#include "BuildingProp_VendingMachine.generated.h"

class AFortPlayerPawn;

UENUM(BlueprintType)
enum class ECreativeVendingMachineState : uint8
{
	DisplayingItem = 0,
	AcceptingItem = 1,
	AcceptedItem = 2,
	RejectedItem = 3,
};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_VendingMachine : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Vending Machine")
	void OnCycleToNextItem();

	UFUNCTION(BlueprintImplementableEvent, Category="Vending Machine")
	void OnPlayerInventoryChange();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Interaction")
	void BlueprintServerNotifyEndLongUse(AFortPlayerPawn* InteractingPawn, bool bUseCompleted);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Interaction")
	void BlueprintServerNotifyStartLongUse(AFortPlayerPawn* InteractingPawn);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interact Methods")
	FGameplayTagContainer AllowedItemRotationDamageTags;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_VendingMachine")
	bool bOnlyListenForResourceChangesInPlayerInventory;

};

