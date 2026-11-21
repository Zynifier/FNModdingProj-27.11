// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortCameraMode_AthenaVehicle.h"
#include "FortCameraMode_Nevada.generated.h"

UCLASS(Config=Game, BlueprintType, Blueprintable)
class UFortCameraMode_Nevada : public UFortCameraMode_AthenaVehicle
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Nevada")
	FVector TractorBeamCameraOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Nevada")
	float TractorBeamCameraLerpTime;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Nevada")
	float TractorBeamCameraExtraPitch;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Nevada")
	float TractorBeamInactiveCameraExtraPitch;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Nevada")
	float TractorBeamCameraPositionResetDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Nevada")
	float MinPitchForOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Nevada")
	float MaxPitchForOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Nevada")
	FVector ExtraOffset;

};

