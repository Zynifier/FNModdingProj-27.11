// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraMode.h"
#include "Fort3PCameraMode.generated.h"

USTRUCT(BlueprintType)
struct FPenetrationAvoidanceFeeler
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PenetrationAvoidanceFeeler")
	FRotator AdjustmentRot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PenetrationAvoidanceFeeler")
	float WorldWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PenetrationAvoidanceFeeler")
	float PawnWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PenetrationAvoidanceFeeler")
	float Extent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PenetrationAvoidanceFeeler")
	int32 TraceInterval;

	UPROPERTY(Transient)
	int32 FramesUntilNextTrace;

};

USTRUCT(BlueprintType)
struct FViewOffsetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ViewOffsetData")
	FVector OffsetHigh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ViewOffsetData")
	FVector OffsetMid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ViewOffsetData")
	FVector OffsetLow;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFort3PCameraMode : public UFortCameraMode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FPenetrationAvoidanceFeeler> PenetrationAvoidanceFeelers;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	FViewOffsetData ViewOffsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	float FOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	FVector SafeLocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	uint8 bValidateSafeLoc : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	uint8 bDoPredictiveAvoidance : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	uint8 bPreventPenetration : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	float PenetrationBlendInTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	float PenetrationBlendOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	FVector PivotLocInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	float PivotRotInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	float FOVInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	float ViewOffsetInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort3PCameraMode")
	float SafeLocationInterpSpeed;

private:
	UPROPERTY(Transient)
	FVector LastActualViewOffset;

	UPROPERTY(Transient)
	FVector LastIdealViewOffset;

	UPROPERTY(Transient)
	FVector LastSafeLocationLocal;

	UPROPERTY(Transient)
	FVector LastSafeLocation;

	UPROPERTY(Transient)
	float LastSafeLocBlockedPct;

	UPROPERTY(Transient)
	float LastPenetrationBlockedPct;

	UPROPERTY(Transient)
	FVector LastActualPivotLoc;

	UPROPERTY(Transient)
	FRotator LastActualPivotRot;

	UPROPERTY(Transient)
	FVector LastIdealPivotLoc;

	UPROPERTY(Transient)
	FRotator LastIdealPivotRot;

};

