// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstance_OctopusDriver.h"
#include "FortPlayerAnimInstance_NevadaDriver.generated.h"

class AFortNevadaVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_NevadaDriver : public UFortPlayerAnimInstance_OctopusDriver
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	TObjectPtr<AFortNevadaVehicle> NevadaVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	float AnimLeftRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	float AnimForwardBackward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	FVector RootAttachmentLoc;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	FRotator RootAttachmentRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	int32 BoostCount;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	int32 PreviousBoostCount;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	bool bIsBoostingAgain;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Driver")
	bool bIsMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver")
	float MinVehicleVelocityToBeMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Names")
	FName DriverSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Names")
	FName RightHandAttachmentSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Names")
	FName LeftHandAttachmentSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Names")
	FName RightFootAttachmentSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Names")
	FName LeftFootAttachementSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Offsets")
	FRotator RightHandRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Offsets")
	FRotator LeftHandRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Offsets")
	FRotator RightFootRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Offsets")
	FRotator LeftFootRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Driver Socket Offsets")
	FVector RootAttachmentOffset;

};

