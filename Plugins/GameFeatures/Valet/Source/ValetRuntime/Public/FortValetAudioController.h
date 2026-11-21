// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortVehicleTypes.h"
#include "FortValetAudioController.generated.h"

class AFortDagwoodVehicle;
class UAudioComponent;
class UCurveFloat;
class UFortCollisionAudioComponent;
class UFortLayeredAudioComponent;
class USoundBase;
class USynthComponentMoto;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnValetEngineLoadChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnValetShiftGearCompleted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValetShiftGearDelegate, bool, bUpshift);

USTRUCT()
struct FValetUpdateContext
{
	GENERATED_BODY()

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class AFortValetAudioController : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void CacheValetVehicle(AFortDagwoodVehicle* InVehicle);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void OnSuspensionCollision_Native(bool& OutResult, float& OutMagnitude);

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	void OnTireModApplied(const FTireInfo& AppliedTireMod);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void Update_Native();

	UPROPERTY(BlueprintAssignable)
	FOnValetEngineLoadChangedDelegate OnEngineLoadChanged;

	UPROPERTY(BlueprintAssignable)
	FOnValetShiftGearCompleted OnShiftGearCompleted;

	UPROPERTY(BlueprintAssignable)
	FOnValetShiftGearDelegate OnShiftGearDelegate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float RPMResetTime_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float JitterAmount_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float ShiftTimeThreshold_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float TimeSinceShift_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float EngineRPMInterp_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float EngineRPMLinear_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float MinRPMRange_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float MaxRPMRange_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	bool bCurrentlyShifting_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float CurrentAccelRateGearModifier_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	float CurrentAccelRate_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing|Internal")
	int32 CurrentGear_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	int32 MaxGear_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float DefaultAccelRateScalar_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float GearAttackInterpSpeed_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float GearReleaseInterpSpeed_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float AccelRateScalarFirstGear_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float AccelRateScalarMinGear_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float AccelRateScalarMaxGear_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float ShiftToRPMStart_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float ShiftToRPMEnd_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float ShiftFromRPMStart_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float ShiftFromRPMEnd_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float MaxRPMSawtoothDecrement_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float MaxRPMSawtoothRepeatTime_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float DownhillAccelScalar_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	float UphillAccelScalar_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gearing")
	TObjectPtr<UCurveFloat> RPMFloatCurveMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float NormalizedSpeed_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float SuspValue_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	bool bIsHandbraking_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float MotoSynthVolume_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float MotoSynthInitialFadeInTime_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float MotoSynthLogRPM_Native;

	UPROPERTY(BlueprintReadWrite, Category="Control")
	bool bHasFuel_Native;

	UPROPERTY(BlueprintReadWrite, Category="Control")
	bool bIsInWater_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	bool bLocalPlayerInVehicle_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float TimeLocalPlayerEnteredVehicle_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	bool bAttemptingDirectionChange_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	bool bPreDestroy_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	bool bEngineLoad_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float SkidAmount_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float TimeSinceAwoken_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	bool bDestroyed_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Control")
	float TimeSinceSurfaceChange_Native;

	UPROPERTY(EditDefaultsOnly, Category="SoundCues")
	TObjectPtr<USoundBase> OnInitialSuspensionSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Skidding")
	float AngleForSkidding_Native;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Suspension")
	float SpringCompressionMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Motosynth")
	float MotoSynthMaxVolume_Native;

	UPROPERTY(EditDefaultsOnly, Category="Motosynth")
	FVector2D MotoSynthTimeInVehicleTimeRange;

	UPROPERTY(EditDefaultsOnly, Category="Motosynth")
	FVector2D MotoSynthTimeInVehicleVolumeRange;

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Category="Vehicle")
	TWeakObjectPtr<AFortDagwoodVehicle> ValetVehicle;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> Engine_Native;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> BoostAudioComponent_Native;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<USynthComponentMoto> SynthComponentMoto_Native;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UFortCollisionAudioComponent> SuspensionCollisionComponent_Native;

};

