// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "FortAthenaSKMotorVehicle.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaSKMotorVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API float GetStandingInPlaceSteeringAngle() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FORTNITEGAME_API bool IsStandingInPlace() const;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float AntiGravityScalerWhenEmpty;

protected:
	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SpringCompressionRefireTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float MovementAmountParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float CurrentMaxSpringCompression;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SparksLeftParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SparksRightParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float LeftSlowDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float RightSlowDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float LeftFastDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float RightFastDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float FastDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float CoastingMovementParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SkiddingAmountParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float InAirParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float ScrapingAmountParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float AudioWindParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SpringCompressionLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SpringCompressionRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SpringCompressionLeftBack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SpringCompressionRightBack;

};

