// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortAthenaAlertStateComponent.generated.h"

class AFortAthenaAIBotController;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent))
class UFortAthenaAlertStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetStealthMeterTarget() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetStealthMeterTargetTime() const;

	UFUNCTION()
	void OnStealthMeterChanged(AFortAthenaAIBotController* BotController, float StealthMeterTarget, float StealthMeterTargetTime);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetStealthMeterTarget(const float InStealthMeterTarget);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetStealthMeterTargetTime(const float InStealthMeterTargetTime);

protected:
	UPROPERTY(BlueprintGetter=GetStealthMeterTarget, BlueprintSetter=SetStealthMeterTarget, Replicated, Category="FortAthenaAlertStateComponent")
	float StealthMeterTarget;

	UPROPERTY(BlueprintGetter=GetStealthMeterTargetTime, BlueprintSetter=SetStealthMeterTargetTime, Replicated, Category="FortAthenaAlertStateComponent")
	float StealthMeterTargetTime;

};

