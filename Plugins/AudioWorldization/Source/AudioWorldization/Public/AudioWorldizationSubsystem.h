// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AudioWorldizationSettings.h"
#include "AudioWorldizationSubsystem.generated.h"

class AAudioWorldizationReflectionProbe;
class UAudioWorldizationTraceDirectionPolicyBase;
class UAudioWorldizationTracePolicyBase;
class USoundControlBus;

UCLASS()
class AUDIOWORLDIZATION_API UAudioWorldizationSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Audio Worldization")
	float GetEnclosureFactor() const;

	UFUNCTION(BlueprintPure, Category="Audio Worldization")
	float GetWallDistanceRatio() const;

	UFUNCTION(BlueprintCallable, Category="Audio Worldization")
	void RemoveWorldizationSettings(const FName InIdentifier);

	UFUNCTION(BlueprintCallable, Category="Audio Worldization")
	void SetDefaultSettings();

	UFUNCTION(BlueprintCallable, Category="Audio Worldization")
	void SetEnabled(bool bNewEnabled);

	UFUNCTION(BlueprintCallable, Category="Audio Worldization")
	void SetWorldizationSettings(const FAudioWorldizationSettings& InSettings);

	UPROPERTY(BlueprintReadOnly, Transient, Category="AudioWorldizationSubsystem")
	TObjectPtr<USoundControlBus> EnclosureBus;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AudioWorldizationSubsystem")
	TObjectPtr<USoundControlBus> WallDistanceBus;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AudioWorldizationSubsystem")
	TObjectPtr<USoundControlBus> ListenerAzimuthBus;

private:
	UPROPERTY(Transient)
	FAudioWorldizationSettings CurrentSettings;

	UPROPERTY(Transient)
	TObjectPtr<AAudioWorldizationReflectionProbe> VolumeActor;

	UPROPERTY(Transient)
	TObjectPtr<UAudioWorldizationTracePolicyBase> TracePolicy;

	UPROPERTY(Transient)
	TObjectPtr<UAudioWorldizationTraceDirectionPolicyBase> TraceDirectionPolicy;

	UPROPERTY(Transient)
	TArray<FAudioWorldizationSettings> SettingsStack;

	UPROPERTY(Transient)
	TArray<TObjectPtr<USoundControlBus>> QuadrantEnclosureBuses;

	UPROPERTY(Transient)
	TArray<TObjectPtr<USoundControlBus>> QuadrantWallDistanceBuses;

};

