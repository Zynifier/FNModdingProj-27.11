// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "FortRarityEnum.h"
#include "FortTypes.h"
#include "BuildingPhoenixRepairActor.generated.h"

class AFortPlayerController;
class UFortItemDefinition;
class UFortWorldItem;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCurrentWeaponChanged);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingPhoenixRepairActor : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanWeaponBeRepaired(UFortWorldItem* WeaponItem) const;

	UFUNCTION(BlueprintPure)
	UFortWorldItem* GetCurrentWeapon(AFortPlayerController* FPC) const;

	UFUNCTION(BlueprintPure)
	bool GetWeaponHasDurability(UFortWorldItem* WeaponItem) const;

	UFUNCTION(BlueprintPure)
	void GetWeaponRepairRecipe(AFortPlayerController* FPC, FRecipe& OutRecipe) const;

	UPROPERTY(EditDefaultsOnly, Category="Phoenix Repair")
	TArray<TObjectPtr<UFortItemDefinition>> ResourceWhitelist;

	UPROPERTY(BlueprintAssignable)
	FCurrentWeaponChanged OnCurrentWeaponChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact Methods|Instance Override")
	bool bCallOnLocalInteract;

	UPROPERTY(BlueprintReadOnly, Category="Interact Methods")
	uint8 bCurrentInteractionSuccess : 1;

	UPROPERTY(BlueprintReadOnly, Category="Interact Methods")
	EFortRarity RepairedWeaponRarity;

};

