// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortTrapGrenadeProjectile.generated.h"

class AFortDecoTool_ContextTrap;
class AFortProjectileDecoHelper;
class UFortContextTrapItemDefinition;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Game|Damage"))
class AFortTrapGrenadeProjectile : public AFortProjectileBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Trap")
	UFortContextTrapItemDefinition* GetTrapDefinition();

	UFUNCTION(BlueprintCallable, Category="TrapGrenade")
	void InitializeProjectileDecoHelperAndTool();

protected:
	UFUNCTION()
	void OnRep_DecoTool();

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_DecoTool, Category="FortTrapGrenadeProjectile")
	TObjectPtr<AFortDecoTool_ContextTrap> ProjectileDecoTool;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTrapGrenadeProjectile")
	TObjectPtr<AFortProjectileDecoHelper> ProjectileDecoHelper;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	TObjectPtr<UFortContextTrapItemDefinition> TrapDefinition;

};

