// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "IceGroundPath.generated.h"

class UBoxComponent;
class UMaterial;
class UStaticMesh;

UCLASS(BlueprintType, Blueprintable)
class AIceGroundPath : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddSplinePoint(FVector InWorldLoc);

	UFUNCTION(BlueprintPure)
	bool GetLastSplinePointLocation(FVector& LastPointLocation) const;

	UFUNCTION(BlueprintCallable)
	FVector GetLocationOnLandscape(FVector Location);

private:
	UFUNCTION()
	void OnRep_SplinePoints();

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	TObjectPtr<UMaterial> Material;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	TEnumAsByte<ESplineMeshAxis::Type> ForwardAxis;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SplinePoints)
	TArray<FVector_NetQuantize> SplinePoints;

	UPROPERTY(EditDefaultsOnly, Category="IceGroundPath")
	FVector SplineOffset;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	float SplineColliderExtentWidth;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	float SplineColliderExtentHeight;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	float LandscapeTraceBuffer;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UBoxComponent>> BoxColliderArray;

};

