// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "FortGravityGunHolder.generated.h"

class AActor;
class AController;
class AFortProjectileBase;
class AFortProjectileTrajectory;
class UFortLayeredAudioComponent;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EGravityGunHolderObjectType : uint8
{
	Invalid = 0,
	PhysicsObject = 1,
	Vehicle = 2,
	Projectile = 3,
	PickUp = 4,
};

UENUM(BlueprintType)
enum class EGravityGunHolderRotationAxis : uint8
{
	XZ = 0,
	YZ = 1,
	ZX = 2,
	MAX = 3,
};

UENUM(BlueprintType)
enum class EGravityGunHolderState : uint8
{
	Invalid = 0,
	Unrooting = 1,
	Catching = 2,
	Holding = 3,
	Detached = 4,
};

USTRUCT()
struct FGravityGunVelocityAudioMapRangeClamped
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GravityGunVelocityAudioMapRangeClamped")
	FVector2D InRange;

	UPROPERTY(EditDefaultsOnly, Category="GravityGunVelocityAudioMapRangeClamped")
	FVector2D OutRange;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortGravityGunHolder : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Gravity Holder")
	AActor* AttemptCloneActorToHold(AActor* InActor) const;

	UFUNCTION(BlueprintCallable)
	void CalculateLaunchVelocity(const bool bDropped, float& OutThrowSpeed, FVector& OutVelocity);

	UFUNCTION(BlueprintImplementableEvent)
	void DetachHeldObject();

	UFUNCTION()
	void LogHeldBuildingObjectDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void LogHeldObjectDestroyed(AActor* InHeldObjectDestroying);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateAudio(const float DeltaSeconds);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateFX(const float DeltaSeconds);

	UPROPERTY(BlueprintReadWrite, Category="FortGravityGunHolder")
	TObjectPtr<AActor> OwningPlayer;

	UPROPERTY(BlueprintReadOnly, Category="FortGravityGunHolder")
	TObjectPtr<AActor> HeldObject;

	UPROPERTY(BlueprintReadWrite, Category="FortGravityGunHolder")
	TSubclassOf<AFortProjectileBase> HeldObjectProjectileClass;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortGravityGunHolder", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> CachedLayeredAudioComponent;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FGravityGunVelocityAudioMapRangeClamped VelocityAudioRangeClamped;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Export, Category="FortGravityGunHolder", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> PivotComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Export, Category="FortGravityGunHolder", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> RingPivotComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Export, Category="FortGravityGunHolder", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> RingSMComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Export, Category="FortGravityGunHolder", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> Ring1SMComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Export, Category="FortGravityGunHolder", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> Ring2SMComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Export, Category="FortGravityGunHolder", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> Ring3SMComponent;

	UPROPERTY(BlueprintReadWrite, Category="FortGravityGunHolder")
	EGravityGunHolderState CurrentState;

	UPROPERTY(BlueprintReadWrite, Category="FortGravityGunHolder")
	EGravityGunHolderObjectType ObjectTypeHeld;

	UPROPERTY(BlueprintReadWrite, Category="FortGravityGunHolder")
	bool bAimingDownSights;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat HoldForwardDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat HoldUpDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat HoldUpDistanceWhileADS;

	UPROPERTY(BlueprintReadWrite, Category="Update Location")
	float MaxAxisLength;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat MaxAxisLengthPercent;

	UPROPERTY(BlueprintReadWrite, Category="Update Location")
	float CurrentRingSizeInUnits;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat MoveSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat MoveSpeedWhileADS;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat MaxMoveSpeedToGoal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat StabilizationCoefficient;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat StabilizationCoefficientWhileADS;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat RingRightDistanceScalar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat FollowSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat VehicleFollowSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat VehicleBroadcastImpactAtLocationRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat MaxDistanceBeforeDetach;

	UPROPERTY(BlueprintReadWrite, Category="Update Location")
	float TimeWhenStartedHolding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Location")
	FScalableFloat MaxHoldTimeForDetach;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Ring Rotation")
	FScalableFloat RingRotationSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Ring Rotation")
	FScalableFloat RingRotationSpeedWhileADS;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Calculate Launch Velocity")
	FScalableFloat ThrowSpeed;

	UPROPERTY(BlueprintReadWrite, Category="Calculate Launch Velocity")
	float LaunchSpeedMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="Calculate Launch Velocity")
	float VehicleLaunchSpeedMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="Update Rotation")
	bool bUseCameraRightAsReference;

	UPROPERTY(BlueprintReadWrite, Category="Update Rotation")
	bool bAllowRotation;

	UPROPERTY(BlueprintReadWrite, Category="Update Rotation")
	EGravityGunHolderRotationAxis CurrentRotationAxisIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Rotation")
	FScalableFloat TargetRotationTorqueStiffness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Rotation")
	FScalableFloat TargetRotationTorqueDampening;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Rotation")
	FScalableFloat TargetRotationTorqueMaxAccel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Rotation")
	FScalableFloat TargetRotationTorqueDeltaTimeScalar;

	UPROPERTY(BlueprintReadWrite, Category="Update Projectile Trajectory")
	TObjectPtr<AFortProjectileTrajectory> TrajectorIndicator;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	FScalableFloat TrajectorySplineFriction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	FScalableFloat TrajectorySplineBounciness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	FScalableFloat TrajectorySplineTimeStep;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	FScalableFloat TrajectorySplineTraceExtent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	TEnumAsByte<ECollisionChannel> TrajectorySplineTraceChannel;

	UPROPERTY(BlueprintReadWrite, Category="Update Projectile Trajectory")
	TArray<TObjectPtr<AActor>> TrajectorySplineExtraIgnoreActors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	FScalableFloat TrajectorySplineMaxBounces;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	FScalableFloat TrajectorySplineMaxSteps;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	FScalableFloat TrajectorySplineMaxDistanceBetweenSplinePoints;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Update Projectile Trajectory")
	FScalableFloat TrajectorySplineInitialDistance;

private:
	UFUNCTION(BlueprintCallable, Category="Gravity Gun Holder Methods")
	void HandleThrowHeldObject();

	UFUNCTION()
	void HeldObjectHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable, Category="Gravity Gun Holder Methods")
	void SetHeldObject(AActor* InHeldObject);

	UPROPERTY(BlueprintReadWrite, Category="Update Location", meta=(AllowPrivateAccess="true"))
	float CachedHoldForwardDistance;

	UPROPERTY(BlueprintReadWrite, Category="Update Location", meta=(AllowPrivateAccess="true"))
	float CachedHoldUpDistance;

	UPROPERTY(BlueprintReadWrite, Category="Update Location", meta=(AllowPrivateAccess="true"))
	float CachedHoldUpDistanceWhileADS;

	UPROPERTY(BlueprintReadWrite, Category="Update Rotation", meta=(AllowPrivateAccess="true"))
	float CachedTargetRotationTorqueDeltaTimeScalar;

};

