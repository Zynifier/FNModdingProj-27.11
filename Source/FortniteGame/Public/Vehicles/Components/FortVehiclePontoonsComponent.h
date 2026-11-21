// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuoyancyComponent.h"
#include "FortVehiclePontoonsComponent.generated.h"

class AFortAthenaVehicle;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FVehicleEffectsPontoonParamSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FX")
	FName PontoonName;

	UPROPERTY(EditAnywhere, Category="FX")
	FName EffectsName;

	UPROPERTY()
	FName ImpulseParamName;

	UPROPERTY()
	FName LocationParamName;

	UPROPERTY()
	FName RotationParamName;

	UPROPERTY()
	FName WaterBodyIndex;

	UPROPERTY()
	FName WaterHeightParamName;

	UPROPERTY()
	FName DepthParamName;

	UPROPERTY()
	FName WaterPlaneLocation;

	UPROPERTY()
	FName WaterPlaneNormal;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FVehiclePontoonBuoyancyDataExtended
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buoyancy|Scaling")
	float ScaleTimeFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buoyancy|Scaling")
	float ScaleRadiusPerTick;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buoyancy|Scaling")
	float MinRadiusToSink;

	UPROPERTY(Transient)
	float ScaledTime;

	UPROPERTY(Transient)
	float BaseRadiusBeforeScale;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent, DisplayName="Pontoons Component"))
class UFortVehiclePontoonsComponent : public UBuoyancyComponent
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API UFortVehiclePontoonsComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION()
	FORTNITEGAME_API void OnRep_PontoonRadius(const TArray<float>& PrevPontoonRadiuses);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FX")
	TArray<FVehicleEffectsPontoonParamSet> WaterEffectsPontoonParameters;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PontoonRadius)
	TArray<float> OverridePontoonRadiuses;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Buoyancy")
	TArray<int32> PushForcePontoons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Buoyancy")
	TArray<int32> LeftTurnPontoons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Buoyancy")
	TArray<int32> RightTurnPontoons;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaVehicle> OwnerVehicle;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	int32 WaterLineStartPontoonIndex;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	int32 WaterLineEndPontoonIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Buoyancy")
	TMap<FName, FVehiclePontoonBuoyancyDataExtended> ExtraBuoyancyData;

};

