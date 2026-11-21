// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "StaticPaths/ScriptedObjectMovementStaticPathTool.h"
#include "CubeMovementStaticPath.generated.h"

class AFortScriptedObjectMovement_MovableObjectBase;
class UFortCorruptionSequenceData;

USTRUCT()
struct FCorruptionCalendarEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CorruptionCalendarEventData")
	FString EventName;

	UPROPERTY(EditDefaultsOnly, Category="CorruptionCalendarEventData", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float StartPercent;

};

USTRUCT()
struct FCorruptionPauseEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CorruptionPauseEvent")
	FString EventName;

	UPROPERTY(EditAnywhere, Category="CorruptionPauseEvent", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float PercentDurationToPause;

};

USTRUCT(BlueprintType)
struct FCubeMovement_CorruptionGenerationSplinePointData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CubeMovement_CorruptionGenerationSplinePointData")
	FTransform SplinePointTransform;

	UPROPERTY(BlueprintReadOnly, Category="CubeMovement_CorruptionGenerationSplinePointData")
	float SplinePercentComplete;

};

USTRUCT(BlueprintType)
struct FCubeMovement_CorruptionGenerationTravelerData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CubeMovement_CorruptionGenerationTravelerData")
	TArray<FCubeMovement_CorruptionGenerationSplinePointData> SplinePointData;

	UPROPERTY(BlueprintReadOnly, Category="CubeMovement_CorruptionGenerationTravelerData")
	TObjectPtr<AFortScriptedObjectMovement_MovableObjectBase> PathTraveler;

};

USTRUCT(BlueprintType)
struct FCubeMovement_CorruptionGenerationData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CubeMovement_CorruptionGenerationData")
	TArray<FCubeMovement_CorruptionGenerationTravelerData> TravelerData;

};

USTRUCT()
struct FTravelerStepCorruptionOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="TravelerStepCorruptionOverrideData")
	TMap<FString, float> PointGroupStepPercentOverrides;

};

UCLASS(BlueprintType, Blueprintable)
class ACubeMovementStaticPath : public AScriptedObjectMovement_StaticPath
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	void EditorGetCorruptionGenerationData(FCubeMovement_CorruptionGenerationData& OutData) const;

protected:
	UFUNCTION(Category="ScriptedObjectMovementStaticPath", meta=(CallInEditor="true", DisplayAfter="GeneratePathData"))
	void ClearAllGeneratedSplinesAndLockedData();

	UPROPERTY(EditAnywhere, Category="CubeMovementStaticPath")
	float GenerationZTraceHeight;

	UPROPERTY(EditAnywhere, Category="CubeMovementStaticPath")
	float CubeSpacingFactor;

	UPROPERTY(EditAnywhere, Category="CubeMovementStaticPath", meta=(ClampMax="90", ClampMin="10"))
	float CubeAngleLimitDegrees;

	UPROPERTY(EditAnywhere, Category="CubeMovementStaticPath")
	TObjectPtr<UFortCorruptionSequenceData> CorruptionSequence;

	UPROPERTY(EditInstanceOnly, Category="CubeMovementStaticPath")
	TArray<FTravelerStepCorruptionOverrideData> TravelerCorruptionStepPercentOverrides;

};

UCLASS(BlueprintType, Blueprintable)
class UFortCorruptionSequenceData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCorruptionSequenceData")
	TArray<FCorruptionCalendarEventData> CorruptionStartEvents;

	UPROPERTY(EditDefaultsOnly, Category="FortCorruptionSequenceData")
	TArray<FCorruptionPauseEvent> CorruptionPauseEvents;

};

