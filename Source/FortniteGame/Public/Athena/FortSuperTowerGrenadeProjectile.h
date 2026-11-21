// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortSuperTowerGrenadeProjectile.generated.h"

class AActor;
class UBuildingStructuralSupportSystem;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Game|Damage"))
class AFortSuperTowerGrenadeProjectile : public AFortProjectileBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tower")
	void ClearGridCells(const TArray<FVector>& GridCellsToClear, bool bDestroyFloorsQuickly, const FVector& BaseDestination, float AngleDeg);

	UFUNCTION(BlueprintCallable, Category="Tower")
	void DestroyActorsInGridCellLocation(UBuildingStructuralSupportSystem* BuildingStructuralSupportSystem, const FVector& CellLocation, bool bDestroyFloorsQuickly);

	UPROPERTY(BlueprintReadWrite, Category="Tower")
	TArray<TObjectPtr<AActor>> BuildingActorsToDestroy;

	UPROPERTY(BlueprintReadWrite, Category="Tower")
	TArray<TObjectPtr<AActor>> BuildingActorsToIgnore;

};

