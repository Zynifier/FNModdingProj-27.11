// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkinnedMeshComponent.h"
#include "Math/MathFwd.h"
#include "Vehicles/FortTreadVehicle.h"
#include "FortTankVehicle.generated.h"

class AFortVehicleAudioController;
class UCapsuleComponent;
class ULegacyCameraShake;
class UNiagaraComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankRepaired);

USTRUCT()
struct FServerSocketTransformOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Socket Override")
	FName SocketName;

	UPROPERTY(EditDefaultsOnly, Category="Socket Override")
	FVector PivotOffset;

	UPROPERTY(EditDefaultsOnly, Category="Socket Override")
	FVector OffsetFromPivot;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortTankVehicle : public AFortTreadVehicle
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintAssignable, Category="Tank|Interact")
	FTankRepaired OnTankRepairedDelegate;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Barrel")
	FName BarrelSocketName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Tank|Barrel", meta=(EditInline="true"))
	TObjectPtr<UCapsuleComponent> BarrelCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Tank|Overlap", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> UnderVehicleCollision;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Socket Override", meta=(DisplayName="Socket Overrides"))
	TArray<FServerSocketTransformOverride> SocketOverrideArray;

	UPROPERTY(Transient)
	TMap<FName, FTransform> SocketTransformOverrideMap;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> CachedSkeletalMeshComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortVehicleAudioController> CachedVehicleAudioController;

	UPROPERTY(Transient)
	EVisibilityBasedAnimTickOption DefaultServerVisibilityBasedAnimTickOption;

	UPROPERTY(Transient)
	bool DefaultServerSkeletalMeshTickEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Main Cannon")
	FName YawPivotSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Main Cannon")
	FName PitchPivotSocketName;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> DriverCameraShakeInstance;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> AcceleratingCameraShakeInstance;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> CachedNiagaraComponentRoadAndExhaust;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FString RoadAndExhaustNiagaraComponentName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustPeelOutLeftName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustPeelOutRightName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustVehicleSpeedName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustSlideDirectionName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	float RoadAndExhaustMinSpeedForDust;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustDustColorLerpName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	float RoadAndExhaustDustColorLerpOffRoad;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	float RoadAndExhaustDustColorLerpOnRoad;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustDustAlphaMultiplierName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	float RoadAndExhaustDustAlphaMultiplierOffRoad;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	float RoadAndExhaustDustAlphaMultiplierOnRoad;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustDustFrontLeftName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustDustFrontRightName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustDustMiddleLeftName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustDustMiddleRightName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustDustRearLeftName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustDustRearRightName;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Niagara|Road And Exhaust")
	FName RoadAndExhaustIsOnDirtName;

};

