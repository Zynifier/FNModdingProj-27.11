// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PersistenceFramework/PersistenceFrameworkSubsystemExtension.h"
#include "PersistenceFrameworkSubsystemExtension_ServiceRegistry.generated.h"

class UPersistenceFrameworkServiceWrapper;

UENUM()
enum class EPersistenceFrameworkStorageEnvironment : uint8
{
	Live = 0,
	Playtest = 1,
};

UCLASS()
class FORTNITEGAME_API UPersistenceFrameworkSubsystemExtension_ServiceRegistry : public UPersistenceFrameworkSubsystemExtension
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	bool IsDataRegistryLoaded;

	UPROPERTY()
	EPersistenceFrameworkStorageEnvironment PersistenceFrameworkStorageEnvironment;

	UPROPERTY()
	TMap<FGameplayTag, TWeakObjectPtr<UPersistenceFrameworkServiceWrapper>> Services;

};

