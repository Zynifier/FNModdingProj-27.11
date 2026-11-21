// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortProjectileFallingTrap.generated.h"

class UStaticMeshComponent;

UCLASS(HideCategories=("Navigation", "Navigation", "Game|Damage"))
class AFortProjectileFallingTrap : public AFortProjectileBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Falling Trap", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> MeshComponent;

};

