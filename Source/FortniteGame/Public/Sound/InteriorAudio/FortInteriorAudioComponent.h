// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Sound/InteriorAudio/FortInteriorAudioTypes.h"
#include "FortInteriorAudioComponent.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortInteriorAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_Init();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PostUpdate(const FInteriorAudioScanResults& InResults);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PreUpdate(UPARAM(ref) FInteriorAudioScanResults& OutResults);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_Shutdown();

	UPROPERTY(EditDefaultsOnly, Category="Interior Audio")
	uint64 FramesPerTick;

};

