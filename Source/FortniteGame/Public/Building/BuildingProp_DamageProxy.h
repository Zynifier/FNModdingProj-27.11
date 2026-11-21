// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingProp.h"
#include "BuildingProp_DamageProxy.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_DamageProxy : public ABuildingProp
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleOnDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleOwningActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void HandleOwningBuildingActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

};

