// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDeviceInterface.generated.h"

enum class EPlayStopPauseExecutionContext : uint8;

UENUM(BlueprintType)
enum class EPlayStopPauseExecutionContext : uint8
{
	ServerOnly = 0,
	ServerAndClient = 1,
};

UINTERFACE(MinimalAPI)
class UNativePlayStopPauseInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API INativePlayStopPauseInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Device", meta=(DisplayName="Get Execution Context"))
	void Blueprint_GetExecutionContext(EPlayStopPauseExecutionContext& ExecContext) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Device", meta=(bDidPause="true", DisplayName="Pause"))
	void Blueprint_Pause(bool& bFailedToPause);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Device", meta=(DisplayName="Play"))
	void Blueprint_Play(bool bUnpaused, bool& bFailedToPlay);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Device", meta=(DisplayName="Stop"))
	void Blueprint_Stop(bool& bFailedToStop);

};

UINTERFACE(MinimalAPI, meta=(DisplayName="PlayPauseStartInterface"))
class UPlayStopPauseInterface : public UInterface
{
	GENERATED_BODY()
};

class IPlayStopPauseInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Device", meta=(DisplayName="Get Execution Context"))
	void BlueprintNativeEvent_GetExecutionContext(EPlayStopPauseExecutionContext& ExecContext) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Device", meta=(bDidPause="true", DisplayName="Pause"))
	void BlueprintNativeEvent_Pause(bool& bFailedToPause);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Device", meta=(DisplayName="Play"))
	void BlueprintNativeEvent_Play(bool& bFailedToPlay);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Device", meta=(DisplayName="Stop"))
	void BlueprintNativeEvent_Stop(bool& bFailedToStop);

};

