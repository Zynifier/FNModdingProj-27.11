// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "AthenaBigBaseWall.generated.h"

enum class EBarrierState : uint8;

UENUM(BlueprintType)
enum class EBarrierState : uint8
{
	BarrierUp = 0,
	BarrierComingDown = 1,
	BarrierDown = 2,
};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaBigBaseWall : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewBarrierState(EBarrierState NewState);

	UFUNCTION()
	void OnRep_BarrierState();

	UFUNCTION()
	void OnRep_ResetBool();

	UFUNCTION()
	void OnRep_TimeUntilWallComesDown();

	UFUNCTION()
	void OnRep_WallGravity();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowOrHideTimer(bool bNewVisibleState);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWallTime(float Digit_0, float Digit_1, float Digit_2, float Digit_3);

	UFUNCTION(BlueprintImplementableEvent)
	void WallStartingToComeDown(bool bIsOnBurgerSide);

	UPROPERTY(ReplicatedUsing=OnRep_WallGravity)
	float WallGravity;

	UPROPERTY(ReplicatedUsing=OnRep_TimeUntilWallComesDown)
	float TimeUntilWallComesDown;

	UPROPERTY(ReplicatedUsing=OnRep_ResetBool)
	bool bResetBool;

	UPROPERTY(ReplicatedUsing=OnRep_BarrierState)
	EBarrierState BarrierState;

	UPROPERTY(EditAnywhere, Category="AthenaBigBaseWall")
	FScalableFloat ZKillLevel;

};

