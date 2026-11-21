// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortWorldItem.h"
#include "FortPlaysetWorldItem.generated.h"

class UFortItemDefinition;

UCLASS()
class UFortPlaysetWorldItem : public UFortWorldItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Playset")
	TObjectPtr<UFortItemDefinition> PlaysetToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	bool bUseVolumeToSpawn;

};

