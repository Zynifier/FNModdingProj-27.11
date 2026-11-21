// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "FortMountedTurret.generated.h"

class AFortPlayerPawn;
class UAudioComponent;
class UCurveFloat;
class UFortLayeredAudioComponent;
class UFortMountedTurretConfigs;
class UFortVehicleAimingWeaponComp;
class ULegacyCameraShake;
class UParticleSystemComponent;

USTRUCT(BlueprintType)
struct FTurretCosmeticData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Effects", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> OverheatSmoke;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Effects", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> OverheatScreenL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Effects", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> OverheatScreenR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Effects", meta=(EditInline="true"))
	TArray<TObjectPtr<UParticleSystemComponent>> OverheatParticleSystems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Effects", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> OverheatAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Effects", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> OnOverheatAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Effects")
	TObjectPtr<UCurveFloat> OverheatAudioCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Effects", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> ServoAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Effects", meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAimingWeaponComp> AimingWeaponComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FName HorizontalAimDeltaParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FName VerticalAimDeltaParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FName OverheatParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float OverheatParamOnOverheatValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FName OverheatColorParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FName OverheatAlphaParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FName RedBlinkParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float RotatationAudioRangeInA;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float RotatationAudioRangeInB;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float RotatationAudioRangeOutA;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float RotatationAudioRangeOutB;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float HotThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float WarmThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float AudioFadeinDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float AudioFadeoutDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FLinearColor WarmColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FLinearColor HotColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float OverheatColorExponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	float ReplicateOverheatMax;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortMountedTurret : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(DevelopmentOnly))
	void DebugDrawTrajectory(const FVector AimDirection, const FVector TargetLocation, const float LaunchVelocity, const float InGravityMult, const FColor LineColor = FColor(0, 0, 255, 255), const float KeepTime = 10.000000f, const int32 Subdivisions = 16) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	FVector GetAimDirectionToHitTarget(const FVector TargetLocation, const float LaunchVelocity, const float InGravityMult) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void GetYawPitchDeltaToTargetAimDirection(const int32 SocketIndex, const FVector TargetAimDirection, float& OutYawDelta, float& OutPitchDelta) const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerRiding() const;

	UFUNCTION(BlueprintPure)
	float NativeCurrentOverheatScalar(float InReplicateOverheatOf20) const;

	UFUNCTION(BlueprintCallable)
	void NativeUpdateOverheatCosmetics(const AFortPlayerPawn* InDriverPawn, float InReplicateOverheatOf20, UPARAM(ref) FRotator& OutTurretRotation);

	UFUNCTION(BlueprintImplementableEvent, Category="MountedTurret")
	void OnGetExitSocketTransform(const FName ExitSocket, const int32 SocketIndex, const FTransform InTransform, bool& bOutOverriderExitSocket, FTransform& OutOverrideTransform);

	UFUNCTION()
	virtual void OnRep_TeamIndex(uint8 OldVal);

	UFUNCTION(BlueprintImplementableEvent, Category="MountedTurret")
	void OnSpecialPressed();

	UFUNCTION(BlueprintImplementableEvent, Category="MountedTurret")
	void OnSpecialReleased();

	UFUNCTION(BlueprintCallable)
	void SetManned(bool bInIsManned);

	UFUNCTION(BlueprintCallable)
	void SetOverheating(bool bInIsOverheating);

	UFUNCTION(BlueprintNativeEvent)
	bool ShouldShowActionLabelAtIndex(const int32 Index, UPARAM(ref) TArray<FName>& SeatActionNames, UPARAM(ref) TArray<FText>& SeatActionLabels) const;

	UFUNCTION(BlueprintCallable)
	void TriggerVehicleSeatChangedCallbacks();

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_TeamIndex, Category="Team")
	uint8 TeamIndex;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	bool bConstrainVerticalRotationOnly;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	bool bImplementsOnSpecialPressed;

	UPROPERTY(Transient)
	FTransform LastFrameTurretTransform;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float PedalScaler;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedTurret")
	float MovementParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedTurret")
	float BatteryParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Rumble")
	float RumbleIntensity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CameraShake")
	TObjectPtr<ULegacyCameraShake> DriverCameraShake;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CameraShake")
	TObjectPtr<ULegacyCameraShake> PassengerCameraShake;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MountedTurret")
	TObjectPtr<AFortPlayerPawn> LocalPlayerPawn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MountedTurret")
	FTurretCosmeticData TurretCosmeticData;

protected:
	UFUNCTION()
	void OnRep_TurretSleeping();

	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedTurret")
	TObjectPtr<UFortMountedTurretConfigs> FortMountedTurretConfigs;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TurretSleeping)
	bool bTurretSleeping;

};

