// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "Math/MathFwd.h"
#include "FortLayeredAudioComponent.generated.h"

class UAudioComponent;
class UCurveFloat;
class UFortLayeredAudioComponent;
class USoundBase;

UENUM()
enum class ELayeredAudioInterpolationType : uint8
{
	None = 0,
	CustomCurve = 1,
	Linear = 2,
};

UENUM(BlueprintType)
enum class ELayeredAudioTriggerDir : uint8
{
	Forward = 0,
	Backward = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLayeredAudioComponentOneshot, UAudioComponent*, AudioComponent, FName, ParameterName, int32, OneshotIndex);

USTRUCT(BlueprintType)
struct FFortLayeredAudioOneshotGate
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Asset")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditDefaultsOnly, Category="Gate", meta=(ClampMax="0.900000", ClampMin="0.100000"))
	float GateValue;

	UPROPERTY(EditDefaultsOnly, Category="Gate")
	ELayeredAudioTriggerDir Direction;

	UPROPERTY(EditDefaultsOnly, Category="Gate")
	bool FadeWhenOutsideGate;

	UPROPERTY(EditDefaultsOnly, Category="Gate")
	float MinTimeSinceTrigger;

	UPROPERTY(EditDefaultsOnly, Category="Gate")
	float InterruptFadeTime;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAudioComponent> AudioComp;

};

USTRUCT(BlueprintType)
struct FFortLayeredAudioFloatParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Parameter")
	bool bEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Parameter", meta=(EditCondition="bEnabled"))
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="Paramater", meta=(DisplayName="Default Value", EditCondition="bEnabled"))
	float Value;

	UPROPERTY(EditDefaultsOnly, Category="Interpolation", meta=(EditCondition="bEnabled"))
	ELayeredAudioInterpolationType InterpType;

	UPROPERTY(EditDefaultsOnly, Category="Interpolation", meta=(EditCondition="InterpType == ELayeredAudioInterpolationType::CustomCurve", EditConditionHides))
	TObjectPtr<UCurveFloat> Curve;

	UPROPERTY(EditDefaultsOnly, Category="Interpolation", meta=(EditCondition="bEnabled"))
	float AttackSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Interpolation", meta=(EditCondition="bEnabled"))
	float ReleaseSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Paramater", meta=(EditCondition="bEnabled"))
	FVector2D ParamRange;

	UPROPERTY(EditDefaultsOnly, Category="Oneshots", meta=(EditCondition="bEnabled", TitleProperty="Sound"))
	TArray<FFortLayeredAudioOneshotGate> Oneshots;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> Owner;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "ActorComponent", "Physics", "Rendering", "Mobility", "LOD", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortLayeredAudioComponent : public UAudioComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ResetAllFloatParameters();

	UFUNCTION(BlueprintCallable)
	void ResetFloatParameter(FName Name);

	UFUNCTION(BlueprintCallable)
	void SetFloatParameterExt(FName Name, float Value);

	UFUNCTION(BlueprintCallable)
	void StopAllAudio();

	UPROPERTY(EditDefaultsOnly, Category="Data")
	bool bFadeWhenOwnerDestroyed;

	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(EditCondition="bFadeWhenOwnerDestroyed"))
	float FadeTimeWhenOwnerDestroyed;

	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(TitleProperty="Name"))
	TArray<FFortLayeredAudioFloatParam> FloatParameters;

	UPROPERTY(BlueprintAssignable, Category="Data")
	FOnLayeredAudioComponentOneshot OnOneshotEvent;

};

