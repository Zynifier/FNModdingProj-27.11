// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "Sound/SoundWave.h"
#include "FortAudioToMPCComponent.generated.h"

class UAudioComponent;
class UMaterialParameterCollection;

USTRUCT(BlueprintType)
struct FChannelData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AudioToMPC")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AudioToMPC")
	float MaxMagnitude;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AudioToMPC")
	float Value;

};

USTRUCT(BlueprintType)
struct FVector4ChannelData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AudioToMPC")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AudioToMPC")
	FVector4 MaxMagnitudes;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AudioToMPC")
	FVector4 Value;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortAudioToMPCComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Audio To MPC")
	void AddTrackedAudioComponent(UAudioComponent* InAudioComponent);

	UFUNCTION(BlueprintPure, Category="Audio To MPC")
	float GetCachedAverageMagnitude() const;

	UFUNCTION(BlueprintPure, Category="Audio To MPC")
	float GetCachedMagnitudeForChannel(int32 ChannelIndex) const;

	UFUNCTION(BlueprintCallable, Category="Audio To MPC")
	bool RemoveTrackedAudioComponent(UAudioComponent* InAudioComponent);

	UPROPERTY(EditAnywhere, Category="Audio To MPC")
	bool bPushDataToMPC;

	UPROPERTY(EditAnywhere, Category="Audio To MPC")
	bool bCacheDataForBlueprintUse;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Audio To MPC")
	void OnGatheredFFTData(UPARAM(ref) TArray<FChannelData>& FFTData, UPARAM(ref) float& OutAmplitudeAverage);

	UPROPERTY(EditAnywhere, Category="Audio To MPC")
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY(EditAnywhere, Category="Audio To MPC")
	TArray<FChannelData> ChannelDataArray;

	UPROPERTY(EditAnywhere, Category="Audio To MPC")
	TArray<FVector4ChannelData> VectorChannelDataArray;

private:
	UPROPERTY(Transient)
	TArray<FSoundWaveSpectralDataPerSound> FFTDataArray;

	UPROPERTY(Transient)
	TArray<FSoundWaveSpectralDataPerSound> TempFFTDataArray;

	UPROPERTY(Transient)
	bool bWasPlaying;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TSet<TObjectPtr<UAudioComponent>> TrackedAudioComponents;

};

