// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "RockVehicleAbility.h"
#include "RockVehicleAbility_GroundTrails.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;

USTRUCT()
struct FGroundTrailsData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GroundTrailsData")
	TEnumAsByte<EPhysicalSurface> SurfaceType;

	UPROPERTY(EditAnywhere, Category="GroundTrailsData")
	TObjectPtr<UNiagaraSystem> NiagaraFx;

};

USTRUCT()
struct FGroundTrailsMap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GroundTrailsMap")
	TObjectPtr<UNiagaraSystem> DefaultTrails;

	UPROPERTY(EditAnywhere, Category="GroundTrailsMap")
	TArray<FGroundTrailsData> GroundTrails;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class ROCKVEHICLERUNTIME_API URockVehicleAbility_GroundTrails : public URockVehicleAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetEnabled(bool bValue);

protected:
	UFUNCTION(BlueprintCallable)
	void OnSurfaceChanged(EPhysicalSurface NewSurface);

	UPROPERTY(EditAnywhere, Category="RockVehicleAbility_GroundTrails")
	FGroundTrailsMap GroundTrailsMap;

	UPROPERTY(EditAnywhere, Category="RockVehicleAbility_GroundTrails")
	TArray<FName> GroundTrailSockets;

	UPROPERTY(EditAnywhere, Category="RockVehicleAbility_GroundTrails")
	TObjectPtr<UNiagaraSystem> HandbrakeSystem;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UNiagaraComponent>> GroundTrailComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UNiagaraComponent>> HandbrakeComponents;

};

