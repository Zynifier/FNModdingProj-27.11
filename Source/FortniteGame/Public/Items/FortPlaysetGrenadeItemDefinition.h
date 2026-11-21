// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelSaveRecordProvider.h"
#include "Weapons/Data/FortWeaponRangedItemDefinition.h"
#include "FortPlaysetGrenadeItemDefinition.generated.h"

class UFortPlaysetItemDefinition;

UCLASS(MinimalAPI, BlueprintType)
class UFortPlaysetGrenadeItemDefinition : public UFortWeaponRangedItemDefinition, public ILevelSaveRecordProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortPlaysetItemDefinition* GetPlaysetToSpawn(bool bForceLoad = false) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Playset")
	TSoftObjectPtr<UFortPlaysetItemDefinition> PlaysetToSpawn;

};

