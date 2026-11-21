// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortMovementComp_GroundSpline.generated.h"

class AActor;
class UAbilitySystemComponent;
class UGameplayEffect;
class USplineComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrossedSplinePoint, int32, SplinePointIndex, bool, bWasMovingForward);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEndOfSplineReached, bool, bHitEndOfSpline);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHitActor, AActor*, HitActor);

USTRUCT()
struct FGroundSplineLocationData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float DistanceAlongSpline;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> SplineComponent;

	UPROPERTY(Transient)
	int32 TeleportRequestNum;

	UPROPERTY(Transient)
	float Timestamp;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FGroundSplineSpeedData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GroundSplineSpeedData")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GroundSplineSpeedData")
	float Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GroundSplineSpeedData")
	float YawSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GroundSplineSpeedData")
	float YawAcceleration;

	UPROPERTY(Transient)
	int32 SnapToNewSpeedRequestNum;

	UPROPERTY(Transient)
	float Timestamp;

};

UCLASS(Config=Game, BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortMovementComp_GroundSpline : public UMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ground Spline Movement")
	void ClientOnlySnapToServerLocationAndSpeed();

	UFUNCTION(BlueprintPure, Category="Ground Spline Movement")
	FGroundSplineSpeedData GetCurrentSpeeds() const;

	UFUNCTION(BlueprintPure, Category="Ground Spline Movement")
	USplineComponent* GetSpline() const;

	UFUNCTION(BlueprintPure, Category="Ground Spline Movement")
	float GetSplineDistance() const;

	UFUNCTION(BlueprintPure, Category="Ground Spline Movement")
	FGroundSplineSpeedData GetTargetSpeeds() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Ground Spline Movement")
	bool GetTransformAtDistanceOnSpline(FTransform& OutTransform, float Distance) const;

	UFUNCTION(BlueprintCallable, Category="Ground Spline Movement")
	void SetAbilitySystemComponent(UAbilitySystemComponent* NewAbilitySystemComponent);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Ground Spline Movement")
	void SetSpline(USplineComponent* NewTravelSpline, float NewDistanceOnSpline);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Ground Spline Movement")
	void SetTargetSpeeds(const FGroundSplineSpeedData& NewTargetSpeeds);

	UFUNCTION(BlueprintCallable, Category="Ground Spline Movement")
	void TeleportToDistanceOnSpline(USplineComponent* NewTravelSpline, float Distance);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ground Spline Movement")
	float SplineLocationOffsetZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ground Spline Movement")
	uint8 bOffsetZIsAbsolute : 1;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Replicated, Category="Ground Spline Movement")
	uint8 bTickGroundSplineMovement : 1;

	UPROPERTY(BlueprintAssignable, Category="Ground Spline Movement")
	FOnHitActor OnHitActor;

	UPROPERTY(BlueprintAssignable, Category="Ground Spline Movement")
	FOnEndOfSplineReached OnEndOfSplineReached;

	UPROPERTY(BlueprintAssignable, Category="Ground Spline Movement")
	FOnCrossedSplinePoint OnCrossedSplinePoint;

protected:
	UFUNCTION()
	void OnRep_ReplicatedSplineLocationData();

	UFUNCTION()
	void OnRep_ReplicatedTargetSpeeds();

	UPROPERTY(Config)
	int32 NumberOfMoveRetriesPerTick;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement", meta=(MinClamp="0.001000"))
	float ClimbSpeedPercent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float PitchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float PitchThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float PitchThresholdSmoothing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float LinearJerk;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float YawJerk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ground Spline Movement")
	float GroundCheckFrequency;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float GroundCheckDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float AttemptUnstickMinimumAngleDegrees;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement", meta=(MinClamp="0.001000"))
	float PawnPushTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float ClientImmediatelySnapToReplicatedLocationTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	float ClientImmediatelySnapToReplicatedLocationDistanceMinimumSquared;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ground Spline Movement", meta=(MinClamp="0.000000"))
	float PawnPushForceMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	TSubclassOf<UGameplayEffect> GameplayEffectClassDestroyBuildings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement")
	FGameplayTag TagDestroyBuildings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement", meta=(MinClamp="0.000000"))
	float SplineDistanceReplicationRecoveryPercent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement", meta=(MinClamp="0.000000"))
	float SplineDistanceReplicationRecoveryMinDistancePerSecond;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ground Spline Movement", meta=(MinClamp="0.000000"))
	float SpeedTimeReplicationRecoveryPercent;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedSplineLocationData)
	FGroundSplineLocationData ReplicatedSplineLocationData;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedTargetSpeeds)
	FGroundSplineSpeedData ReplicatedTargetSpeeds;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

};

