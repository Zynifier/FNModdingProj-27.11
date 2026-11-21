// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Math/MathFwd.h"
#include "DeployableTurretLibrary.h"
#include "DeployableTurretAnimInstance.generated.h"

class ABuildingGameplayActor;

USTRUCT(BlueprintType)
struct FDeployableTurretBPAnimData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurretBPAnimData")
	FRotator AimRotation;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurretBPAnimData")
	float SurfaceRollDegrees;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurretBPAnimData")
	float SurfacePitchDegrees;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurretBPAnimData")
	EDeployableTurretState State;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class DEPLOYABLETURRETGAMEPLAYRUNTIME_API UDeployableTurretAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void SetNativeVariables(const ABuildingGameplayActor* OwningTurretBGA, const FDeployableTurretBPAnimData& AnimData);

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bIsAttacking : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bIsWindUp : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bIsTracking : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bIsWindDown : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bIsDeactivated : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bIsScanning : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bIsAggro : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bFallAndDeployToDeactivated : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bFallAndDeployToScan : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bAggroToFire : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bInterruptibleCurveOverThreshold : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	uint8 bTurnEndCurveOverThreshold : 1;

	UPROPERTY(EditDefaultsOnly, Category="DeployableTurret|Nativized")
	FName InterruptibleCurveName;

	UPROPERTY(EditDefaultsOnly, Category="DeployableTurret|Nativized")
	float InterruptibleCurveThreshold;

	UPROPERTY(EditDefaultsOnly, Category="DeployableTurret|Nativized")
	FName TurnEndCurveName;

	UPROPERTY(EditDefaultsOnly, Category="DeployableTurret|Nativized")
	float TurnEndCurveThreshold;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	FRotator AimRotationInComponentSpace;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeployableTurret|Nativized")
	FRotator SurfaceRotation;

};

