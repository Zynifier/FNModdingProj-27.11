// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/LayerAnimInstance/FortItemLayerAnimInstance_FullLocomotion.h"
#include "FortItemLayerAnimInstance_GalileoPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortItemLayerAnimInstance_GalileoPatrol : public UFortItemLayerAnimInstance_FullLocomotion
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_GalileoPatrol")
	float WalkAdditiveStartOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortItemLayerAnimInstance_GalileoPatrol")
	FName PatrolLocomotionStateMachineName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_GalileoPatrol")
	bool bRecentlyFired;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_GalileoPatrol")
	bool bIsLandPatrolling;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_GalileoPatrol")
	bool bIdle_Walk_Transition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_GalileoPatrol")
	bool bIsPatrolLocomotionCurrentTimeAboveThreshold;

};

