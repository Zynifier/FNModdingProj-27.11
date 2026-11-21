// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "BattleLabDeviceGameplayActor.generated.h"

class UFortBattleLabDeviceItemDefinition;

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABattleLabDeviceGameplayActor : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_BattleLabDeviceItemData();

	UPROPERTY(ReplicatedUsing=OnRep_BattleLabDeviceItemData)
	TObjectPtr<UFortBattleLabDeviceItemDefinition> BattleLabDeviceItemData;

};

