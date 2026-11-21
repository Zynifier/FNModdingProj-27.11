// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundSubmixSend.h"
#include "Subsystems/WorldSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "Sound/AudioAnalysis/FortAudioAnalysisTypes.h"
#include "FortAudioAnalysisSubsystem.generated.h"

class UAudioAnalysisSubmixAnalyzer;
class UFortAudioAnalysisDebugWidget;
class UFortAudioAnalysisSettings;
class UFortAudioAnalysisSubsystem;
class USoundSubmix;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAudioAnalysisStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAudioAnalysisStopped);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnvelopeFollowerUpdated, USoundSubmix*, Submix, float, Amplitude);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpectralAnalysisUpdated, USoundSubmix*, Submix, const TArray<float>&, Amplitudes);

UCLASS(BlueprintType)
class UAudioAnalysisSubmixAnalyzer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnSubmixEnvelope(const TArray<float>& Amplitudes);

	UFUNCTION()
	void OnSubmixSpectralAnalysis(const TArray<float>& Amplitudes);

	UPROPERTY()
	FOnSubmixEnvelopeBP OnSubmixEnvelopeDelegate;

	UPROPERTY()
	FOnSubmixSpectralAnalysisBP OnSubmixSpectralAnalysisDelegate;

private:
	UPROPERTY()
	TObjectPtr<USoundSubmix> Submix;

	UPROPERTY()
	FFortSubmixAnalyzerData AnalyzerData;

	UPROPERTY()
	TObjectPtr<UFortAudioAnalysisSubsystem> OwningSubsystem;

};

UCLASS(Config=Game, meta=(DisplayName="Audio Analysis Subsystem"))
class UFortAudioAnalysisSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AudioAnalysis")
	UFortAudioAnalysisSettings* GetAnalysisSettings() const;

	UFUNCTION(BlueprintPure, Category="AudioAnalysis")
	bool IsAnalysisActive() const;

	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	void RegisterDefaultSubmix();

	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	void RegisterSubmix(USoundSubmix* InSubmix, FFortSubmixAnalyzerData InAnalyzerData);

	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	void UnRegisterDefaultSubmix();

	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	void UnRegisterSubmix(USoundSubmix* InSubmix);

	UPROPERTY(Config, meta=(AllowedClasses="/Script/FortniteGame.FortAudioAnalysisSettings"))
	FSoftObjectPath AudioAnalysisSettingsPath;

	UPROPERTY(Transient)
	TObjectPtr<UFortAudioAnalysisSettings> DefaultAnalysisSettings;

	UPROPERTY(BlueprintAssignable, Category="AudioAnalysis")
	FOnAudioAnalysisStarted OnAudioAnalysisStarted;

	UPROPERTY(BlueprintAssignable, Category="AudioAnalysis")
	FOnAudioAnalysisStopped OnAudioAnalysisStopped;

	UPROPERTY(BlueprintAssignable, Category="AudioAnalysis")
	FOnEnvelopeFollowerUpdated OnEnvelopeFollowerUpdated;

	UPROPERTY(BlueprintAssignable, Category="AudioAnalysis")
	FOnSpectralAnalysisUpdated OnSpectralAnalysisUpdated;

private:
	UFUNCTION()
	UAudioAnalysisSubmixAnalyzer* GetAnalyzerForSubmix(USoundSubmix* InSubmix);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAudioAnalysisDebugWidget> DebugWidget;

	UPROPERTY()
	TMap<TObjectPtr<USoundSubmix>, TObjectPtr<UAudioAnalysisSubmixAnalyzer>> SubmixAnalyzers;

	UPROPERTY()
	TMap<TObjectPtr<USoundSubmix>, int32> SubmixRefCount;

};

