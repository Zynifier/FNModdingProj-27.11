// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScalableFloat.h"
#include "FortAthena_WaxToken.generated.h"

class AActor;
class USplineComponent;
class UStaticMeshComponent;

UENUM()
enum class EWaxTokenState : uint8
{
	None = 0,
	FirstSpline = 1,
	Interpolation = 2,
	LastSpline = 3,
	Finished = 4,
};

UCLASS()
class AFortAthena_WaxToken : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Mechanics")
	void OnReachedTarget();

	UFUNCTION(BlueprintImplementableEvent, Category="Mechanics")
	void OnStart();

	UFUNCTION(BlueprintImplementableEvent, Category="Mechanics")
	void OnUpdateToNewState();

	UPROPERTY(BlueprintReadOnly, Category="Mechanics")
	TObjectPtr<AActor> Target;

	UPROPERTY(BlueprintReadOnly, Category="Visuals")
	int32 PayloadCount;

	UPROPERTY(BlueprintReadOnly, Category="Mechanics")
	EWaxTokenState CurrentState;

	UPROPERTY(BlueprintReadOnly, Category="Mechanics", meta=(DisplayName="Current Time in State"))
	float TimeInState;

	UPROPERTY(BlueprintReadOnly, Category="Mechanics")
	float InterpolationSpeed;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Visuals", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> TokenMesh;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USplineComponent> EntrySpline;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USplineComponent> ExitSpline;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortAthena_WaxToken", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USplineComponent> ReusedSpline;

	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="Mechanics")
	TMap<EWaxTokenState, FScalableFloat> TravelTimeAtState;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat TotalTravelTime;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	FScalableFloat DistanceStopInterpolationAt;

};

