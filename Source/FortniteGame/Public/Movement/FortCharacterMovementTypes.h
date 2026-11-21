// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCharacterMovementTypes.generated.h"

UENUM(BlueprintType)
namespace EChuteActions
{
	enum Type
	{
		None = 0,
		WantsToOpen = 1,
		WantsToClose = 2,
	};
}

UENUM(BlueprintType)
namespace EFortCustomMovement
{
	enum Type
	{
		Default = 0,
		Driving = 1,
		Passenger = 2,
		Parachuting = 3,
		Skydiving = 4,
		SkydiveFollowing = 5,
		Hover = 6,
		RemoteControl_Flying = 7,
		Ziplining = 8,
		ZipliningOnSpline = 9,
		Grinding = 10,
		Ballooning = 11,
		SurfaceSwimming = 12,
		DBNOCarried = 13,
		Floating = 14,
		Goop = 15,
		DeimosPreFall = 16,
		Sliding = 17,
		Skating = 18,
		Swinging = 19,
		SwingingGrounded = 20,
		SynchedAction = 21,
		Ridden = 22,
		FlyingRidden = 23,
		MovementExtension = 24,
		Count = 25 UMETA(Hidden),
	};
}

USTRUCT(BlueprintType)
struct FSynchedActionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SynchedActionInfo")
	FName WarpSyncPoint1Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SynchedActionInfo")
	FName WarpSyncPointLandingOrientationName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float DistanceToTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float DistanceToTargetX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float DistanceToTargetY;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float DistanceToTargetZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float AngleToTargetHorizontal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float DistanceWarpPoint1ToWarpPoint2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float DistanceWarpPoint1ToWarpPoint2X;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float DistanceWarpPoint1ToWarpPoint2Y;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float DistanceWarpPoint1ToWarpPoint2Z;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SynchedActionInfo")
	float StartingGroundAngle;

};

