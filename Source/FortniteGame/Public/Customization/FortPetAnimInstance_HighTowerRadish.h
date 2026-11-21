// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortPetAnimInstance.h"
#include "Animation/FortPetOffsets.h"
#include "FortPetAnimInstance_HighTowerRadish.generated.h"

class UFortPlayerAnimInstance;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPetAnimInstance_HighTowerRadish : public UFortPetAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsTurningSharply() const;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	TObjectPtr<UFortPlayerAnimInstance> OwnerAnimBP;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	FVector BodyOffset_Total;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	float OwnerLocomotionDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	float OwnerLocomotionSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool StoppedMovingOrMeleeForLongEnoughTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool bPetUnderwater;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool HighTowerRadish_LobbySkyDive_Diving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool HighTowerRadish_LobbySkyDive_Gliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool FrontEndIdleTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	float AdditiveTransitionCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	float LeftHandIKCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	float TurnOffLeans;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	float OffsetRootYawFractioned;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	float OffsetRootYawSmooth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool bIsPlayingEmoteExtra;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool bIsInVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	float InVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool bIsSkydivingFE;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool bSlowDownInterp;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool bPetUnderWaterAndNotTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool bIsOwnerPlayingMeleeAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPetAnimInstance_HighTowerRadish")
	bool bIsSkydivingInGameOrIsParachuteOpen;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance_HighTowerRadish")
	FFortPetOffsets BodyOffsetsFromPlayer;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance_HighTowerRadish")
	FVector BodyOffsetWhenSkydivingFE;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance_HighTowerRadish")
	FVector BodyOffsetWhenNotSkydivingFE;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance_HighTowerRadish")
	float BodyOffsetSpringMass;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance_HighTowerRadish")
	FVector BodyOffsetSpringLagFactor;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnteredVehicle();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitedVehicle();

};

