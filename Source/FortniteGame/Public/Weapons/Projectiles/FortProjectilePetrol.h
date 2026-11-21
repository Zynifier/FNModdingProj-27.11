// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortProjectilePetrol.generated.h"

class AActor;
class ABuildingGameplayActorPetrol;
class AFortSplineGroundPath;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Navigation", "Game|Damage"))
class AFortProjectilePetrol : public AFortProjectileBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	float FuelAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	TSubclassOf<ABuildingGameplayActorPetrol> PetrolTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	TSubclassOf<AFortSplineGroundPath> FortSplineGroundPathTemplate;

	UPROPERTY(Transient)
	bool bImpacted;

	UPROPERTY(EditDefaultsOnly, Category="Config")
	float MaxLifeSpanOnCollision;

	UPROPERTY(EditDefaultsOnly, Category="Config")
	float GroundSlopeAngleThreshold;

	UPROPERTY(Transient)
	FVector CachedImpactDir;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortProjectilePetrol")
	TWeakObjectPtr<AActor> SplatterSourceActor;

};

