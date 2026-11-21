// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PersistenceFrameworkSubsystem.generated.h"

class UObject;
class UPersistenceFrameworkActionQueue;
class UPersistenceFrameworkServiceWrapper;
class UPersistenceFrameworkSubsystemExtension;

UCLASS()
class FORTNITEGAME_API UPersistenceFrameworkSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FName ModeName;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkActionQueue> DeinitProcess;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UPersistenceFrameworkServiceWrapper>> ServiceWrappers;

	UPROPERTY()
	TMap<TSubclassOf<UObject>, TObjectPtr<UPersistenceFrameworkSubsystemExtension>> ClassToExtension;

};

