// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "GravityGunTargetTrackingComponent.generated.h"

class AActor;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeactivateReticleDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoundTargetDelegate, AActor*, NewTarget);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UGravityGunTargetTrackingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void FindTargetActor(AActor* OwningPlayer, const FVector& TraceStart, const FVector& TraceEnd);

	UFUNCTION(BlueprintCallable, Category="Targeting")
	bool FindTargetProjectile(AActor* OwningPlayer, const FVector& TraceStart, const FVector& TraceEnd, float TargetingRadius);

	UFUNCTION(BlueprintCallable, Category="Targeting")
	bool IsValidTarget(AActor* OwningPlayer, AActor* PotentialTarget, FGameplayTagContainer& ReasonForFailure);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FScalableFloat AllowLargeObjects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FScalableFloat AllowMultipleGrabbers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FScalableFloat AllowVehicles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FScalableFloat AllowPickups;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FScalableFloat AllowProjectiles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FScalableFloat AllowForay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FScalableFloat AllowWhileInVehicle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FName GrabbedByGravityGunTagName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FGameplayTagContainer InvalidTargetTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FGameplayTagContainer TargetIsPlayerTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FGameplayTagContainer TargetIsAlreadyGrabbedTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	FGameplayTagContainer TargetIsOwnVehicleTag;

	UPROPERTY(BlueprintAssignable, Category="Targeting")
	FFoundTargetDelegate FoundTargetDelegate;

	UPROPERTY(BlueprintAssignable, Category="Targeting")
	FDeactivateReticleDelegate DeactivateReticleDelegate;

};

