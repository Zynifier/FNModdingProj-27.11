// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreativePowerBarComponent.generated.h"

class UCurveFloat;

UCLASS()
class UCreativePowerBarComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetPowerPercentage() const;

	UFUNCTION(BlueprintCallable)
	void InitializePowerBar(const bool bLoops = true, const float ChangeRate = 1.000000f, const UCurveFloat* NewPowerCurve = nullptr);

	UFUNCTION(BlueprintPure)
	bool IsInterpolationPaused() const;

	UFUNCTION(BlueprintCallable)
	void ResumeInterpolation();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetStopTime(const float ServerStopTime);

	UFUNCTION(BlueprintCallable)
	void SetLooping(const bool bLooping);

	UFUNCTION(BlueprintCallable)
	void SetPowerCurve(const UCurveFloat* NewPowerCurve);

	UFUNCTION(BlueprintCallable)
	void StopInterpolation();

protected:
	UPROPERTY(Replicated)
	float StartTime;

	UPROPERTY(Replicated)
	bool bLoop;

	UPROPERTY(Replicated)
	TObjectPtr<UCurveFloat> PowerCurve;

};

