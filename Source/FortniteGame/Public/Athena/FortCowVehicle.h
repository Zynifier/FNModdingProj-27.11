// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortSphericalVehicle.h"
#include "FortCowVehicle.generated.h"

class UFortLayeredAudioComponent;
class UMaterialInstanceDynamic;
class UNiagaraComponent;

USTRUCT()
struct FCowVehicleFloatSpringInterp
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CowVehicleFloatSpringInterp")
	float Stiffness;

	UPROPERTY(EditDefaultsOnly, Category="CowVehicleFloatSpringInterp")
	float CriticalDampingFactor;

	UPROPERTY(EditDefaultsOnly, Category="CowVehicleFloatSpringInterp")
	float Mass;

};

USTRUCT()
struct FCowVehicleImpactPointInterp
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CowVehicleImpactPointInterp")
	float Target;

	UPROPERTY(EditDefaultsOnly, Category="CowVehicleImpactPointInterp")
	float InterpSpeed;

};

USTRUCT()
struct FCowVehicleMapRangeClamped
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CowVehicleMapRangeClamped")
	float InRangeA;

	UPROPERTY(EditDefaultsOnly, Category="CowVehicleMapRangeClamped")
	float InRangeB;

	UPROPERTY(EditDefaultsOnly, Category="CowVehicleMapRangeClamped")
	float OutRangeA;

	UPROPERTY(EditDefaultsOnly, Category="CowVehicleMapRangeClamped")
	float OutRangeB;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortCowVehicle : public AFortSphericalVehicle
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Cow Vehicle | Audio", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> PhysicsAudioComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Cow Vehicle | Niagara", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> SpeedLinesNSComponent;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Audio", meta=(DisplayName="On Ground Name"))
	FName AudioParamOnGroundName;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Audio", meta=(DisplayName="Speed Name"))
	FName AudioParamSpeedName;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Audio", meta=(DisplayName="In Water Name"))
	FName AudioParamInWaterName;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Audio")
	FCowVehicleMapRangeClamped SpeedMapRangeClamped;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara")
	bool bIsSquashing;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara")
	float SquashTime;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara")
	float MaxSquashTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara")
	float CurrentSquash;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara")
	float TargetSquash;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara")
	float ErrorToleranceImpactComparison;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara")
	float SquashSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara")
	float CurrentSquashSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara | Impact Interp")
	float ImpactPointInterp;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara | Impact Interp")
	FCowVehicleImpactPointInterp ImpactPointInterpData;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara | Impact Interp")
	float ForceNormalized;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara | Spring Interp")
	float ErrorToleranceSpringComparison;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara | Spring Interp")
	float PreviousSpeed;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara | Spring Interp")
	FCowVehicleMapRangeClamped PreviousSpeedMapRangeClamped;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara | Spring Interp")
	FCowVehicleFloatSpringInterp SquashFloatSpringInterp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Cow Vehicle | Niagara")
	TObjectPtr<UMaterialInstanceDynamic> SquashMID;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara", meta=(DisplayName="Speed Lines Threshold Name"))
	FName NSParamSpeedLinesThresholdName;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara", meta=(DisplayName="Squash Amount Name"))
	FName NSParamSquashAmountName;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara", meta=(DisplayName="Ripple Start Name"))
	FName NSRippleStartName;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara", meta=(DisplayName="Ripple Length Interp Name"))
	FName NSRippleLengthInterpName;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Cow Vehicle | Niagara | Impact Interp", meta=(DisplayName="Use World Impact Point Name"))
	FName NSUseWorldImpactPointName;

};

