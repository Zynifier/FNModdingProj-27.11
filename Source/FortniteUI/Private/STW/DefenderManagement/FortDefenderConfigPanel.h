// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortDefenderConfigPanel.generated.h"

class ABuildingTrapDefender;
class AFortAIPawn;
class UFortItem;
class UFortSchematicItemDefinition;
class UFortWorldItem;
class UFortWorldItemDefinition;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortDefenderConfigPanel : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Defenders")
	int32 GetAmmoCountFromDefender(const UFortWorldItemDefinition* AmmoItemDef) const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	int32 GetAmmoCountFromPlayer(const UFortWorldItemDefinition* AmmoItemDef) const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	UFortWorldItem* GetCompatibleAmmo() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	UFortWorldItemDefinition* GetCompatibleAmmoDef() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	UFortWorldItem* GetDefenderPawnWeaponItem(const AFortAIPawn* DefenderPawn) const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	AFortAIPawn* GetSelectedDefenderPawn() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	UFortSchematicItemDefinition* GetSourceSchematic(const UFortWorldItemDefinition* ItemDefUsedForCrafting) const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	bool HasAnyDefenders() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	bool HasWeaponForSelectedDefender() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	bool IsWeaponSelectionValid() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	bool SpawnDefender() const;

	UFUNCTION(BlueprintPure, Category="Defenders")
	bool UnsummonDefender() const;

protected:
	UPROPERTY(BlueprintReadWrite, Category="Defenders")
	TWeakObjectPtr<UFortItem> SelectedDefenderItem;

	UPROPERTY(BlueprintReadWrite, Category="Defenders")
	TWeakObjectPtr<UFortItem> SelectedWeaponItem;

	UPROPERTY(BlueprintReadWrite, Category="Defenders")
	TWeakObjectPtr<UFortItem> SelectedAmmoItem;

	UPROPERTY(BlueprintReadWrite, Category="Defenders")
	int32 SelectedAmmoQuantity;

	UPROPERTY(BlueprintReadWrite, Category="Defenders")
	TWeakObjectPtr<ABuildingTrapDefender> DefenderTrap;

};

