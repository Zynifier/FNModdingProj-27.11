// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortCurieFXManager.generated.h"

class AFortCurieGrassFireReplicator;
class UAudioComponent;
class UFortCurieComponent;
class UFortCurieFXSettings;
class UFortCurieNativeFXHandler;
class UFortCurieWorldNiagaraComponent;
class UFortPlaysetItemDefinition;
class UMaterialParameterCollection;
class UNiagaraComponent;
class UNiagaraSystem;
class USoundBase;
class UStaticMesh;
class UStaticMeshComponent;
class UTextureRenderTarget2D;

USTRUCT()
struct FFortCurieActiveAmbientAudio
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	UAudioComponent* AudioComponent;

	UPROPERTY()
	int32 AudioClusterCount;

};

USTRUCT()
struct FFortCurieActiveElectricityArc
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector TargetActorSmallestAxis;

	UPROPERTY(Export, meta=(EditInline="true"))
	UStaticMeshComponent* Mesh;

	UPROPERTY(Export, meta=(EditInline="true"))
	UFortCurieComponent* OwningComponent;

	UPROPERTY()
	float StartTime;

	UPROPERTY()
	bool bPlayedImpact;

};

USTRUCT()
struct FFortCurieAmbientAudioLocationKey
{
	GENERATED_BODY()


	FORTNITEGAME_API bool operator==(const FFortCurieAmbientAudioLocationKey& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FFortCurieAmbientAudioLocationKey& Value);
};

USTRUCT()
struct FFortCurieFXManagerTickFunction : public FTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FFortCurieFXManagerTickFunction> : public TStructOpsTypeTraitsBase2<FFortCurieFXManagerTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

USTRUCT()
struct FFortCurieFireParticleActorData
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	UFortCurieComponent* AssociatedComponent;

};

USTRUCT()
struct FFortCurieFireParticleGrassData
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortCurieGlowFadeRequest
{
	GENERATED_BODY()

public:
	UPROPERTY(Export)
	TWeakObjectPtr<UFortCurieComponent> CurieComponent;

	UPROPERTY()
	FGameplayTag FXTag;

	UPROPERTY()
	float StartTimestamp;

	UPROPERTY()
	bool bIsFadeIn;

};

USTRUCT()
struct FFortCuriePendingElectricityArcRequest
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	UFortCurieComponent* RequestingComponent;

	UPROPERTY()
	float ExecutionTime;

	UPROPERTY()
	bool bIsFirstIteration;

};

USTRUCT()
struct FFortCurieWorldFirePlayerSystem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFortCurieWorldNiagaraComponent* ActiveWorldFireSystem;

	UPROPERTY(Transient)
	float LastFireParticleSampleTimestamp;

};

UCLASS(Config=Game)
class UFortCurieFXManager : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnElectricityImpactFXComplete(UNiagaraComponent* InComponent);

	UPROPERTY(Transient)
	TObjectPtr<UFortPlaysetItemDefinition> CurrentPlayset;

	UPROPERTY()
	FFortCurieFXManagerTickFunction PrimaryManagerTick;

	UPROPERTY(Transient)
	TObjectPtr<UFortCurieFXSettings> FXSettings;

	UPROPERTY(Transient)
	TArray<UStaticMesh*> ValidElectricityArcMeshes;

	UPROPERTY(Transient)
	TObjectPtr<UNiagaraSystem> ElectricityArcImpactSystem;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> ElectricityArcSound;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> ElectricityAmbientSound;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> FireAmbientSound;

	UPROPERTY(Transient)
	TMap<FFortCurieAmbientAudioLocationKey, FFortCurieActiveAmbientAudio> ActiveAmbientAudioMap;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UAudioComponent*> AvailablePooledAmbientAudioComponents;

	UPROPERTY(Transient)
	FTimerHandle AudioComponentCleanupTimerHandle;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TSet<UNiagaraComponent*> ActiveElectricityArcImpactFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UNiagaraComponent*> AvailablePooledNiagaraComponents;

	UPROPERTY(Transient)
	TArray<FFortCurieGlowFadeRequest> GlowFadeRequests;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UStaticMeshComponent*> AvailablePooledElectricityMeshComponents;

	UPROPERTY(Transient)
	TArray<FFortCurieActiveElectricityArc> ActiveElectricityArcs;

	UPROPERTY(Transient)
	TArray<FFortCuriePendingElectricityArcRequest> PendingElectricityArcRequestHeap;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UFortCurieComponent*> PrematureComponents;

	UPROPERTY(Transient)
	FTimerHandle PrematureComponentTimerHandle;

	UPROPERTY(Transient)
	TArray<AFortCurieGrassFireReplicator*> GrassFireReplicators;

	UPROPERTY(Transient)
	UTextureRenderTarget2D* LandscapeCharRenderTarget;

	UPROPERTY(Transient)
	TMap<FGameplayTag, UFortCurieNativeFXHandler*> NativeFXHandlers;

	UPROPERTY(Transient)
	FBox GrassFireBounds;

	UPROPERTY(Transient)
	float ElectricityArcFXSignificanceRequirement;

	UPROPERTY(Transient)
	float ElectricityImpactFXSignificanceRequirement;

	UPROPERTY(Transient)
	float ElectricityArcSoundSignificanceRequirement;

	UPROPERTY(Transient)
	float AmbientAudioSignificanceRequirement;

	UPROPERTY(Transient)
	float AmbientAudioSurroundSignificanceRequirement;

	UPROPERTY(Transient)
	float GlowInterpolationSignificanceRequirement;

	UPROPERTY(Transient)
	UMaterialParameterCollection* MaterialParameterCollection;

	UPROPERTY(Transient)
	float TimeSinceAudioUpdate;

	UPROPERTY(Transient)
	double PreviousGlowFadeTickTime;

	UPROPERTY(Transient)
	uint8 bNiagaraImpactFXActive : 1;

	UPROPERTY(Transient)
	uint8 bFireElementEnabled : 1;

	UPROPERTY(Transient)
	uint8 bElectricityElementEnabled : 1;

	UPROPERTY(Transient)
	uint8 bShutdown : 1;

};

