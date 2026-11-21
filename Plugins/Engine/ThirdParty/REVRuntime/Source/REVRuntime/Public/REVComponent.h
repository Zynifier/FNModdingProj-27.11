// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SynthComponent.h"
#include "IAudioMotorSimOutput.h"
#include "REVComponent.generated.h"

class UREVModel;
class URevSettings;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "ActorComponent", "Physics", "Rendering", "Mobility", "LOD", "Trigger", "PhysicsVolume"), ClassGroup=("Synth"), meta=(BlueprintSpawnableComponent))
class REVRUNTIME_API UREVComponent : public USynthComponent, public IAudioMotorSimOutput
{
	GENERATED_BODY()

public:
	UREVComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="REVComponent")
	void SetRevModel(UREVModel* InModel);

	UFUNCTION(BlueprintCallable, Category="REVComponent")
	void SetSettings(URevSettings* InSettings);

	UFUNCTION(BlueprintCallable, Category="REVComponent")
	void UpdateParameters(const float InPitch, const float InRPM, const float InThrottle, const float InVelocity, const int32 InGear, const bool bInEnableShifting);

	UFUNCTION(BlueprintCallable, Category="REVComponent")
	void UpdateSimSettings();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="REV")
	TObjectPtr<UREVModel> Model;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="REV")
	TObjectPtr<URevSettings> SimSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="REV", meta=(ClampMax="2.000000", ClampMin="0.250000"))
	float PitchMultiplier;

	virtual void Update(FAudioMotorSimInputContext& Input, FAudioMotorSimRuntimeContext& RuntimeInfo) override;

	virtual void StartOutput() override;

	virtual void StopOutput() override;

};

