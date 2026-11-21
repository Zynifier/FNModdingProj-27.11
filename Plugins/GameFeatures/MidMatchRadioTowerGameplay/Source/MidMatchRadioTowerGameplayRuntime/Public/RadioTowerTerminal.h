// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "RadioTowerTerminal.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ARadioTowerTerminal : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="RadioTowerTerminal")
	float MaxInteractHalfAngle;

};

