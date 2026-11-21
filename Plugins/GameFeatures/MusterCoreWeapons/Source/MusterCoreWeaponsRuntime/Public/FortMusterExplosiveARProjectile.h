// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/FortProjectileAthena.h"
#include "FortMusterExplosiveARProjectile.generated.h"

class UMaterialInterface;
class UNiagaraSystem;
class UParticleSystemComponent;
class USoundBase;

UCLASS(HideCategories=("Navigation", "Navigation", "Navigation", "Game|Damage"))
class AFortMusterExplosiveARProjectile : public AFortProjectileAthena
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_HitLocation();

	UFUNCTION(BlueprintCallable)
	void SetHitLocation(const FVector& NewHitLocation);

	UFUNCTION(BlueprintCallable)
	void SetHitPlayer(bool bWasHit);

	UFUNCTION(BlueprintCallable)
	void SetHitRotation(const FRotator& NewHitRotation);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_HitLocation, Category="FortMusterExplosiveARProjectile")
	FVector HitLocation;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortMusterExplosiveARProjectile")
	FRotator HitRotation;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortMusterExplosiveARProjectile")
	bool bHitPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMusterExplosiveARProjectile")
	float DrawDistance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortMusterExplosiveARProjectile", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> ProjectileTrail;

private:
	UPROPERTY(EditDefaultsOnly, Category="Cosmetic")
	TObjectPtr<UNiagaraSystem> NS_Explosion;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic")
	FGameplayTag FeedbackCue;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic | Decals")
	FVector DecalSize;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic | Decals")
	float DecalLifespan;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic | Decals")
	float TimebeforeDecalFadeOut;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic | Decals")
	float DecalFadeOutDuration;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic | Decals")
	TObjectPtr<UMaterialInterface> DecalMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic")
	TObjectPtr<USoundBase> Cue_CloseSound;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic")
	TObjectPtr<USoundBase> Cue_DistantSound;

};

