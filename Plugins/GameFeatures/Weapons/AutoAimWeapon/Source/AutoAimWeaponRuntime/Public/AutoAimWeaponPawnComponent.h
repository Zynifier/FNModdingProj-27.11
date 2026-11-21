// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Components/FortPawnComponent.h"
#include "AutoAimWeaponPawnComponent.generated.h"

class AFortPawn;

USTRUCT(BlueprintType)
struct FAutoAimWeaponBoneSegmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AutoAimWeaponBoneSegmentData")
	FName BoneName1;

	UPROPERTY(EditDefaultsOnly, Category="AutoAimWeaponBoneSegmentData")
	FName BoneName2;

	UPROPERTY(EditDefaultsOnly, Category="AutoAimWeaponBoneSegmentData")
	float BoneCollisionCapsuleRadiusAproximation;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(ChildCanTick))
class UAutoAimWeaponPawnComponent : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetCurrentLockOnCount() const;

	UFUNCTION(BlueprintPure)
	float GetLockOnProgress() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	bool GetLockOnTargetLocation(FVector& OutLockTargetLocation) const;

	UFUNCTION(BlueprintPure)
	float GetTargetToReticleDistanceNormalized() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AutoAimWeaponPawnComponent")
	FGameplayTagContainer UseSingleLocationTargetingPawnTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AutoAimWeaponPawnComponent")
	FGameplayTagContainer LowPriorityTargetPawnTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AutoAimWeaponPawnComponent")
	TArray<FAutoAimWeaponBoneSegmentData> MultiSocketTargetingBoneSegmentDatas;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AutoAimWeaponPawnComponent")
	FScalableFloat LockOnTimeReticleCenter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AutoAimWeaponPawnComponent")
	FScalableFloat LockOnTimeReticleEdge;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AutoAimWeaponPawnComponent")
	FScalableFloat MaxLockOns;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoAimWeaponPawnComponent")
	float ProgressTowardNextLockOn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoAimWeaponPawnComponent")
	int32 CurrentLockOnCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoAimWeaponPawnComponent")
	float TargetToReticleDistanceNormalized;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoAimWeaponPawnComponent")
	TWeakObjectPtr<AFortPawn> LockOnTarget;

};

