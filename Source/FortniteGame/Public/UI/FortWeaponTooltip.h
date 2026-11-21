// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortWorldItemTooltip.h"
#include "FortWeaponTooltip.generated.h"

class UFortAbilitySystemComponent;
class UFortWorldItem;

UCLASS(BlueprintType, Blueprintable, meta=(ShortTooltip="Gathers data from weapons for display tooltips."))
class UFortWeaponTooltip : public UFortWorldItemTooltip
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TWeakObjectPtr<UFortWorldItem> CachedWeapon;

	UPROPERTY(Export)
	TWeakObjectPtr<UFortAbilitySystemComponent> CachedAbilitySystemComponent;

};

