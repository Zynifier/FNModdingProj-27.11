// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Math/RandomStream.h"
#include "Components/FortProjectileMovementComponent.h"
#include "FortTypes.h"
#include "FortProjectileMoveComp_Drunk.generated.h"

UCLASS()
class UFortProjectileMoveComp_Drunk : public UFortProjectileMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetDrunkConfig(const FProjectileMovementDrunkConfig& NewConfig);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Drunk Movement")
	FProjectileMovementDrunkConfig DrunkConfig;

	UPROPERTY(Transient)
	float DrunkTravelTime;

	UPROPERTY(Transient)
	bool bDrunkDirectionChange;

	UPROPERTY(ReplicatedUsing=OnRep_RandSeed)
	int32 RandSeed;

	UPROPERTY(Transient)
	float DrunkDirectionChangeTimer;

	UPROPERTY(Transient)
	float DrunkHomingDirectionChangeTimer;

	UPROPERTY(Transient)
	FVector DrunkHomingTargetPosition;

	UPROPERTY(Transient)
	FRandomStream DrunkRandStream;

	UPROPERTY(Transient)
	float DrunkBlendOutMaxRange;

	UPROPERTY(Transient)
	bool bDoingTimeBasedBlendOut;

	UPROPERTY(Transient)
	float CachedBlendAlpha;

private:
	UFUNCTION()
	void OnRep_RandSeed();

};

