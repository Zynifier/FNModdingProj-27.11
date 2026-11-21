// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortSplineAudioActor.generated.h"

class UAudioComponent;
class USoundBase;
class USplineComponent;

UCLASS()
class AFortSplineAudioActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Update Culling")
	float UpdateFrequencyInaudible;

	UPROPERTY(EditAnywhere, Category="Update Culling")
	float UpdateFrequencyAudible;

	UPROPERTY(EditAnywhere, Category="Update Culling")
	float MaxAudibleRange;

	UPROPERTY(EditAnywhere, Category="Spline Properties")
	int32 NumSamplePoints;

	UPROPERTY(BlueprintReadOnly, Category="Spline Properties")
	TArray<FVector> SamplePoints;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> ClosestPointSound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> NextClosestPointSound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> MidPointSound;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSplineAudioActor", meta=(EditInline="true"))
	TObjectPtr<USplineComponent> AudioSpline;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSplineAudioActor", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioAtClosestPoint;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSplineAudioActor", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioAtNextClosestPoint;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSplineAudioActor", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioAtMidPoint;

};

