// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScalableFloat.h"
#include "FortSkyTube.generated.h"

class AActor;
class UMeshComponent;
class USplineComponent;

UENUM(BlueprintType)
enum class ESkyTubeMovementDirection : uint8
{
	// Movement backward or forward through the tube

	BothWays = 0,
	// Movement in the direction of the spline tangent

	Forward = 1,
	// Movement in the opposite direction of the spline tangent.

	Reverse = 2,
};

USTRUCT()
struct FSkyTubeConfig
{
	GENERATED_BODY()

};

USTRUCT()
struct FSkyTubeMagnetismVelocityDebugData
{
	GENERATED_BODY()

};

USTRUCT()
struct FSkyTubeSplineComponentData
{
	GENERATED_BODY()

};

USTRUCT()
struct FSkyTubeSplineData
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class AFortSkyTube : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void DeferredEnableOverlaps();

	UFUNCTION(BlueprintPure, Category="SkyTube")
	float GetDelayUntilDisabled() const;

	UFUNCTION(BlueprintImplementableEvent, Category="SkyTube")
	void HandleForcedExit(AActor* ExitingPawn);

	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsExemptFromShutdown() const;

	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsShuttingDown() const;

	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsSkyTubeEnabled() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnabledChanged();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnStartShuttingDown();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="SkyTube", meta=(EditInline="true"))
	TObjectPtr<USplineComponent> Spline;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat ExitAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat ExitGravity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat TangentialAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat TangentialMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat TangentialMinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube")
	bool bApplyTangentialForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat MaxEntrySpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat MaxPerpendicularEntrySpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat EntryBiasTowardTangent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat EntryVelocityAngleRequired;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMax="90.000000", ClampMin="0.000000", UIMax="90.000000", UIMin="0.000000"))
	FScalableFloat ActiveForwardSteeringAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube")
	ESkyTubeMovementDirection AllowedMovementDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube")
	FScalableFloat InnerMagnetRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube")
	FScalableFloat OuterMagnetAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube")
	FScalableFloat InnerMagnetDecel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube")
	FScalableFloat OuterMagnetSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube")
	FScalableFloat InnerMagnetSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTubeProjectiles")
	FScalableFloat ProjectileTangentialMinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTubeProjectiles")
	FScalableFloat ProjectileTangentialMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTubeProjectiles")
	FScalableFloat SpiralAccelerationProjectiles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTubeProjectiles")
	FScalableFloat ProjectileForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTubeProjectiles")
	FScalableFloat ProjectileEntryMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTubePhysics")
	FScalableFloat SpiralAccelerationPhysics;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTubePhysics")
	FScalableFloat PhysicsForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTubePhysics")
	FScalableFloat PhysicsEntryMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat MagnetMaxReductionFromSteering;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat MagnetMaxMultiplierWhenSteering;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMax="90.000000", ClampMin="0.000000", UIMax="90.000000", UIMin="0.000000"))
	FScalableFloat SteeringMagnetMaxSteerAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMin="0.000000", UIMin="0.000000"))
	FScalableFloat MagnetLowVelocityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat MagnetLowVelocityMinValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMin="1.000000", UIMin="1.000000"))
	FScalableFloat SteeringReduceAccelerationPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkyTube", meta=(ClampMin="1.000000", UIMin="1.000000"))
	FScalableFloat SteeringReduceDecelerationPower;

	UPROPERTY(EditAnywhere, Category="SkyTube")
	FScalableFloat MovementRestrictionRadius;

protected:
	UFUNCTION(BlueprintCallable)
	void AddNonSkyTubeMeshComponent(const UMeshComponent* MeshComponent);

	UFUNCTION(BlueprintPure)
	bool IsMeshComponentPartOfSkyTube(const UMeshComponent* MeshComponent) const;

	UPROPERTY(EditAnywhere, Category="SkyTube")
	bool bExemptFromShutdown;

	UPROPERTY()
	bool bEnabled;

	UPROPERTY()
	bool bShuttingDown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SkyTube")
	FScalableFloat bCanEverBeEnabled;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UMeshComponent>> NonSkyTubeMeshComponents;

private:
	UPROPERTY()
	FSkyTubeConfig CachedSkyTubeConfig;

};

