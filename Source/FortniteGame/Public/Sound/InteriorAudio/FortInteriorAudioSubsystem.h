// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Sound/InteriorAudio/FortInteriorAudioTypes.h"
#include "FortInteriorAudioSubsystem.generated.h"

class AFortInteriorAudioManager;
class AFortPlayerController;

UCLASS(Config=Game, meta=(DisplayName="Interior Audio Subsystem"))
class UFortInteriorAudioSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Interior Audio")
	void SetEnabled(bool bNewEnabled);

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> FPC;

	UPROPERTY(Transient)
	TObjectPtr<AFortInteriorAudioManager> AudioManager;

	UPROPERTY(Transient)
	FInteriorAudioScanResults CurrentScanResults;

};

