// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Abilities/FortGameplayCueNotify_Actor.h"
#include "Abilities/FortGameplayCueTypes.h"
#include "FortGameplayCueNotify_BurstLatent.generated.h"

class AActor;
class ADecalActor;
class UAudioComponent;
class UFXSystemComponent;
class ULegacyCameraShake;
class UNiagaraComponent;
class UParticleSystemComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(Category="GameplayCue", DisplayName="GCN Burst Latent", ShortTooltip="A one off GameplayCue that can use latent actions such as timelines"))
class AFortGameplayCueNotify_BurstLatent : public AFortGameplayCueNotify_Actor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Burst (Cascade)"))
	void OnBurst(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UParticleSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Burst (Either VFX - prefer this version)"))
	void OnBurstGeneric(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UFXSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Burst (Niagara)"))
	void OnBurstNiagara(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UNiagaraComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Burst Effects")
	FFortBurstEffectData BurstEffectData;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayCueNotify_BurstLatent")
	FFortGameplayCueSpawnResult BurstResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cleanup")
	float MaxBurstLatentLifetime;

};

