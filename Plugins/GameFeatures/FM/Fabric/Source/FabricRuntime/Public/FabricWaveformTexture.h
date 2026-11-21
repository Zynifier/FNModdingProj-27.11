// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FabricWaveformTexture.generated.h"

class UTexture2D;

UCLASS(BlueprintType, Blueprintable)
class UFabricWaveformTexture : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddMultipleValuesToWaveformTexture(TArray<float>& Values);

	UFUNCTION(BlueprintCallable)
	void AddNewValueToWaveformTexture(float Value);

	UFUNCTION(BlueprintPure)
	UTexture2D* GetWaveformTexture() const;

	UFUNCTION(BlueprintCallable)
	void Initialize();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricWaveformTexture")
	int32 WaveformNumSamplesHeld;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricWaveformTexture")
	int32 WaveformSmoothingDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricWaveformTexture")
	float WaveformSmoothingFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricWaveformTexture")
	float WaveformDecayPerSecond;

private:
	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> WaveformTexture;

	UPROPERTY(Transient)
	bool bEnableTextureRequests;

};

