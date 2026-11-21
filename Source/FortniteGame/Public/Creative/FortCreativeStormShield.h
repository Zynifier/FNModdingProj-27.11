// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "Missions/FortMissionStormShield.h"
#include "FortCreativeStormShield.generated.h"

class AFortCreativeStormShield;
class AFortVolume;
class UAudioComponent;
class UCurveFloat;
enum class EAthenaGamePhaseStep : uint8;

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortCreativeStormShieldGamePhaseStepUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativeStormShieldGamePhaseStepUpdatedEvent")
	TWeakObjectPtr<AFortCreativeStormShield> StormShield;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeStormShieldGamePhaseStepUpdatedEvent")
	EAthenaGamePhaseStep GamePhaseStep;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class AFortCreativeStormShield : public AFortMissionStormShield
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Storm Shield")
	void SetGamePhaseStep(const EAthenaGamePhaseStep NewGamePhaseStep);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Storm Shield", meta=(DisplayName="OnRep_GamePhaseStep"))
	void BP_OnRep_GamePhaseStep();

	UFUNCTION(BlueprintImplementableEvent, Category="Storm Shield", meta=(DisplayName="On Target Radius Reached"))
	void BP_OnTargetRadiusReached();

	UFUNCTION(BlueprintPure, Category="Storm Shield")
	float GetServerTime() const;

	UFUNCTION(BlueprintCallable, Category="Storm Shield")
	void OnGamePhaseStepChanged();

	UFUNCTION()
	void OnRep_GamePhaseStep();

	UPROPERTY(BlueprintReadOnly, Transient, Category="Storm Shield")
	FVector ViewTargetLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Storm Shield")
	bool bIsViewTargetPawnOutside;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_GamePhaseStep, Category="FortCreativeStormShield")
	EAthenaGamePhaseStep GamePhaseStep;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortCreativeStormShield")
	float NextTargetRadius;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortCreativeStormShield")
	FVector NextTargetLocation;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortCreativeStormShield")
	float NextNextTargetRadius;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortCreativeStormShield")
	FVector NextNextTargetLocation;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortCreativeStormShield")
	float InstancedServerTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeStormShield")
	float StartWaitTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeStormShield")
	float StartShrinkTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeStormShield")
	float FinishShrinkTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeStormShield")
	float FinishDestroyTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeStormShield")
	float AudioLowPassValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeStormShield")
	float AudioPitchMod;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeStormShield")
	float AudioCrossfade;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<UCurveFloat> MovementAudioCrossfadeCurve;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<UCurveFloat> MovementAudioPitchModCurve;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<UCurveFloat> ClockTickingAudioVolumeCurve;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<UCurveFloat> ClockTickingAudioPitchCurve;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Audio", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> ShieldBoundaryAudio;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Audio", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> HoldingAudio;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Audio", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> HoldingTickAudio;

	UPROPERTY(Transient)
	TObjectPtr<AFortVolume> SpawnVolume;

};

