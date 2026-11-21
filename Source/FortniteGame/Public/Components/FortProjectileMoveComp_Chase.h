// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortProjectileMovementComponent.h"
#include "FortProjectileMoveComp_Chase.generated.h"

class UCurveFloat;
class USceneComponent;

USTRUCT(BlueprintType)
struct FChaseExternalForce
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseExternalForce")
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseExternalForce")
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseExternalForce")
	float Magnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseExternalForce")
	TObjectPtr<UCurveFloat> MagnitudeScaleCurve;

};

UCLASS(MinimalAPI, ClassGroup=("Movement"), meta=(BlueprintSpawnableComponent))
class UFortProjectileMoveComp_Chase : public UFortProjectileMovementComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnChaseTargetReachedDelegate);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	void AddExternalForce(const FChaseExternalForce& ExternalForce);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Projectile")
	void ClearChaseTarget();

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void ClearExternalForces();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Projectile")
	void SetChaseTarget(USceneComponent* InChaseTarget, FName InSocketName, float InTargetReachedDistance, bool bInHomeOnChaseTarget = true);

	UPROPERTY(BlueprintAssignable)
	FOnChaseTargetReachedDelegate OnChaseTargetReached;

protected:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastAddExternalForce(const FChaseExternalForce& ExternalForce);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> InternalChaseTarget;

	UPROPERTY(Transient)
	FName ChaseTargetSocket;

	UPROPERTY(Transient)
	float ChaseTargetReachedDistance;

};

