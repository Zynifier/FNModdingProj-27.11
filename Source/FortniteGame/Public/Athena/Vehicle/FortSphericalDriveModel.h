// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortSphericalDriveModel.generated.h"

class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSphericalDriveContactAction, const FVector&, Location, const FVector&, Normal, const float, Magnitude, UPrimitiveComponent*, HitComponent);

USTRUCT()
struct FSphericalDriveContact
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FVector Normal;

	UPROPERTY()
	FVector Impulse;

	UPROPERTY()
	float Traction;

	UPROPERTY(Export)
	TWeakObjectPtr<UPrimitiveComponent> Component;

	UPROPERTY()
	bool bIsBouncy;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FSphericalDriveParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SphericalDriveParams")
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SphericalDriveParams")
	float MaxSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Acceleration")
	float LowSpeedAccelerationForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Acceleration")
	float HighSpeedAccelerationForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Acceleration")
	float MaxInclineDeg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Air Control")
	float MaxAirControlForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Air Control")
	float MaxAirControlSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Air Control")
	float ShellAngularDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drag")
	float DragCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Auto Brake")
	float DragCoefficientAutoBrake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Auto Brake")
	float MaxAutoBrakeSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Contact")
	float ContactRepulsionForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Contact")
	float ContactThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Steering")
	float MassDirectionMaxAngleDeg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Steering")
	float MassDirectionStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Steering")
	bool bMassDirectionInvert;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Traction")
	float TractionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bounce")
	float BounceForce;

};

