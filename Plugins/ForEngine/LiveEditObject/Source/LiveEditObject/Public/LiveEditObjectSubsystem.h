// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "LiveEditObjectSubsystem.generated.h"

class ULiveEditObjectConnection;
class ULiveEditObjectSubsystemState;

UCLASS(Config=Engine)
class LIVEEDITOBJECT_API ULiveEditObjectSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	int32 MaxBytesQueuedForReplication;

	UPROPERTY(Config)
	int32 NumPackageMapBunchesToDelayTickFor;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ULiveEditObjectSubsystemState>> NetDriverStates;

};

UCLASS()
class LIVEEDITOBJECT_API ULiveEditObjectSubsystemState : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<ULiveEditObjectConnection>> Connections;

};

