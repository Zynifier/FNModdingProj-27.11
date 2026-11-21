// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "FortSkeletalAudioComponent.generated.h"

class UAudioComponent;
class UFortSkeletalAudioAssetBank;
class USkeletalMeshComponent;
class USoundBase;

UENUM()
enum class ESkeletalAudioBoneEvent : uint8
{
	None = 0,
	SlowThresholdStart = 1,
	SlowThresholdStop = 2,
	MediumThreshold = 3,
	FastThreshold = 4,
};

UENUM(BlueprintType)
enum class ESkeletalAudioBoneSpace : uint8
{
	Relative = 0,
	World = 1,
};

UENUM(BlueprintType)
enum class ESkeletalAudioBoneVelocityType : uint8
{
	Linear = 0,
	Rotational = 1,
	Custom = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeavySoundTriggered, UAudioComponent*, Sound);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLoopSoundModulated, UAudioComponent*, Sound, float, Intensity);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoopSoundTriggered, UAudioComponent*, Sound);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMediumSoundTriggered, UAudioComponent*, Sound, float, Intensity);

USTRUCT(BlueprintType)
struct FSkeletalAudioBoneConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	FName BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	TObjectPtr<USoundBase> SoundLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	TObjectPtr<USoundBase> SoundMediumDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	TObjectPtr<USoundBase> SoundHighDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	float ThresholdLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	float ThresholdMedium;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	float ThresholdHigh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	float RetriggerDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	ESkeletalAudioBoneSpace TrackingSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkeletalAudioBoneConfig")
	ESkeletalAudioBoneVelocityType VelocityTrackingType;

};

USTRUCT(BlueprintType)
struct FSkeletalAudioBoneInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> LoopInstance;

	UPROPERTY(BlueprintReadOnly, Category="SkeletalAudioBoneInstance")
	float Delta;

};

UCLASS()
class UFortSkeletalAudioAssetBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortSkeletalAudioAssetBank")
	TArray<FSkeletalAudioBoneConfig> BoneConfigs;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortSkeletalAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Components|SkeletalAudio")
	void SetCanPlay(bool CanPlay);

	UFUNCTION(BlueprintCallable, Category="Components|SkeletalAudio")
	void SetCustomTrackedTransform(int32 Index, const FTransform& Transform);

	UFUNCTION(BlueprintCallable, Category="Components|SkeletalAudio")
	void SetSkeletalMesh(USkeletalMeshComponent* NewSkeletalMesh);

	UFUNCTION(BlueprintCallable, Category="Components|SkeletalAudio")
	void SetVolumeMultiplier(float Multiplier);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSkeletalAudioComponent")
	TObjectPtr<UFortSkeletalAudioAssetBank> AudioAssetBank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSkeletalAudioComponent")
	bool bShouldIgnoreDilation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSkeletalAudioComponent")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSkeletalAudioComponent")
	bool bShouldAttachOneShots;

	UPROPERTY(BlueprintReadOnly, Category="FortSkeletalAudioComponent")
	TArray<FSkeletalAudioBoneInstance> BoneInstances;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSkeletalAudioComponent", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh;

	UPROPERTY(BlueprintAssignable, Category="Physics Audio")
	FOnLoopSoundTriggered OnLoopSoundTriggered;

	UPROPERTY(BlueprintAssignable, Category="Physics Audio")
	FOnLoopSoundModulated OnLoopSoundModulated;

	UPROPERTY(BlueprintAssignable, Category="Physics Audio")
	FOnMediumSoundTriggered OnMediumSoundTriggered;

	UPROPERTY(BlueprintAssignable, Category="Physics Audio")
	FOnHeavySoundTriggered OnHeavySoundTriggered;

};

