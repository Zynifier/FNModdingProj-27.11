// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortProjectile_MOBATurret.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Game|Damage"))
class AFortProjectile_MOBATurret : public AFortProjectileBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnHomingTargetDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(Transient)
	TArray<FHitResult> ForcedHitResults;

};

