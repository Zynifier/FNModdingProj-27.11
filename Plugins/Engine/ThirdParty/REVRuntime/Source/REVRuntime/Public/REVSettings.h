// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "REVSettings.generated.h"

// Settings from the Engine Controls section of the REV authoring tool that can be used to override behaviors on REV instances at runtime

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class REVRUNTIME_API URevSettings : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="RevSettings")
	void UpdateSettings();

	// Aka Fall Duration

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float UpShiftDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Attack", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float UpShiftAttackDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Attack", meta=(ClampMax="3.000000", ClampMin="1.000000"))
	float UpShiftAttackVolumeSpike;

	// RPM Spike

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Attack", meta=(ClampMax="2.000000", ClampMin="0.000000"))
	float UpShiftAttackRPM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Attack", meta=(ClampMax="0.300000", ClampMin="0.000000"))
	float UpShiftAttackThrottleTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Wobble", meta=(ClampMax="10.000000", ClampMin="0.050000"))
	float UpShiftWobblePitchFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Wobble", meta=(ClampMax="0.300000", ClampMin="0.000000"))
	float UpShiftWobblePitchAmp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Wobble")
	bool UpShiftWobbleEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Wobble", meta=(ClampMax="12", ClampMin="0.050000"))
	float UpShiftWobbleVolFreq;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Wobble", meta=(ClampMax="3.000000", ClampMin="0.000000"))
	float UpShiftWobbleVolAmp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Upshift | Wobble", meta=(ClampMax="3.000000", ClampMin="0.050000"))
	float UpShiftWobbleDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DownShift", meta=(ClampMax="3.000000", ClampMin="0.000000"))
	float DownShiftDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pop", meta=(ClampMax="3.000000", ClampMin="0.000000"))
	float PopDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Clutch", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float ClutchRPMSpike;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Clutch", meta=(ClampMax="2.000000", ClampMin="0.000000"))
	float ClutchRPMSpikeDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Clutch", meta=(ClampMax="2.000000", ClampMin="0.000000"))
	float ClutchRPMMergeTime;

};

