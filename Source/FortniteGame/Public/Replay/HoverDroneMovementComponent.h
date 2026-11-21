// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawnMovement.h"
#include "Math/MathFwd.h"
#include "HoverDroneMovementComponent.generated.h"

class AFortPlayerControllerSpectating;
class AFortPlayerState;

UCLASS()
class UHoverDroneMovementComponent : public USpectatorPawnMovement
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float RotAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float RotDeceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float MaxPitchRotSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float MaxYawRotSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float TurboRotAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float TurboRotDeceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float TurboMaxPitchRotSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float TurboMaxYawRotSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	FVector2D TurboAccelerationRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	FVector2D TurboAccelerationAltitudeRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float TurboDeceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float TurboHoverThrustScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	float FullAirFrictionVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDroneMovement")
	FVector CreativeModeBoundsScale;

private:
	UFUNCTION()
	void OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer);

};

