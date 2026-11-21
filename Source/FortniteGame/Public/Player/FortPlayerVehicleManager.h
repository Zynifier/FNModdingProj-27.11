// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortPlayerVehicleManager.generated.h"

UENUM(BlueprintType)
enum class EVehicleTrickAxis : uint8
{
	//X Positive/Roll

	X = 0,
	//X Negative/Roll Negative

	XNeg = 1,
	//Y Positive/Pitch

	Y = 2,
	//Y Negative/Pitch Negative

	YNeg = 3,
	//Z Positive/Yaw

	Z = 4,
	//Z Negative/Yaw Negative

	ZNeg = 5,
	Count = 6,
};

UENUM(BlueprintType)
enum class EVehicleTrickType : uint8
{
	None = 0,
	RollIncrement = 1,
	ReverseRollIncrement = 2,
	YawIncrement = 3,
	ReverseYawIncrement = 4,
	PitchIncrement = 5,
	ReversePitchIncrement = 6,
	HeightIncrement = 7,
	DistanceIncrement = 8,
	AirTimeIncrement = 9,
	ShoppingCart_Flying = 10,
	ShoppingCart_Stooping = 11,
	//Here a timer starts to make sure they don't bounce or wipe out.  No credit yet...

	StartedLanding = 12,
	FailedLanding = 13,
	Cancelled = 14,
	//Credit given here.

	StuckLanding = 15,
	GenericTrick1 = 16,
	GenericTrick2 = 17,
	GenericTrick3 = 18,
	GenericTrick4 = 19,
	IncrementGenericTrick1 = 20,
	IncrementGenericTrick2 = 21,
	IncrementGenericTrick3 = 22,
	IncrementGenericTrick4 = 23,
	Count = 24,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FVehicleTrickInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float LastOnGroundTime;

	UPROPERTY(BlueprintReadWrite, Category="VehicleTrickInfo")
	float mCreditDisabledTime;

	UPROPERTY()
	int32 TrickScore;

	UPROPERTY()
	int32 TrickAxisCount;

	UPROPERTY()
	float AirControlsAlpha;

	UPROPERTY()
	float AirDistance;

	UPROPERTY()
	float AirDistanceSqrd;

	UPROPERTY()
	float AirTime;

	UPROPERTY()
	float AirHeight;

	UPROPERTY()
	float TimeAtLaunch;

	UPROPERTY()
	FVector LocationAtLaunch;

	UPROPERTY()
	FVector ForwardVectorAtLaunch;

	UPROPERTY()
	FVector UpVectorAtLaunch;

	UPROPERTY()
	FVector FlatForwardVectorAtLaunch;

	UPROPERTY()
	FVector PrevForwardVec;

	UPROPERTY()
	FVector PrevRightVec;

	UPROPERTY()
	FVector PrevUpVec;

	UPROPERTY(BlueprintReadWrite, Category="VehicleTrickInfo")
	int32 PeterPanCount;

	UPROPERTY(BlueprintReadWrite, Category="VehicleTrickInfo")
	int32 StoopingSquirrelCount;

	UPROPERTY(BlueprintReadWrite, Category="VehicleTrickInfo")
	uint8 bDidPeterPan : 1;

	UPROPERTY(BlueprintReadWrite, Category="VehicleTrickInfo")
	uint8 bDidStoopingSquirrel : 1;

	UPROPERTY()
	uint8 bInAirTrick : 1;

	UPROPERTY(BlueprintReadWrite, Category="VehicleTrickInfo")
	uint8 bCreditTrick : 1;

	UPROPERTY(BlueprintReadWrite, Category="VehicleTrickInfo")
	uint8 bTrickDeactivated : 1;

	UPROPERTY()
	uint8 bStuckLanding : 1;

	UPROPERTY()
	uint8 bDoingRotationTrick : 1;

};

USTRUCT()
struct FVehicleTrickLocalAxisRotInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Angle;

	UPROPERTY()
	int32 AccumulatedHalfSpinCount;

	UPROPERTY()
	float AccumulatedAngle;

	UPROPERTY()
	float AngleAtFurthestExtent;

	UPROPERTY()
	int32 TrickOrder;

	UPROPERTY()
	int32 Points;

};

