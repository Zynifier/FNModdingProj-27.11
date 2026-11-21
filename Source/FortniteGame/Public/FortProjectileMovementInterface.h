// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortProjectileHomingData.h"
#include "FortProjectileMovementInterface.generated.h"

class AActor;
class AFortPlayerController;
class UFortProjectileMovementComponent;
enum class EFortHomingStyle : uint8;

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortProjectileMovementInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortProjectileMovementInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile")
	FVector GetCurrentLocation() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile")
	UFortProjectileMovementComponent* GetFortProjectileMovementComponent() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile")
	AFortPlayerController* GetInstigatorPlayerController() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile")
	bool IsProjectileBeingKilled() const;

	UFUNCTION(BlueprintImplementableEvent, Category="ProjectileMovement")
	void OnHomingPassedTarget();

	UFUNCTION(BlueprintImplementableEvent, Category="ProjectileMovement")
	void OnReachedLockTargetDistanceThreshold();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetAccelerationMagnitude(AActor* SelfActor, const float InAccelerationMagnitude);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetDesiredDirection(AActor* SelfActor, const FVector& Direction);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingData(AActor* SelfActor, const FProjectileHomingData& NewHomingData);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingLaserTargetDistance(AActor* SelfActor, float NewDistance);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingLockTargetDistanceThreshold(AActor* SelfActor, float NewDistanceThreshold);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingStyle(AActor* SelfActor, EFortHomingStyle NewHomingStyle, bool ResetHomingTurnSpeedTimer);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingTarget(AActor* SelfActor, AActor* HomingTarget);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingTargetOffset(AActor* SelfActor, const FVector& NewHomingOffset);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingTargetPosition(AActor* SelfActor, const FVector& HomingTargetPosition);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingTimeUntilMaxTurnSpeed(AActor* SelfActor, float NewTimeUntilMax);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingTurnSpeedMax(AActor* SelfActor, float NewTurnSpeedMin);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Projectile", meta=(DefaultToSelf="SelfActor"))
	void SetHomingTurnSpeedMin(AActor* SelfActor, float NewTurnSpeedMin);

};

