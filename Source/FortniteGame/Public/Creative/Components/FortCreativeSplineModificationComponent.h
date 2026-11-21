// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SplineComponent.h"
#include "Math/MathFwd.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortCreativeSplineModificationComponent.generated.h"

class AActor;
class AFortCreativeSplineControlPoint;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSerializedSplinePointsLoaded);

USTRUCT(BlueprintType)
struct FSplinePoint_Serializable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="SplinePoint")
	float InputKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="SplinePoint")
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="SplinePoint")
	FVector ArriveTangent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="SplinePoint")
	FVector LeaveTangent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="SplinePoint")
	FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="SplinePoint")
	FVector Scale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="SplinePoint")
	TEnumAsByte<ESplinePointType::Type> Type;

};

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortCreativeSplineModificationComponent : public UActorComponent, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void GenerateControlPointsForSpline();

	UFUNCTION(BlueprintCallable)
	static FSplinePoint MakeSplinePoint(const FSplinePoint_Serializable& SerializableSplinePoint);

	UFUNCTION(BlueprintCallable)
	void OnSavedSplineDataLoaded(const TArray<FSplinePoint_Serializable>& SavedSplinePoints);

	UFUNCTION(BlueprintCallable)
	void SetSplinePoints(const TArray<FSplinePoint>& InSplinePoints);

	UFUNCTION(BlueprintCallable)
	void UpdateEditorPreview(const TArray<FSplinePoint_Serializable>& InSplinePoints);

	UFUNCTION(BlueprintCallable)
	void UpdateTransientComponentTransforms();

protected:
	UFUNCTION(BlueprintCallable)
	void PopulateSerializedSplineDataFromSpline();

	UFUNCTION(BlueprintCallable)
	void SaveSplinePointData();

	UPROPERTY(Transient)
	TArray<FSplinePoint_Serializable> SplinePoints;

	UPROPERTY(ReplicatedUsing=OnRep_SplinePoints_NonSerializable)
	TArray<FSplinePoint> SplinePoints_NonSerializable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeSplineModificationComponent")
	TArray<FSplinePoint> DefaultSplinePoints;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeSplineModificationComponent")
	FName SplinePointsPropertyName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeSplineModificationComponent")
	TSoftClassPtr<AFortCreativeSplineControlPoint> ControlPointClass;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ControlPoints)
	TArray<AFortCreativeSplineControlPoint*> ControlPoints;

private:
	UFUNCTION()
	void DestroyControlPoints(AActor* DestroyedActor);

	UFUNCTION()
	void OnRep_ControlPoints();

	UFUNCTION()
	void OnRep_SplinePoints_NonSerializable();

};

