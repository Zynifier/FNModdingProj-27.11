// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Building/BuildingGameplayActor.h"
#include "FortSplineGroundPath.generated.h"

class AFortSplineGroundPath;
class UCapsuleComponent;
class UMaterial;
class USplineMeshComponent;
class UStaticMesh;

USTRUCT()
struct FFortEvenlySizedSegment
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USplineMeshComponent> SplineMeshComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

};

USTRUCT()
struct FFortReppedPoint : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 LastServerIndex;

	UPROPERTY(Transient)
	float BurnTime;

	UPROPERTY(Transient)
	FVector_NetQuantize ReppedPoint;

};

USTRUCT()
struct FFortReppedPointList : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FFortReppedPoint> FortReppedPoints;

	UPROPERTY(Transient)
	TObjectPtr<AFortSplineGroundPath> FortSplineGroundPath;

};

USTRUCT()
struct FRawPointToLastServerIndexPlusAlpha
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float ReppedLastServerIndexPlusAlpha;

};

USTRUCT()
struct FReppedLastServerIndexToIndex
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 ReppedPointIdx;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortSplineGroundPath : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Creation")
	float MaxDistanceBetweenPathwayPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	float EvenlySpacedPointsDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	float TangentDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Update")
	float PathUpdateSecondIntervals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	float PathTestRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	float MinDistanceForAddingRawPoint;

	UPROPERTY(EditAnywhere, Category="Debug")
	uint8 bDrawDebugRawPoints : 1;

	UPROPERTY(EditAnywhere, Category="Debug")
	uint8 bDrawDebugRawEnd : 1;

	UPROPERTY(EditAnywhere, Category="Debug")
	uint8 bDrawDebugReppedPoints : 1;

	UPROPERTY(EditAnywhere, Category="Debug")
	uint8 bDrawDebugEvenlySizedSegments : 1;

	UPROPERTY(EditAnywhere, Category="Debug")
	uint8 bDrawDebugTangents : 1;

	UPROPERTY(EditAnywhere, Category="Debug")
	uint8 bDrawDebugCollision : 1;

	UPROPERTY(EditAnywhere, Category="Debug")
	uint8 bDrawDebugSplineEnd : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cleanup")
	float CleanupTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cleanup")
	FVector PathwayPointOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ease in and out")
	float LerpScaleRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ease in and out")
	float GrowthSmoothingStrength;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_MostRecentlyAddedLocation, Category="FortSplineGroundPath")
	FVector MostRecentlyAddedLocation;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortSplineGroundPath")
	float MostRecentlyAddedTime;

	UPROPERTY(Transient, Replicated)
	FFortReppedPointList FortReppedPointList;

	UPROPERTY(Transient)
	TArray<FVector> RawPoints;

	UPROPERTY(Transient)
	int32 ServerIndexToAssign;

protected:
	UFUNCTION()
	void DebugDisplayPathPoints() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAddedEvenlySizedSegment(const int32 ArrayIndex);

	UFUNCTION()
	void OnRep_MostRecentlyAddedLocation();

	UFUNCTION()
	void StartNextSectionTimedOut();

	UPROPERTY(Transient)
	TArray<FFortEvenlySizedSegment> EvenlySizedSegments;

	UPROPERTY(Transient)
	FVector2D FrontEndCurrentScale;

	UPROPERTY(Transient)
	FVector2D FrontEndDestScale;

	UPROPERTY(Transient)
	TArray<FReppedLastServerIndexToIndex> ReppedLastServerIndexToReppedPointIndices;

	UPROPERTY(Transient)
	TArray<FRawPointToLastServerIndexPlusAlpha> RawPointsToLastServerIndicesPlusAlpha;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	TObjectPtr<UMaterial> Material;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	FVector2D StaticMeshScaleStart;

	UPROPERTY(EditDefaultsOnly, Category="SplineMesh")
	FVector2D StaticMeshScaleTarget;

	UPROPERTY(EditAnywhere, Category="SplineMesh")
	TEnumAsByte<ESplineMeshAxis::Type> ForwardAxis;

	UPROPERTY(EditAnywhere, Category="Ease in and out")
	float LerpLocationRate;

	UPROPERTY(Transient)
	bool bMostRecentLocationHasBeenSet;

	UPROPERTY(Transient)
	bool bHasWarnedOfArrayOverfill;

	UPROPERTY(Transient)
	bool bHasWarnedOfUnableToRepDestroy;

	UPROPERTY(Transient)
	int32 FirstActiveEvenlySizedSegmentIndex;

	UPROPERTY(EditDefaultsOnly, Category="Points")
	int32 MaxReppedPointsBeforeOverfill;

	UPROPERTY(Transient)
	FVector LerpedMostRecentLocation;

	UPROPERTY(Transient)
	float DistanceRemainingToNextEvenlySpacedPoint;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	FName PositionFinalizedParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	FName GrowthParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	FName ShrinkParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	FName OpacityParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	float TotalFadeInTime;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	float TotalFadeOutTime;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	float SectionsLifeTime;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	float ShrinkTimeMultWhenFading;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	float ShrinkTimeMultWhenBurning;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	float GrowthTimeMult;

	UPROPERTY(EditDefaultsOnly, Category="Ease in and out")
	float LocationLerpTimeMult;

	UPROPERTY(BlueprintReadOnly, Category="Ease in and out")
	float CurrentFadeInTime;

	UPROPERTY(BlueprintReadOnly, Category="Ease in and out")
	float CurrentFadeOutTime;

	UPROPERTY(Transient)
	int32 TotalSplineMeshesToFadeIn;

	UPROPERTY(Transient)
	int32 LowestUninitializedRawLastServerIndex;

	UPROPERTY(Transient)
	int32 LowestUninitializedReppedIndex;

private:
	UPROPERTY(Transient)
	int32 NumIgnitedSections;

	UPROPERTY(Transient)
	bool bSomeSectionsAreFadingOut;

};

