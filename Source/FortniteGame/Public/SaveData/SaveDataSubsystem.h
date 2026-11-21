// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "SaveDataSubsystem.generated.h"

class UDeviceSaveCollection;

UENUM()
enum class ESaveLocation : uint8
{
	/** Local settings specific to the device you're using.  For platforms with cloud save, this means, it will work like Cloud_ForPlatform */
	Local_ForDevice = 0,
};

UCLASS(Abstract, MinimalAPI)
class USaveData : public UObject
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class USaveDataSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UDeviceSaveCollection> LocalForDevice;

};

