// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortAbilitySystemProjectileBase.generated.h"

class UFortAbilitySystemComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Game|Damage"))
class AFortAbilitySystemProjectileBase : public AFortProjectileBase, public IFortAbilitySystemInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AbilitySystem", meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};

