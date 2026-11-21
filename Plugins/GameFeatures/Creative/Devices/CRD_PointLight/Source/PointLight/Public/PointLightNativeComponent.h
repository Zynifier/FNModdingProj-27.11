// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TimerHandle.h"
#include "Math/Color.h"
#include "PointLightNativeComponent.generated.h"

class ULightComponent;
class UStaticMeshComponent;
class UTimelineComponent;

UENUM(BlueprintType)
enum class EPointLightDeviceLightType : uint8
{
	Point = 0,
	Spot = 1,
};

UENUM(BlueprintType)
enum class EPointLightDeviceModes : uint8
{
	/** Continuous color */
	Constant = 0,
	/** Slight color and intensity variations */
	Flicker = 1,
	/** Sine wave intensity variation */
	Wave = 2,
	/** Sudden flashes of high and low intensity values */
	ShortCircuit = 3,
	/** Switch between colors */
	Party = 4,
	/** Light moves from side to side */
	Windy = 5,
	/** Light flashes On and Off */
	Flash = 6,
};

USTRUCT(BlueprintType)
struct FPointLightRhythmParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PointLightRhythmParameters")
	FLinearColor LightColor;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="PointLightRhythmParameters", meta=(EditInline="true"))
	TObjectPtr<ULightComponent> ActiveLight;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="PointLightRhythmParameters", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(BlueprintReadWrite, Category="PointLightRhythmParameters")
	int32 ColorBands;

	UPROPERTY(BlueprintReadWrite, Category="PointLightRhythmParameters")
	float RhythmFrequencyValue;

	UPROPERTY(BlueprintReadWrite, Category="PointLightRhythmParameters")
	float WindAmplitudeSpotLight;

	UPROPERTY(BlueprintReadWrite, Category="PointLightRhythmParameters")
	float FlashFactor;

	UPROPERTY(BlueprintReadWrite, Category="PointLightRhythmParameters")
	float SizeBasedIntensity;

	UPROPERTY(BlueprintReadWrite, Category="PointLightRhythmParameters")
	EPointLightDeviceLightType LightType;

	UPROPERTY(BlueprintReadWrite, Category="PointLightRhythmParameters")
	EPointLightDeviceModes RhythmMode;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class POINTLIGHT_API UPointLightNativeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void StartRhythmUpdate(FTimerHandle& TimerHandle, float Rate);

	UFUNCTION(BlueprintCallable)
	void StartShortCircuitUpdate(UTimelineComponent* ShortCircuitTimeline);

	UFUNCTION(BlueprintCallable)
	void StopShortCircuitUpdate();

	UFUNCTION(BlueprintCallable)
	void UpdateDeviceSettings(const FPointLightRhythmParameters& RhythmParameters);

	UPROPERTY(EditAnywhere, Category="Rhythm")
	FLinearColor FlickerColor;

	UPROPERTY(EditAnywhere, Category="Rhythm")
	float ShortCircuitMinDelay;

	UPROPERTY(EditAnywhere, Category="Rhythm")
	float ShortCircuitMaxDelay;

private:
	UFUNCTION()
	void UpdateShortCircuit();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UTimelineComponent> ShortCircuitTimelineComponent;

};

