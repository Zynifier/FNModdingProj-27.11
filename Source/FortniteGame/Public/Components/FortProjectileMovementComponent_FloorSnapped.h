// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Engine/TimerHandle.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Components/FortProjectileMovementComponent.h"
#include "FortProjectileMovementComponent_FloorSnapped.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSteepSlopeWasHit, const FHitResult&, SlopeHitResult);

UCLASS(MinimalAPI)
class UFortProjectileMovementComponent_FloorSnapped : public UFortProjectileMovementComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintAssignable, Category="Deflection")
	FOnSteepSlopeWasHit OnSteepSlopeWasHit;

private:
	UFUNCTION()
	void OnRep_CurrentGravity();

	UPROPERTY(EditDefaultsOnly, Category="Deflection")
	FScalableFloat MaxClimbableSlope;

	UPROPERTY(EditDefaultsOnly, Category="Gravity")
	FScalableFloat GravityScaleAfterTouchedFloor;

	UPROPERTY(EditDefaultsOnly, Category="Deflection")
	float MaxPenetrationDepthAllowedForSliding;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentGravity)
	float ReplicatedGravity;

	UPROPERTY(EditDefaultsOnly, Category="Movement Correction")
	float CorrectionDuration;

	UPROPERTY(EditDefaultsOnly, Category="Movement Correction")
	float CorrectionUpSpeed;

	UPROPERTY(Transient)
	bool bNeedsCorrection;

	UPROPERTY(Transient)
	int32 NumFramesNotMoved;

	UPROPERTY(EditDefaultsOnly, Category="Stuck Detection")
	int32 NumFramesNotMovedToConsiderStuck;

	UPROPERTY(Transient)
	FVector LastRecordedLocation;

	UPROPERTY(Transient)
	float TimeElapsedSinceCorrectionStarted;

	UPROPERTY(Transient)
	FTimerHandle DebugCorrectionDrawingTimerHandle;

};

