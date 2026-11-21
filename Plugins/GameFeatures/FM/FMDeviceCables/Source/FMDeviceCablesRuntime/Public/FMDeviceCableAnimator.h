// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FabricMetasoundPatchWrapper.h"
#include "FMDeviceCableAnimator.generated.h"

class UCurveFloat;
class UFMDeviceCableConnectionBase;
class UFMDeviceCablePortComponent;
class UFabricFloatProviderBase;
class UFabricMeshProviderBase;
class UFabricMetaSoundPatchWrapper;
class UFabricTextureProviderBase;
class UMaterialInstanceDynamic;
class UTexture2D;

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableAnimatorBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddMaterialInstance(UMaterialInstanceDynamic* InMaterialInstance);

	UFUNCTION(BlueprintCallable)
	void RemoveMaterialInstance(UMaterialInstanceDynamic* InMaterialInstance);

	UFUNCTION(BlueprintCallable)
	void SetOwnerPort(UFMDeviceCablePortComponent* OwnerPort);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Tick"))
	void ReceiveTick(float DeltaSeconds);

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFMDeviceCablePortComponent> OwnerPort;

private:
	UFUNCTION()
	void OnConnectionEnded(UFMDeviceCableConnectionBase* EndedConnection);

	UFUNCTION()
	void OnConnectionStarted(UFMDeviceCableConnectionBase* NewConnection);

	UFUNCTION()
	void OnPortArtifactUpdated();

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableAnimatorAudioAnalyzer : public UFMDeviceCableAnimatorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetLastAnalyzerValue() const;

	UFUNCTION(BlueprintCallable)
	void SetAnalyzerName(FName AnalyzerName);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	FName FftTextureParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	FName WaveformTextureParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	FName AmplitudeTextureParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	FName AmplitudeDataParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	FName CableQualityParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	FName CableReactivityParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	int32 WaveformNumSamplesHeld;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	int32 WaveformSmoothingDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	float WaveformSmoothingFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorAudioAnalyzer")
	float WaveformDecayPerSecond;

private:
	UFUNCTION()
	void OnMetaSoundOutputFloatChangedBatch(const FName& OutputName, TArray<float>& Output, FFabricMetaSoundPatchWrapperPeakTamer& PeakTamer, float DeltaSeconds);

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> WaveformTexture;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> AmplitudeTexture;

	UPROPERTY(Transient)
	TObjectPtr<UFabricMetaSoundPatchWrapper> PatchWrapper;

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableAnimatorFloatProvider : public UFMDeviceCableAnimatorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetFloatProvider(UFabricFloatProviderBase* InFloatProvider);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorFloatProvider")
	FName CableDataParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorFloatProvider")
	FName FloatProviderTypeParam;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFabricFloatProviderBase> FloatProvider;

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableAnimatorMeshProvider : public UFMDeviceCableAnimatorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetMeshProvider(UFabricMeshProviderBase* InMeshProvider);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorMeshProvider")
	FName CableDataParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorMeshProvider")
	float DecayRate;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFabricMeshProviderBase> MeshProvider;

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableAnimatorMidiEvent : public UFMDeviceCableAnimatorBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorMidiEvent")
	FName NoteTextureParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorMidiEvent")
	TObjectPtr<UCurveFloat> NoteShapeCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorMidiEvent")
	float NotePercentOfTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorMidiEvent")
	float NoteTravelBeats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorMidiEvent")
	float NoteStartDelayBeats;

private:
	UFUNCTION()
	void OnMetaSoundOutputIntChangedBatch(const FName& OutputName, const TArray<int32>& Output);

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> NoteTexture;

	UPROPERTY(Transient)
	TObjectPtr<UFabricMetaSoundPatchWrapper> PatchWrapper;

};

UCLASS(BlueprintType, Blueprintable)
class UFMDeviceCableAnimatorTextureProvider : public UFMDeviceCableAnimatorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetTextureProvider(UFabricTextureProviderBase* InTextureProvider);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorTextureProvider")
	FName CableDataParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCableAnimatorTextureProvider")
	float DecayRate;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFabricTextureProviderBase> TextureProvider;

};

