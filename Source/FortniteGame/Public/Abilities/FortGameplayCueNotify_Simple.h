// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Static.h"
#include "GameplayEffectTypes.h"
#include "Particles/WorldPSCPool.h"
#include "FortParticleSystemParamBucket.h"
#include "FortGameplayCueNotify_Simple.generated.h"

class UParticleSystem;
class UParticleSystemComponent;
class USoundBase;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Replication"), meta=(Category="GameplayCue", DisplayName="GCN Simple (Deprecated)", ShortTooltip="This class is deprecated. Use UFortGameplayCueNotify_Burst (GCN Burst) instead."))
class UFortGameplayCueNotify_Simple : public UGameplayCueNotify_Static
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="GameplayCueNotify")
	void OnStartParticleSystemSpawned(UParticleSystemComponent* SpawnedParticleSysComponent, const FGameplayCueParameters& Parameters) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	TObjectPtr<USoundBase> StartSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particles")
	TObjectPtr<UParticleSystem> StartParticleSystem;

	UPROPERTY(EditAnywhere, Category="Particles")
	FFortParticleSystemParamBucket StartParticleSystemParameters;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	FName AttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bStayAttached;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bUseHitResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bUseWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bIgnoreRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bUseUnsmoothedNetworkPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	EPSCPoolMethod PoolingMethod;

};

