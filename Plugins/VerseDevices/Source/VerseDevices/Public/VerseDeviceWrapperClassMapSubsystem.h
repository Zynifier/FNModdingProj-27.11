// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "VerseDeviceWrapperClassMapSubsystem.generated.h"

class AActor;
class UObject;

UCLASS(Transient)
class UVerseDeviceWrapperClassMapSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<TSoftClassPtr<AActor>, TSubclassOf<UObject>> DeviceClassToVerseClassMap;

};

