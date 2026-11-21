// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortBattleLabDeviceItemDefinition.generated.h"

class ABattleLabDeviceGameplayActor;

UCLASS(MinimalAPI)
class UFortBattleLabDeviceItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Battle Lab", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<ABattleLabDeviceGameplayActor> BattleLabDeviceActorClass;

};

