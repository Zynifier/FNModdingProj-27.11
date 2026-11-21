// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortArmoredBattleBusVehicleAnimInstance.generated.h"

class AFortAthenaVehicle;
class AFortPlayerPawn;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortArmoredBattleBusVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus")
	void GetPitchAndYaw(const AFortAthenaVehicle* VehicleActor, const AFortPlayerPawn* GunnerActor, float& AdjustedPitch, float& AdjustedYaw, bool& bIsLocalPlayerControlled, FRotator& YawRotator);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus")
	float UpdateSmoothedVehicleYawRate(const AFortAthenaVehicle* VehicleActor, const FRotator PreviousRotator);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus")
	void UpdateTurretAimPitchWeaponYaw(const AFortAthenaVehicle* OwnerVehicle, const AFortPlayerPawn* GunnerActor, const FName SocketName, const float YawOffset, float& TurretAimPitch, float& YawDeltaSmoothed, FRotator& WeaponYaw);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus")
	float UpdateYawDeltaSmoothed(const AFortAthenaVehicle* VehicleActor, const FName SocketName, const FRotator NewRotation, const float SmoothedYawValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	float FrontTurretAimPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	float RearTurretAimPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	float FrontYawDeltaSmoothed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	float RearYawDeltaSmoothed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	float SmoothedVehicleYawRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	float FrontYawDeltaSmoothedAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	float RearYawDeltaSmoothedAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	FRotator FrontWeaponYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	FRotator RearWeaponYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	FRotator PreviousVehicleRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	bool bHasFrontTurretPassenger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus")
	bool bHasRearTurretPassenger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus|Settings")
	float NetworkEaseRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus|Settings")
	float UpdateYawDeltaSmoothedLerpRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus|Settings")
	int32 FrontPassengerSeatIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus|Settings")
	int32 RearPassengerSeatIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus|Settings")
	float FrontPassengerYawOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus|Settings")
	float RearPassengerYawOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus|Settings")
	FName FrontPassengerBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus|Settings")
	FName RearPassengerBoneName;

};

