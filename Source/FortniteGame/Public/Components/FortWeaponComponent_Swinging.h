// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Components/FortWeaponComponent.h"
#include "FortWeaponComponent_Swinging.generated.h"

class AActor;
class UGameplayEffect;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeaponComponent_Swinging : public UFortWeaponComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CancelForgivenessTimer();

	UFUNCTION(BlueprintCallable)
	void ForceEndForgivenessTimer();

	UFUNCTION(BlueprintPure)
	bool IsActorPullable(const AActor* Actor) const;

	UFUNCTION(BlueprintPure)
	bool IsForgivenessTimerActive() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDetachTooClose();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDetachTooSlow();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitGround();

	UFUNCTION(BlueprintImplementableEvent)
	void OnForgivenessTimerCanceled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnForgivenessTimerFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnForgivenessTimerStarted();

	UFUNCTION()
	void OnSingleFire();

	UFUNCTION()
	void OnSpawnedProjectile();

	UFUNCTION(BlueprintCallable)
	void SetForgivenessTimer(const float NewTimer);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTargetingResults(const FHitResult& HitResult, const bool bHitSomething);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateReticle(const bool bHitSomething, const bool bUseBlocked, const bool bIsWeaponAimingAtTarget, const FVector& TargetPos);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	float CurForgivenessTimer;

protected:
	UFUNCTION(Server, Reliable)
	void ServerSetTargetingResults(const FHitResult& HitResult, const bool bHitSomething);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	FHitResult TargetingHitResult;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	bool bFoundTarget;

	UPROPERTY(Transient)
	bool bMaintainCurrentTargetAfterSweeps;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	FVector CameraLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	FVector CameraDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	FVector LastTargetPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	bool bGrounded;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	bool bFastSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponComponent_Swinging")
	float TimeBelowDetachSpeedThreshold;

	UPROPERTY(EditDefaultsOnly, Category="DetachTooSlow")
	FScalableFloat SpeedThresholdDetachTooSlow;

	UPROPERTY(EditDefaultsOnly, Category="DetachTooSlow")
	FScalableFloat TimeThresholdDetachTooSlow;

	UPROPERTY(EditDefaultsOnly, Category="DetachTooSlow")
	FScalableFloat DetachTooSlowMaxDotUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat LineTraceStartOffsetFromCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat MaxRangeMultiplierBasedOnHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat SphereTraceOneStartOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat TargetOutOfRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat SphereTraceOneRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat SphereTraceTwoRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat SphereTraceOneRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat SphereTraceTwoRadius;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	FScalableFloat SpeedLinesThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	FScalableFloat GroundedThreshold;

	UPROPERTY(EditDefaultsOnly, Category="ProximityDetach")
	FScalableFloat MaxDotForProximityDetach;

	UPROPERTY(EditDefaultsOnly, Category="ProximityDetach")
	FScalableFloat DistanceForProximityDetach;

	UPROPERTY(EditDefaultsOnly, Category="ProximityDetach")
	FScalableFloat MinSpeedForProximityDetach;

	UPROPERTY(EditDefaultsOnly, Category="ProximityDetach")
	FScalableFloat DotForValidTargetPosition;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	FGameplayTag SpeedLinesTag;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	FGameplayTag UseIsBlocked;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	FGameplayTag SwingInputHeld;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> SpeedLinesGE;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat bAllowTargetWalkableTerrain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	bool bCheckForCloseDetach;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat bAllowTargetNonBGAStaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat bAllowTargetSplineMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat bAllowTargetVehicles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat bAllowTargetProjectiles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat bAllowTargetPullablesWhileSwinging;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat bAllowTargetPickups;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat bAllowTargetRebootCards;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FScalableFloat AngleFromTargetForSphereSweep;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	FName TargetingDenyListedActorTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Cooldown Timer Data")
	FScalableFloat DefaultForgivenessTimer;

};

