// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortProjectileAthena.h"
#include "FortExCaliberProjectile.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;
class UStaticMeshComponent;

UCLASS(HideCategories=("Navigation", "Navigation", "Navigation", "Game|Damage"))
class AFortExCaliberProjectile : public AFortProjectileAthena
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnProjectileStopped"))
	void BP_OnProjectileStopped();

	UFUNCTION()
	void OnAttachedActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnAttachedBuildingDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnRep_bSimulationRunning();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayPreExplosionEfffects();

	UFUNCTION(BlueprintCallable)
	void RestartSimulating();

	UFUNCTION(BlueprintImplementableEvent)
	void SetFuseColorBasedOnTeam();

	UFUNCTION(BlueprintImplementableEvent)
	void SetupProjectileHitAudio(const FVector& ProjectileImpactLocation, const AActor* HitActor);

	UFUNCTION(BlueprintCallable)
	void SetupSwordRevealEffects(UStaticMeshComponent* ProjectileMesh, float SwordRevealAlpha, float ColorChangeAlpha, float HDRMultiplierAlpha);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void TriggerExplosion();

	UFUNCTION(BlueprintImplementableEvent)
	void UnblockPawnCollision();

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_bSimulationRunning, Category="FortExCaliberProjectile")
	bool bSimulationRunning;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Explosion")
	FScalableFloat TimeToExplode;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortExCaliberProjectile")
	bool bHasStopped;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortExCaliberProjectile")
	FVector HitNormal;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortExCaliberProjectile")
	TEnumAsByte<EPhysicalSurface> SurfaceType;

private:
	UPROPERTY(EditDefaultsOnly, Category="Material Settings")
	FName SwordRevealMaterialParam;

	UPROPERTY(EditDefaultsOnly, Category="Material Settings")
	FName EmissiveColorMaterialParam;

	UPROPERTY(EditDefaultsOnly, Category="Material Settings")
	FName HDRMultiplierMaterialParam;

	UPROPERTY(EditDefaultsOnly, Category="Material Settings")
	FLinearColor EmissiveBlueColor;

	UPROPERTY(EditDefaultsOnly, Category="Material Settings")
	FLinearColor EmissivePurpleColor;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic Adjustments")
	float MinPitchForRotationAdjustment;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic Adjustments")
	float MaxPitchForRotationAdjustment;

};

