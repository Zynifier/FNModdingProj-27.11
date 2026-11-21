// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_PatrolAnimSet.h"
#include "Animation/FortPatrolAnimAsset.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortPatrolAnimLayer.generated.h"

class AFortWeapon;
class UFortPatrolAnimAsset;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPatrolAnimLayer : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortPatrolAnimAsset* GetPatrolAnimSetFromWeapon(const TArray<FFortPatrolAnimSetWeaponPair>& AnimWeaponPairs, const AFortWeapon* NewWeapon) const;

	UFUNCTION(BlueprintCallable)
	void SetPatrolAnimAsset(UFortPatrolAnimAsset* NewAnimAsset);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Patrol")
	FFortAnimInput_PatrolAnimSet CurrentAnimSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPatrolAnimLayer")
	float CurrentSpeedInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPatrolAnimLayer")
	float PatrolForceEnableSpeedThreshold;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	float WalkAdditiveStartOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	float Speed2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	float LocalVelocityYawAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	float DisableIdleDuringWalk;

	UPROPERTY(EditDefaultsOnly, Category="FortPatrolAnimLayer")
	FName PatrolLocomotionStateMachineName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bRecentlyFired;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bIsLandPatrolling;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bIdle_Walk_Transition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bIsPatrolLocomotionCurrentTimeAboveThreshold;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bIsDBNO;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bIsMoving2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bIsAIPatrolling;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bIsStressed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bIsDanceStunned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortPatrolAnimLayer")
	bool bEnableFullbodyOverride;

};

