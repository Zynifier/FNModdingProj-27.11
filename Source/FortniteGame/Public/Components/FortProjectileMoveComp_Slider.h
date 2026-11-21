// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortProjectileMovementComponent.h"
#include "FortProjectileMoveComp_Slider.generated.h"

UCLASS()
class UFortProjectileMoveComp_Slider : public UFortProjectileMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetSuspensionEnabled(const bool bInEnableSuspensionUp, const bool bInEnableSuspensionDown);

	UFUNCTION(BlueprintCallable)
	void ZeroOutSuspensionTension();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortProjectileMoveComp_Slider")
	uint8 bWhenLimitingVelocityFavorZ : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortProjectileMoveComp_Slider")
	uint8 bSuspensionEnabled_Up : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortProjectileMoveComp_Slider")
	uint8 bSuspensionEnabled_Down : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Suspension", meta=(ClampMin="0.000000"))
	float SuspensionTensionToSpeedScalar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Suspension", meta=(ClampMin="0.000001"))
	float SuspensionTensionBuildUpExponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Suspension")
	float SuspensionTensionEqualizeSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Suspension", meta=(ClampMin="0.000000"))
	float SuspensionTensionMax;

};

