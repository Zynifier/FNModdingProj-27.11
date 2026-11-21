// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Math/MathFwd.h"
#include "Athena/FortProjectileAthena.h"
#include "FortProjectileSniperAthena.generated.h"

class AActor;
class UMaterialInterface;
class UNiagaraComponent;
class USoundBase;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Navigation", "Navigation", "Game|Damage"))
class AFortProjectileSniperAthena : public AFortProjectileAthena
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void PlayImpactSFX(EPhysicalSurface SurfaceType, AActor* HitActor);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortProjectileSniperAthena", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UNiagaraComponent> BulletTrailParticleComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Cosmetic | Sounds", meta=(AllowPrivateAccess="true"))
	TMap<TEnumAsByte<EPhysicalSurface>, TObjectPtr<USoundBase>> SurfaceImpactSFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Cosmetic | Decals", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UMaterialInterface> DecalMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Cosmetic | Decals", meta=(AllowPrivateAccess="true"))
	FVector DecalSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Cosmetic | Decals", meta=(AllowPrivateAccess="true"))
	float DecalLifeSpan;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Cosmetic | Decals", meta=(AllowPrivateAccess="true"))
	float DeactivationSecondsDelay;

};

