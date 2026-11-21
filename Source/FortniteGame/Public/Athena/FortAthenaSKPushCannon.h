// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKPushVehicle.h"
#include "FortAthenaSKPushCannon.generated.h"

class AFortPawn;
class AFortPlayerPawn;
class ULegacyCameraShake;
class UPhysicalMaterial;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaSKPushCannon : public AFortAthenaSKPushVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable)
	void MultiCastPushCannonLaunchedPlayer();

	UFUNCTION(BlueprintImplementableEvent, Category="MountedCannon")
	void OnPostExitVehicle(AFortPawn* ExitingPawn, const int32 SeatIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="PushCannon")
	void OnPushCannonFired(int32 ShotsRemaining, bool bLaunchingPlayer);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPassengerTorquing(bool bSetTo);

	UFUNCTION(BlueprintImplementableEvent, Category="PushCannon")
	void ShowCooldownCue(AFortPlayerPawn* Pawn, float Duration);

	UPROPERTY(EditDefaultsOnly, Category="PushCannon")
	bool bUseCameraForSteering;

	UPROPERTY(EditDefaultsOnly, Category="PushCannon")
	bool bDriverMustADSToAim;

	UPROPERTY(EditDefaultsOnly, Category="PushCannon")
	bool bShouldConstrainDriverCameraToBarrelOnlyWhenTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PushCannon")
	FName MainPhysicsProfileName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PushCannon")
	float MovementParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PushCannon")
	float BatteryParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Rumble")
	float RumbleIntensity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CameraShake")
	TObjectPtr<ULegacyCameraShake> DriverCameraShake;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CameraShake")
	TObjectPtr<ULegacyCameraShake> PassengerCameraShake;

	UPROPERTY(Transient)
	FVector PlayerTorque;

	UPROPERTY(Transient, Replicated)
	bool bPlayerTorquingRepped;

	UPROPERTY(Transient)
	bool bPlayerTorquing;

	UPROPERTY(Transient)
	int32 CannonBoneIdx;

	UPROPERTY(EditDefaultsOnly, Category="Physics")
	TObjectPtr<UPhysicalMaterial> PushCannonNoSleepPhysicsMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Physics")
	TObjectPtr<UPhysicalMaterial> PushCannonPhysicsMaterial;

protected:
	UFUNCTION(BlueprintPure)
	FRotator GetCurrentWorldAimOrientationCorrected() const;

	UFUNCTION(BlueprintImplementableEvent, Category="MountedCannon")
	void OnLaunchPawn(AFortPlayerPawn* Pawn, const FVector LaunchDir);

	UFUNCTION(BlueprintImplementableEvent, Category="MountedCannon")
	void OnPreLaunchPawn(AFortPlayerPawn* Pawn, const FVector LaunchDir);

};

