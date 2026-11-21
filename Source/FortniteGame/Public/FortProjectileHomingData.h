// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortProjectileHomingData.generated.h"

class AActor;

UENUM(BlueprintType)
enum class EFortHomingStyle : uint8
{
	None = 0,
	LockOn = 1,
	LaserTargeted = 2,
	LaserTargeted_NoTrace = 3,
	DrunkArtillery = 4,
};

USTRUCT(BlueprintType)
struct FProjectileHomingData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	EFortHomingStyle HomingStyle;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	float MinTurnSpeed;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	float MaxTurnSpeed;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	float RampTimeFromMinToMaxTurnSpeed;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	float LockTargetDistanceThreshold;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	int32 RandomSeed;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	TWeakObjectPtr<AActor> LockedOnTarget;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	FVector LockedOnTargetPosition;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	FVector TargetOffset;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	bool bScaleTargetOffsetWithCapsuleHeight;

	UPROPERTY(BlueprintReadWrite, Category="ProjectileHomingData")
	bool ResetTurnSpeedTimer;

};

