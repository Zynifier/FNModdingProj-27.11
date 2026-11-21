// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "Math/MathFwd.h"
#include "FortTrackMovementComponent.generated.h"

class AFortTrack;
class USplineComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortLostTrack);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortOutOfTrack);

USTRUCT()
struct FTrackMovement
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> CurrentSpline;

	UPROPERTY(Transient)
	float DistanceAlongSpline;

	UPROPERTY(Transient)
	bool bReverseDirectionAlongSpline;

};

USTRUCT()
struct FRepTrackMovement : public FTrackMovement
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float Timestamp;

};

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortTrackMovementComponent : public UMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Track")
	void FlipDirection();

	UFUNCTION(BlueprintPure, Category="Track")
	float GetDistanceAlongSpline() const;

	UFUNCTION(BlueprintPure, Category="Track")
	USplineComponent* GetSpline() const;

	UFUNCTION(BlueprintPure, Category="Track")
	AFortTrack* GetTrack() const;

	UFUNCTION(BlueprintPure, Category="Track")
	bool IsReverseDirection() const;

	UPROPERTY(EditAnywhere, Category="Track")
	TObjectPtr<AFortTrack> OptionalEditorPlacedTrack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Track")
	FVector TrackSnapExtent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Track")
	FVector TurnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Track")
	float SplineLocationOffsetZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Track")
	float DiscoverSplineFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Track")
	float TrackVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Track")
	bool bReverseYawWhenReversedOnSpline;

	UPROPERTY(BlueprintAssignable, Category="Track")
	FFortOutOfTrack OnOutOfTrack;

	UPROPERTY(BlueprintAssignable, Category="Track")
	FFortLostTrack OnLostTrack;

	UPROPERTY(Transient)
	FTrackMovement TrackMovement;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedTrackMovement)
	FRepTrackMovement ReplicatedTrackMovement;

private:
	UFUNCTION()
	void OnRep_ReplicatedTrackMovement();

	UPROPERTY(Transient)
	float ClientPredictionSpeedModifier;

};

