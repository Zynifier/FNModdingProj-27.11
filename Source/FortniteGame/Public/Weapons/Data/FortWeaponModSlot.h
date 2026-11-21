// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWeaponModSlot.generated.h"

class UFortWeaponModItemDefinition;

USTRUCT()
struct FFortSavedWeaponModSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(SaveGame)
	FString WeaponModTemplateID;

	UPROPERTY(SaveGame)
	bool bIsDynamic;

};

USTRUCT(BlueprintType)
struct FFortWeaponModSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeaponModSlot")
	TObjectPtr<UFortWeaponModItemDefinition> WeaponMod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeaponModSlot")
	bool bIsDynamic;

};

