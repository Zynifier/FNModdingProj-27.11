// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortAbilityTargetingSourceEnum.h"
#include "FortMountedWeaponInterface.generated.h"

class AActor;
class IFortVehicleInterface;
class UFortVehicleSeatWeaponComponent;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FMountedWeaponInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="MountedWeaponInfo")
	TArray<TObjectPtr<AActor>> TraceIgnoreActors;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float ThirdPersonDistanceCorrection;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float ThirdPersonDistanceCorrectionPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aiming")
	EFortAbilityTargetingSource DamageStartFromSourceTowardFocus;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aiming")
	bool bUseMountedWeaponAimRotOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aiming")
	bool bUseAimingClampAngles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aiming", meta=(EditCondition="bUseAimingClampAngles"))
	float MaximumPitchAimingAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aiming", meta=(EditCondition="bUseAimingClampAngles"))
	float MinimumPitchAimingAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aiming")
	bool bTargetSourceFromVehicleMuzzle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	float MinReticleAlphaForAimInterpolation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	float MinAimAngleDiffForReticleAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	float MaxAimAngleDiffForReticleAlpha;

	UPROPERTY(EditDefaultsOnly, Category="MountedWeaponInfo")
	bool bIgnoreHostVehicleInWeaponTrace;

	UPROPERTY(Transient)
	bool bNeedsVehicleAttachment;

	UPROPERTY(Transient)
	int32 AttachAttemptCount;

	UPROPERTY(EditDefaultsOnly, Category="Muzzle Check")
	FName MuzzleFallbackSocketName;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FMountedWeaponInfoRepped
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedWeaponInfoRepped")
	TScriptInterface<IFortVehicleInterface> HostVehicleCached;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedWeaponInfoRepped")
	int32 HostVehicleSeatIndexCached;

	UPROPERTY(Transient)
	FVector DriverCameraLocationCached;

	UPROPERTY(Transient)
	FVector DriverCameraDirectionCached;

};

UINTERFACE(MinimalAPI, BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UFortMountedWeaponInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortMountedWeaponInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="WeaponTrace")
	virtual void AddToIgnoreActors(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Vehicle", meta=(DisplayName="Get Host Vehicle"))
	virtual TScriptInterface<IFortVehicleInterface> BP_GetHostVehicle() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	virtual UFortVehicleSeatWeaponComponent* GetWeaponComponentCached();

};

