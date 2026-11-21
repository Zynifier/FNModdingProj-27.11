// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Harmonix/HarmonixDeveloperSettings.h"
#include "HarmonixDsp/PitchShifterName.h"
#include "StretcherAndPitchShifterFactoryConfig.generated.h"

USTRUCT()
struct FPitchShifterNameRedirect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Factory")
	FName OldName;

	UPROPERTY(EditDefaultsOnly, Category="Factory")
	FName NewName;

};

UCLASS(Config=Engine, DefaultConfig, meta=(DisplayName="Pitch Shifter Settings"))
class HARMONIXDSP_API UStretcherAndPitchShifterFactoryConfig : public UHarmonixDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Factory")
	TArray<FName> FactoryPriority;

	UPROPERTY(EditDefaultsOnly, Config, Category="Factory")
	FPitchShifterName DefaultFactory;

private:
	// visible in editor, but not editable

	UPROPERTY(EditDefaultsOnly, Config, Category="Factory", meta=(EditCondition="false"))
	TArray<FPitchShifterNameRedirect> FactoryNameRedirects;

};

