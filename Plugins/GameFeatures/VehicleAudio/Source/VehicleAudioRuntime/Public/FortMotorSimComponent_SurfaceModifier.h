// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IAudioMotorSim.h"
#include "Math/MathFwd.h"
#include "FortMotorSimComponent_SurfaceModifier.generated.h"

class UCurveFloat;

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class VEHICLEAUDIORUNTIME_API UFortMotorSimComponent_SurfaceModifier : public UAudioMotorSimComponent
{
	GENERATED_BODY()

public:
	UFortMotorSimComponent_SurfaceModifier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortMotorSimComponent_SurfaceModifier")
	TObjectPtr<UCurveFloat> CurrentCurve;

private:
	UFUNCTION(BlueprintCallable)
	void SetSurface(FName NewSurface);

	UPROPERTY(EditAnywhere, Category="FortMotorSimComponent_SurfaceModifier")
	TMap<FName, TObjectPtr<UCurveFloat>> Surfaces;

	UPROPERTY(EditAnywhere, Category="FortMotorSimComponent_SurfaceModifier", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	FVector2f ThrottleRange;

	UPROPERTY(EditAnywhere, Category="FortMotorSimComponent_SurfaceModifier", meta=(ClampMin="0.000000"))
	float OnsetInterpTime;

};

