// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Sound/SoundSourceBusSend.h"
#include "FMDeviceCablesFunctionLibrary.generated.h"

class UObject;
class USoundSourceBus;

UCLASS(BlueprintType, Blueprintable)
class FMDEVICECABLESRUNTIME_API UFMDeviceCablesFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="Outer", WorldContext="Context"))
	static USoundSourceBus* DeepCopySoundSourceBus(const UObject* Context, UObject* Outer, USoundSourceBus* Source);

	UFUNCTION(BlueprintCallable)
	static FSoundSourceBusSendInfo MakeSoundSourceBusSendInfo(USoundSourceBus* SoundSourceBus);

};

