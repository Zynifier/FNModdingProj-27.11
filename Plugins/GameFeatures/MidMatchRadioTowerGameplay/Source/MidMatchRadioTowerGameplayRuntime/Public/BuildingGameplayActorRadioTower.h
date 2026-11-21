// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorRadioTower.generated.h"

class ARadioTowerTerminal;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorRadioTower : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Marking")
	ARadioTowerTerminal* GetLinkedRadioTowerTerminal() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Marking")
	FScalableFloat MarkLinkedRadioTowerTerminal;

};

