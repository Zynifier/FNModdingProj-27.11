// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FMInWorldKnobInterface.generated.h"

class APlayerController;
class UPlaylistUserOptionBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInWorldKnobRuntimeValueChanged, FString, Value, UPlaylistUserOptionBase*, Option);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnInWorldKnobSerializedValueChanged, FString, Value, UPlaylistUserOptionBase*, Option, APlayerController*, PlayerController);

UINTERFACE()
class FMINWORLDKNOBSRUNTIME_API UInWorldKnobInterface : public UInterface
{
	GENERATED_BODY()
};

class FMINWORLDKNOBSRUNTIME_API IInWorldKnobInterface
{
	GENERATED_BODY()

};

