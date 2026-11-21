// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Actor.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Particles/WorldPSCPool.h"
#include "FortParticleSystemParamBucket.h"
#include "FortGameplayCueNotify_Looping.generated.h"

class AActor;
class UAudioComponent;
class UParticleSystem;
class UParticleSystemComponent;
class USceneComponent;
class USoundBase;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Replication"), meta=(Category="GameplayCue", DisplayName="GCN Looping (Deprecated)", ShortTooltip="This class is deprecated. Use AFortGameplayCueNotify_Loop (GCN Loop) instead."))
class AFortGameplayCueNotify_Looping : public AGameplayCueNotify_Actor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="GameplayCueNotify")
	bool GetSpawnTransform(AActor* TargetActor, FName AttachPointName, const FGameplayCueParameters& Parameters, FTransform& OutTransform) const;

	UFUNCTION(BlueprintPure, Category="GameplayCueNotify")
	USceneComponent* GetTargetComponent(AActor* TargetActor, const FGameplayCueParameters& Parameters) const;

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayCueNotify")
	void OnStartParticleSystemSpawned(UParticleSystemComponent* SpawnedParticleSysComponent, const FGameplayCueParameters& Parameters) const;

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayCueNotify")
	void OnStopParticleSystemSpawned(UParticleSystemComponent* SpawnedParticleSysComponent, const FGameplayCueParameters& Parameters) const;

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayCueNotify")
	void OnWhileActiveParticleSystemActivate(UParticleSystemComponent* WhileActiveParticleSysComponent, const FGameplayCueParameters& Parameters) const;

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayCueNotify")
	void OnWhileActiveParticleSystemDeactivate(UParticleSystemComponent* WhileActiveParticleSysComponent, const FGameplayCueParameters& Parameters) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	TObjectPtr<USoundBase> StartSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	TObjectPtr<USoundBase> StopSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particles")
	TObjectPtr<UParticleSystem> StartParticleSystem;

	UPROPERTY(EditAnywhere, Category="Particles")
	FFortParticleSystemParamBucket StartParticleSystemParameters;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particles")
	TObjectPtr<UParticleSystem> StopParticleSystem;

	UPROPERTY(EditAnywhere, Category="Particles")
	FFortParticleSystemParamBucket StopParticleSystemParameters;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	FName AttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bStayAttached;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bSnapToAttachPointAndPreserveWorldRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bUseHitResult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bUseWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	bool bIgnoreRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	FGameplayTagContainer HUDElementTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attach")
	EPSCPoolMethod PoolingMethod;

private:
	UPROPERTY()
	bool bIsValid;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Sounds", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Sound,Audio,Audio|Components|Audio"))
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Particles", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Particles|Beam,Particles|Parameters,Particles,Effects|Components|ParticleSystem,Rendering,Activation,Components|Activation"))
	TObjectPtr<UParticleSystemComponent> ParticleSystemComponent;

};

