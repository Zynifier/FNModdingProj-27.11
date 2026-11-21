// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Building/BuildingGameplayActor.h"
#include "FortCurieUpdraftActor.generated.h"

class AActor;
class UCapsuleComponent;
class UCurveFloat;
class UPrimitiveComponent;

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortCurieUpdraftActor : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnUpdraftBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnUpdraftEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, Export, Category="Collision", meta=(EditInline="true"))
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	float PlayerPawnVortexLaunchMagnitude;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	float PlayerPawnVortexGravityFloorScalar;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	float VehicleGravityMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	float ProjectileGravityMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	float ProjectileZLaunchMagnitude;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	uint8 bGlanceProjectiles : 1;

	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(EditCondition="bGlanceProjectiles"))
	TObjectPtr<UCurveFloat> ProjectileGlanceCurve;

	UPROPERTY(Transient)
	TMap<TObjectPtr<AActor>, float> ActorToPreexistingGravityMultiplierMap;

};

