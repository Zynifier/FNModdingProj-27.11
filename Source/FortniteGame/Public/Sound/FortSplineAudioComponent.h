// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Sound/FortAudioShapeComponent.h"
#include "FortSplineAudioComponent.generated.h"

class UAudioComponent;
class USoundBase;
class USplineComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAudioUpdateInAudibleRange, UAudioComponent*, AudioComponent, float, SplineInputKey);

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortSplineAudioComponent : public UFortAudioShapeComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Spline")
	UAudioComponent* GetAudioComponent();

	UFUNCTION(BlueprintCallable, Category="Spline")
	void SetSpline(USplineComponent* NewSpline);

	UPROPERTY(EditAnywhere, Category="Spline")
	float TravelDistanceCrossfadeThreshold;

	UPROPERTY(EditAnywhere, Category="Spline")
	float TravelDistanceCrossfadeTime;

	UPROPERTY(EditAnywhere, Category="Asset")
	TObjectPtr<USoundBase> ClosestPointSound;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnAudioUpdateInAudibleRange OnAudioUpdateInAudibleRange;

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortSplineAudioComponent")
	FBox SplineAABB;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioComponent>> FadingComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> Spline;

};

