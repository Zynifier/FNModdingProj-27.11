// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/SpecialActor/NavArrow.h"
#include "HUDNavArrow.generated.h"

class UCurveFloat;
class UDestinationTrackerPawnComponent;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AHUDNavArrow : public ANavArrow
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void InitializeTrackerComponent(UDestinationTrackerPawnComponent* InDestinationComponent);

	UFUNCTION(BlueprintCallable)
	virtual void SetApproachRadius(const float InApproachRadius);

	UFUNCTION(BlueprintCallable)
	virtual void SetDepartRadius(const float InDepartRadius);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Location")
	FVector LocationRelativeToCamera;

	UPROPERTY(EditDefaultsOnly, Category="Location")
	FScalableFloat PitchRelativeToCamera;

	UPROPERTY(EditDefaultsOnly, Category="Location")
	FScalableFloat ArrowSizeRelativeToScreen;

	UPROPERTY(EditDefaultsOnly, Category="Location")
	FScalableFloat ArrowPlacementHeightRelativeToScreen;

	UPROPERTY(EditDefaultsOnly, Category="Animations")
	FScalableFloat DefaultApproachRadius;

	UPROPERTY(EditDefaultsOnly, Category="Animations")
	FScalableFloat DefaultDepartRadius;

	UPROPERTY(EditDefaultsOnly, Category="Animations")
	TObjectPtr<UCurveFloat> ScaleCurve;

	UPROPERTY(BlueprintReadWrite, Export, Category="StaticMesh", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> ArrowComponent;

};

