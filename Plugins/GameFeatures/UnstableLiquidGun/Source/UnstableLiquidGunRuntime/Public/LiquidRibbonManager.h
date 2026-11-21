// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "LiquidRibbonManager.generated.h"

class AFortLiquidGunProjectile;
class UCurveFloat;
class UNiagaraComponent;

USTRUCT(BlueprintType)
struct FLiquidRibbonSplineSegment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineSegment")
	FVector A;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineSegment")
	FVector B;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineSegment")
	FVector C;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineSegment")
	FVector D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineSegment")
	float DirectLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineSegment")
	bool bHasDetachment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineSegment")
	TArray<FVector> PointPositions;

};

USTRUCT(BlueprintType)
struct FLiquidRibbonSplineDetachment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineDetachment")
	int32 FirstRibbonID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineDetachment")
	int32 SecondRibbonID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineDetachment")
	float TimeDetached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineDetachment")
	FLiquidRibbonSplineSegment Segment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineDetachment")
	FVector SegmentStartPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonSplineDetachment")
	FVector SegmentEndPoint;

};

UCLASS(BlueprintType, Blueprintable)
class ALiquidRibbonManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float CalculatePointFlashIntensity(const int32 PointSize) const;

	UFUNCTION(BlueprintPure)
	float CalculatePointSize(int32 SegmentIndex, int32 PointIndex) const;

	UFUNCTION(BlueprintCallable)
	TArray<FLiquidRibbonSplineSegment> CalculateSegments(const TArray<FVector>& Points, const float Tension);

	UFUNCTION(BlueprintCallable)
	void CalculateSplinePointsAndSetNiagaraData(const TArray<AFortLiquidGunProjectile*>& Projectiles, bool bAttachSplineToMuzzle, UNiagaraComponent* NiagaraComponent, TArray<FVector>& OutAllPositions, TArray<int32>& OutRibbonIDs, TArray<bool>& OutRibbonVisibilities, TArray<float>& OutFlashIntensities, TArray<int32>& OutRibbonSizes);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	int32 GetFirstVisiblePointIndex() const;

	UFUNCTION(BlueprintCallable)
	const FLiquidRibbonSplineDetachment& GetOrAddDetachment(const int32 RibbonID, const FLiquidRibbonSplineSegment& Segment);

	UFUNCTION(BlueprintPure)
	FVector GetPointOnSegment(float T, const FLiquidRibbonSplineSegment& Segment) const;

	UFUNCTION(BlueprintCallable)
	void RunSplineCollisionTestOnProjectiles();

	UFUNCTION(BlueprintPure)
	void SetNiagaraData(UNiagaraComponent* NiagaraComponent, const TArray<FVector>& Positions, const TArray<int32>& RibbonIDs, const TArray<bool>& RibbonVisibilities, const TArray<float>& FlashIntensities, const TArray<int32>& RibbonSizes) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonManager", meta=(ClampMin="2"))
	int32 PointsPerSegment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonManager")
	FScalableFloat MaxSegmentLengthBeforeBreak;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LiquidRibbonManager")
	float SplineCurveTension;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	float MinPointSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	float MaxPointSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	int32 NumPointsAtMinPointSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	int32 NumPointsAtMaxPointSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	float SplineLengthForSizeCalculation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	int32 NumPointsToTaperDownSplineEndSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	float MinSplineEndTaperSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	float TaperSizeAtDetachment_RemapClosenessToBreakageOldMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PointSize")
	float TaperSizeAtDetachment_RemapClosenessToBreakageOldMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlashIntensity")
	float MinPointSizePercentForFlashIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlashIntensity")
	float MaxPointSizePercentForFlashIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NiagaraParams")
	FName PositionsNiagaraParamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NiagaraParams")
	FName RibbonIDsNiagaraParamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NiagaraParams")
	FName RibbonVisibilitiesNiagaraParamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NiagaraParams")
	FName FlashIntensitiesNiagaraParamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NiagaraParams")
	FName RibbonSizesNiagaraParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Curling")
	FScalableFloat CalculateBaseCurlOffset_MaxSegmentLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Curling")
	FScalableFloat CalculateBaseCurlOffset_MaxTimeSinceDetachment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Curling")
	FScalableFloat CalculateBaseCurlOffset_TowardPerpendicularMult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Curling")
	FScalableFloat CalculateBaseCurlOffset_TowardEndMult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Curling")
	FScalableFloat CalculateBaseCurlOffset_TowardRandomMult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Curling")
	TObjectPtr<UCurveFloat> TimeSinceDetachmentCurlCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Curling")
	FScalableFloat TimeSinceDetachmentCurlCurve_MaxTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Curling")
	float CurlingMaxClosenessToBreakage;

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Category="LiquidRibbonManager")
	TArray<float> SegmentLengths;

	UPROPERTY(BlueprintReadWrite, Transient, Category="LiquidRibbonManager")
	TArray<FLiquidRibbonSplineDetachment> Detachments;

	UPROPERTY(BlueprintReadWrite, Transient, Category="LiquidRibbonManager")
	TArray<FLiquidRibbonSplineSegment> SplineSegments;

	UPROPERTY(BlueprintReadWrite, Transient, Category="LiquidRibbonManager")
	TArray<TObjectPtr<AFortLiquidGunProjectile>> Projectiles_Native;

};

