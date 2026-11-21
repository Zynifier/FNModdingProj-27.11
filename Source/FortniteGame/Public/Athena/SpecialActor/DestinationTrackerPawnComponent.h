// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "Math/MathFwd.h"
#include "DestinationTrackerPawnComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UDestinationTrackerPawnComponent : public UPawnComponent
{
	GENERATED_BODY()

public:
	UDestinationTrackerPawnComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void ClearDestination();

	UFUNCTION(BlueprintPure)
	const FVector& GetDestination() const;

	UFUNCTION(BlueprintPure)
	const FRotator& GetDirection() const;

	UFUNCTION(BlueprintPure)
	float GetDistanceSquared() const;

	UFUNCTION(BlueprintPure)
	bool HasDestination() const;

	UFUNCTION(BlueprintCallable)
	void SetDestination(const FVector& InDestination);

protected:
	UFUNCTION()
	void OnRep_Destination();

	UPROPERTY(ReplicatedUsing=OnRep_Destination)
	FVector Destination;

	UPROPERTY(Transient)
	float DistanceSquared;

	UPROPERTY(Transient)
	FRotator Direction;

};

