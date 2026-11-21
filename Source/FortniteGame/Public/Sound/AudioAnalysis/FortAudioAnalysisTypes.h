// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Sound/SoundSubmix.h"
#include "Sound/SoundSubmixSend.h"
#include "FortAudioAnalysisTypes.generated.h"

class UMaterialParameterCollection;
class UNiagaraParameterCollection;

UENUM(BlueprintType)
enum class EAudioAnalysisEnvelopeFollowerStereoBehavior : uint8
{
	Average = 0,
	Add = 1,
	Max = 2,
	Count = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EAudioAnalysisParameterType : uint8
{
	Scalar = 0,
	Vector4 = 1,
	Count = 2 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FAudioAnalysisEnvelopeFollowerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisEnvelopeFollowerData")
	FVector2D DecibelRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisEnvelopeFollowerData")
	EAudioAnalysisEnvelopeFollowerStereoBehavior StereoBehavior;

};

USTRUCT(BlueprintType)
struct FAudioAnalysisParamHistory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParamHistory")
	bool bEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParamHistory")
	FName NameSuffix;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParamHistory")
	int32 FrameCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParamHistory")
	float TimeBetweenFrames;

	UPROPERTY(BlueprintReadOnly, Category="AudioAnalysisParamHistory")
	TArray<FString> GeneratedParamNames;

};

USTRUCT(BlueprintType)
struct FAudioAnalysisParameterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParameterBase")
	FName Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParameterBase")
	TObjectPtr<UMaterialParameterCollection> MaterialPC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParameterBase")
	TObjectPtr<UNiagaraParameterCollection> NiagaraPC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParameterBase")
	FAudioAnalysisParamHistory History;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParameterBase")
	uint8 bDebug : 1;

};

USTRUCT(BlueprintType)
struct FAudioAnalysisParameterScalar : public FAudioAnalysisParameterBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FAudioAnalysisParameterVector : public FAudioAnalysisParameterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AudioAnalysisParameterVector", meta=(UIMin="1"))
	int32 VectorCount;

	UPROPERTY(BlueprintReadOnly, Category="AudioAnalysisParameterVector")
	TArray<FString> GeneratedParamNames;

};

USTRUCT(BlueprintType)
struct FAudioAnalysisSpectralAnalysisData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delegate")
	TArray<FSoundSubmixSpectralAnalysisBandSettings> BandSettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delegate")
	float UpdateRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delegate")
	float DecibelNoiseFloor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delegate")
	bool bDoNormalize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delegate")
	bool bDoAutoRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delegate")
	float AutoRangeAttackTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delegate")
	float AutoRangeReleaseTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FFT")
	EFFTSize FFTSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FFT")
	EFFTPeakInterpolationMethod InterpolationMethod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FFT")
	EFFTWindowType WindowType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FFT")
	float HopSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FFT")
	EAudioSpectrumType SpectrumType;

};

USTRUCT(BlueprintType)
struct FFortSubmixAnalyzerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Config")
	FAudioAnalysisEnvelopeFollowerData AmplitudeData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Config")
	FAudioAnalysisSpectralAnalysisData SpectrumData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSubmixAnalyzerData", meta=(TitleProperty="Name"))
	TArray<FAudioAnalysisParameterScalar> ScalarParameters;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSubmixAnalyzerData", meta=(TitleProperty="Name"))
	TArray<FAudioAnalysisParameterVector> VectorParameters;

};

