// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortAICloudVortex.generated.h"

class UParticleSystemComponent;
class USplineMeshComponent;

UCLASS(BlueprintType, Blueprintable, meta=(ChildCanTick))
class AFortAICloudVortex : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CloudVortex")
	void CalculateTwisterWiggle(double TickDelta);

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="CloudVortex", meta=(EditInline="true"))
	TArray<USplineMeshComponent*> SplineMeshesBody;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="CloudVortex", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> VortexBase;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="CloudVortex", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> VortexRing;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CloudVortex")
	TArray<FVector> SplinePointsA;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CloudVortex")
	TArray<FVector> SplinePointsB;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CloudVortex")
	TArray<FVector> SplineTangentsA;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CloudVortex")
	TArray<FVector> SplineTangentsB;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CloudVortex")
	TArray<double> TimeRandomArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CloudVortex", meta=(ExposeOnSpawn="TRUE"))
	float TwistOverTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CloudVortex", meta=(ExposeOnSpawn="TRUE"))
	int32 NumberOfSplinePoints;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CloudVortex", meta=(ExposeOnSpawn="TRUE"))
	bool bEnableVortexBaseParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CloudVortex", meta=(ExposeOnSpawn="TRUE"))
	bool bEnableVortexRingParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CloudVortex", meta=(ExposeOnSpawn="TRUE"))
	FVector BasePSOffset;

};

