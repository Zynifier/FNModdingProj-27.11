// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "Math/MathFwd.h"
#include "FortVehicleAudioModulation.generated.h"

class UAudioComponent;
class UCurveFloat;
class USoundBase;

UENUM()
enum class EVehicleAudioInterpolationType : uint8
{
	None = 0,
	CustomCurve = 1,
	Linear = 2,
};

UENUM(BlueprintType)
enum class EVehicleAudioTriggerDir : uint8
{
	Forward = 0,
	Backward = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVehicleAudioVoiceOneShot, UAudioComponent*, AudioComponent, int32, Index);

USTRUCT(BlueprintType)
struct FFortVehicleAudioParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Data")
	float Value;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	EVehicleAudioInterpolationType InterpType;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	TObjectPtr<UCurveFloat> Curve;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	float AttackSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	float ReleaseSpeed;

};

USTRUCT(BlueprintType)
struct FFortVehicleAudioFloatParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Data")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FFortVehicleAudioParam Data;

};

USTRUCT(BlueprintType)
struct FFortVehicleAudioOneshotGate
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Data")
	float GateValue;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	EVehicleAudioTriggerDir Direction;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	bool FadeWhenOutsideGate;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	float MinTimeSinceTrigger;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	float InterruptFadeTime;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAudioComponent> AudioComp;

};

UCLASS(HideCategories=("Object", "ActorComponent", "Physics", "Rendering", "Mobility", "LOD", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortVehicleAudioVoice : public UAudioComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetParam(float Param);

	UFUNCTION(BlueprintCallable)
	void SetParamExplicit(FName Name, float Param);

	UFUNCTION(BlueprintCallable)
	void SetParamRange(float Min, float Max);

	UFUNCTION(BlueprintCallable)
	void StopAllAudio();

	UPROPERTY(EditDefaultsOnly, Category="Data")
	TObjectPtr<USoundBase> LoopingSound;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	bool bFadeWhenOwnerDestroyed;

	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(EditCondition="bFadeWhenOwnerDestroyed"))
	float FadeTimeWhenOwnerDestroyed;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	TArray<FFortVehicleAudioOneshotGate> OneshotGates;

	UPROPERTY(BlueprintAssignable, Category="Data")
	FOnVehicleAudioVoiceOneShot OnOneshotEvent;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	float OneShotGateInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FFortVehicleAudioParam VolumeParam;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FFortVehicleAudioParam PitchParam;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	TArray<FFortVehicleAudioFloatParam> FloatParams;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	TArray<FFortVehicleAudioFloatParam> ExplicitFloatParams;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FVector2D ParamRange;

};

