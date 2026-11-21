// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortCameraMode_Tethered.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortCameraMode_Tethered : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Tethered")
	FVector OriginOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Tethered")
	FVector2D TetherOffsetRangeX;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Tethered")
	FVector2D TetherDistanceRange;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Tethered")
	float TetherJumpOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Tethered")
	float TetherJumpOffsetTime;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Tethered")
	float TetheredBoostFOV;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Tethered")
	float FOVInterpSpeed;

};

