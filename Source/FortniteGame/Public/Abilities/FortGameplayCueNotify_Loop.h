// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "GameplayEffectTypes.h"
#include "Abilities/FortGameplayCueNotify_Actor.h"
#include "Abilities/FortGameplayCueTypes.h"
#include "FortGameplayCueNotify_Loop.generated.h"

class AActor;
class ADecalActor;
class UAudioComponent;
class UFXSystemComponent;
class ULegacyCameraShake;
class UNiagaraComponent;
class UParticleSystemComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(Category="GameplayCue", DisplayName="GCN Loop", ShortTooltip="A GameplayCue that has a duration that is driven by the game.", ShowWorldContextPin))
class AFortGameplayCueNotify_Loop : public AFortGameplayCueNotify_Actor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Application (Cascade)"))
	FORTNITEGAME_API void OnApplication(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UParticleSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Application (Either VFX - prefer this one)"))
	FORTNITEGAME_API void OnApplicationGeneric(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UFXSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Application (Niagara)"))
	FORTNITEGAME_API void OnApplicationNiagara(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UNiagaraComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Looping Start (Cascade)"))
	FORTNITEGAME_API void OnLoopingStart(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UParticleSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Looping Start (Either VFX - prefer this version)"))
	FORTNITEGAME_API void OnLoopingStartGeneric(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UFXSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Looping Start (Niagara)"))
	FORTNITEGAME_API void OnLoopingStartNiagara(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UNiagaraComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Recurring (Cascade)"))
	FORTNITEGAME_API void OnRecurring(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UParticleSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Recurring (Either VFX - prefer this one)"))
	FORTNITEGAME_API void OnRecurringGeneric(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UFXSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Recurring (Niagara)"))
	FORTNITEGAME_API void OnRecurringNiagara(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UNiagaraComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Removal (Cascade)"))
	FORTNITEGAME_API void OnRemoval(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UParticleSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Removal (Either VFX - prefer this version)"))
	FORTNITEGAME_API void OnRemovalGeneric(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UFXSystemComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Removal (Niagara)"))
	FORTNITEGAME_API void OnRemovalNiagara(AActor* MyTarget, const FGameplayCueParameters& Parameters, const TArray<UNiagaraComponent*>& ParticleComponents, const TArray<UAudioComponent*>& AudioComponents, ULegacyCameraShake* BurstCameraShakeInstance, ADecalActor* BurstDecalInstance);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Application Effects")
	FFortBurstEffectData ApplicationBurst;

	UPROPERTY(BlueprintReadOnly, Category="Application Effects")
	FFortGameplayCueSpawnResult ApplicationResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Looping Effects")
	FFortGameplayCueAttachInfo DefaultLoopingAttachment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Looping Effects")
	TArray<FFortGameplayCueParticleInfo> LoopingParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Looping Effects")
	TArray<FFortGameplayCueAudioInfo_Looping> LoopingSounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Looping Effects")
	FFortGameplayCueForceFeedbackInfo LoopingForceFeedbackEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Looping Effects")
	FFortGameplayCueCameraLensEffectInfo LoopingCameraLensEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Looping Effects")
	FFortGameplayCueCameraShakeInfo LoopingCameraShake;

	UPROPERTY(BlueprintReadOnly, Category="Application Effects")
	FFortGameplayCueSpawnResult LoopingResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recurring Effects")
	FFortBurstEffectData RecurringBurst;

	UPROPERTY(BlueprintReadOnly, Category="Recurring Effects")
	FFortGameplayCueSpawnResult RecurringResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Removal Effects")
	FFortBurstEffectData RemovalBurst;

	UPROPERTY(BlueprintReadOnly, Category="Removal Effects")
	FFortGameplayCueSpawnResult RemovalResult;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameplayCueNotify")
	bool bTickEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameplayCueNotify", meta=(EditCondition="bTickEnabled"))
	float TickInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameplayCueNotify")
	TEnumAsByte<ETickingGroup> TickGroup;

};

