// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Math/MathFwd.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortArmoredBattleBusPassengerAnimInstance.generated.h"

class AFortAthenaVehicle;
class USkeletalMeshComponent;

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortArmoredBattleBusPassengerAnimInstance : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus Passenger")
	void GenerateCharacterPitchAndYawForSlopedTerrain(const AFortAthenaVehicle* VehicleActor, float& TurretYaw, float& TurretPitch, FRotator& PawnYawRotator);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus Passenger")
	FTransform GetFootAttachTransform(const USkeletalMeshComponent* BusMeshComponent);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus Passenger")
	FVector GetHandAttachLocation(const USkeletalMeshComponent* BusMeshComponent, const FName FrontHandAttachBoneName, const FName RearHandAttachBoneName);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus Passenger")
	FTransform GetPassengerTransform(const USkeletalMeshComponent* BusMeshComponent);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus Passenger")
	FVector UnrotateHandAttachLocation(const FVector& HandLocation, const FVector& FootLocation, const FRotator& FootRotation);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus Passenger")
	void UpdateHandPositionsSlopeValues(const USkeletalMeshComponent* BusMeshComponent);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus Passenger")
	void UpdateSmoothedVehicleYawRate(const AFortAthenaVehicle* VehicleActor);

	UFUNCTION(BlueprintCallable, Category="Armored Battle Bus Passenger")
	void UpdateYawDeltaSmoothed(const AFortAthenaVehicle* VehicleActor, const FName SocketName, const FRotator& NewRotation, float& SmoothedYawValue);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	FRotator PreviousVehicleRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus Passenger")
	float SmoothedVehicleYawRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	int32 PawnSeat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	bool bIsFrontTurretPassenger;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	bool bIsRearTurretPassenger;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	float Speed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	float YawDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus Passenger")
	float TurretYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Armored Battle Bus Passenger")
	float TurretPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	FRotator TurretYawRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	float SlopeRollDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	float SlopePitchDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	FVector HandAttachL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Armored Battle Bus Passenger")
	FVector HandAttachR;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	TEnumAsByte<ERelativeTransformSpace> TransformSpace;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	float UpdateYawDeltaSmoothedLerpRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	int32 TurretPassengerFront;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	int32 TurretPassengerRear;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	FName FrontFootBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	FName RearFootBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	FName GunHandAttachBoneName_FrontLeft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	FName GunHandAttachBoneName_RearLeft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	FName GunHandAttachBoneName_FrontRight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	FName GunHandAttachBoneName_RearRight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	FName PassengerBoneName_Front;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	FName PassengerBoneName_Rear;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	float TurretPitchDegMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	float TurretPitchDegMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Armored Battle Bus Passenger|Settings")
	float LocalPlayerTurretPitchEaseRate;

};

