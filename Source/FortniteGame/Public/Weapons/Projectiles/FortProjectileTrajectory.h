// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortProjectileTrajectory.generated.h"

class USplineComponent;
class USplineMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortProjectileTrajectory : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Trajectory")
	void SetTrajectorySpline(const TArray<FVector>& SplinePoints, const TArray<FVector>& SplineTangents);

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Trajectory", meta=(EditInline="true"))
	TObjectPtr<USplineComponent> SplineComponent;

	UPROPERTY(EditDefaultsOnly, Category="Trajectory")
	TSubclassOf<USplineMeshComponent> SplineMeshComponentClass;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Trajectory", meta=(EditInline="true"))
	TArray<TObjectPtr<USplineMeshComponent>> SplineMeshComponents;

	UPROPERTY(EditDefaultsOnly, Category="Trajectory")
	int32 MaxSplineMeshesToCreate;

};

