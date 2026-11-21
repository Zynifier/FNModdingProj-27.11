// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Static.h"
#include "GameplayEffectTypes.h"
#include "Abilities/FortGameplayCueTypes.h"
#include "FortGameplayCueNotify_Burst.generated.h"

class AActor;
class ADecalActor;
class UAudioComponent;
class UFXSystemComponent;
class ULegacyCameraShake;
class UNiagaraComponent;
class UParticleSystemComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Replication"), meta=(Category="GameplayCue", DisplayName="GCN Burst", ShortTooltip="A one off instant GameplayCue, this is never spawned into the world", ShowWorldContextPin))
class UFortGameplayCueNotify_Burst : public UGameplayCueNotify_Static
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="On Burst (Cascade)"))
	void OnBurst(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UParticleSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Burst (Either VFX - prefer this version)"))
	void OnBurstGeneric(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UFXSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Burst (Niagara)"))
	void OnBurstNiagara(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UNiagaraComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Defaults")
	FFortGameplayCueSpawnCondition DefaultCondition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Defaults")
	FFortGameplayCueAttachInfo DefaultAttachment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Burst Effects")
	FFortBurstEffectData BurstEffectData;

};

