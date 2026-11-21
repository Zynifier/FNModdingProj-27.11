// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortTeamEnum.h"
#include "FortCheckPointSplineActor.generated.h"

class USplineComponent;
class USplineMeshComponent;

UCLASS(BlueprintType)
class AFortCheckPointSplineActor : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	TArray<FVector> GetCheckPointLocations() const;

	UFUNCTION(BlueprintImplementableEvent)
	USplineComponent* GetSplineComponent() const;

	UFUNCTION(BlueprintCallable)
	void HideMapUI();

	UFUNCTION(BlueprintCallable)
	void HideSplineMeshes();

	UFUNCTION(BlueprintCallable)
	void ShowFullMapUI();

	UFUNCTION(BlueprintCallable)
	void ShowMapUI(int32 SplineIndexStart, int32 SplineIndexEnd);

	UFUNCTION(BlueprintCallable)
	void ShowSplineMeshes(int32 SplineIndexStart, int32 SplineIndexEnd);

protected:
	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	bool bSmoothSplineMesh;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	float SplineMeshTension;

	UPROPERTY(EditAnywhere, Category="SplineMesh")
	bool bShowSplineMeshAtStartup;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USplineMeshComponent>> SplineMeshComponents;

	UPROPERTY(EditDefaultsOnly, Category="Spline Map UI")
	bool bDrawSplineMapUI;

	UPROPERTY(EditDefaultsOnly, Category="Spline Map UI", meta=(EditCondition="bDrawSplineMapUI"))
	TMap<TEnumAsByte<EFortTeam::Type>, FLinearColor> SplineMapUITeamColors;

	UPROPERTY(EditDefaultsOnly, Category="Spline Map UI", meta=(EditCondition="bDrawSplineMapUI"))
	int32 NumSplineMapUISegments;

	UPROPERTY(EditDefaultsOnly, Category="Spline Map UI", meta=(EditCondition="bDrawSplineMapUI"))
	float SplineMapUIThickness;

	UPROPERTY(EditDefaultsOnly, Category="Spline Map UI", meta=(EditCondition="bDrawSplineMapUI"))
	bool bSplineMapUIAntialias;

};

