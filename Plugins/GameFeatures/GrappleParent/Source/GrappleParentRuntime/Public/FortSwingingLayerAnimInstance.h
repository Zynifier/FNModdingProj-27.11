// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortSwingingLayerAnimInstance.generated.h"

class AActor;
class AFortPlayerPawnAthena;
class UAnimInstance;

UCLASS(NonTransient, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortSwingingLayerAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	FVector GetAttachVectorInPlayerSpace(const FVector& InPlayerToAttachPoint);

	UFUNCTION()
	void GetPlayerAnglesFromAttachPoint(float& Pitch, float& Roll, float& Yaw);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSwingingLayerAnimInstance")
	UAnimInstance* MainAnimBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	AFortPlayerPawnAthena* Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsGroundSwing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsFemale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float PlayerDistanceToGround;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool CalculateRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FScalableFloat ForwardInfluenceOnRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FScalableFloat TimeForMaxRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FScalableFloat MaxRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FScalableFloat RotationSpeedWhileNotAttached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FScalableFloat RotationSpeedWhileNotRotated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	AActor* GetAttachedActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool isFreeFalling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsAttached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsNotAttachedToCliff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FVector XYVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FVector VecFromPlayerToAttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float PitchAngleFromAttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float RollAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float YawAngleToAttachTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName CurveName_SwingPhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName CurveName_BlendOut;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float SwingPhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FRotator CurrentRootRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FVector CurrentRootTranslation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsSwingRelease1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsSwingRelease2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsSwingRelease3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsSwingRelease4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsSwingRelease5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsSwingReleaseSkid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsMovingAttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsBlendOut;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float WebCastAttachDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsWebCastDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsSwingOneHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsRandomHandBool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsRandomSwingReleaseBool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsRandomeReleaseBool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsWithin100UnitsOfGround;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsHanging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsFallRelease;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsOnGroundWebCast;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsSwingNearGroundToSkid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsHangToSwingInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	bool IsHangToSwingNearGround;

};

