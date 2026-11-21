// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Items/FortDecoItemDefinition.h"
#include "FortTrapItemDefinition.generated.h"

class USoundBase;

UCLASS(MinimalAPI, HideCategories=("Damage", "Effects"))
class UFortTrapItemDefinition : public UFortDecoItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	FRotator KnockbackDirOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	bool bKnockBackUsingPawnDir;

protected:
	UPROPERTY(EditAnywhere, Category="Sounds", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> EquipSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AutoEquip")
	FGameplayTagContainer OverrideAutoEquipTags;

};

