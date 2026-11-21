// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/Vehicle/FortSphericalDriveModel.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortSphericalVehicle.generated.h"

class AActor;

USTRUCT()
struct FFortSphericalVehicleAsyncDef
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortSphericalVehicleInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortSphericalVehicleOutContinuous : public FFortVehicleOutContinuous
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortSphericalVehicleOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortSphericalVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHit(const FVector& Location, const FVector& Normal, const float Force, AActor* HitActor);

	UFUNCTION(BlueprintCallable)
	void TickSpawnEffects(float DeltaTime, float Val, float ForwardSpeedKmh);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="SphericalDriveModel")
	FSphericalDriveParams BaseSphericalDriveParams;

};

