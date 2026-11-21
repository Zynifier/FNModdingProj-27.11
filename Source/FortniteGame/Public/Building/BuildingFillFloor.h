// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingFillFloor.generated.h"

class AFortPlayerPawn;

USTRUCT()
struct FFillFloorPositionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FillFloorPositionData")
	FScalableFloat MoveTime;

	UPROPERTY(EditAnywhere, Category="FillFloorPositionData")
	FScalableFloat Height;

	UPROPERTY(EditAnywhere, Category="FillFloorPositionData")
	FScalableFloat PostMoveDelay;

};

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingFillFloor : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartMovement();

	UPROPERTY(EditAnywhere, Category="Damage")
	FScalableFloat ZKillOffset;

	UPROPERTY(EditAnywhere, Category="Damage")
	FScalableFloat ZMovementToleranceOffset;

protected:
	UFUNCTION(BlueprintPure)
	bool GetFloorPositionFromStep(int32 Step, float& MoveTime, float& Height, float& PostMoveDelay) const;

	UFUNCTION()
	void InterpToStopCallback(const FHitResult& ImpactResult, float Time);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHeightEvent(float Height, int32 HeightEventIndex);

	UFUNCTION(BlueprintCallable)
	void OnLavaOverlap(AFortPlayerPawn* Pawn);

	UFUNCTION()
	void OnRep_FloorZ();

	UFUNCTION()
	void OnRep_IsMoving();

	UFUNCTION()
	void OnRep_StepIndex();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartMoving(int32 CurrentStep);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStopMoving(int32 CurrentStep);

	UFUNCTION()
	void StopMovement();

	UPROPERTY(ReplicatedUsing=OnRep_StepIndex)
	int32 StepIndex;

	UPROPERTY(ReplicatedUsing=OnRep_FloorZ)
	float FloorZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Position Data")
	float InitialDelay;

	UPROPERTY(EditAnywhere, Category="Position Data")
	FFillFloorPositionData FloorPositionData;

	UPROPERTY()
	int32 NumStepsToUse;

	UPROPERTY(EditAnywhere, Category="Height Events")
	TArray<float> EventHeights;

	UPROPERTY(EditAnywhere, Category="Updates")
	FScalableFloat MovementTimerUpdatePeriod;

	UPROPERTY(Replicated)
	float FloorMovementSpeed;

	UPROPERTY(ReplicatedUsing=OnRep_IsMoving)
	bool bIsMoving;

};

