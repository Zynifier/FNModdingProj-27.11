// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/MathFwd.h"
#include "FortAnimInput_DBNOCarried.generated.h"

class AFortPlayerPawn;
class UAnimMontage;
class UFortPlayerAnimInstance;

USTRUCT(BlueprintType)
struct FFortAnimInput_DBNOCarried
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="DBNOCarried")
	FCachedAnimStateData DropStateData;

	UPROPERTY(BlueprintReadOnly, Category="DBNOCarried")
	FFloatSpringState CarrierYawSpringState;

	UPROPERTY(BlueprintReadOnly, Category="DBNOCarried")
	FFloatSpringState CarrierSpinePitchSpringState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DBNOCarried")
	TObjectPtr<UAnimMontage> CarrierDropMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DBNOCarried")
	TObjectPtr<UAnimMontage> CarrierPickupMontage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	TObjectPtr<AFortPlayerPawn> CarrierPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	TObjectPtr<UFortPlayerAnimInstance> CarrierAnimBP;

	UPROPERTY(BlueprintReadOnly, Category="DBNOCarried")
	TObjectPtr<UAnimMontage> CarrierInterrogationMontage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	FVector LHandIKLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	FRotator LHandIKRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	FVector TempAttachLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	FRotator TempAttachRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	float SubAnimPhysicsWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	float DropMontagePosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	float PickupMontagePosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	float InterrogationMontagePosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	float PickupToIdleTransitionPosition;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarrierPawnVelocityZ;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarrierYawDeltaSmoothed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarriedJogNAnimPosition;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarriedJogSAnimPosition;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarriedCrouchNAnimPosition;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarriedCrouchSAnimPosition;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarriedSprintAnimPosition;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarriedCrouchSprintAnimPosition;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float CarrierSpinePitch;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	float DropStateWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	uint8 bBeingCarried : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	uint8 bIsBeingPickedUp : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	uint8 bIsBeingDropped : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	uint8 bCarrierIsCrouching : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	uint8 bCarrierIsMovingBackward : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	uint8 bCarrierHasSyncMarkers : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNOCarried")
	uint8 bTransitionFromPickupToIdle : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	uint8 bTransitionFromIdleToJogging : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	uint8 bTransitionFromJoggingToSprinting : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	uint8 bTransitionFromInAirToLanding : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DBNOCarried")
	uint8 bJackalPlayJumpTrickVertical : 1;

};

