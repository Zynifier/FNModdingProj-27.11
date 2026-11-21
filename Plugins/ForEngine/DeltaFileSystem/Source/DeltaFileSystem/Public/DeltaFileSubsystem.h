// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "UObject/SoftObjectPath.h"
#include "DeltaFileSubsystem.generated.h"

class UObject;
class UWorld;

USTRUCT()
struct FDeltaTrackingHandles
{
	GENERATED_BODY()

};

UCLASS(Config=Engine)
class DELTAFILESYSTEM_API UDeltaFileSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<TObjectPtr<UWorld>, FDeltaTrackingHandles> WorldToTrackingHandles;

	UPROPERTY(Transient)
	TMap<FName, TObjectPtr<UObject>> DeltaFiles;

	UPROPERTY(Config)
	FSoftClassPath DefaultDeltaFileClass;

};

