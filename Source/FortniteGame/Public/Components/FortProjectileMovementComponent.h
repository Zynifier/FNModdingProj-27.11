// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/MathFwd.h"
#include "Core/FortManagedTickSubsystem.h"
#include "FortProjectileHomingData.h"
#include "FortProjectileMovementComponent.generated.h"

class AActor;
class AFortPawn;
class UFortWaterInteractionComponent;
enum class EFortHomingStyle : uint8;

USTRUCT()
struct FFortReplicatedVelocityData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 RepIncrement;

	UPROPERTY()
	FVector ReplicatedVelocity;

};

USTRUCT()
struct FFortStopSimulatingRepData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 RepIncrement;

	UPROPERTY()
	FVector StopLocation;

};

UCLASS(MinimalAPI, ClassGroup=("Movement"), meta=(BlueprintSpawnableComponent))
class UFortProjectileMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProjectileVelocityReplicated, const FVector&, ReplicatedVelocity);

public:
	UFUNCTION(BlueprintPure, Category="Projectile")
	EFortHomingStyle GetInitalHomingStyle() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetAccelerationMagnitude(const float InAccelerationMagnitude);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetDesiredDirection(const FVector& Direction);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingData(const FProjectileHomingData& NewHomingData);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingLaserTargetDistance(float NewDistance);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingLockTargetDistanceThreshold(float NewDistanceThreshold);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingStyle(EFortHomingStyle NewHomingStyle, bool ResetHomingTurnSpeedTimer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingTarget(AActor* HomingTarget);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingTargetOffset(const FVector& NewHomingOffset, const bool bScaleTargetOffsetWithCapsuleHeight = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingTargetPosition(const FVector& HomingTargetPosition);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingTimeUntilMaxTurnSpeed(float NewTimeUntilMax);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingTurnSpeedMax(float NewHomingTurnSpeedMax);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void SetHomingTurnSpeedMin(float NewHomingTurnSpeedMin);

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void SetReplicatedAutoRegisterUpdatedComponent(const bool bInReplicatedAutoRegisterUpdatedComponent);

	UFUNCTION(BlueprintCallable, Category="Projectile")
	virtual void SetVelocity(const FVector& InReplicatedVelocity);

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void SetWaterInteractionComponent(UFortWaterInteractionComponent* WaterComponent);

	UPROPERTY(BlueprintAssignable)
	FOnProjectileVelocityReplicated OnProjectileVelocityReplicated;

protected:
	UFUNCTION()
	void OnRep_FortStopSimulatingRepData();

	UFUNCTION()
	void OnRep_ReplicatedAutoRegisterUpdatedComponent();

	UFUNCTION()
	void OnRep_ReplicatedVelocity();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_HomingData)
	FProjectileHomingData HomingData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile")
	EFortHomingStyle InitialHomingStyle;

	UPROPERTY(Transient)
	bool bHasHomedTowardTarget;

	UPROPERTY(Transient)
	bool bSetInitialLocAndDir;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedAutoRegisterUpdatedComponent)
	uint8 bReplicatedAutoRegisterUpdatedComponent : 1;

	UPROPERTY(EditAnywhere, Category="Projectile")
	uint8 bReplicateStopSimulating : 1;

	UPROPERTY(Transient)
	float HomingLaserTargetDistance;

	UPROPERTY(Transient)
	float HomingTravelTime;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPawn> LockedOnTarget;

	UPROPERTY(Transient, Replicated)
	FVector DesiredDirection;

	UPROPERTY(Transient)
	FVector PreviousHomingTargetPosition;

	UPROPERTY(Transient)
	FVector LaunchPosition;

	UPROPERTY(Transient)
	FVector InitialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float StickyImpactAngle;

	UPROPERTY(EditAnywhere, Replicated, Category="Projectile")
	float AccelerationMagnitude;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedVelocity)
	FFortReplicatedVelocityData ReplicatedVelocityData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_FortStopSimulatingRepData)
	FFortStopSimulatingRepData FortStopSimulatingRepData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	bool bUseSurfaceMaterial;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWaterInteractionComponent> WaterInteractionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gravity In Water")
	bool bUseSeparateGravityScaleInWater;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gravity In Water")
	float GravityScaleInWater;

private:
	UFUNCTION()
	void OnRep_HomingData();

};

UCLASS(MinimalAPI)
class UFortProjectileMovementTickSubsystem : public UFortManagedComponentTickSubsystem
{
	GENERATED_BODY()

};

