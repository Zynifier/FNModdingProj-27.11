// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "FortVehicleSoundComponent.h"
#include "FortVehicleSoundComponent_Surface.generated.h"

USTRUCT(BlueprintType)
struct FFortVehicleSoundSurfaceParam
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortVehicleSoundSurfaceParam")
	TEnumAsByte<EPhysicalSurface> Surface;

	UPROPERTY(BlueprintReadOnly, Category="FortVehicleSoundSurfaceParam")
	FName Name;

	UPROPERTY(BlueprintReadOnly, Category="FortVehicleSoundSurfaceParam")
	float Value;

};

USTRUCT(BlueprintType)
struct VEHICLEAUDIORUNTIME_API FFortVehicleSoundComponent_SurfaceContext
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float BrakingHardStopThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float BrakingSoftStopThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float SurfaceParamInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	TMap<TEnumAsByte<EPhysicalSurface>, TEnumAsByte<EPhysicalSurface>> SurfaceMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	FName WaterParamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float WaterParamInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	FName AirParamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float AirParamAttackInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float AirParamReleaseInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float MinSpeedForSkidFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float MaxSpeedForSkidFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	FName SkiddingParamName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVehicleSoundComponent_SurfaceContext")
	float SkiddingParamInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Category="FortVehicleSoundComponent_SurfaceContext")
	TEnumAsByte<EPhysicalSurface> CurrentSurface;

	UPROPERTY(BlueprintReadOnly, Category="FortVehicleSoundComponent_SurfaceContext")
	TArray<FFortVehicleSoundSurfaceParam> SurfaceParams;

};

UCLASS(HideDropdown, BlueprintType, Blueprintable, HideCategories=("Tags", "ComponentReplication", "Activation", "Variable", "Cooking", "AssetUserData", "Replication", "Collision"), meta=(ChildCanTick))
class VEHICLEAUDIORUNTIME_API UFortVehicleSoundComponent_Surface : public UFortVehicleSoundComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="VehicleSound|Native")
	void OnBrakingChanged(bool bNewState);

	UFUNCTION(BlueprintImplementableEvent, Category="VehicleSound|Native")
	void OnInAirChanged(bool bNewState);

	UFUNCTION(BlueprintImplementableEvent, Category="VehicleSound|Native")
	void OnSkiddingChanged(bool bNewState);

	UFUNCTION()
	void OnSurfaceChanged(EPhysicalSurface NewSurface);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleSound|Native")
	FFortVehicleSoundComponent_SurfaceContext Context;

};

