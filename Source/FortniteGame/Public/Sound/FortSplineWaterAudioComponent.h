// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Sound/FortSplineAudioComponent.h"
#include "FortSplineWaterAudioComponent.generated.h"

class AFortWaterBodyActor;
class USoundBase;

UENUM(BlueprintType)
enum class ESplineWaterAudioFacingDirection : uint8
{
	None = 0,
	Inwards = 1,
	Outwards = 2,
};

UENUM(BlueprintType)
enum class ESplineWaterAudioWindingOrder : uint8
{
	Clockwise = 0,
	Counterclockwise = 1,
};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortSplineWaterAudioComponent : public UFortSplineAudioComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Asset")
	TObjectPtr<USoundBase> InsideSplineSound;

	UPROPERTY(EditAnywhere, Category="Asset")
	TObjectPtr<USoundBase> SplineEndSound;

	UPROPERTY(EditAnywhere, Category="Spline")
	ESplineWaterAudioFacingDirection SplineFacingDirection;

	UPROPERTY(EditAnywhere, Category="Spline")
	bool bIsExclusionSpline;

	UPROPERTY(EditAnywhere, Category="Spline")
	FVector2D WaterVelocityRange;

	UPROPERTY(EditAnywhere, Category="Spline")
	float ShorelineOffset;

	UPROPERTY(EditAnywhere, Category="Spline")
	float TerrainZOffset;

	UPROPERTY(EditAnywhere, Category="Update Rate")
	float MaxVerticalDistanceToCheckInside;

protected:
	UPROPERTY()
	TObjectPtr<AFortWaterBodyActor> WaterBodyOwner;

};

