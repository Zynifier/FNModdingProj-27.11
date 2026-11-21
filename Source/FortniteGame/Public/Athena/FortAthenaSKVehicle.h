// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaVehicle.h"
#include "FortVehicleInterface.h"
#include "FortAthenaSKVehicle.generated.h"

class ABuildingActor;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaSKVehicle : public AFortAthenaVehicle
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelOffsetFR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelOffsetFL;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float WheelOffsetLimitF;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelOffsetBR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelOffsetBL;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float WheelOffsetLimitB;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float WheelOffsetLerpPerSecondUp;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float WheelOffsetLerpPerSecondDown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AxleOffsetZ;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AxleOffsetZ_B;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float AxleCenterF;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float AxleCenterB;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float AxleRollF;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float AxleRollB;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelRotationFR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelRotationFL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelRotationBR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelRotationBL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelRotationVelocityFR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelRotationVelocityFL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelRotationVelocityBR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelRotationVelocityBL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelSpinFR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelSpinFL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelSpinBR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelSpinBL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelSpinVelocityFR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelSpinVelocityFL;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelSpinVelocityBR;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float WheelSpinVelocityBL;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float WheelSpinDampingPerSecond;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TArray<FVehicleWheelFXSocketInfo> WheelFXSockets;

protected:
	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual float GetModifiedDamageForActor(float Damage, const ABuildingActor* BuildingActor) const;

};

