// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraTypes.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/HitResult.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "ParticleHelper.h"
#include "Effects/FortNiagaraCascadeMigration.h"
#include "FortGameplayCueTypes.generated.h"

class AActor;
class ADecalActor;
class ICameraLensEffectInterface;
class UAudioComponent;
class UFXSystemComponent;
class UForceFeedbackEffect;
class ULegacyCameraShake;
class UNiagaraSystem;
class UParticleSystem;
class USoundBase;
class USoundLibraryContext;

UENUM(BlueprintType)
enum class EFortGameplayCueAttachType : uint8
{
	/** We will attach to the target if possible */
	AttachToTarget = 0,
	/** We will not attach to target. We may use it to get spawn location/info but will not attach the spawned component */
	DoNotAttach = 1,
};

UENUM(BlueprintType)
enum class EFortGameplayCueSourceCondition : uint8
{
	/** No special condition: this always spawns for everyone */
	AnySource = 0,
	/** Only spawn if this effect was instigated from a locally controlled player */
	LocalPlayerSource = 1,
	/** Only spawn if this effect was NOT instigated from a locally controlled player */
	NonLocalPlayerSource = 2,
};

USTRUCT(BlueprintType)
struct FFortGameplayCueAttachInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo")
	EFortGameplayCueAttachType AttachType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo")
	uint8 bAttachToWeapon : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo")
	uint8 bAttachToHitResult : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo")
	uint8 bUseUnsmoothedNetworkPosition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo")
	uint8 bIgnoreLocation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo")
	uint8 bIgnoreScale : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo")
	uint8 bIgnoreRotation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo", meta=(EditCondition="bIgnoreLocation"))
	FVector OverrideLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo", meta=(EditCondition="bIgnoreScale"))
	FVector OverrideScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAttachInfo", meta=(EditCondition="bIgnoreRotation"))
	FRotator OverrideRotation;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueSpawnCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueSpawnCondition")
	EFortGameplayCueSourceCondition SourceCondition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueSpawnCondition")
	TArray<TEnumAsByte<EPhysicalSurface>> AllowedSurfaces;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueSpawnCondition")
	TArray<TEnumAsByte<EPhysicalSurface>> DisallowedSurfaces;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueSpawnCondition")
	float ChanceToPlay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueSpawnCondition", meta=(DisplayName="Distance Priority"))
	EParticleSignificanceLevel Significance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueSpawnCondition")
	int32 RequiredDetailMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueSpawnCondition")
	uint8 bRequireVisible : 1;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueAudioInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAudioInfo", meta=(EditCondition="bOverrideCondition"))
	FFortGameplayCueSpawnCondition Condition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAudioInfo", meta=(EditCondition="bOverrideAttachment"))
	FFortGameplayCueAttachInfo Attachment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAudioInfo")
	TObjectPtr<USoundBase> SoundCue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAudioInfo", meta=(Categories="SoundLibrary"))
	FGameplayTag SoundLibraryTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAudioInfo", meta=(Categories="SoundLibrary"))
	TSubclassOf<USoundLibraryContext> SoundLibraryContextClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAudioInfo")
	float DelayBeforePlayInSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAudioInfo", meta=(InlineEditConditionToggle))
	uint8 bOverrideCondition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAudioInfo", meta=(InlineEditConditionToggle))
	uint8 bOverrideAttachment : 1;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueAOEInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAOEInfo")
	float InnerRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueAOEInfo")
	float OuterRadius;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueCameraLensEffectInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraLensEffectInfo", meta=(MustImplement="/Script/Engine.CameraLensEffectInterface"))
	TSubclassOf<AActor> CameraLensEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraLensEffectInfo")
	FFortGameplayCueAOEInfo Falloff;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraLensEffectInfo")
	bool bAlwaysPlayOnTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraLensEffectInfo")
	bool bCancelOnRemove;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueCameraShakeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraShakeInfo")
	TSubclassOf<ULegacyCameraShake> Shake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraShakeInfo")
	float Scale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraShakeInfo")
	ECameraShakePlaySpace PlaySpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraShakeInfo")
	FRotator UserPlaySpaceRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraShakeInfo")
	bool bAlwaysPlayOnTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraShakeInfo")
	bool bCalculateUserPlaySpaceRotationFromLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraShakeInfo")
	bool bCancelOnRemove;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueCameraShakeInfo")
	FFortGameplayCueAOEInfo Falloff;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueDecalInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueDecalInfo", meta=(EditCondition="bOverrideCondition"))
	FFortGameplayCueSpawnCondition Condition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueDecalInfo", meta=(EditCondition="bOverrideAttachment"))
	FFortGameplayCueAttachInfo Attachment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueDecalInfo", meta=(InlineEditConditionToggle))
	uint8 bOverrideCondition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueDecalInfo", meta=(InlineEditConditionToggle))
	uint8 bOverrideAttachment : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueDecalInfo", meta=(InlineEditConditionToggle))
	uint8 bOverrideFadeOut : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueDecalInfo")
	TSubclassOf<ADecalActor> Decal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueDecalInfo", meta=(EditCondition="bOverrideFadeOut"))
	float FadeOutStartDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueDecalInfo", meta=(EditCondition="bOverrideFadeOut"))
	float FadeOutDuration;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueForceFeedbackInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueForceFeedbackInfo")
	TObjectPtr<UForceFeedbackEffect> ForceFeedbackEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueForceFeedbackInfo")
	float EffectRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueForceFeedbackInfo")
	TObjectPtr<UForceFeedbackEffect> FarForceFeedbackEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueForceFeedbackInfo")
	float FarEffectRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueForceFeedbackInfo")
	FName EffectTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueForceFeedbackInfo")
	bool bAlwaysPlayOnTarget;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueParticleInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueParticleInfo", meta=(EditCondition="bOverrideCondition"))
	FFortGameplayCueSpawnCondition Condition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueParticleInfo", meta=(EditCondition="bOverrideAttachment"))
	FFortGameplayCueAttachInfo Attachment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles")
	EFXType FXType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles", meta=(DisplayName="Niagara VFX"))
	TObjectPtr<UNiagaraSystem> NiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles", meta=(DisplayName="Cascade VFX"))
	TObjectPtr<UParticleSystem> ParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueParticleInfo")
	uint8 bUseComponentPool : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueParticleInfo")
	uint8 bCastShadow : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueParticleInfo", meta=(InlineEditConditionToggle))
	uint8 bOverrideCondition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortGameplayCueParticleInfo", meta=(InlineEditConditionToggle))
	uint8 bOverrideAttachment : 1;

};

USTRUCT(BlueprintType)
struct FFortBurstEffectData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Effects")
	TArray<FFortGameplayCueParticleInfo> BurstParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Effects")
	TArray<FFortGameplayCueAudioInfo> BurstSounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Effects")
	FFortGameplayCueCameraShakeInfo BurstCameraShake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Effects")
	FFortGameplayCueCameraLensEffectInfo BurstCameraLensEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Effects")
	FFortGameplayCueForceFeedbackInfo BurstForceFeedbackEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Effects")
	FFortGameplayCueDecalInfo BurstDecal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Effects")
	bool bCancelSoundsOnRemove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Effects")
	bool bCancelParticlesOnRemove;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueAudioInfo_Looping : public FFortGameplayCueAudioInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Looping Effects")
	float LoopingSoundFadeOutDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Looping Effects", meta=(DisplayName="Looping Sound Fade Out Volume Level"))
	float LoopingSoundVolumeLevel;

};

USTRUCT(BlueprintType)
struct FFortGameplayCueSpawnResult
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFXSystemComponent>> ParticleComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioComponent>> AudioComponents;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> CameraShake;

	UPROPERTY(Transient)
	TScriptInterface<ICameraLensEffectInterface> CameraLensEffect;

	UPROPERTY(Transient)
	TObjectPtr<ADecalActor> DecalActor;

};

UCLASS()
class UFortGameplayCueFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="GameplayCue", meta=(WorldContext="WorldContextObject"))
	static void AddGameplayCue(AActor* TargetActor, const FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context);

	UFUNCTION(BlueprintCallable, Category="Projectile", meta=(DisplayName="Add GameplayCue (Looping) Local"))
	static void AddGameplayCueLocal(AActor* Target, FGameplayTag GameplayCueTag, const FGameplayCueParameters& CueParameters, bool bOnlyNotifies = true);

	UFUNCTION(BlueprintCallable, Category="GameplayCue")
	static void BuildCueParametersFromHitResult(AActor* SourceActor, const FHitResult& HitResult, FGameplayCueParameters& OutCueParameters);

	UFUNCTION(BlueprintCallable, Category="GameplayCue")
	static void BuildCueParametersFromSource(AActor* SourceActor, FGameplayCueParameters& OutCueParameters);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="GameplayCue")
	static bool CheckSpawnConditionForCueParameters(AActor* Target, const FGameplayCueParameters& CueParameters, const FFortGameplayCueSpawnCondition& Condition);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="GameplayCue")
	static bool CheckSpawnConditionForHitResult(AActor* Target, AActor* SourceActor, const FHitResult& HitResult, const FFortGameplayCueSpawnCondition& Condition);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="GameplayCue")
	static bool CheckSpawnConditionForSource(AActor* Target, AActor* SourceActor, const FFortGameplayCueSpawnCondition& Condition);

	UFUNCTION(BlueprintCallable, Category="GameplayCue", meta=(WorldContext="WorldContextObject"))
	static void ExecuteGameplayCue(AActor* TargetActor, const FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="GameplayCue", meta=(DisplayName="Execute GameplayCue (Burst) Local", GameplayTagFilter="GameplayCue"))
	static void ExecuteGameplayCueLocal(AActor* Target, FGameplayTag GameplayCueTag, const FGameplayCueParameters& CueParameters, bool bOnlyNotifies = true);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="GameplayCue")
	static void PlayBurstEffect(const FFortBurstEffectData& BurstEffect, AActor* Target, const FGameplayCueParameters& CueParameters, FFortGameplayCueSpawnResult& OutResult);

	UFUNCTION(BlueprintCallable, Category="GameplayCue", meta=(WorldContext="WorldContextObject"))
	static void RemoveGameplayCue(AActor* TargetActor, const FGameplayTag GameplayCueTag);

	UFUNCTION(BlueprintCallable, Category="Projectile", meta=(DisplayName="Remove GameplayCue (Looping) Local"))
	static void RemoveGameplayCueLocal(AActor* Target, FGameplayTag GameplayCueTag, const FGameplayCueParameters& CueParameters, bool bOnlyNotifies = true);

};

