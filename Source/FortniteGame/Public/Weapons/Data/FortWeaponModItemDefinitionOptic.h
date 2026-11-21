// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Data/FortWeaponModItemDefinition.h"
#include "FortWeaponModItemDefinitionOptic.generated.h"

class UFortWeaponOpticDefinition;

UCLASS(BlueprintType, Blueprintable)
class UFortWeaponModItemDefinitionOptic : public UFortWeaponModItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Optic")
	TObjectPtr<UFortWeaponOpticDefinition> OpticDefinition;

};

