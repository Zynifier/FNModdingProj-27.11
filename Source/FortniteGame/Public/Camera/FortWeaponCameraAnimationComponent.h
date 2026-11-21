// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortWeaponCameraAnimationComponent.generated.h"

class AFortWeapon;
class AFortWeaponRanged;
class UFortWeaponCameraAnimation;
class UPrimaryDataAsset;

UCLASS(BlueprintType, Blueprintable)
class UFortWeaponCameraAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void CallFiringCameraShake();

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	void GetShakeDataClass(bool bIsHipFire, TSubclassOf<UPrimaryDataAsset>& OutShakeDataClass) const;

	UFUNCTION(BlueprintCallable)
	void HandleStartFiring();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsUpdatedFeedbackEnabled();

	UFUNCTION()
	void NativeWeaponFired(AFortWeapon* FiringWeapon);

	UFUNCTION(BlueprintImplementableEvent)
	void SetInputAndShakeDataParams(UFortWeaponCameraAnimation* ActiveShake, TSubclassOf<UPrimaryDataAsset> ShakeDataClass, float StartTime, float TimeBetweenShots);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortWeaponCameraAnimationComponent")
	TSubclassOf<UFortWeaponCameraAnimation> CameraShakeModifierToAdd;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortWeaponCameraAnimationComponent")
	bool bLastTargetingState;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortWeaponCameraAnimationComponent")
	bool bIsFirstShot;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortWeaponCameraAnimationComponent")
	UFortWeaponCameraAnimation* ActiveShakeModifier;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortWeaponCameraAnimationComponent")
	TSubclassOf<UPrimaryDataAsset> HipfireShakeDataCached;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortWeaponCameraAnimationComponent")
	TSubclassOf<UPrimaryDataAsset> ADSShakeDataCached;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="Default", meta=(MultiLine="true"))
	TObjectPtr<AFortWeaponRanged> OwnerWeapon;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortWeaponCameraAnimationComponent")
	bool bIsProjectileWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="Default")
	bool TriggerPressed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="Default")
	int64 LastFiredFrame;

};

