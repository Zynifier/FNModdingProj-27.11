// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortDBNOAnimInstance.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortDBNOAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	EFortPlayerAnimBodyType AnimBodyType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LeanAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float SpeedAdjustedPlayrate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LeanAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float Speed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float MovementBlendSpaceSpeed2D;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Locomotion")
	float MaxMovementBlendSpaceSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalVelocityYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNO")
	float DBNOTurnPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsOnGround : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_FullBody_DBNOMove : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_FullBody_DBNOTurn : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortDBNOAnimInstance")
	uint8 bIsLargeBodyType : 1;

};

