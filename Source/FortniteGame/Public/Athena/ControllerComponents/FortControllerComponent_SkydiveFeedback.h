// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/ControllerComponents/FortControllerComponent_HasCoupledWidgets.h"
#include "FortTypes.h"
#include "FortControllerComponent_SkydiveFeedback.generated.h"

class ULegacyCameraShake;

UENUM(BlueprintType)
enum class ESkydiveFeedbackPhase : uint8
{
	Initial = 0,
	WithGlider = 1,
	InVortex = 2,
	None = 3,
};

USTRUCT()
struct FSkydiveFeedbackData : public FFortChangeMonitoringStruct
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_SkydiveFeedback : public UFortControllerComponent_HasCoupledWidgets
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> SkydiveCamShake;

	UPROPERTY(EditAnywhere, Category="FortControllerComponent_SkydiveFeedback")
	TSubclassOf<ULegacyCameraShake> SkydiveCamShakeClass;

	UPROPERTY(EditAnywhere, Category="FortControllerComponent_SkydiveFeedback")
	float DropSpeedForMinShakeMultiplier;

	UPROPERTY(EditAnywhere, Category="FortControllerComponent_SkydiveFeedback")
	float DropSpeedForMaxShakeMultiplier;

	UPROPERTY(EditAnywhere, Category="FortControllerComponent_SkydiveFeedback")
	float DropSpeedBlendExponent;

	UPROPERTY(Transient)
	float CachedSkydiveDropSpeedMin;

	UPROPERTY(Transient)
	float CachedSkydiveDropSpeedMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscPitchMinAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscPitchMaxAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscYawMinAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscYawMaxAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscRollMinAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscRollMaxAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscPitchMinFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscPitchMaxFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscYawMinFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscYawMaxFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscRollMinFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat RotOscRollMaxFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscXMinAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscXMaxAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscYMinAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscYMaxAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscZMinAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscZMaxAmplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscXMinFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscXMaxFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscYMinFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscYMaxFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscZMinFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Oscillation")
	FScalableFloat TransOscZMaxFreq;

};

