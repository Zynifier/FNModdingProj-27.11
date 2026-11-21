// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SoundModulationWatcherFortnite.generated.h"

class USoundModulatorBase;

UCLASS(Config=Engine, EditInlineNew, BlueprintType)
class AUDIOMODULATIONFORTNITE_API USoundModulationWatcher : public UObject
{
	GENERATED_BODY()

public:
	// Returns true if a modulator was being watched and has been cleared.

	UFUNCTION(BlueprintCallable, Category="Audio|Modulation", meta=(DisplayName="Clear Modulator"))
	bool ClearModulator();

	// Returns currently set modulator being watched.

	UFUNCTION(BlueprintPure, Category="Audio|Modulation")
	const USoundModulatorBase* GetModulator() const;

	// Returns the last calculated modulator value sampled from the thread controls are processed on.

	UFUNCTION(BlueprintPure, Category="Audio|Modulation", meta=(DisplayName="Get Watched Modulator Value"))
	float GetValue() const;

	// Returns true if modulator was set to new value or was already set to provided value.

	UFUNCTION(BlueprintCallable, Category="Audio|Modulation", meta=(DisplayName="Set Watched Modulator"))
	bool SetModulator(const USoundModulatorBase* InModulator);

private:
	UPROPERTY()
	TObjectPtr<USoundModulatorBase> Modulator;

};

