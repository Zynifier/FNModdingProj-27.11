// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MovieSceneFwd.h"
#include "DaySequenceProjectSettings.generated.h"

UCLASS(Config=Engine, DefaultConfig, meta=(DisplayName="Day Sequence"))
class UDaySequenceProjectSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Timeline", meta=(ConsoleVariable="DaySequence.DefaultLockEngineToDisplayRate"))
	bool bDefaultLockEngineToDisplayRate;

	UPROPERTY(EditAnywhere, Config, Category="Timeline", meta=(ConsoleVariable="DaySequence.DefaultDisplayRate"))
	FString DefaultDisplayRate;

	UPROPERTY(EditAnywhere, Config, Category="Timeline", meta=(ConsoleVariable="DaySequence.DefaultTickResolution"))
	FString DefaultTickResolution;

	UPROPERTY(EditAnywhere, Config, Category="Timeline", meta=(ConsoleVariable="DaySequence.DefaultClockSource"))
	EUpdateClockSource DefaultClockSource;

};

