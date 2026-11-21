// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoutDroneTetherIndicator.generated.h"

class AFortScoutDrone;

UCLASS()
class UScoutDroneTetherIndicator : public UUserWidget
{
	GENERATED_BODY()

public:
	UScoutDroneTetherIndicator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Tether Events", meta=(DisplayName="OnEnterSignalLossRange"))
	void BP_OnEnterSignalLossRange();

	UFUNCTION(BlueprintImplementableEvent, Category="Tether Events", meta=(DisplayName="OnEnterWarningRange"))
	void BP_OnEnterWarningRange();

	UFUNCTION(BlueprintImplementableEvent, Category="Tether Events", meta=(DisplayName="OnExitWarningRange"))
	void BP_OnExitWarningRange();

	UFUNCTION(BlueprintImplementableEvent, Category="Tether Events", meta=(DisplayName="WhileInWarningRange"))
	void BP_WhileInWarningRange(float SignalIntensityPercentage);

	UFUNCTION(BlueprintPure, Category="Drone")
	AFortScoutDrone* GetControlledDrone() const;

};

